# Notas de la Versión / Release Notes v1.4.12 (VersionCode 32) - C-PIC Compiler

Fecha de lanzamiento / Release Date: 18 de Octubre de 2026 / October 18, 2026

---

## 🇪🇸 Español

### 🚀 Novedades y Correcciones Principales

#### 1. Blindaje de `BillingManager` contra Crash en `ProxyBillingActivity`
• **Detección de entornos de prueba automatizada (`isRunningInTestLab`)**: En los emuladores `x86_64` del Informe Previo al Lanzamiento de Google Play Console / Firebase Test Lab (`Settings.System: firebase.test.lab = true`), Google Play Services no entrega un `PendingIntent` de compra válido, provocando `NullPointerException: PendingIntent.getIntentSender()` dentro de `ProxyBillingActivity.onCreate`. Ahora `BillingManager` detecta este entorno y omite la apertura de la actividad proxy de forma segura.
• **Validación de ciclo de vida y estado de conexión**: Se verifica que la `Activity` esté activa (`!isFinishing() && !isDestroyed()`) y que `billingClient.isReady()` sea verdadero antes de lanzar el flujo de compra, reconectando automáticamente si el servicio se desconectó.
• **Protección anti-doble-toque (`LAUNCH_DEBOUNCE_MS = 2000ms`) y `try-catch`**: Evita abrir dos instancias concurrentes de `ProxyBillingActivity` y captura cualquier excepción en tiempo de ejecución al invocar `launchBillingFlow`.

#### 2. Actualización de Dependencias y Herramientas de Compilación (`libs.versions.toml`)
• **Android Gradle Plugin (`agp`)**: `9.2.1` ➔ **`9.4.1`**
• **Firebase BoM (`firebaseBom`)**: `34.14.0` ➔ **`35.0.2`** (`firebase-analytics 24.0.0`, `firebase-crashlytics-ndk 21.0.0`)
• **Firebase Crashlytics (`firebaseCrashlytics`)**: `20.0.6` ➔ **`21.0.0`** (plugin `3.0.8`, `google-services 4.5.0`)
• **Google Play Services Ads (`playServicesAds`)**: `25.3.0` ➔ **`25.5.0`**
• **AndroidX**: `appcompat 1.8.0` y `constraintlayout 2.2.2`.
• **Play Automatic Protection (`minSdk 24`)**: Nivel mínimo de API actualizado a Android 7.0 (API 24) en línea con los requisitos de Google Play Services 2026 y la Protección Automática de Google Play.

---

## 🇺🇸 English

### 🚀 Main Features & Bug Fixes

#### 1. `BillingManager` Hardening Against `ProxyBillingActivity` Crash
• **Automated Test Lab detection (`isRunningInTestLab`)**: On Google Play Console Pre-Launch Report / Firebase Test Lab `x86_64` virtual devices (`Settings.System: firebase.test.lab = true`), Google Play Services does not return a valid purchase `PendingIntent`, causing `ProxyBillingActivity.onCreate` to throw `NullPointerException: PendingIntent.getIntentSender()`. `BillingManager` now detects Test Lab environments and safely skips launching the billing proxy activity.
• **Activity lifecycle & client readiness guards**: Verifies that the host `Activity` is active (`!isFinishing() && !isDestroyed()`) and `billingClient.isReady()` before launching the purchase flow, reconnecting automatically if needed.
• **Double-tap debounce (`LAUNCH_DEBOUNCE_MS = 2000ms`) & `try-catch`**: Prevents overlapping `ProxyBillingActivity` launches from rapid taps and catches runtime exceptions around `launchBillingFlow`.

#### 2. Dependency & Build Tool Upgrades (`libs.versions.toml`)
• **Android Gradle Plugin (`agp`)**: `9.2.1` ➔ **`9.4.1`**
• **Firebase BoM (`firebaseBom`)**: `34.14.0` ➔ **`35.0.2`** (`firebase-analytics 24.0.0`, `firebase-crashlytics-ndk 21.0.0`)
• **Firebase Crashlytics (`firebaseCrashlytics`)**: `20.0.6` ➔ **`21.0.0`** (plugin `3.0.8`, `google-services 4.5.0`)
• **Google Play Services Ads (`playServicesAds`)**: `25.3.0` ➔ **`25.5.0`**
• **AndroidX**: `appcompat 1.8.0` and `constraintlayout 2.2.2`.
• **Play Automatic Protection (`minSdk 24`)**: Updated minimum API level to Android 7.0 (API 24) in alignment with 2026 Google Play Services requirements and Google Play Automatic Protection.

---

## 📦 Artefactos de la Versión / Release Artifacts

• **Versión / Version**: v1.4.12 (VersionCode 32)
• **Nivel de API Android / Target API**: Target SDK 37, Min SDK 24.
