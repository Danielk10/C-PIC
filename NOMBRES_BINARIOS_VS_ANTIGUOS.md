# Nombres Nuevos vs Antiguos (Binarios Ejecutables y Librerías)
**Paquete**: `com.diamon.ptc` (C PIC Compiler)

De acuerdo a las políticas de seguridad de Google Play Store, todos los ejecutables nativos y bibliotecas dinámicas compartidas empaquetadas en un APK/AAB deben residir en la carpeta `jniLibs/<arch>/` y cumplir estrictamente con el patrón de nomenclatura `lib<nombre>.so`.

A continuación se detalla la correspondencia entre los nombres originales de la suite **GPUTILS**, **SDCC** y **UCSIM**, su nombre de empaquetado en `jniLibs/arm64-v8a/`, y la ruta exacta reconstruida en tiempo de ejecución (`fake_root`) mediante enlaces simbólicos.

---

## 1. Mapeo de Binarios Ejecutables (60 Binarios)

| Binario Original | Nombre en `jniLibs/arm64-v8a` | Ruta Reconstruida en App (`usr/bin/` o `usr/libexec/`) | Propósito / Suite |
|---|---|---|---|
| `cc1` | `libcc1.so` | `usr/libexec/sdcc/aarch64-unknown-linux-gnu/12.1.0/cc1`, `usr/bin/cc1` | Compilador C interno SDCC |
| `gpasm` | `libgpasm.so` | `usr/bin/gpasm` | Ensamblador PIC GNU |
| `gpdasm` | `libgpdasm.so` | `usr/bin/gpdasm` | Desensamblador PIC GNU |
| `gplib` | `libgplib.so` | `usr/bin/gplib` | Gestor de librerías GNU PIC |
| `gplink` | `libgplink.so` | `usr/bin/gplink` | Enlazador GNU PIC |
| `gpstrip` | `libgpstrip.so` | `usr/bin/gpstrip` | Depurador de símbolos GNU PIC |
| `gpvc` | `libgpvc.so` | `usr/bin/gpvc` | Visualizador de binarios GNU PIC |
| `gpvo` | `libgpvo.so` | `usr/bin/gpvo` | Visor de objetos GNU PIC |
| `makebin` | `libmakebin.so` | `usr/bin/makebin` | Conversor HEX a BIN SDCC |
| `packihx` | `libpackihx.so` | `usr/bin/packihx` | Empaquetador Intel HEX |
| `s51` | `libs51.so` | `usr/bin/s51` | Simulador 8051 |
| `sdar` | `libsdar.so` | `usr/bin/sdar` | Archiver SDCC |
| `sdas390` | `libsdas390.so` | `usr/bin/sdas390` | Ensamblador DS390 |
| `sdas6500` | `libsdas6500.so` | `usr/bin/sdas6500` | Ensamblador 6502 |
| `sdas6808` | `libsdas6808.so` | `usr/bin/sdas6808` | Ensamblador 6808 |
| `sdas8051` | `libsdas8051.so` | `usr/bin/sdas8051` | Ensamblador 8051 |
| `sdasf8` | `libsdasf8.so` | `usr/bin/sdasf8` | Ensamblador Fairchild F8 |
| `sdasgb` | `libsdasgb.so` | `usr/bin/sdasgb` | Ensamblador GameBoy Z80 |
| `sdaspdk13` | `libsdaspdk13.so` | `usr/bin/sdaspdk13` | Ensamblador Padauk PDK13 |
| `sdaspdk14` | `libsdaspdk14.so` | `usr/bin/sdaspdk14` | Ensamblador Padauk PDK14 |
| `sdaspdk15` | `libsdaspdk15.so` | `usr/bin/sdaspdk15` | Ensamblador Padauk PDK15 |
| `sdasrab` | `libsdasrab.so` | `usr/bin/sdasrab` | Ensamblador Rabbit 2000 |
| `sdasstm8` | `libsdasstm8.so` | `usr/bin/sdasstm8` | Ensamblador STM8 |
| `sdastlcs90` | `libsdastlcs90.so` | `usr/bin/sdastlcs90` | Ensamblador Toshiba TLCS90 |
| `sdasz80` | `libsdasz80.so` | `usr/bin/sdasz80` | Ensamblador Z80 |
| `sdcc` | `libsdcc.so` | `usr/bin/sdcc` | Driver principal del compilador SDCC |
| `sdcdb` | `libsdcdb.so` | `usr/bin/sdcdb` | Depurador SDCC |
| `sdcpp` | `libsdcpp.so` | `usr/bin/sdcpp`, `usr/bin/sdcc-sdcpp` | Preprocesador C SDCC |
| `sdld` | `libsdld.so` | `usr/bin/sdld` | Enlazador SDCC |
| `sdld6808` | `libsdld6808.so` | `usr/bin/sdld6808` | Enlazador 6808 |
| `sdldf8` | `libsdldf8.so` | `usr/bin/sdldf8` | Enlazador F8 |
| `sdldgb` | `libsdldgb.so` | `usr/bin/sdldgb` | Enlazador GameBoy |
| `sdldpdk` | `libsdldpdk.so` | `usr/bin/sdldpdk` | Enlazador Padauk |
| `sdldstm8` | `libsdldstm8.so` | `usr/bin/sdldstm8` | Enlazador STM8 |
| `sdldz80` | `libsdldz80.so` | `usr/bin/sdldz80` | Enlazador Z80 |
| `sdnm` | `libsdnm.so` | `usr/bin/sdnm` | Utilidad de símbolos SDCC |
| `sdobjcopy` | `libsdobjcopy.so` | `usr/bin/sdobjcopy` | Conversor de objetos SDCC |
| `sdranlib` | `libsdranlib.so` | `usr/bin/sdranlib` | Generador de índices de librerías |
| `ucsim_51` | `libucsim_51.so` | `usr/bin/ucsim_51` | Simulador MCS51 |
| `ucsim_avr` | `libucsim_avr.so` | `usr/bin/ucsim_avr` | Simulador Atmel AVR |
| `ucsim_f8` | `libucsim_f8.so` | `usr/bin/ucsim_f8` | Simulador F8 |
| `ucsim_i8048` | `libucsim_i8048.so` | `usr/bin/ucsim_i8048` | Simulador Intel 8048 |
| `ucsim_i8051` | `libucsim_i8051.so` | `usr/bin/ucsim_i8051` | Simulador Intel 8051 |
| `ucsim_i8085` | `libucsim_i8085.so` | `usr/bin/ucsim_i8085` | Simulador Intel 8085 |
| `ucsim_m6800` | `libucsim_m6800.so` | `usr/bin/ucsim_m6800` | Simulador Motorola 6800 |
| `ucsim_m6809` | `libucsim_m6809.so` | `usr/bin/ucsim_m6809` | Simulador Motorola 6809 |
| `ucsim_m68hc08` | `libucsim_m68hc08.so` | `usr/bin/ucsim_m68hc08` | Simulador Motorola 68HC08 |
| `ucsim_m68hc11` | `libucsim_m68hc11.so` | `usr/bin/ucsim_m68hc11` | Simulador Motorola 68HC11 |
| `ucsim_m68hc12` | `libucsim_m68hc12.so` | `usr/bin/ucsim_m68hc12` | Simulador Motorola 68HC12 |
| `ucsim_mos6502` | `libucsim_mos6502.so` | `usr/bin/ucsim_mos6502` | Simulador MOS 6502 |
| `ucsim_oisc` | `libucsim_oisc.so` | `usr/bin/ucsim_oisc` | Simulador OISC |
| `ucsim_p1516` | `libucsim_p1516.so` | `usr/bin/ucsim_p1516` | Simulador P1516 |
| `ucsim_pblaze` | `libucsim_pblaze.so` | `usr/bin/ucsim_pblaze` | Simulador PicoBlaze |
| `ucsim_pdk` | `libucsim_pdk.so` | `usr/bin/ucsim_pdk` | Simulador Padauk |
| `ucsim_rxk` | `libucsim_rxk.so` | `usr/bin/ucsim_rxk` | Simulador RXK |
| `ucsim_st7` | `libucsim_st7.so` | `usr/bin/ucsim_st7` | Simulador STMicroelectronics ST7 |
| `ucsim_stm8` | `libucsim_stm8.so` | `usr/bin/ucsim_stm8` | Simulador STM8 |
| `ucsim_tlcs` | `libucsim_tlcs.so` | `usr/bin/ucsim_tlcs` | Simulador Toshiba TLCS |
| `ucsim_xa` | `libucsim_xa.so` | `usr/bin/ucsim_xa` | Simulador Philips XA |
| `ucsim_z80` | `libucsim_z80.so` | `usr/bin/ucsim_z80` | Simulador Zilog Z80 |

---

## 2. Mapeo de Librerías Compartidas (12 Librerías)

| Librería Original / SONAME | Nombre en `jniLibs/arm64-v8a` | Ruta / Enlace en App (`usr/lib/`) |
|---|---|---|
| `libandroid-support.so` | `libandroid-support.so` | `usr/lib/libandroid-support.so` |
| `libc++_shared.so` | `libc++_shared.so` | `usr/lib/libc++_shared.so` |
| `libfl.so` | `libfl.so` | `usr/lib/libfl.so` |
| `libgc.so` | `libgc.so` | `usr/lib/libgc.so` |
| `libgmp.so` | `libgmp.so` | `usr/lib/libgmp.so` |
| `libiconv.so` | `libiconv.so` | `usr/lib/libiconv.so` |
| `libisl.so` | `libisl.so` | `usr/lib/libisl.so` |
| `libncursesw.so.6` | `libncursesw.so` | `usr/lib/libncursesw.so.6`, `usr/lib/libncursesw.so` |
| `libpanelw.so.6` | `libpanelw.so` | `usr/lib/libpanelw.so.6`, `usr/lib/libpanelw.so` |
| `libreadline.so.8` | `libreadline.so` | `usr/lib/libreadline.so.8`, `usr/lib/libreadline.so` |
| `libz.so.1` | `libz.so` | `usr/lib/libz.so.1`, `usr/lib/libz.so` |
| `libzstd.so.1` | `libzstd.so` | `usr/lib/libzstd.so.1`, `usr/lib/libzstd.so` |

---

## 3. Estado de Archivos en `assets` vs `fake_root`

1. **Binarios y Librerías (`.so`):** Ubicados exclusivamente en `app/src/main/jniLibs/arm64-v8a/` cumpliendo con Google Play.
2. **Archivos de Assets:** Contienen únicamente los recursos esenciales (`headers` de PIC, archivos `.lkr`, cabeceras C de SDCC y librerías precompiladas `.lib`).
3. **Limpieza de Assets:** Se excluyeron los manuales (`doc/`, `man/`) y código fuente de compilación (`src/`) para optimizar el peso del APK y velocidad de inicio.
