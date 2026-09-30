# Reporte de Limpieza de Assets y Optimización de Paquetes
**Paquete**: `com.diamon.ptc` (C PIC Compiler)

Este reporte documenta los archivos y carpetas dentro de `fake_root/data/data/com.diamon.ptc/files/usr` que no son necesarios en el directorio `assets/` de la aplicación Android en runtime, y que fueron omitidos para reducir drásticamente el tamaño del APK y mejorar el rendimiento de extracción.

---

### 1. Archivos y Carpetas Depurados en `assets`

**A. Binarios Ejecutables Nativos ELF (59 binarios en `usr/bin/` y 1 en `usr/libexec/`)**
* **Ruta Original:** `usr/bin/*` y `usr/libexec/sdcc/aarch64-unknown-linux-gnu/12.1.0/cc1`
* **Razón:** Google Play exige que todos los ejecutables y librerías ELF residan en `jniLibs/arm64-v8a/` bajo el nombre `lib<nombre>.so`. Dejarlos en `assets` duplicaría el peso en más de 43 MB.
* **Ahorro:** ~44.3 MB

**B. Código Fuente de Librerías SDCC (`src/`)**
* **Rutas:** `usr/share/sdcc/lib/src/` y `usr/share/sdcc/non-free/lib/src/`
* **Razón:** Contienen el código fuente en C y ensamblador usado originalmente para construir las librerías precompiladas de SDCC. En tiempo de ejecución, el compilador solo enlaza los archivos `.lib` ya compilados (`lib/pic14/*.lib`, `lib/pic16/*.lib`, etc.) y las cabeceras `.h`. No requiere el código fuente.
* **Ahorro:** ~105.0 MB

**C. Documentación y Manuales de Usuario (Man Pages / HTML)**
* **Rutas:** `usr/share/doc/` y `usr/share/man/`
* **Razón:** La aplicación móvil cuenta con su propia interfaz de usuario nativa y no visualiza ni accede a manuales UNIX (`man1/`, `man3/`) ni documentación HTML en runtime.
* **Ahorro:** ~1.1 MB

---

### 2. Archivos y Carpetas Necesarios Conservados en `assets`

* **`usr/share/gputils/header/`**: Archivos de cabecera (`.inc`) para todos los microcontroladores PIC soportados por gputils.
* **`usr/share/gputils/lkr/`**: Scripts de enlace (`.lkr`) para la asignación de memoria en microcontroladores PIC.
* **`usr/share/sdcc/include/`**: Cabeceras estándar y específicas de microcontroladores (`pic14/`, `pic16/`, etc.).
* **`usr/share/sdcc/lib/`**: Librerías binarias precompiladas (`.lib`) organizadas por arquitectura de microcontrolador.
* **`usr/share/sdcc/non-free/include/`**: Cabeceras de microcontroladores adicionales.
* **`usr/share/sdcc/non-free/lib/`**: Librerías binarias precompiladas non-free.

---

### 3. Resumen del Impacto de la Limpieza
* **Espacio Ahorrado en APK/AAB:** Más de **150 MB** reducidos.
* **Velocidad de Arranque:** `AssetExtractor.java` extrae los recursos indispensables en una fracción del tiempo original durante el primer inicio de la aplicación.
* **Compatibilidad:** 100% compatible con las políticas de Google Play Store y optimizado para arquitecturas ARM64 con alineación de páginas a 16 KB.

---

### 4. Rutas Críticas de Ejecución y Enlaces Simbólicos

En Android (especialmente en Android 10+ / API 29+ y targetSdk 37), el sistema operativo impone estrictas políticas de SELinux (`W^X`):
1. **Directorio de Binarios Nativos**: Todos los ejecutables ELF (`sdcc`, `sdld`, `sdcpp`, `cc1`, `gpasm`, `gplink`, etc.) **deben residir exclusivamente en `jniLibs/arm64-v8a/`** con el formato `lib<nombre>.so`. Ningún ejecutable debe colocarse directamente en `assets/` para su ejecución en `files/usr/bin`, ya que SELinux bloquea la ejecución de archivos ubicados en `app_data_file`.
2. **Entorno y Rutas Críticas (`SdccExecutor.java`)**:
   - `SDCC_HOME`: Debe apuntar a `/data/data/com.diamon.ptc/files/usr`.
   - `SDCC_LIB`: Apunta a `usr/share/sdcc/lib`.
   - `SDCC_INCLUDE`: Apunta a `usr/share/sdcc/include`.
   - `PATH`: Incluye `usr/bin:` seguido del directorio de librerías nativas `nativeLibraryDir` (`/data/app/.../lib/arm64`).
   - `LD_LIBRARY_PATH`: Debe incluir `usr/lib:` y `nativeLibraryDir` para resolver librerías compartidas con versionado (`libncursesw.so.6`, `libreadline.so.8`, `libz.so.1`, etc.).
3. **Enlaces Simbólicos en `usr/bin/` y `usr/libexec/`**:
   `SdccExecutor.java` reconstruye dinámicamente enlaces simbólicos apuntando a los archivos reales en `nativeLibraryDir`. Para garantizar que herramientas como `cc1`, `sdcpp`, `sdld`, `gpasm`, `gplink` y los ensambladores sean localizados sin importar el mecanismo de búsqueda de SDCC, se deben mantener enlaces tanto en `usr/bin/` como en `usr/libexec/sdcc/aarch64-unknown-linux-gnu/4.5.0/` (y sus variantes genéricas).

---

### 5. Protocolo Crítico para la Incorporación de Nuevos Binarios de SDCC en Versiones Futuras

Cuando en el futuro se compile o actualice una nueva versión de SDCC (por ejemplo, SDCC 4.6.0+ o compilaciones desde código fuente para Termux / Android), **es obligatorio verificar y aplicar el siguiente ajuste en el enlazador `sdld` (ASlink)**:

#### El Problema de Detección de Arquitectura en Android:
En el código fuente original de ASlink (`sdas/linksrc/`):
```c
char *base = basename(argv[0]);
if (strncmp(base, "sdld", 4) == 0) {
    is_sdld = 1;
    if (base[4] == '\0') {
        target = 4; // MCS-51 / 8051 por defecto
    } else {
        // Busca sub-cadenas: gb (1), z80 (2), z180 (3), 8051 (4), 6808 (5), stm8 (6), pdk (7), f8 (11)
    }
} else {
    is_sdld = 0; // Desconocido / generic
}
```

Al empaquetar para Android:
1. `libsdcc.so` inspecciona su propio nombre de archivo. Al llamarse `libsdcc.so`, detecta el prefijo `lib` y el sufijo `.so`. En consecuencia, al invocar al enlazador no ejecuta `sdld`, sino `/data/app/.../lib/arm64/libsdld.so`.
2. Al ejecutarse con `argv[0] = "libsdld.so"`, `strncmp("libsdld.so", "sdld", 4)` **falla**, porque el nombre inicia con `lib` y no con `sdld`. Esto deja `is_sdld = 0` y `target = 0`.
3. Además, si el nombre termina en `.so`, `base[4]` es `'.'` en lugar de `'\0'`, impidiendo que asigne el `target = 4` por defecto.

#### Síntomas de la Falla si no se Aplica el Ajuste:
- **Error 1**: `?ASlink-Warning-Undefined Global 'l_IRAM' referenced by module ''`. Ocurre porque la definición automática de `l_IRAM` sólo se activa si `target == 4`. Al ser `target == 0`, `crtclear.rel` (el startup de MCS-51) no puede enlazar.
- **Error 2**: `?ASlink-Error-<cannot open> : "0x0100.rel"`. Ocurre cuando se pasa `--iram-size 256` (que escribe `-I 0x0100` en el `.lk`). Si `is_sdld == 0`, ASlink no consume el parámetro numérico de `-I`, tratándolo como un archivo objeto inexistente.

#### Ajuste Requerido en los Binarios de `libsdld*.so`:
En cualquier binario nuevo de `sdld` para Android:
1. Cambiar la condición de detección para buscar la presencia de `"sdld"` mediante `strstr(base, "sdld")` (o descartar el prefijo `lib`).
2. Si ninguna de las sub-arquitecturas (`gb`, `z80`, `z180`, `stm8`, `pdk`, `f8`, `6808`) coincide, **asignar por defecto `target = 4` (MCS-51 / 8051)**, igual que en PC.
3. Asegurar que las réplicas en `jniLibs/arm64-v8a/` (`libsdld.so`, `libsdldz80.so`, `libsdldstm8.so`, `libsdldgb.so`, `libsdldpdk.so`, `libsdldf8.so`, `libsdld6808.so`) incorporen esta detección.
