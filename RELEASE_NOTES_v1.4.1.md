# Notas de la Versión v1.4.1 (VersionCode 21) - C-PIC Compiler

Fecha de lanzamiento: 20 de Septiembre de 2026

## 🚀 Novedades y Correcciones Principales

### 1. Corrección de `TransactionTooLargeException` (Crashlytics #93e7d779)
• **Causa raíz eliminada**: Se deshabilitó la serialización automática de la vista de terminal en el Bundle del sistema (`android:saveEnabled="false"` en `activity_main.xml`), impidiendo que más de 600 KB de logs de compilación intenten viajar por Binder IPC y excedan el límite de 1 MB de Android.
• **Persistencia eficiente sin sobrecargar Binder**: Se implementó almacenamiento en caché temporal privado en disco (`terminal_cache.tmp`) durante cambios de configuración (rotación de pantalla y cambio de actividad).
• **Limpieza estricta de sesión**: Al iniciar la app desde el lanzador (cold start), la terminal arranca completamente limpia con los mensajes iniciales. Al rotar, los logs se restauran en memoria y el archivo temporal se elimina inmediatamente del almacenamiento en un bloque `finally`.

### 2. Detección y Blindaje contra Señales Nativas (SIGSEGV, SIGABRT, SIGKILL)
• **Diagnóstico descriptivo en terminal**: Si un subproceso de compilador (`sdcc`, `gpasm`, `gplink`, `makebin`, etc.) es terminado por una señal del sistema, la terminal ahora traduce e informa con exactitud el origen del fallo (ej: `SIGSEGV (acceso a memoria no válido)`, `SIGABRT (proceso abortado)`, `SIGKILL (proceso terminado por el sistema)`).
• **Protección contra procesos congelados (Watchdog Timeout)**: Todos los ejecutores nativos (`SdccExecutor` y `GpUtilsExecutor`) ahora imponen un timeout estricto de 120 segundos mediante `process.waitFor(120, TimeUnit.SECONDS)`. Si una tarea entra en bucle infinito, el subproceso es destruido forzosamente (`destroyForcibly()`) evitando que la aplicación se congele.

---

## 📦 Artefactos de la Versión

• **APK Release**: `C_PIC_Compiler_v1.4.1.apk`
• **AAB Release**: `C_PIC_Compiler_v1.4.1.aab`
• **Firma Oficial**: Keystore de producción (`firmacompilador.jks`, SHA-1: `D7:50:AD:E8:3D:D6:47:1A:E3:68:B6:DC:11:01:CB:07:AC:C9:A8:70`).
• **Nivel de API Android**: Target SDK 37 (Android 17 / Cinnamon Bun), Min SDK 23 (Android 6.0 / Marshmallow).
