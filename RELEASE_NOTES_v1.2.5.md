# C PIC Compiler v1.2.5 (Release 18) 🚀

Esta versión incluye una importante modernización del entorno de desarrollo, compatibilidad completa con las últimas versiones de Android y optimizaciones del motor de compilación nativo.

---

## 🌟 Novedades y Mejoras

### 📱 Compatibilidad y Plataforma
- **Android Target SDK 37**: Actualización a la API 37 de Android (Android 17) con soporte hacia atrás desde Android 6.0 (API 23).
- **Alineación de páginas a 16 KB**: Optimizaciones en las bibliotecas nativas ARM64 (`arm64-v8a`) para garantizar compatibilidad total con los requisitos de Android 15, Android 16 y Android 17.
- **Herramientas de Compilación Modernizadas**:
  - Android Gradle Plugin (AGP) **9.2.1**
  - Gradle Wrapper **9.6.0**
  - Android NDK **30.0.14904198 rc1**
  - CMake **4.1.2**
  - Build Tools **37.0.0**

### 🔒 Seguridad y Configuración
- Configuración automatizada de firmas para versiones de producción mediante variables de entorno y archivo local seguro.
- Protección estricta de claves y certificados en `.gitignore`.

### 🛠 Automatización y Documentación
- Incorporación de `setup-sdk.sh` para aprovisionamiento rápido del SDK en `/tmp/android-sdk`.
- Redirección de cachés y artefactos de compilación a `/tmp/calculo` y `/tmp/.gradle` para optimizar el almacenamiento.
- Integración de script de despliegue a Google Play API (`upload_play_store.py`) y guía técnica `GUIA_PUBLICACION_PLAY_STORE.md`.
- Actualización completa de la documentación en `README.md` y `GEMINI.md`.

---

## 📦 Artefactos Adjuntos
- **`C_PIC_Compiler_v1.2.5.apk`**: APK Release optimizado y firmado para dispositivos ARM64.
- **`C_PIC_Compiler_v1.2.5.aab`**: Android App Bundle firmado listo para Google Play Store.
