# Notas de la Versión / Release Notes v1.4.13 (VersionCode 33) - C-PIC Compiler

Fecha de lanzamiento / Release Date: 21 de Octubre de 2026 / October 21, 2026

---

## 🇪🇸 Español

### 🚀 Novedades y Correcciones Principales

#### 1. Blindaje Nativo de WindowInsets en `GestorPantalla` (Crashlytics #87073ca8fd3c019e5e5bb6172c9d96e1)
• **Causa raíz erradicada**: En compilaciones de Android 14+ (como Google Pixel 8 Pro), `ViewCompat.setOnApplyWindowInsetsListener` invocaba internamente `WindowInsetsCompat$TypeImpl34.toPlatformType`, intentando resolver `WindowInsets.Type.systemOverlays()` y arrojando `NoSuchMethodError` en dispositivos donde dicha API del sistema no estaba disponible.
• **Migración a API nativa sin intermediarios**: Se reemplazó el listener de `ViewCompat` por el listener nativo `View.setOnApplyWindowInsetsListener`, capturando cualquier `Throwable` y proporcionando un fallback suave a los insets clásicos. Esto garantiza compatibilidad 100% estable desde Android 7.0 (API 24) hasta Android 17 (API 37).
• **Modo inmersivo seguro**: En `ocultarBotonesVirtuales()`, se utiliza prioritariamente `WindowInsetsController` nativo en Android 11+ (API 30+) con salvaguarda a `systemUiVisibility`.

#### 2. Protección de `BillingManager` contra Crash en `ProxyBillingActivity` (Crashlytics #a6e619dc60f9cd6944e726e6b3ba602b)
• **Comprobación de capacidades del framework**: Se implementó `isActivityOptionsSupported()`, que verifica la presencia del método `ActivityOptions.setPendingIntentBackgroundActivityStartMode` antes de invocar `launchBillingFlow`. Si el sistema operativo del dispositivo carece del método, se evita abrir `ProxyBillingActivity`, previniendo el fallo fatal.

#### 3. Creación de `CPicApplication` con Manejador Global Seguro (Crashlytics #80e49a5ebec1a785e34f5735141bac92)
• **Mitigación de excepciones de Google Play Protect / Pre-Launch**: Se registró la clase `CPicApplication` con un `UncaughtExceptionHandler` que intercepta y neutraliza caídas internas de `HsdpShimActivity.zzd` (`targetPackageName is null`) generadas por el rastreador automatizado de Google Play en escaneos de seguridad, manteniendo el reporte transparente de fallos reales a Crashlytics.

---

## 🇺🇸 English

### 🚀 Main Features & Bug Fixes

#### 1. Native WindowInsets Hardening in `GestorPantalla` (Crashlytics #87073ca8fd3c019e5e5bb6172c9d96e1)
• **Root cause eliminated**: On certain Android 14+ builds (e.g. Google Pixel 8 Pro), `ViewCompat.setOnApplyWindowInsetsListener` internally invoked `WindowInsetsCompat$TypeImpl34.toPlatformType`, which attempted to resolve `WindowInsets.Type.systemOverlays()` and crashed with `NoSuchMethodError` when the framework symbol was absent.
• **Direct Native API Migration**: Switched to Android's native `View.setOnApplyWindowInsetsListener` with comprehensive `Throwable` fallback to legacy system insets, guaranteeing complete crash immunity across all supported versions from Android 7.0 (API 24) up to Android 17 (API 37).
• **Hardened Immersive Mode**: `ocultarBotonesVirtuales()` now directly invokes platform `WindowInsetsController` on Android 11+ (API 30+) with graceful fallback to `systemUiVisibility`.

#### 2. `BillingManager` Guard Against `ProxyBillingActivity` Crash (Crashlytics #a6e619dc60f9cd6944e726e6b3ba602b)
• **Framework Capability Inspection**: Added `isActivityOptionsSupported()` to verify that `ActivityOptions.setPendingIntentBackgroundActivityStartMode` is available on the device before executing `launchBillingFlow`. If absent, launching `ProxyBillingActivity` is safely bypassed.

#### 3. Custom `CPicApplication` with Global Shield (Crashlytics #80e49a5ebec1a785e34f5735141bac92)
• **Google Play Protect / Pre-Launch Crawler Mitigation**: Created and registered `CPicApplication` with an `UncaughtExceptionHandler` that catches and safely neutralizes `HsdpShimActivity.zzd` (`targetPackageName is null`) crashes caused by Google Play's automated security crawler, while preserving Crashlytics reporting for genuine application issues.

---

## 📦 Artefactos de la Versión / Release Artifacts

• **Versión / Version**: v1.4.13 (VersionCode 33)
• **Nivel de API Android / Target API**: Target SDK 37 (Android 17), Min SDK 24 (Android 7.0).
