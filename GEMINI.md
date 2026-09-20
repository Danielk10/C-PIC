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

Para compilar el proyecto manteniendo el espacio de trabajo limpio, los artefactos de compilación se generan en el directorio temporal `/tmp/calculo`.

### Comandos de Compilación:

- **Compilar APK en modo Debug:**
  ```bash
  ./gradlew assembleDebug
  ```
  Salida: `/tmp/calculo/outputs/apk/debug/app-debug.apk`

- **Compilar APK firmado en modo Release:**
  ```bash
  ./gradlew assembleRelease
  ```
  Salida: `/tmp/calculo/outputs/apk/release/app-release.apk`

- **Compilar Android App Bundle (.aab) firmado para Google Play:**
  ```bash
  ./gradlew bundleRelease
  ```
  Salida: `/tmp/calculo/outputs/bundle/release/app-release.aab`

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

Siempre que se preparen, redacten o presenten notas de lanzamiento (Release Notes para GitHub Releases o Google Play Store), **deben mostrarse y documentarse obligatoriamente en ambos idiomas: inglés y español**.

