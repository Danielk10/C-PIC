# Notas de la Versión v1.4.0 (VersionCode 20) - C-PIC Compiler

Fecha de lanzamiento: 20 de Agosto de 2026

## 🚀 Novedades y Mejoras Principales

### 1. Herramientas Opcionales de Post-Procesamiento (`packihx` y `makebin`)
- **Normalización Intel HEX (`packihx`)**: Empaqueta y normaliza los registros del archivo Intel HEX generado para asegurar compatibilidad total con programadores de hardware estrictos (como TL866 / MiniPro, Willem, etc.).
- **Generación de Binarios Planos (`makebin`)**: Convierte la salida HEX en una imagen binaria cruda byte a byte (`.bin`) para grabadores de memoria EEPROM/Flash, o en formato ROM compatible para Game Boy (`-Z` en la arquitectura SM83).
- **Nuevo menú interactivo y diálogo**: Acceso rápido desde el menú principal para configurar ejecución automática tras cada compilación o ejecutar las utilidades bajo demanda sobre el proyecto activo.

### 2. Simulación de Hardware Integrada (`ucSim` / `s51`)
- **Soporte de simulación para todas las familias**: Mapeo directo de la familia activa con su emulador oficial (`s51` para 8051 y Dallas DS390, `ucsim_z80` para Z80/SM83, `ucsim_stm8` para STM8, `ucsim_pdk` para Padauk, `ucsim_mos6502` para 6502, `ucsim_p1516` para PIC, `ucsim_m68hc08` para HC08/S08, `ucsim_rxk` para Rabbit, etc.).
- **Transmisión en tiempo real**: Ejecución paso a paso y volcado interactivo de registros del procesador (PC, acumuladores, punteros de pila, banderas de estado) directamente en la terminal.

### 3. Visor Hexadecimal Dual (HEX y BIN)
- El visor de memoria ahora soporta la inspección detallada de archivos Intel HEX (`.hex`) e imágenes binarias planas (`.bin`), mostrando dirección de memoria, valores hexadecimales y representación ANSI.
- Diálogo selector de formato si el proyecto contiene tanto `.hex` como `.bin`.

### 4. Exportación SAF Integral
- Todos los artefactos generados (`.hex` normalizado, `.bin`, `.lst`, `.o`, `.rel`) se exportan automáticamente al almacenamiento seleccionado mediante Storage Access Framework.

### 5. Paridad Lingüística al 100% y Calidad de Código
- Paridad exacta (140 claves) entre español (`res/values/strings.xml`) e inglés (`res/values-en/strings.xml`).
- Cero cadenas de texto hardcodeadas en interfaces de usuario y logs de ejecución.
- 27 pruebas unitarias automatizadas superadas al 100% cubriendo compilación, post-procesamiento y simuladores.

---

## 📦 Artefactos de la Versión
- **APK Release**: `C_PIC_Compiler_v1.4.0.apk`
- **AAB Release**: `C_PIC_Compiler_v1.4.0.aab`
- **Firma Oficial**: Keystore de producción (SHA1: `D7:50:AD:E8:3D:D6:47:1A:E3:68:B6:DC:11:01:CB:07:AC:C9:A8:70`).
- **Nivel de API Android**: Target SDK 37 (Android 17 / Cinnamon Bun), Min SDK 23 (Android 6.0 / Marshmallow).
