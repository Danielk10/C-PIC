# C PIC Compiler v1.4.21 (versionCode 41) — Banner adaptable sin franjas

Fecha / Date: 22 de noviembre de 2026 / November 22, 2026

---

## 🇪🇸 Español

### 📌 Resumen
Se corrige el banner inferior de AdMob para que ocupe todo el ancho de la
pantalla, igual que en PIC K150 Programming, Comunicador OTG, EEPROM Flasher y
Flash SPI Tool. Desaparecen el margen lateral y las franjas negras que se veían
alrededor del anuncio.

### 🛠️ Cambios
• **Banner adaptable real:** el `AdView` se crea en código con
  `AdSize.getCurrentOrientationAnchoredAdaptiveBannerAdSize()` usando el ancho
  real de la ventana en la orientación actual.
• **Contenedor limpio:** se elimina el `app:adSize="BANNER"` fijo (320×50) del
  XML, junto con el fondo y la altura mínima del contenedor, que provocaban las
  franjas negras a los lados.
• **Mismo patrón que las demás apps:** contenedor `FrameLayout` vacío que solo
  se muestra cuando AdMob confirma la carga del anuncio.
• **Recalculo al recrear la actividad:** si cambia la orientación o el sistema
  recrea la pantalla, el banner vuelve a calcular su ancho.
• **Actualización de versión:** avance a `versionCode 41` y `versionName 1.4.21`.

### 🧩 Unidades AdMob usadas
| Bloque | Formato | ID |
|---|---|---|
| Banner | Adaptable | `ca-app-pub-5141499161332805/1220566600` |
| visor HEX | INTERSTITIAL | `ca-app-pub-5141499161332805/8342402367` |
| NativoC | NATIVE | `ca-app-pub-5141499161332805/2593369042` |

---

## 🇺🇸 English

### 📌 Overview
The bottom AdMob banner now spans the full screen width, matching PIC K150
Programming, Comunicador OTG, EEPROM Flasher and Flash SPI Tool. The side
margin and black stripes around the ad are gone.

### 🛠️ Changes
• **True adaptive banner:** the `AdView` is created in code with
  `AdSize.getCurrentOrientationAnchoredAdaptiveBannerAdSize()` using the real
  window width for the current orientation.
• **Clean container:** the fixed `app:adSize="BANNER"` (320×50) XML attribute,
  the container background and the minimum height that caused the black side
  stripes were removed.
• **Same pattern as the other apps:** an empty `FrameLayout` container that is
  only shown after AdMob confirms the ad load.
• **Recalculated on recreation:** the banner recalculates its width when the
  orientation changes or the system recreates the screen.
• **Version update:** bumped to `versionCode 41` and `versionName 1.4.21`.

### 🧩 AdMob units used
| Block | Format | ID |
|---|---|---|
| Banner | Adaptive | `ca-app-pub-5141499161332805/1220566600` |
| HEX viewer | INTERSTITIAL | `ca-app-pub-5141499161332805/8342402367` |
| NativoC | NATIVE | `ca-app-pub-5141499161332805/2593369042` |
