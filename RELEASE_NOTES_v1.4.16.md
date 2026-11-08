# C PIC Compiler v1.4.16 (versionCode 36) — Corrección del ANR de resaltado / Syntax Highlighting ANR Fix

Fecha de lanzamiento / Release Date: 8 de noviembre de 2026 / November 8, 2026

---

## 🇪🇸 Español

### 📌 Resumen
Esta versión corrige el ANR que ocurría en dispositivos Xiaomi/POCO con MIUI al seleccionar texto en el editor. El resaltado de sintaxis creaba un `ForegroundColorSpan` por cada coincidencia de cada patrón sobre el documento completo en cada pulsación; en archivos grandes eso generaba miles de spans y MIUI se bloqueaba recorriéndolos al calcular el rectángulo de la selección (`FloatingActionModeHelper.onGetContentRect` → `Layout.getParagraphSpans` → `countSpans`).

### 🛠️ Cambios
• El resaltado ahora cubre solo la ventana visible del editor, con 24 líneas de margen y alineación a líneas completas.
• Presupuesto máximo de spans por tipo de token (600 en total), independiente del tamaño del archivo.
• Debounce de 120 ms para no recalcular en cada pulsación.
• Se refresca al hacer scroll, porque cambia la zona visible.
• Ya no se reemplaza todo el texto del editor: solo se eliminan y añaden los spans propios.
• Nueva clase pura `SyntaxHighlightPlanner` con tests de regresión para la ventana y el presupuesto de spans.

### ✅ Validación
• `:app:testDebugUnitTest`: 64 tests, 0 fallos, 0 errores (incluye 7 tests nuevos de `SyntaxHighlightPlanner`).
• Compilaciones debug y release (`:app:assembleDebug`, `:app:assembleRelease`) y AAB (`:app:bundleRelease`) correctas.
• APK y AAB firmados con la clave de producción (alias `compilador`); huella SHA-256 verificada.
• `versionCode 36` y `versionName 1.4.16`.

### 📦 Artefactos
• **APK Release:** `C-PIC-Compiler-v1.4.16-release.apk`  
  **SHA-256:** `08001ce4b875c01174b9024bfa5d29084e4695dd96d1e9415a65a19f6be82515`
• **AAB Release (Google Play Bundle):** `C-PIC-Compiler-v1.4.16-release.aab`  
  **SHA-256:** `f947b5bb5a39f6c8ceb0c7e1aa4263ff309d3d561b37e28f4ce54bc2576a0eb4`
• **APK Debug:** `C-PIC-Compiler-v1.4.16-debug.apk`  
  **SHA-256:** `07fd829a3b6b5903bead3701d99a5ac936a8d567332da8cf31b7bf3a486202bf`

---

## 🇺🇸 English

### 📌 Overview
This release fixes the ANR that occurred on Xiaomi/POCO devices with MIUI when selecting text in the editor. Syntax highlighting created one `ForegroundColorSpan` per match of every pattern over the whole document on each keystroke; on large files this produced thousands of spans, and MIUI blocked while walking them to compute the selection rectangle (`FloatingActionModeHelper.onGetContentRect` → `Layout.getParagraphSpans` → `countSpans`).

### 🛠️ Changes
• Highlighting now covers only the visible editor window, with a 24-line margin and alignment to whole lines.
• Maximum span budget per token type (600 total), independent of file size.
• 120 ms debounce to avoid recomputing on every keystroke.
• Refreshes on scroll because the visible area changes.
• The editor text is no longer replaced wholesale: only the app's own spans are removed and added.
• New pure `SyntaxHighlightPlanner` class with regression tests for the window and span budget.

### ✅ Validation
• `:app:testDebugUnitTest`: 64 tests, 0 failures, 0 errors (including 7 new `SyntaxHighlightPlanner` tests).
• Debug and release builds (`:app:assembleDebug`, `:app:assembleRelease`) and AAB (`:app:bundleRelease`) completed successfully.
• APK and AAB signed with the production key (alias `compilador`); SHA-256 fingerprint verified.
• `versionCode 36` and `versionName 1.4.16`.

### 📦 Artifacts
• **APK Release:** `C-PIC-Compiler-v1.4.16-release.apk`  
  **SHA-256:** `08001ce4b875c01174b9024bfa5d29084e4695dd96d1e9415a65a19f6be82515`
• **AAB Release (Google Play Bundle):** `C-PIC-Compiler-v1.4.16-release.aab`  
  **SHA-256:** `f947b5bb5a39f6c8ceb0c7e1aa4263ff309d3d561b37e28f4ce54bc2576a0eb4`
• **APK Debug:** `C-PIC-Compiler-v1.4.16-debug.apk`  
  **SHA-256:** `07fd829a3b6b5903bead3701d99a5ac936a8d567332da8cf31b7bf3a486202bf`

---

## 🔗 Enlaces / Links
• **Repositorio / Repository:** https://github.com/Danielk10/C-PIC
• **Release:** https://github.com/Danielk10/C-PIC/releases/tag/v1.4.16
