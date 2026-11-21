# C PIC Compiler v1.4.20 (versionCode 40) — Anuncio nativo y banner unificado

Fecha / Date: 21 de noviembre de 2026 / November 21, 2026

---

## 🇪🇸 Español

### 📌 Resumen
Esta versión integra el anuncio nativo de AdMob **NativoC** en la pantalla
principal, justo antes del campo de nombre del proyecto, y unifica el banner
inferior con el mismo estilo de contenedor adaptativo que usan las demás apps
(OTG Flash EEPROM, EEPROM Flasher y Lector de Memorias).

### 🛠️ Cambios
• **Anuncio nativo `NativoC`:** tarjeta con icono, titular, descripción,
anunciante y botón de acción, ubicada antes de la caja del nombre del proyecto.
• **Banner con contenedor:** el `AdView` vive dentro de `bannerContainer`, con
fondo y altura mínima iguales al resto de las apps; solo se muestra cuando
AdMob confirma la carga.
• **Respeto de compras y consentimiento:** el nativo y el banner se ocultan si
el usuario compró «Quitar anuncios» o no otorgó consentimiento UMP.
• **Actualización de versión:** avance a `versionCode 40` y `versionName 1.4.20`.

### 🧩 Unidades AdMob usadas
| Bloque | Formato | ID |
|---|---|---|
| Banner | BANNER | `ca-app-pub-5141499161332805/1220566600` |
| visor HEX | INTERSTITIAL | `ca-app-pub-5141499161332805/8342402367` |
| NativoC | NATIVE | `ca-app-pub-5141499161332805/2593369042` |

---

## 🇺🇸 English

### 📌 Overview
This release integrates the AdMob native ad **NativoC** on the main screen,
right before the project name field, and unifies the bottom banner with the
same adaptive container style used by the other apps (OTG Flash EEPROM, EEPROM
Flasher and Lector de Memorias).

### 🛠️ Changes
• **`NativoC` native ad:** card with icon, headline, body, advertiser and call
to action, placed before the project name box.
• **Banner with container:** the `AdView` lives inside `bannerContainer`, with
the same background and minimum height as the other apps; it is only shown
after AdMob confirms the load.
• **Purchases and consent respected:** native and banner ads are hidden when
the user bought "Remove ads" or did not grant UMP consent.
• **Version Update:** bumped to `versionCode 40` and `versionName 1.4.20`.

### 🧩 AdMob units used
| Block | Format | ID |
|---|---|---|
| Banner | BANNER | `ca-app-pub-5141499161332805/1220566600` |
| HEX viewer | INTERSTITIAL | `ca-app-pub-5141499161332805/8342402367` |
| NativoC | NATIVE | `ca-app-pub-5141499161332805/2593369042` |
