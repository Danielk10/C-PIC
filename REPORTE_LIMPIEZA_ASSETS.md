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
