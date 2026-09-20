# Notas de la Versión / Release Notes v1.4.1 (VersionCode 21) - C-PIC Compiler

Fecha de lanzamiento / Release Date: 20 de Septiembre de 2026 / September 20, 2026

---

## 🇪🇸 Español

### 🚀 Novedades y Correcciones Principales

#### 1. Corrección de `TransactionTooLargeException` (Crashlytics #93e7d779)
• **Causa raíz eliminada**: Se deshabilitó la serialización automática de la vista de terminal en el Bundle del sistema (`android:saveEnabled="false"` en `activity_main.xml`), impidiendo que más de 600 KB de logs de compilación intenten viajar por Binder IPC y excedan el límite de 1 MB de Android al rotar o minimizar.
• **Persistencia eficiente sin sobrecargar Binder**: Se implementó almacenamiento en caché temporal privado en disco (`terminal_cache.tmp`) durante cambios de configuración (rotación de pantalla y cambio de actividad).
• **Limpieza estricta de sesión**: Al iniciar la app desde el lanzador (cold start), la terminal arranca completamente limpia con los mensajes iniciales. Al rotar, los logs se restauran en memoria y el archivo temporal se elimina inmediatamente del almacenamiento en un bloque `finally`.

#### 2. Detección y Diagnóstico de Señales Nativas (SIGSEGV, SIGABRT, SIGKILL)
• **Diagnóstico descriptivo en terminal**: Si un subproceso de compilador (`sdcc`, `gpasm`, `gplink`, `makebin`, etc.) es terminado por una señal del sistema operativo, la terminal traduce e informa con exactitud el origen del fallo (ej: `SIGSEGV (acceso a memoria no válido)`, `SIGABRT (proceso abortado)`, `SIGKILL (proceso terminado por el sistema)`), facilitando el diagnóstico inmediato de errores nativos en vez de mostrar códigos numéricos genéricos.
• **Compilación libre sin límite de tiempo artificial**: Se garantiza la ejecución continua sin restricciones arbitrarias de tiempo, permitiendo compilar proyectos extensos y ejecutar simulaciones completas de hardware (`s51` / `ucsim`) sin cortes prematuros.

#### 3. Inglés como Idioma Base Predeterminado en Recursos
• **Internacionalización**: Se reorganizaron los recursos para que `res/values/strings.xml` contenga inglés como idioma base por defecto para usuarios internacionales, y `res/values-es/strings.xml` contenga la localización completa al español, con paridad del 100% en todas las cadenas.

---

## 🇺🇸 English

### 🚀 Main Features & Bug Fixes

#### 1. Fix for `TransactionTooLargeException` (Crashlytics #93e7d779)
• **Root cause resolved**: Disabled automatic View hierarchy serialization for the terminal view in the system Bundle (`android:saveEnabled="false"` in `activity_main.xml`), preventing 600+ KB compiler logs from overflowing the 1 MB Android Binder IPC transaction limit during rotation or backgrounding.
• **Efficient persistence bypassing Binder**: Implemented private disk-cached session storage (`terminal_cache.tmp`) during configuration changes (screen rotation and activity switches).
• **Strict session lifecycle**: On cold starts from the launcher, the terminal starts fresh with initial welcome messages. Upon rotation, logs are restored to memory and the temporary cache file is immediately deleted in a `finally` block.

#### 2. Native Signal Detection & Diagnostics (SIGSEGV, SIGABRT, SIGKILL)
• **Descriptive terminal diagnostics**: If a native toolchain process (`sdcc`, `gpasm`, `gplink`, `makebin`, etc.) is terminated by an OS signal, the terminal now translates and reports the exact failure cause (e.g., `SIGSEGV (invalid memory access)`, `SIGABRT (process aborted)`, `SIGKILL (process killed by OS)`), replacing cryptic exit status numbers.
• **Unconstrained compilation execution**: Compiler and simulator processes run without artificial watchdog timeouts, ensuring large projects and extensive hardware simulations (`s51` / `ucsim`) run to natural completion.

#### 3. English as Base Default Resource Language
• **Global localization**: Reorganized app resources so `res/values/strings.xml` provides English as the global fallback locale, while `res/values-es/strings.xml` provides complete Spanish translations with 100% key parity.

---

## 📦 Artefactos de la Versión / Release Artifacts

• **APK Release**: `C_PIC_Compiler_v1.4.1.apk`
• **AAB Release**: `C_PIC_Compiler_v1.4.1.aab`
• **Firma Oficial / Official Signature**: Keystore de producción (`firmacompilador.jks`, SHA-1: `D7:50:AD:E8:3D:D6:47:1A:E3:68:B6:DC:11:01:CB:07:AC:C9:A8:70`).
• **Nivel de API Android / Target API**: Target SDK 37 (Android 17 / Cinnamon Bun), Min SDK 23 (Android 6.0 / Marshmallow).
