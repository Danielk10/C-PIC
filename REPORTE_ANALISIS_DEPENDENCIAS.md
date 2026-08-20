# Reporte de Análisis de Dependencias y Arquitectura ELF
**Paquete**: `com.diamon.ptc` (C PIC Compiler)
**Arquitectura Objetivo**: `arm64-v8a` (64 bits)

Este informe técnico documenta el análisis detallado de las dependencias dinámicas (`DT_NEEDED`), símbolos compartidos (`SONAME`), alineación de segmentos de memoria ELF y compatibilidad con las especificaciones de **Android 15 y Android 16 (API 37)**.

---

## 1. Verificación de Alineación de Memoria (16 KB Page Alignment)

Todos los ejecutables y bibliotecas nativas de C-PIC han sido enlazados con la bandera `-Wl,-z,max-page-size=16384` (`Align: 0x4000`), garantizando compatibilidad nativa con dispositivos Android que utilizan páginas de memoria virtual de 16 KB.

---

## 2. Mapa de Dependencias Dinámicas (DT_NEEDED)

### A. Herramientas Principales de Compilación y Ensamblado

| Binario | Librerías Dinámicas Requeridas (`DT_NEEDED`) | Estado de Resolución |
|---|---|---|
| **`libsdcc.so`** (SDCC Driver) | `libm.so`, `libgc.so`, `libc++_shared.so`, `libdl.so`, `libc.so` | ✅ Resuelto en `jniLibs` y sistema |
| **`libcc1.so`** (SDCC C Compiler) | `libiconv.so`, `libisl.so`, `libz.so.1`, `libzstd.so.1`, `libc++_shared.so`, `libdl.so`, `libm.so`, `libc.so` | ✅ Resuelto vía `usr/lib/` symlinks |
| **`libsdcpp.so`** (Preprocesador C) | `libiconv.so`, `libc++_shared.so`, `libdl.so`, `libm.so`, `libc.so` | ✅ Resuelto en `jniLibs` y sistema |
| **`libgpasm.so`** (Ensamblador PIC) | `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libgplink.so`** (Enlazador PIC) | `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libgplib.so`** (Gestor de Librerías) | `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libgpdasm.so`** (Desensamblador PIC)| `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libgpstrip.so`**, **`libgpvc.so`**, **`libgpvo.so`** | `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libmakebin.so`**, **`libpackihx.so`** | `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libsdar.so`**, **`libsdnm.so`**, **`libsdobjcopy.so`**, **`libsdranlib.so`** | `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libsdcdb.so`** (Depurador) | `libreadline.so.8`, `libdl.so`, `libc.so` | ✅ Resuelto vía `usr/lib/` symlinks |
| **`libsdld.so`** y variantes (`sdld6808`, `sdldf8`, `sdldgb`, `sdldpdk`, `sdldstm8`, `sdldz80`) | `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libsdas390.so`** y variantes (`sdas6500`, `sdas6808`, `sdas8051`, `sdasf8`, `sdasgb`, `sdaspdk*`, `sdasrab`, `sdasstm8`, `sdastlcs90`, `sdasz80`) | `libdl.so`, `libc.so` | ✅ Resuelto (Android Bionic) |
| **`libucsim_*.so`** (Simuladores UCSIM) | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` | ✅ Resuelto vía `usr/lib/` symlinks |

---

### B. Bibliotecas Compartidas de Soporte

| Librería | SONAME | Dependencias Exigidas |
|---|---|---|
| `libandroid-support.so` | `None` | `libc.so` |
| `libc++_shared.so` | `libc++_shared.so` | `libc.so`, `libm.so`, `libdl.so` |
| `libfl.so` | `libfl.so` | `libm.so`, `libc.so` |
| `libgc.so` | `libgc.so` | `libc.so`, `libdl.so` |
| `libgmp.so` | `libgmp.so` | `libc.so` |
| `libiconv.so` | `libiconv.so` | `libc.so` |
| `libisl.so` | `libisl.so` | `libgmp.so`, `libc.so` |
| `libncursesw.so` | `libncursesw.so.6` | `libc.so` |
| `libpanelw.so` | `libpanelw.so.6` | `libc.so`, `libncursesw.so.6` |
| `libreadline.so` | `libreadline.so.8` | `libandroid-support.so`, `libncursesw.so.6`, `libc.so` |
| `libz.so` | `libz.so.1` | `libc.so` |
| `libzstd.so` | `libzstd.so.1` | `libc.so` |

---

## 3. Estrategia de Enlaces Simbólicos en Tiempo de Ejecución

Para permitir que los binarios compilados encuentren sus bibliotecas dependientes sin modificar los `DT_NEEDED` internos de upstream:
1. El directorio `usr/lib/` dentro del almacenamiento interno de la app contiene enlaces simbólicos para los nombres con versión (`libncursesw.so.6`, `libpanelw.so.6`, `libreadline.so.8`, `libz.so.1`, `libzstd.so.1`) apuntando hacia los binarios extraídos en `nativeLibraryDir`.
2. La variable de entorno `LD_LIBRARY_PATH` se establece en `<nativeLibDir>:<workDir>/usr/lib`.
3. Todos los ejecutables se referencian mediante enlaces simbólicos en `usr/bin/` y `usr/libexec/sdcc/...` para máxima compatibilidad con scripts y llamadas internas.
