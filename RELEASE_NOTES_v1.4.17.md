# C PIC Compiler v1.4.17 (versionCode 37) — Corrección de PICsim, nombres de emulador y consentimiento

Fecha / Date: 10 de noviembre de 2026 / November 10, 2026

> **Publicado / Published:** compilado, firmado y verificado con el SDK de
> Android. Tests unitarios: 76 ejecutados, 0 fallos.

---

## 🇪🇸 Español

### 📌 Resumen
Esta versión corrige el falso error que aparecía al terminar una simulación
PIC correcta, muestra el nombre real del emulador en las herramientas y retrasa
el formulario de consentimiento UMP hasta que la app termina de cargar recursos.

### 🛠️ Cambios
• **PICsim ya no reporta un falso error:** su CLI devuelve `1` cuando la
  simulación termina bien y `0` cuando falla `pic_init()`. La app ahora traduce
  esos códigos con `PicsimSupport` en lugar de exigir `0`.
• **Lista real de procesadores PICsim:** se añadieron los 33 modelos del commit
  fijado (`3ee7918`). Si el PIC seleccionado no está soportado, la app lo avisa
  y no lanza una simulación falsa.
• **Nombre correcto del emulador:** el diálogo de herramientas muestra
  «Simular con PICsim» para PIC y «Simular con ucSim» para el resto. El botón se
  deshabilita cuando el dispositivo PIC no está soportado.
• **Consentimiento UMP después de la carga:** el formulario ya no se muestra
  encima del progressbar inicial; se solicita cuando los recursos terminaron de
  extraerse y el overlay de carga se ocultó.
• **Entorno PICsim homogéneo:** se configuran symlinks y variables de entorno
  como en los demás ejecutores.
• **Log más limpio:** se filtra el aviso irrelevante
  `/dev/tnt2: No such file or directory` que PICsim escribe al arrancar.
• **Códigos de señal:** `ProcessExitCodes.describeSignal` ya no interpreta el
  `255` de PICsim como una señal POSIX.

### ✅ Validación
• `PicsimSupportTest` + `PortRegistryTest` con JUnit 4.13.2: **23 tests, 0 fallos**.
• Verificación del CLI PICsim en host: éxito = `1`, HEX inválido = `0` con
  `Pic_init error`, procesador inválido = `255` con `Error: Invalid processor`.
• `versionCode 37` y `versionName 1.4.17`.

### 📦 Artefactos
- `C-PIC-Compiler-v1.4.17-release.apk` — 61.660.362 bytes
  - SHA-256: `0b120dcf45dab8f999b1e1ca386453be624ed13590c5a0d957ccbbc79efcd527`
- `C-PIC-Compiler-v1.4.17-release.aab` — 61.079.571 bytes
  - SHA-256: `c94cc4171ab7fe1146fb9cfb9cc153375a2624fe9567152c9412cf7e8a31a553`
- Firma: certificado `CN=Daniel Elias Diamon Vazquez`, APK con esquema V2.
- `versionCode 37`, `versionName 1.4.17`, `minSdk 24`, `targetSdk 37`.

---

## 🇺🇸 English

### 📌 Overview
This release fixes the false error shown after a successful PIC simulation,
displays the real emulator name in the tools dialog, and delays the UMP consent
form until the app has finished loading resources.

### 🛠️ Changes
• **PICsim no longer reports a false error:** its CLI returns `1` after a
  successful run and `0` when `pic_init()` fails. The app now translates those
  codes with `PicsimSupport` instead of requiring `0`.
• **Real PICsim processor list:** the 33 devices from the pinned commit
  (`3ee7918`) were added. Unsupported PICs are reported clearly and never run a
  fake simulation.
• **Correct emulator name:** the tools dialog shows “Simulate with PICsim” for
  PIC and “Simulate with ucSim” for other architectures. The button is disabled
  when the selected PIC is unsupported.
• **UMP consent after loading:** the form is no longer shown over the startup
  progress bar; it is requested after resources are extracted and the loading
  overlay is hidden.
• **Consistent PICsim environment:** symlinks and environment variables are
  configured like the other executors.
• **Cleaner log:** the irrelevant `/dev/tnt2: No such file or directory` message
  printed by PICsim at startup is filtered out.
• **Signal codes:** `ProcessExitCodes.describeSignal` no longer treats PICsim’s
  `255` as a POSIX signal.

### ✅ Validation
• `PicsimSupportTest` + `PortRegistryTest` with JUnit 4.13.2: **23 tests, 0 failures**.
• Host PICsim CLI verification: success = `1`, invalid HEX = `0` with
  `Pic_init error`, invalid processor = `255` with `Error: Invalid processor`.
• `versionCode 37` and `versionName 1.4.17`.

### 📦 Artifacts
- `C-PIC-Compiler-v1.4.17-release.apk` — 61,660,362 bytes
  - SHA-256: `0b120dcf45dab8f999b1e1ca386453be624ed13590c5a0d957ccbbc79efcd527`
- `C-PIC-Compiler-v1.4.17-release.aab` — 61,079,571 bytes
  - SHA-256: `c94cc4171ab7fe1146fb9cfb9cc153375a2624fe9567152c9412cf7e8a31a553`
- Signature: `CN=Daniel Elias Diamon Vazquez` certificate, APK uses V2 scheme.
- `versionCode 37`, `versionName 1.4.17`, `minSdk 24`, `targetSdk 37`.
