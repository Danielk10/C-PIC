# Reporte de Dependencias Originales (Binarios y Librerías sin Modificar)
**Paquete**: `com.diamon.ptc` (C PIC Compiler)
**Arquitectura**: `aarch64` (`arm64-v8a`)

Este documento contiene el inventario y análisis técnico de referencia de todos los **binarios ejecutables** y **librerías compartidas** con sus **nombres originales** y sus dependencias dinámicas nativas (`DT_NEEDED`) tal como son generados upstream por **GPUTILS**, **SDCC** y **UCSIM**.

---

## 1. Herramientas de Compilación SDCC y Preprocesador

| Binario Original | Ubicación Original en Filesystem | Dependencias Dinámicas Originales (`DT_NEEDED`) |
|---|---|---|
| **`sdcc`** | `usr/bin/sdcc` | `libm.so`, `libgc.so`, `libc++_shared.so`, `libdl.so`, `libc.so` |
| **`cc1`** | `usr/libexec/sdcc/aarch64-unknown-linux-gnu/12.1.0/cc1` | `libiconv.so`, `libisl.so`, `libz.so.1`, `libzstd.so.1`, `libc++_shared.so`, `libdl.so`, `libm.so`, `libc.so` |
| **`sdcpp`** | `usr/bin/sdcpp` | `libiconv.so`, `libc++_shared.so`, `libdl.so`, `libm.so`, `libc.so` |
| **`sdcdb`** | `usr/bin/sdcdb` | `libreadline.so.8`, `libdl.so`, `libc.so` |
| **`sdar`** | `usr/bin/sdar` | `libz.so.1`, `libfl.so`, `libm.so`, `libdl.so`, `libc.so` |
| **`sdnm`** | `usr/bin/sdnm` | `libz.so.1`, `libm.so`, `libdl.so`, `libc.so` |
| **`sdobjcopy`** | `usr/bin/sdobjcopy` | `libz.so.1`, `libm.so`, `libdl.so`, `libc.so` |
| **`sdranlib`** | `usr/bin/sdranlib` | `libz.so.1`, `libfl.so`, `libm.so`, `libdl.so`, `libc.so` |
| **`makebin`** | `usr/bin/makebin` | `libdl.so`, `libc.so` |
| **`packihx`** | `usr/bin/packihx` | `libdl.so`, `libc.so` |

---

## 2. Herramientas GNU PIC (GPUTILS)

| Binario Original | Ubicación Original en Filesystem | Dependencias Dinámicas Originales (`DT_NEEDED`) |
|---|---|---|
| **`gpasm`** | `usr/bin/gpasm` | `libdl.so`, `libc.so` |
| **`gpdasm`** | `usr/bin/gpdasm` | `libdl.so`, `libc.so` |
| **`gplib`** | `usr/bin/gplib` | `libdl.so`, `libc.so` |
| **`gplink`** | `usr/bin/gplink` | `libdl.so`, `libc.so` |
| **`gpstrip`** | `usr/bin/gpstrip` | `libdl.so`, `libc.so` |
| **`gpvc`** | `usr/bin/gpvc` | `libdl.so`, `libc.so` |
| **`gpvo`** | `usr/bin/gpvo` | `libdl.so`, `libc.so` |

---

## 3. Ensambladores de Arquitecturas Cruzadas (SDAS)

| Binario Original | Ubicación Original en Filesystem | Dependencias Dinámicas Originales (`DT_NEEDED`) |
|---|---|---|
| **`sdas390`** | `usr/bin/sdas390` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdas6500`** | `usr/bin/sdas6500` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdas6808`** | `usr/bin/sdas6808` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdas8051`** | `usr/bin/sdas8051` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdasf8`** | `usr/bin/sdasf8` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdasgb`** | `usr/bin/sdasgb` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdaspdk13`** | `usr/bin/sdaspdk13` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdaspdk14`** | `usr/bin/sdaspdk14` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdaspdk15`** | `usr/bin/sdaspdk15` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdasrab`** | `usr/bin/sdasrab` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdasstm8`** | `usr/bin/sdasstm8` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdastlcs90`** | `usr/bin/sdastlcs90` | `libm.so`, `libdl.so`, `libc.so` |
| **`sdasz80`** | `usr/bin/sdasz80` | `libm.so`, `libdl.so`, `libc.so` |

---

## 4. Enlazadores de Arquitecturas Cruzadas (SDLD)

| Binario Original | Ubicación Original en Filesystem | Dependencias Dinámicas Originales (`DT_NEEDED`) |
|---|---|---|
| **`sdld`** | `usr/bin/sdld` | `libdl.so`, `libc.so` |
| **`sdld6808`** | `usr/bin/sdld6808` | `libdl.so`, `libc.so` |
| **`sdldf8`** | `usr/bin/sdldf8` | `libdl.so`, `libc.so` |
| **`sdldgb`** | `usr/bin/sdldgb` | `libdl.so`, `libc.so` |
| **`sdldpdk`** | `usr/bin/sdldpdk` | `libdl.so`, `libc.so` |
| **`sdldstm8`** | `usr/bin/sdldstm8` | `libdl.so`, `libc.so` |
| **`sdldz80`** | `usr/bin/sdldz80` | `libdl.so`, `libc.so` |

---

## 5. Simuladores y Emuladores UCSIM / S51

Todos los simuladores de la suite UCSIM comparten el mismo conjunto de dependencias dinámicas con soporte de interfaz de terminal extendida (ncurses/panel):

| Binario Original | Ubicación Original en Filesystem | Dependencias Dinámicas Originales (`DT_NEEDED`) |
|---|---|---|
| **`s51`** | `usr/bin/s51` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_51`** | `usr/bin/ucsim_51` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_avr`** | `usr/bin/ucsim_avr` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_f8`** | `usr/bin/ucsim_f8` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_i8048`** | `usr/bin/ucsim_i8048` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_i8051`** | `usr/bin/ucsim_i8051` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_i8085`** | `usr/bin/ucsim_i8085` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_m6800`** | `usr/bin/ucsim_m6800` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_m6809`** | `usr/bin/ucsim_m6809` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_m68hc08`**| `usr/bin/ucsim_m68hc08`| `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_m68hc11`**| `usr/bin/ucsim_m68hc11`| `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_m68hc12`**| `usr/bin/ucsim_m68hc12`| `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_mos6502`**| `usr/bin/ucsim_mos6502`| `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_oisc`** | `usr/bin/ucsim_oisc` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_p1516`** | `usr/bin/ucsim_p1516` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_pblaze`**| `usr/bin/ucsim_pblaze`| `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_pdk`** | `usr/bin/ucsim_pdk` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_rxk`** | `usr/bin/ucsim_rxk` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_st7`** | `usr/bin/ucsim_st7` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_stm8`** | `usr/bin/ucsim_stm8` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_tlcs`** | `usr/bin/ucsim_tlcs` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_xa`** | `usr/bin/ucsim_xa` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |
| **`ucsim_z80`** | `usr/bin/ucsim_z80` | `libpanelw.so.6`, `libncursesw.so.6`, `libm.so`, `libc.so`, `libc++_shared.so`, `libdl.so` |

---

## 6. Bibliotecas Compartidas Nativas (Librerías de Soporte)

| Librería Original | Ubicación Original en Filesystem | `SONAME` Original | Dependencias Originales (`DT_NEEDED`) |
|---|---|---|---|
| **`libandroid-support.so`** | `usr/lib/libandroid-support.so` | Ninguno | `libc.so` |
| **`libc++_shared.so`** | `usr/lib/libc++_shared.so` | `libc++_shared.so` | `libc.so`, `libm.so`, `libdl.so` |
| **`libfl.so`** | `usr/lib/libfl.so` | `libfl.so` | `libm.so`, `libc.so` |
| **`libgc.so`** | `usr/lib/libgc.so` | `libgc.so` | `libc.so`, `libdl.so` |
| **`libgmp.so`** | `usr/lib/libgmp.so` | `libgmp.so` | `libc.so` |
| **`libiconv.so`** | `usr/lib/libiconv.so` | `libiconv.so` | `libc.so` |
| **`libisl.so`** | `usr/lib/libisl.so` | `libisl.so` | `libgmp.so`, `libc.so` |
| **`libncursesw.so.6`** | `usr/lib/libncursesw.so.6` | `libncursesw.so.6` | `libc.so` |
| **`libpanelw.so.6`** | `usr/lib/libpanelw.so.6` | `libpanelw.so.6` | `libc.so`, `libncursesw.so.6` |
| **`libreadline.so.8`** | `usr/lib/libreadline.so.8` | `libreadline.so.8` | `libandroid-support.so`, `libncursesw.so.6`, `libc.so` |
| **`libz.so.1`** | `usr/lib/libz.so.1` | `libz.so.1` | `libc.so` |
| **`libzstd.so.1`** | `usr/lib/libzstd.so.1` | `libzstd.so.1` | `libc.so` |
