# C PIC Compiler - Compilador Multi-Arquitectura C/ASM en Android (SDCC & GPUTILS)

![License](https://img.shields.io/badge/license-GPL--3.0-blue.svg)
![Platform](https://img.shields.io/badge/platform-Android-green.svg)
![API Level](https://img.shields.io/badge/API-23%20to%2037-brightgreen.svg)
![Android](https://img.shields.io/badge/Android-17%20(API%2037)-blue.svg)
![Architecture](https://img.shields.io/badge/arch-ARM64-orange.svg)
![Gradle](https://img.shields.io/badge/Gradle-9.6.0-02303A.svg)
![AGP](https://img.shields.io/badge/AGP-9.2.1-34A853.svg)
![NDK](https://img.shields.io/badge/NDK-30.0.14904198-informational.svg)
![SDCC](https://img.shields.io/badge/SDCC-4.5.0-red.svg)
![GPUTILS](https://img.shields.io/badge/GPUTILS-1.5.2-purple.svg)

## Captura de Pantalla

![C-PIC Compiler App](screenshot_app.jpg)

## Descripción

**C PIC Compiler** es una suite de desarrollo móvil nativa profesional de alto rendimiento diseñada para escribir, editar, compilar, depurar y simular código en **lenguaje C** y **ensamblador (ASM)** directamente desde dispositivos Android para **24 arquitecturas de microcontroladores**.

Impulsada por **SDCC 4.5.0** (Small Device C Compiler), **GPUTILS 1.5.2** (GNU PIC Utilities) y la suite de simuladores **ucSim**, esta herramienta permite a ingenieros de sistemas embebidos, estudiantes y makers generar archivos binarios (`.hex`, `.ihx`, `.bin`, `.map`, `.lst`, `.o`, `.rel`) de manera 100% autónoma y sin conexión a internet.

---

## ✨ Características Principales

- ✅ **Compilación 100% Offline**: Compilación y ensamblado autónomo local en el propio dispositivo Android.
- ✅ **Soporte Multi-Puerto SDCC (24 Arquitecturas Soportadas)**:
  - **PIC (Microchip)**: PIC14 (PIC10/12/16) y PIC16 (PIC18) con modo dual **C (SDCC)** y **ASM nativo (GPUTILS `gpasm`/`gplink`)**.
  - **MCS-51 (Intel 8051)**: Incluye 81 cabeceras de microcontroladores (`8052`, `AT89C51`, `STC`, etc.).
  - **DS390 / DS400 (Dallas Semiconductor)**: Microcontroladores de 24 bits.
  - **Familia Z80**: Z80, Z180, Z80N (ZX Spectrum Next), eZ80 (modo Z80), R800 (MSX).
  - **Rabbit**: R2K (Rabbit 2000), R2KA (Rabbit 2000A), R3KA (Rabbit 3000A).
  - **SM83 (Sharp LR35902 / Game Boy)**: Arquitectura de consola portátil con registros de hardware integrados.
  - **TLCS-90 (Toshiba)**: Microcontroladores Toshiba TLCS-90.
  - **STM8 (STMicroelectronics)**: Microcontroladores ST de 8 bits.
  - **HC08 / S08 (Freescale/NXP)**: Familias MC68HC08 y HCS08 con cabeceras de registro `.h`.
  - **PDK (Padauk)**: PDK13 (13 bits), PDK14 (14 bits), PDK15 (15 bits).
  - **MOS 6502 / 65C02**: Microprocesadores clásicos de 8 bits y WDC 65C02.
  - **Fairchild F8**: Microcontrolador F8.
- ✅ **Terminal Nativa de Registros y Streaming**:
  - Salida de comandos en tiempo real estilo terminal sin enlaces rotos ni bloqueos.
  - Auto-desplazamiento inteligente (`LogScrollView`) que respeta la navegación del usuario.
  - Botón de limpieza en la cabecera de la terminal y soporte para copiar registros con pulsación prolongada.
- ✅ **Editor de Código Multi-Pestaña y Plantillas Dinámicas**:
  - Resaltado de sintaxis en tiempo real para C y ASM.
  - Carga automática de plantillas funcionales validadas para cada arquitectura al cambiar de familia.
  - Soporte de múltiples pestañas y proyectos independientes.
- ✅ **Alineación ELF a 16 KB (`max-page-size=16384`)**:
  - Todos los 72 binarios y librerías dinámicas están alineados a 16 KB, garantizando compatibilidad total con **Android 15, Android 16 y Android 17**.
- ✅ **Cumplimiento Estricto de Google Play**:
  - Ejecutables y librerías empaquetados bajo el estándar `lib<nombre>.so` en `jniLibs/arm64-v8a/` y reconstruidos transparentemente en tiempo de ejecución.
- ✅ **Internacionalización Completa**: Interfaz y mensajes completamente localizados en español e inglés sin cadenas hardcodeadas.

---

## 🎯 Matriz de Puertos y Compatibilidad (SDCC 4.5.0)

| Familia de Puerto | Variantes / Sub-arquitecturas | Flag SDCC | Selector de Dispositivos | Modo ASM (GPUTILS) |
|---|---|:---:|:---:|:---:|
| **PIC (Microchip)** | PIC14 (PIC10/12/16), PIC16 (PIC18) | `-mpic14`, `-mpic16` | ✅ Sí (`.inc` GPUTILS) |  **Sí** (`gpasm`/`gplink`) |
| **MCS-51 (8051)** | 8051, 8052, AT89C51, etc. | `-mmcs51` | ✅ Sí (81 headers `.h`) | ❌ Solo C |
| **DS390 (Dallas)** | DS390 (80C390), DS400 | `-mds390`, `-mds400` | ✅ Sí (`.h`) | ❌ Solo C |
| **Z80 Family** | Z80, Z180, Z80N, eZ80 (Z80 mode), R800 | `-mz80`, `-mz180`, etc. | ❌ Directo | ❌ Solo C |
| **Rabbit** | Rabbit 2000, Rabbit 2000A, Rabbit 3000A | `-mr2k`, `-mr2ka`, `-mr3ka` | ✅ Sí (`.h`) | ❌ Solo C |
| **SM83 (Game Boy)** | Sharp LR35902 | `-msm83` | ❌ Directo | ❌ Solo C |
| **TLCS-90 (Toshiba)**| TLCS-90 | `-mtlcs90` | ❌ Directo | ❌ Solo C |
| **STM8 (ST)** | STM8S, STM8L, STM8AF, STM8AL | `-mstm8` | ❌ Directo | ❌ Solo C |
| **HC08/S08 (NXP)** | HC08, S08 | `-mhc08`, `-ms08` | ✅ Sí (`.h`) | ❌ Solo C |
| **PDK (Padauk)** | PDK13, PDK14, PDK15 | `-mpdk13`, `-mpdk14`, `-mpdk15` | ❌ Directo | ❌ Solo C |
| **MOS 6502** | MOS 6502, WDC 65C02 | `-mmos6502`, `-mmos65c02` | ❌ Directo | ❌ Solo C |
| **F8 (Fairchild)** | Fairchild F8 | `-mf8` | ❌ Directo | ❌ Solo C |

---

## 📱 Especificaciones Técnicas

| Componente | Versión / Valor |
|---|---|
| **Android Compile SDK** | `android-37` (Android 17) |
| **Android Target SDK** | `37` (Android 17) |
| **Android Min SDK** | `23` (Android 6.0 Marshmallow) |
| **Android Build Tools** | `37.0.0` |
| **Gradle** | `9.6.0` |
| **Android Gradle Plugin (AGP)** | `9.2.1` |
| **Android NDK** | `30.0.14904198` (`rc1`) |
| **CMake** | `4.1.2` |
| **SDCC (Small Device C Compiler)** | `4.5.0` (24 puertos activos) |
| **GPUTILS (GNU PIC Utilities)** | `1.5.2` |
| **Arquitectura de Ejecución** | ARM64 (`arm64-v8a` de 64 bits) |
| **Alineación ELF** | 16 KB (`max-page-size=16384`) |

---

## 🚀 Entorno de Compilación

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

### 3. Comandos de Compilación

Los artefactos se generan en el directorio temporal `/tmp/calculo`:

```bash
# Compilar APK de depuración (Debug)
./gradlew assembleDebug

# Compilar APK firmado de producción (Release)
./gradlew assembleRelease

# Compilar Android App Bundle (.aab) firmado para Google Play Store
./gradlew bundleRelease
```

**Rutas de salida:**
- **APK Debug:** `/tmp/calculo/outputs/apk/debug/app-debug.apk`
- **APK Release:** `/tmp/calculo/outputs/apk/release/app-release.apk`
- **AAB Release:** `/tmp/calculo/outputs/bundle/release/app-release.aab`

---

## 📂 Estructura del Repositorio

```
C-PIC/
├── app/
│   ├── build.gradle                               # Configuración del módulo de aplicación
│   └── src/
│       ├── main/
│       │   ├── AndroidManifest.xml                # Manifiesto de la aplicación Android
│       │   ├── assets/data/data/com.diamon.ptc/   # Headers, scripts LKR y librerías precompiladas
│       │   │   └── files/usr/share/
│       │   │       ├── gputils/                   # Headers (.inc) y scripts (.lkr) de PIC
│       │   │       └── sdcc/                      # Includes C y librerías de las 24 arquitecturas
│       │   ├── cpp/                               # Soporte nativo C/C++ (CMake/NDK)
│       │   ├── java/com/diamon/ptc/               # Código fuente Java
│       │   │   ├── MainActivity.java              # Controlador principal de UI, terminal y editor
│       │   │   ├── PortConfig.java                # Modelo inmutable de configuración de puertos
│       │   │   ├── PortRegistry.java              # Registro estático de las 12 familias SDCC y templates
│       │   │   ├── SdccExecutor.java              # Ejecutor de SDCC y gestión de symlinks libexec
│       │   │   ├── GpUtilsExecutor.java           # Ejecutor de herramientas GPUTILS (gpasm/gplink)
│       │   │   ├── AssetExtractor.java            # Extractor eficiente de recursos
│       │   │   ├── IntelHexParser.java            # Analizador de formatos HEX
│       │   │   ├── FileManager.java               # Gestión de exportación y SAF
│       │   │   ├── BillingManager.java            # Gestión de compras in-app y facturación
│       │   │   ├── views/LogScrollView.java       # ScrollView con soporte de auto-desplazamiento inteligente
│       │   │   └── policy/PolicyActivity.java     # Pantalla de política de privacidad
│       │   ├── jniLibs/arm64-v8a/                 # 72 binarios nativos ARM64 (lib*.so)
│       │   └── res/                               # Layouts, recursos gráficos y cadenas localizadas
│       │       ├── layout/activity_main.xml       # Layout principal con spinners de arquitectura y terminal
│       │       ├── values/strings.xml             # Cadenas en Español
│       │       └── values-en/strings.xml          # Cadenas en Inglés
│       └── test/java/com/diamon/ptc/              # Suite de 20 pruebas unitarias automatizadas
│           ├── PortRegistryTest.java              # Validación de familias y arquitecturas
│           ├── ProjectSourceProcessingTest.java   # Procesamiento de fuentes, headers y exportación
│           ├── IntelHexParserTest.java            # Validación de análisis de registros HEX
│           └── LocalSdccMultiPortCompilationTest.java # Compilación real multi-puerto
├── fake_root/                                     # Estructura base inmutable de referencia
├── libs/                                          # Librerías dinámicas compartidas de soporte
├── setup-sdk.sh                                   # Script instalador del SDK 37 y NDK 30
├── upload_play_store.py                           # Script de subida automática a Google Play
├── RELEASE_NOTES_v1.4.0.md                        # Notas del lanzamiento v1.4.0
├── RELEASE_NOTES_v1.3.0.md                        # Notas del lanzamiento v1.3.0
├── NOMBRES_BINARIOS_VS_ANTIGUOS.md                # Correspondencia de binarios lib*.so vs originales
├── REPORTE_LIMPIEZA_ASSETS.md                     # Auditoría de limpieza y ahorro en assets
├── REPORTE_ANALISIS_DEPENDENCIAS.md               # Análisis de dependencias DT_NEEDED y 16KB
├── REPORTE_DEPENDENCIAS_ORIGINALES.md             # Inventario de dependencias nativas upstream
└── README.md                                      # Este documento
```

---

## 📚 Documentación Técnica Adicional

1. **[RELEASE_NOTES_v1.4.0.md](RELEASE_NOTES_v1.4.0.md)**: Notas completas del lanzamiento actual v1.4.0.
2. **[RELEASE_NOTES_v1.3.0.md](RELEASE_NOTES_v1.3.0.md)**: Notas del lanzamiento previo v1.3.0.
3. **[GEMINI.md](GEMINI.md)**: Arquitectura del proyecto, variables de entorno y firma.
4. **[GUIA_PUBLICACION_PLAY_STORE.md](GUIA_PUBLICACION_PLAY_STORE.md)**: Procedimiento para el despliegue a Google Play Console.
5. **[NOMBRES_BINARIOS_VS_ANTIGUOS.md](NOMBRES_BINARIOS_VS_ANTIGUOS.md)**: Mapeo de los 60 ejecutables y 12 librerías nativas adaptadas a Google Play.
6. **[REPORTE_LIMPIEZA_ASSETS.md](REPORTE_LIMPIEZA_ASSETS.md)**: Detalle del ahorro de espacio de más de 150 MB al depurar fuentes y binarios redundantes.
7. **[REPORTE_ANALISIS_DEPENDENCIAS.md](REPORTE_ANALISIS_DEPENDENCIAS.md)**: Análisis de dependencias `DT_NEEDED` y alineación estricta de páginas a 16 KB.

---

## 📄 Licencia

Este proyecto está distribuido bajo la **Licencia Pública General de GNU v3.0 (GPL-3.0)**. Consulta el archivo [`LICENSE`](LICENSE) para conocer todos los términos y condiciones.

---

## 👤 Autor

- **Desarrollador**: Daniel Diamon ([@Danielk10](https://github.com/Danielk10))
- **Repositorio Oficial**: [https://github.com/Danielk10/C-PIC](https://github.com/Danielk10/C-PIC)
- **Lanzamientos Oficiales**: [GitHub Releases](https://github.com/Danielk10/C-PIC/releases)
