# C PIC Compiler v1.3.0 (Release 19) 🚀

Esta versión representa una evolución integral de la aplicación, transformándola en un entorno de desarrollo integrado móvil multi-arquitectura con soporte completo para **24 arquitecturas de microcontroladores y microprocesadores**, terminal nativa en tiempo real y una suite de pruebas automatizadas.

---

## 🌟 Novedades y Mejoras Principales

### ⚙️ Soporte Multi-Arquitectura Completo (SDCC 4.5.0 & GPUTILS 1.5.2)
- **12 Familias y 24 Puertos Soportados:**
  - **PIC (Microchip)**: Modo dual con ensamblador nativo **GPUTILS** (`gpasm`/`gplink`) y compilador C **SDCC** (`-mpic14`, `-mpic16`).
  - **MCS-51 (Intel 8051)**: Soporte de 81 cabeceras de microcontroladores (`8052`, `AT89C51`, `STC`, etc.).
  - **DS390 / DS400 (Dallas Semiconductor)**: Soporte completo para 24 bits (`-mds390`, `-mds400`).
  - **Familia Z80**: Z80, Z180, Z80N (ZX Spectrum Next), eZ80 (modo Z80) y R800 (MSX).
  - **Rabbit**: R2K (Rabbit 2000), R2KA (Rabbit 2000A) y R3KA (Rabbit 3000A).
  - **SM83 (Sharp LR35902 / Game Boy)**: Consola portátil con registros de hardware integrados (`-msm83`).
  - **TLCS-90 (Toshiba)**: Microcontroladores Toshiba TLCS-90 (`-mtlcs90`).
  - **STM8 (STMicroelectronics)**: Microcontroladores ST de 8 bits (`-mstm8`).
  - **HC08 / S08 (Freescale/NXP)**: Familias MC68HC08 y HCS08 con cabeceras `.h` oficiales.
  - **PDK (Padauk)**: PDK13 (13 bits), PDK14 (14 bits) y PDK15 (15 bits).
  - **MOS 6502 / 65C02**: Microprocesadores clásicos de 8 bits y WDC 65C02.
  - **Fairchild F8**: Microcontroladores F8 (`-mf8`).

### 💻 Terminal Nativa de Registros y Streaming
- **Salida en Tiempo Real**: Consola nativa sin dependencias externas, enlaces rotos ni retrasos.
- **Auto-Desplazamiento Inteligente**: Nuevo componente `LogScrollView` con bloqueo dinámico durante la lectura del usuario.
- **Acciones Rápidas**: Botón de limpieza integrado en la barra de la terminal y soporte para copiar registros con pulsación prolongada.

### 📝 Editor y Gestión de Proyectos
- **Plantillas Dinámicas y Validadas**: Inserción automática de código funcional probado localmente al cambiar de arquitectura.
- **Soporte Multi-Archivo y Cabeceras Propias**: Compilación modular de múltiples archivos `.c` / `.asm` y cabeceras personalizadas (`#include "custom.h"`) mediante inclusión local automática `-I`.
- **Adaptabilidad de UI**: Detección inteligente de modo: la interfaz oculta selectores no aplicables para arquitecturas de solo C y activa el modo dual únicamente para PIC.

### 🔍 Visor Hexadecimal Universal y Exportación (SAF)
- **Visor HEX Avanzado**: Decodificación en 3 columnas (Dirección, Hexadecimal, ANSI) para cualquier archivo `.hex` generado por cualquier puerto mediante `IntelHexParser`.
- **Exportación Segura**: Exportación de fuentes, `.hex`, `.map`, `.lst` y scripts de enlace directamente a cualquier carpeta seleccionada mediante Storage Access Framework (SAF).

### 🧪 Suite de Pruebas Unitarias y Validación
- 20 tests unitarios automatizados que validan la resolución de puertos, empaquetado de proyectos, análisis de archivos HEX y compilación real con SDCC / GPUTILS.

---

## 📱 Especificaciones Técnicas
- **Target SDK**: Android 16 (API 37) | **Min SDK**: Android 6.0 (API 23)
- **Compiladores Integrados**: SDCC 4.5.0 + GPUTILS 1.5.2 + Suite ucSim
- **Alineación ELF**: 16 KB (`-Wl,-z,max-page-size=16384`) para Android 15/16
- **Gradle**: 9.6.0 | **AGP**: 9.2.1 | **NDK**: 30.0.14904198 rc1 | **CMake**: 4.1.2

---

## 📦 Artefactos Adjuntos
- **`C_PIC_Compiler_v1.3.0.apk`**: APK Release optimizado y firmado para dispositivos ARM64 (`arm64-v8a`).
- **`C_PIC_Compiler_v1.3.0.aab`**: Android App Bundle firmado listo para Google Play Store.
