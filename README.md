# C PIC Compiler - Compilador C/ASM para Microcontroladores PIC en Android

![License](https://img.shields.io/badge/license-GPL--3.0-blue.svg)
![Platform](https://img.shields.io/badge/platform-Android-green.svg)
![API Level](https://img.shields.io/badge/API-23%20to%2037-brightgreen.svg)
![Android](https://img.shields.io/badge/Android-16%20(API%2037)-blue.svg)
![Architecture](https://img.shields.io/badge/arch-ARM64-orange.svg)
![Gradle](https://img.shields.io/badge/Gradle-9.6.0-02303A.svg)
![AGP](https://img.shields.io/badge/AGP-9.2.1-34A853.svg)
![NDK](https://img.shields.io/badge/NDK-30.0.14904198-informational.svg)

## Captura de Pantalla

![C-PIC Compiler App](screenshot_app.jpg)

## Descripción

**C PIC Compiler** es una aplicación Android nativa profesional de alto rendimiento diseñada para compilar código en lenguaje C y ensamblador (ASM) directamente en tu dispositivo móvil para microcontroladores PIC (Microchip). 

Esta herramienta permite a desarrolladores de sistemas embebidos, ingenieros y estudiantes compilar, enlazar, depurar, simular y exportar binarios (`.hex`, `.bin`, `.map`) de manera autónoma sin necesidad de conexión a internet ni dependencia de una computadora.

---

## ✨ Características Principales

- ✅ **Compilación 100% Offline**: Compilación autónoma y local directamente en el dispositivo Android.
- ✅ **Motores Oficiales Integrados**:
  - **SDCC 4.5.0** (Small Device C Compiler).
  - **GPUTILS 1.5.2** (GNU PIC Utilities: `gpasm`, `gplink`, `gplib`, `gpdasm`, etc.).
  - **Suite UCSIM / S51**: Simuladores y emuladores de microcontroladores integrados.
- ✅ **Soporte Extenso de Familias PIC**: Compatible con Microchip PIC12, PIC14, PIC16, PIC18 y arquitecturas cruzadas soportadas por SDCC.
- ✅ **Alineación de Memoria a 16 KB**: Binarios compilados y enlazados estrictamente con `-Wl,-z,max-page-size=16384` (`Align 0x4000`), garantizando compatibilidad total con **Android 15** y **Android 16**.
- ✅ **Cumplimiento Estricto de Google Play**: Todos los ejecutables y bibliotecas nativas se distribuyen bajo el estándar `lib<nombre>.so` en `jniLibs/arm64-v8a/` y se reconstruyen de forma transparente en tiempo de ejecución.
- ✅ **Optimización de Assets**: Depuración de archivos redundantes y fuentes innecesarias en runtime, reduciendo más de 150 MB del paquete base.
- ✅ **Interfaz de Usuario Moderna**: Desarrollada con Material Design, visor de registros en tiempo real y selector interactivo de microcontroladores.

---

## 📱 Especificaciones Técnicas y Versiones

| Componente | Versión / Valor |
|---|---|
| **Android Compile SDK** | `android-37` (Android 16) |
| **Android Target SDK** | `37` (Android 16) |
| **Android Min SDK** | `23` (Android 6.0 Marshmallow) |
| **Android Build Tools** | `37.0.0` |
| **Gradle** | `9.6.0` |
| **Android Gradle Plugin (AGP)** | `9.2.1` |
| **Android NDK** | `30.0.14904198` (`rc1`) |
| **CMake** | `4.1.2` |
| **SDCC (Small Device C Compiler)** | `4.5.0` |
| **GPUTILS (GNU PIC Utilities)** | `1.5.2` |
| **Arquitectura de Ejecución** | ARM64 (`arm64-v8a` de 64 bits) |
| **Alineación ELF** | 16 KB (`max-page-size=16384`) |

---

## 🚀 Entorno de Compilación y Uso

### 1. Clonar el Repositorio
```bash
git clone https://github.com/Danielk10/C-PIC.git
cd C-PIC
```

### 2. Configurar el Entorno del SDK y NDK
El script [`setup-sdk.sh`](setup-sdk.sh) instala de manera desatendida las plataformas, build-tools, CMake y NDK requeridos en `/tmp/android-sdk`:

```bash
bash setup-sdk.sh
```

### 3. Compilación de Artefactos

Para mantener limpio el árbol de trabajo, los artefactos de compilación se generan en el directorio temporal `/tmp/calculo`:

```bash
# Compilar APK de depuración (Debug)
./gradlew assembleDebug

# Compilar APK firmado de producción (Release)
./gradlew assembleRelease

# Compilar Android App Bundle (.aab) firmado para Google Play Store
./gradlew bundleRelease
```

**Rutas de salida generadas:**
- **APK Debug:** `/tmp/calculo/outputs/apk/debug/app-debug.apk`
- **APK Release:** `/tmp/calculo/outputs/apk/release/app-release.apk`
- **AAB Release:** `/tmp/calculo/outputs/bundle/release/app-release.aab`

---

## 📂 Estructura del Repositorio

```
C-PIC/
├── app/
│   ├── build.gradle                               # Configuración de compilación del módulo
│   └── src/main/
│       ├── AndroidManifest.xml                    # Manifiesto de la aplicación Android
│       ├── assets/data/data/com.diamon.ptc/files/ # Headers, scripts LKR y librerías precompiladas
│       │   └── usr/share/
│       │       ├── gputils/                       # Headers (.inc) y scripts (.lkr) de PIC
│       │       └── sdcc/                          # Includes C y librerías compiladas (.lib)
│       ├── cpp/                                   # Soporte nativo C/C++ (CMake/NDK)
│       ├── java/com/diamon/ptc/                   # Código fuente Java
│       │   ├── MainActivity.java                  # Controlador principal de la UI
│       │   ├── SdccExecutor.java                  # Ejecutor de SDCC y gestión de symlinks
│       │   ├── GpUtilsExecutor.java               # Ejecutor de herramientas GPUTILS
│       │   ├── AssetExtractor.java                # Extractor eficiente de recursos
│       │   ├── IntelHexParser.java                # Analizador de formatos HEX
│       │   └── BillingManager.java                # Gestión de compras in-app
│       ├── jniLibs/arm64-v8a/                     # 72 binarios nativos ARM64 (lib*.so)
│       └── res/                                   # Layouts, recursos gráficos y cadenas
├── fake_root/                                     # Estructura base inmutable de referencia
├── libs/                                          # Librerías dinámicas compartidas de soporte
├── build_sdcc_custom.sh                           # Script de construcción personalizada de SDCC
├── build_gputils_custom.sh                        # Script de construcción personalizada de GPUTILS
├── setup-sdk.sh                                   # Script instalador del SDK 37 y NDK 30
├── upload_play_store.py                           # Script de subida automática a Google Play
├── GEMINI.md                                      # Especificación de arquitectura y compilación
├── GUIA_PUBLICACION_PLAY_STORE.md                 # Guía de publicación en Google Play
├── NOMBRES_BINARIOS_VS_ANTIGUOS.md                # Correspondencia de binarios lib*.so vs originales
├── REPORTE_LIMPIEZA_ASSETS.md                     # Auditoría de limpieza y ahorro en assets
├── REPORTE_ANALISIS_DEPENDENCIAS.md               # Análisis de dependencias DT_NEEDED y 16KB
├── REPORTE_DEPENDENCIAS_ORIGINALES.md             # Inventario de dependencias nativas upstream
├── RELEASE_NOTES_v1.2.5.md                        # Notas de versión del lanzamiento v1.2.5
└── README.md                                      # Este documento
```

---

## 📚 Documentación Técnica Adicional

Para más detalles técnicos, consulta los documentos especializados en la raíz del proyecto:

1. **[GEMINI.md](GEMINI.md)**: Arquitectura del proyecto, configuración de variables de entorno y firma.
2. **[NOMBRES_BINARIOS_VS_ANTIGUOS.md](NOMBRES_BINARIOS_VS_ANTIGUOS.md)**: Mapeo detallado de los 60 ejecutables y 12 librerías nativas adaptadas a Google Play.
3. **[REPORTE_LIMPIEZA_ASSETS.md](REPORTE_LIMPIEZA_ASSETS.md)**: Detalle del ahorro de espacio de más de 150 MB al depurar fuentes y binarios redundantes.
4. **[REPORTE_ANALISIS_DEPENDENCIAS.md](REPORTE_ANALISIS_DEPENDENCIAS.md)**: Análisis de dependencias `DT_NEEDED` y alineación estricta de páginas a 16 KB.
5. **[REPORTE_DEPENDENCIAS_ORIGINALES.md](REPORTE_DEPENDENCIAS_ORIGINALES.md)**: Registro de referencia con los nombres y dependencias upstream sin alterar.
6. **[GUIA_PUBLICACION_PLAY_STORE.md](GUIA_PUBLICACION_PLAY_STORE.md)**: Procedimiento paso a paso para el despliegue automático a Google Play Console.

---

## 📄 Licencia

Este proyecto está distribuido bajo la **Licencia Pública General de GNU v3.0 (GPL-3.0)**. Consulta el archivo [`LICENSE`](LICENSE) para conocer todos los términos y condiciones.

---

## 👤 Autor

- **Desarrollador**: Daniel Diamon ([@Danielk10](https://github.com/Danielk10))
- **Repositorio Oficial**: [https://github.com/Danielk10/C-PIC](https://github.com/Danielk10/C-PIC)
- **Lanzamientos Oficiales**: [GitHub Releases](https://github.com/Danielk10/C-PIC/releases)
