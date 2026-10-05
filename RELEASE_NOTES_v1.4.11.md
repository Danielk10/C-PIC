# Notas de la Versión / Release Notes v1.4.11 (VersionCode 31) - C-PIC Compiler

Fecha de lanzamiento / Release Date: 5 de Octubre de 2026 / October 5, 2026

---

## 🇪🇸 Español

### 🚀 Novedades y Correcciones Principales

#### 1. Corrección Crítica en `GestorPantalla` (Crashlytics #a5e646968e0f1c4dbacf2d2a5bbb3468)
• **Causa raíz eliminada**: En dispositivos con Android 14+ (como Google Pixel 8 Pro), invocar `WindowInsetsCompat.Type.systemBars()` llamaba internamente al método del framework `WindowInsets.Type.systemOverlays()`, lanzando `NoSuchMethodError` en compilaciones del sistema donde este método no está presente.
• **Protección robusta con fallback retrocompatible**: Se implementó `obtenerInsetsSeguros(...)` que captura cualquier `Throwable` del framework y recurre a los insets tradicionales del sistema (`getSystemWindowInsetBottom()`, etc.) o `Insets.NONE`, garantizando inmunidad total contra caídas en cualquier versión de Android.

#### 2. Actualización y Alineación de `androidx.activity` (Crashlytics #d0a67347f3284ffecee82b617e7a9833)
• **Compatibilidad con ComponentDialog**: Se declaró explícitamente la dependencia `androidx.activity:activity:1.13.0` en `gradle/libs.versions.toml` y `app/build.gradle` para resolver incompatibilidades de desugaring con `ActivityOptions.setPendingIntentBackgroundActivityStartMode()` en diálogos del sistema.

---

## 🇺🇸 English

### 🚀 Main Features & Bug Fixes

#### 1. Critical Crash Fix in `GestorPantalla` (Crashlytics #a5e646968e0f1c4dbacf2d2a5bbb3468)
• **Root cause resolved**: On Android 14+ devices (such as Google Pixel 8 Pro), calling `WindowInsetsCompat.Type.systemBars()` internally invoked the platform method `WindowInsets.Type.systemOverlays()`, throwing `NoSuchMethodError` on firmware builds where this method is missing.
• **Robust fallback protection**: Implemented `obtenerInsetsSeguros(...)` which catches any framework `Throwable` and gracefully falls back to legacy system window insets (`getSystemWindowInsetBottom()`, etc.) or `Insets.NONE`, ensuring complete crash immunity across all Android versions.

#### 2. Dependency Alignment for `androidx.activity` (Crashlytics #d0a67347f3284ffecee82b617e7a9833)
• **ComponentDialog compatibility**: Explicitly declared `androidx.activity:activity:1.13.0` in `gradle/libs.versions.toml` and `app/build.gradle` to eliminate desugaring compatibility issues with `ActivityOptions.setPendingIntentBackgroundActivityStartMode()` in system dialogs.

---

## 📦 Artefactos de la Versión / Release Artifacts

• **Versión / Version**: v1.4.11 (VersionCode 31)
• **Nivel de API Android / Target API**: Target SDK 37, Min SDK 23.
