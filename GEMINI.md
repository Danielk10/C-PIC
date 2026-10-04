# Instrucciones de Compilación y Configuración de C-PIC

Este documento describe la arquitectura, configuración del entorno, herramientas de compilación, firma y proceso de despliegue para el proyecto **C-PIC** (`com.diamon.ptc`).

---

## 1. Instalación del Entorno y SDK de Android

El entorno de compilación se configura de forma desatendida mediante el script [`setup-sdk.sh`](setup-sdk.sh):

```bash
bash setup-sdk.sh
```

### Componentes y Rutas:
- **Directorio del SDK:** `/tmp/android-sdk`
- **Build Tools:** `37.0.0`
- **Platforms:** `android-23`, `android-37.0`
- **CMake:** `4.1.2`
- **NDK:** `30.0.14904198` (`rc1`)
- **Gradle:** `9.6.0` (Gradle Wrapper configurado con `GRADLE_USER_HOME=/tmp/.gradle`)
- **Android Gradle Plugin (AGP):** `9.2.1`

---

## 2. Configuración de Firma y Seguridad

La firma para compilaciones de producción (Release) se configura a través del archivo `keystore.properties` ubicado en la raíz del proyecto:

```properties
storeFile=/ruta/a/tu/keystore.jks
storePassword=********
keyAlias=tu_alias
keyPassword=********
```

> 🔒 **Seguridad**: El archivo `keystore.properties`, los certificados `*.jks`, `local.properties`, `google-services.json` y credenciales `pc-api-*.json` están estrictamente ignorados en [`.gitignore`](.gitignore) para evitar su exposición en repositorios remotos.

---

## 3. Compilación

Para compilar el proyecto manteniendo el espacio de trabajo limpio, los artefactos de compilación se generan en el directorio temporal `/tmp/c-pic-compiler`.

### Comandos de Compilación:

- **Compilar APK en modo Debug:**
  ```bash
  ./gradlew assembleDebug
  ```
  Salida: `/tmp/c-pic-compiler/outputs/apk/debug/app-debug.apk`

- **Compilar APK firmado en modo Release:**
  ```bash
  ./gradlew assembleRelease
  ```
  Salida: `/tmp/c-pic-compiler/outputs/apk/release/app-release.apk`

- **Compilar Android App Bundle (.aab) firmado para Google Play:**
  ```bash
  ./gradlew bundleRelease
  ```
  Salida: `/tmp/c-pic-compiler/outputs/bundle/release/app-release.aab`

---

## 4. Publicación en Google Play Store

El repositorio incluye el script automatizado [`upload_play_store.py`](upload_play_store.py) y su guía completa [`GUIA_PUBLICACION_PLAY_STORE.md`](GUIA_PUBLICACION_PLAY_STORE.md) para realizar despliegues directos a la consola de Google Play.

---

## 5. Idioma por Defecto en Recursos de la App

- **Idioma Base Obligatorio**: El directorio principal de recursos [`app/src/main/res/values/strings.xml`](app/src/main/res/values/strings.xml) debe contener **estrictamente el idioma inglés** como idioma por defecto para cualquier usuario a nivel global cuyo idioma no coincida con una variante específica.
- **Localización al Español**: La traducción completa al español debe residir obligatoriamente en [`app/src/main/res/values-es/strings.xml`](app/src/main/res/values-es/strings.xml).
- **Paridad Lingüística**: Se debe mantener paridad exacta del 100% de claves entre los recursos base (inglés) y las variantes regionales.

---

## 6. Notas de Lanzamiento Bilingües Obligatorias

Siempre que se preparen, redacten o presenten notas de lanzamiento (Release Notes para GitHub Releases o Google Play Store), **deben mostrarse y documentarse obligatoriamente en ambos idiomas: inglés y español**:

- **GitHub Releases**: Las notas de versión para GitHub deben ser completas, exhaustivas y detalladas, cubriendo tanto mejoras técnicas de arquitectura, cambios de enlaces, solución de bugs, detalles de interfaz y cobertura de pruebas.
- **Google Play Store**: Las notas de versión para Google Play Store son más concisas y orientadas al usuario final (adecuadas a los límites de longitud de la tienda). **Siempre se debe proporcionar al usuario la nota de versión de Google Play Store en inglés y en español** de manera explícita para que pueda revisarla y validarla antes de publicar en la tienda.

---

## 7. Actualización de Binarios de SDCC / GPUTILS y Rutas Críticas del Enlazador (`libsdld.so`)

Al compilar o integrar versiones futuras de SDCC (como SDCC 4.6.0+ o paquetes actualizados desde Termux/código fuente), **es imprescindible cumplir con las siguientes directrices arquitectónicas**:

1. **Restricción de Ejecutables en Android**: Todos los binarios ejecutables ELF deben ubicarse en `app/src/main/jniLibs/arm64-v8a/` bajo el prefijo `lib` y sufijo `.so` (`libsdcc.so`, `libsdld.so`, `libgpasm.so`, etc.). Nunca deben colocarse ejecutables en `assets/` para ejecutarse en `files/usr/bin/` debido a restricciones de SELinux (`W^X` / `app_data_file`) en Android 10+ (API 29+).
2. **Invocación de Binarios Compañeros**: `libsdcc.so` inspecciona su propio nombre de ejecutable. Al llamarse `libsdcc.so`, deduce que sus herramientas asociadas usan el prefijo `lib` y sufijo `.so` (ejecutando `/data/app/.../lib/arm64/libsdld.so`).
3. **Requisito Crítico en `libsdld*.so` (ASlink)**:
   - En el código fuente nativo de ASlink (`sdas/linksrc/`), la función `init_target()` comprueba `strncmp(basename(argv[0]), "sdld", 4) == 0`.
   - Como en Android el nombre es `libsdld.so`, la comprobación estándar falla al iniciar con `lib`, provocando que `is_sdld` sea `0` y la arquitectura objetivo quede en `0` (desconocida).
   - **Ajuste Obligatorio en Nuevos Binarios**: Se debe adaptar la búsqueda para detectar `"sdld"` mediante `strstr(base, "sdld")`. Además, si ninguna de las sub-arquitecturas (`gb`, `z80`, `stm8`, etc.) coincide, debe asignar por defecto `target = 4` (MCS-51 / 8051).
   - De omitirse este ajuste, fallará el enlace en MCS-51 con el error `Undefined Global 'l_IRAM'` y la opción de memoria `--iram-size` lanzará `?ASlink-Error-<cannot open> : "0x0100.rel"`.
4. **Mantenimiento de Enlaces en `SdccExecutor.java`**:
   - Se deben mantener los enlaces simbólicos explícitos para `sdld`, `sdld8051`, `sdld-8051` y ensambladores `as*` tanto en `usr/bin/` como en las rutas de búsqueda de `usr/libexec/`.
   - La eliminación de enlaces simbólicos previos debe realizarse de forma atómica mediante `Files.deleteIfExists` para evitar excepciones `EEXIST` tras actualizaciones de la aplicación.


