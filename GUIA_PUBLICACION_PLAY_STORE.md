# Guía de Publicación Automatizada en Google Play Store 🚀

Esta guía detalla los pasos para compilar, firmar y publicar automáticamente nuevas versiones de **C PIC Compiler** (`com.diamon.ptc`) en la Google Play Store mediante la API oficial de Google Play Developer.

---

## 🛠 Requisitos Previos

1. **Dependencias de Python**:
   ```bash
   pip install google-api-python-client google-auth-httplib2 google-auth-oauthlib
   ```

2. **Credenciales de Servicio (JSON)**:
   - Archivo de cuenta de servicio de Google Cloud Console con permisos de publicación en Google Play Console:
     `/ruta/a/tu/google-play-api.json`

3. **Clave de Firma (Keystore)**:
   - Archivo: `/ruta/a/tu/keystore.jks`
   - Configurado automáticamente vía `keystore.properties` (excluido en `.gitignore`).

---

## 📦 Paso 1: Compilación y Generación del Android App Bundle (.aab)

Ejecuta Gradle Wrapper para compilar la versión optimizada y firmada de producción:

```bash
./gradlew bundleRelease assembleRelease
```

Los artefactos firmados se generarán en:
- **AAB:** `/tmp/calculo/outputs/bundle/release/app-release.aab`
- **APK:** `/tmp/calculo/outputs/apk/release/app-release.apk`

---

## 🚀 Paso 2: Publicación con el Script Python

Ejecuta el script `upload_play_store.py` especificando el ID de paquete, la ruta al bundle `.aab`, el archivo de credenciales y las notas de versión estructuradas:

```bash
python3 upload_play_store.py \
  --package_name com.diamon.ptc \
  --aab_path /tmp/calculo/outputs/bundle/release/app-release.aab \
  --service_account_json /ruta/a/tu/google-play-api.json \
  --track production \
  --release_notes "- Compatibilidad actualizada con Android 17 (API 37).
- Optimización de binarios nativos ARM64 con alineación de páginas a 16 KB.
- Actualización de dependencias y mejoras generales de estabilidad." \
  --release_notes_en "- Updated compatibility with Android 17 (API 37).
- Native ARM64 binary optimization with 16 KB page alignment.
- Updated dependencies and general stability improvements."
```

---

## 📋 Parámetros del Script `upload_play_store.py`

| Parámetro | Obligatorio | Descripción | Ejemplo |
| :--- | :---: | :--- | :--- |
| `--package_name` | Sí | Nombre del paquete de la aplicación | `com.diamon.ptc` |
| `--aab_path` | Sí | Ruta al bundle compilado `.aab` | `/tmp/calculo/outputs/bundle/release/app-release.aab` |
| `--service_account_json` | Sí | Ruta a la clave JSON de la cuenta de servicio | `/ruta/a/tu/google-play-api.json` |
| `--track` | No | Canal de distribución (`production`, `beta`, `internal`) | `production` (por defecto) |
| `--release_notes` | No | Notas de versión en español (`es-419` y `es-ES`) | `"- Correcciones de estabilidad."` |
| `--release_notes_en` | No | Notas de versión en inglés (`en-US`) | `"- Stability fixes."` |

---

## 🧹 Paso 3: Limpieza posterior

Una vez concluida la publicación, puedes limpiar los archivos generados en `/tmp`:

```bash
rm -rf /tmp/calculo/outputs/
```
