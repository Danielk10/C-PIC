# Notas de la Versión / Release Notes v1.4.14 (VersionCode 34) - C-PIC Compiler

Fecha de lanzamiento / Release Date: 2 de Noviembre de 2026 / November 2, 2026

---

## 🇪🇸 Español

### 🚀 Resumen
Esta versión corrige los tres fallos reportados en Crashlytics: el `RejectedExecutionException` de `loadDeviceList`, el ANR de `DestroyJavaVM` y el `NullPointerException` de accesibilidad de `ViewRootImpl`. También fija Play Billing en 8.3.0 y HSDP en 2.2.0.

### 🛠️ Correcciones Principales

#### 1. `RejectedExecutionException` en `MainActivity.loadDeviceList` (Crashlytics `704211d86c5a9f21320980f4cd267551`)
• **Causa raíz:** `initResources()` seguía ejecutándose en un hilo del pool y llamaba a `loadDeviceList()` después de `onDestroy()`, cuando el `ExecutorService` ya estaba en `shutdown`.
• **Corrección:** se añadió `executeAsync()`, que comprueba `isFinishing()`/`isDestroyed()` y captura `RejectedExecutionException`. Las tareas de UI usan `postToUi()` con la misma comprobación de ciclo de vida. Los hilos del pool ahora son daemon y se usa `shutdownNow()` al finalizar.

#### 2. ANR `art::ConditionVariable::WaitHoldingLocks` / `DestroyJavaVM` (Crashlytics `ad004d1ef57fa8db88a9373446c84b3c`)
• **Causa raíz:** `CPicApplication` absorbía excepciones conocidas de terceros (HSDP, Billing, WindowInsets) también en el hilo principal. Al morir el looper, `AndroidRuntime` terminaba en `DestroyJavaVM` esperando a los hilos no-daemon del executor.
• **Corrección:** se eliminó el `UncaughtExceptionHandler` que se tragaba excepciones; Crashlytics vuelve a reportar los fallos reales. Se fijaron **HSDP 2.2.0** y **Billing 8.3.0**, y los hilos de trabajo son daemon.

#### 3. `ViewRootImpl.fireAccessibilityFocusEventIfHasFocusedNode` — `NullPointerException` (Crashlytics `3514c195444a9d2721af13abc0135748`)
• **Causa raíz:** al reconstruir las pestañas se eliminaban vistas que podían conservar el foco de entrada o accesibilidad. En el siguiente focus gain, `ViewRootImpl` intentaba enviar el evento a una vista cuyo `ViewParent` ya era `null`.
• **Corrección:** se limpia el foco de entrada y accesibilidad antes de `removeAllViews()` de las pestañas y en `onStop()`/`onDestroy()`. Es una mitigación del fallo de framework; si reaparece en producción, Crashlytics reabrirá el issue.

#### 4. Dependencias de terceros
• **Play Billing 9.1.0 ➔ 8.3.0:** evita el `NoSuchMethodError` de `ActivityOptions.setPendingIntentBackgroundActivityStartMode` en compilaciones de Android 14 que no exponen el método.
• **HSDP 2.0.1 ➔ 2.2.0:** evita el `IllegalStateException: targetPackageName is null` de `HsdpShimActivity`.

### ✅ Validación
• **Tests:** 55 pruebas unitarias, 0 fallos, 0 errores, 0 omitidas.
• **Build release:** `:app:assembleRelease` y `:app:bundleRelease` correctos; APK y AAB firmados con la clave de producción (`firma_c_pic_compiler.jks`).
• **Emulador:** C-PIC no dispone de un emulador de hardware propio; la validación se realizó con la suite JUnit y la compilación release.

### 📦 Artefactos de la Versión / Release Artifacts
• **APK Release:** `C-PIC-Compiler-v1.4.14-release.apk`  
  **SHA-256:** `8b3aa64eae428f556b1895f329bfea1f7dba5f3f4803762fdff62141ffc9564c`
• **AAB Release (Google Play Bundle):** `C-PIC-Compiler-v1.4.14-release.aab`  
  **SHA-256:** `c64f00547eacc96b6f844aba6d694f7a0d6edb19111c364b10ed98386916302a`

---

## 🇺🇸 English

### 🚀 Overview
This release fixes the three Crashlytics issues: the `RejectedExecutionException` in `loadDeviceList`, the `DestroyJavaVM` ANR, and the `ViewRootImpl` accessibility `NullPointerException`. It also pins Play Billing to 8.3.0 and HSDP to 2.2.0.

### 🛠️ Key Fixes

#### 1. `RejectedExecutionException` in `MainActivity.loadDeviceList` (Crashlytics `704211d86c5a9f21320980f4cd267551`)
• **Root cause:** `initResources()` was still running on a pool thread and called `loadDeviceList()` after `onDestroy()`, when the `ExecutorService` was already shutting down.
• **Fix:** added `executeAsync()`, which checks `isFinishing()`/`isDestroyed()` and catches `RejectedExecutionException`. UI updates use `postToUi()` with the same lifecycle check. Pool threads are now daemon and `shutdownNow()` is used when finishing.

#### 2. ANR `art::ConditionVariable::WaitHoldingLocks` / `DestroyJavaVM` (Crashlytics `ad004d1ef57fa8db88a9373446c84b3c`)
• **Root cause:** `CPicApplication` swallowed known third-party exceptions (HSDP, Billing, WindowInsets) on the main thread as well. With the looper dead, `AndroidRuntime` ended in `DestroyJavaVM` waiting for the executor's non-daemon threads.
• **Fix:** removed the exception-swallowing `UncaughtExceptionHandler`; Crashlytics reports real failures again. Pinned **HSDP 2.2.0** and **Billing 8.3.0**, and worker threads are daemon.

#### 3. `ViewRootImpl.fireAccessibilityFocusEventIfHasFocusedNode` — `NullPointerException` (Crashlytics `3514c195444a9d2721af13abc0135748`)
• **Root cause:** rebuilding the tab strip removed views that could still hold input or accessibility focus. On the next focus gain, `ViewRootImpl` tried to send the event to a view whose `ViewParent` was already `null`.
• **Fix:** clears input and accessibility focus before the tab strip's `removeAllViews()` and in `onStop()`/`onDestroy()`. This mitigates a framework bug; if it recurs in production, Crashlytics will reopen the issue.

#### 4. Third-party dependencies
• **Play Billing 9.1.0 ➔ 8.3.0:** avoids the `NoSuchMethodError` from `ActivityOptions.setPendingIntentBackgroundActivityStartMode` on Android 14 builds where the method is absent.
• **HSDP 2.0.1 ➔ 2.2.0:** avoids the `IllegalStateException: targetPackageName is null` from `HsdpShimActivity`.

### ✅ Validation
• **Tests:** 55 unit tests, 0 failures, 0 errors, 0 skipped.
• **Release build:** `:app:assembleRelease` and `:app:bundleRelease` succeeded; APK and AAB signed with the production key (`firma_c_pic_compiler.jks`).
• **Emulator:** C-PIC has no dedicated hardware emulator; validation used the JUnit suite and the release build.

### 📦 Release Artifacts
• **APK Release:** `C-PIC-Compiler-v1.4.14-release.apk`  
  **SHA-256:** `8b3aa64eae428f556b1895f329bfea1f7dba5f3f4803762fdff62141ffc9564c`
• **AAB Release (Google Play Bundle):** `C-PIC-Compiler-v1.4.14-release.aab`  
  **SHA-256:** `c64f00547eacc96b6f844aba6d694f7a0d6edb19111c364b10ed98386916302a`

---

## 📋 Notas Cortas para Google Play Console / Short Play Store Release Notes

### 🇪🇸 Español (`es-419` / `es-ES`)
```text
• Corregido cierre por RejectedExecutionException al cargar la lista de dispositivos.
• Corregido ANR al cerrar la app por hilos no-daemon y manejo de excepciones.
• Mitigado NPE de accesibilidad al reconstruir las pestañas del editor.
• Actualizados Play Billing 8.3.0 y HSDP 2.2.0.
```

### 🇺🇸 English (`en-US`)
```text
• Fixed a RejectedExecutionException crash while loading the device list.
• Fixed an app-exit ANR caused by non-daemon threads and exception handling.
• Mitigated an accessibility NPE when rebuilding editor tabs.
• Updated Play Billing 8.3.0 and HSDP 2.2.0.
```

---

## 🔗 Enlaces / Links
• **Repositorio / Repository:** https://github.com/Danielk10/C-PIC
• **Lanzamiento / Release:** https://github.com/Danielk10/C-PIC/releases/tag/v1.4.14
