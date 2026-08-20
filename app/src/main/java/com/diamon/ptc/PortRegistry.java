package com.diamon.ptc;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Registro estático de todas las familias de puertos SDCC soportadas.
 * Cada familia contiene la configuración completa para compilar, editar y mostrar la UI.
 */
public final class PortRegistry {

    private static final List<PortConfig> PORTS = new ArrayList<>();

    static {
        // ═══════════════════════════════════════════════════════════════
        // 1. PIC (Microchip) — Única familia con modo ASM (GPUTILS)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("PIC (Microchip)", "pic14")
                .subArchitectures(
                        new String[]{"pic14", "pic16"},
                        new String[]{"PIC14 (PIC10/12/16)", "PIC16 (PIC18)"}
                )
                .hasAsmMode(true)
                .hasProcessorFlag(true)
                .headerIncludeDir("gputils/header")  // usa headers GPUTILS
                .headerExtension(".inc")
                .headerPrefix("p")
                .headerUpperCase(true)
                .useNonFree(true)
                .defaultDevice("16F628A")
                .defaultCCode(
                        "#include <pic14/pic16f628a.h>\n\n" +
                        "// Ejemplo básico para PIC16F628A\n" +
                        "void main(void) {\n" +
                        "    TRISB = 0x00; // Puerto B como salida\n" +
                        "    while(1) {\n" +
                        "        PORTB = 0xFF;\n" +
                        "        for(unsigned int i=0; i<1000; i++); // Retardo\n" +
                        "        PORTB = 0x00;\n" +
                        "        for(unsigned int i=0; i<1000; i++);\n" +
                        "    }\n" +
                        "}\n"
                )
                .defaultAsmCode(
                        "; Código de prueba para PIC16F628A\n" +
                        "    PROCESSOR 16F628A\n" +
                        "    INCLUDE \"P16F628A.INC\"\n\n" +
                        "    ORG 0x00\n" +
                        "START:\n" +
                        "    BANKSEL TRISB\n" +
                        "    CLRF TRISB\n" +
                        "LOOP:\n" +
                        "    MOVLW 0xFF\n" +
                        "    MOVWF PORTB\n" +
                        "    GOTO LOOP\n" +
                        "    END\n"
                )
                .editorHintC("// Write your C code here…")
                .editorHintAsm("; Write your code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 2. MCS-51 (Intel 8051)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("MCS-51 (8051)", "mcs51")
                .hasProcessorFlag(false)
                .headerIncludeDir("sdcc/include/mcs51")
                .headerExtension(".h")
                .headerPrefix("")
                .headerUpperCase(false)
                .defaultDevice("8052")
                .defaultCCode(
                        "#include <8052.h>\n\n" +
                        "// Blink LED on P1.0 - 8051\n" +
                        "void delay(unsigned int ms) {\n" +
                        "    unsigned int i, j;\n" +
                        "    for(i = 0; i < ms; i++)\n" +
                        "        for(j = 0; j < 120; j++);\n" +
                        "}\n\n" +
                        "void main(void) {\n" +
                        "    while(1) {\n" +
                        "        P1 = 0xFF;\n" +
                        "        delay(500);\n" +
                        "        P1 = 0x00;\n" +
                        "        delay(500);\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your 8051 C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 3. DS390 (Dallas 80C390)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("DS390 (Dallas)", "ds390")
                .subArchitectures(
                        new String[]{"ds390", "ds400"},
                        new String[]{"DS390 (80C390)", "DS400"}
                )
                .headerIncludeDir("sdcc/include/ds390")
                .headerExtension(".h")
                .defaultDevice(null)
                .defaultCCode(
                        "#include <stdint.h>\n\n" +
                        "// Ejemplo básico para Dallas DS390/DS400\n" +
                        "__sfr __at (0x80) P0;\n\n" +
                        "void delay(uint16_t ms) {\n" +
                        "    uint16_t i, j;\n" +
                        "    for(i = 0; i < ms; i++)\n" +
                        "        for(j = 0; j < 100; j++);\n" +
                        "}\n\n" +
                        "void main(void) {\n" +
                        "    while(1) {\n" +
                        "        P0 ^= 0x01;\n" +
                        "        delay(500);\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your DS390 C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 4. Z80 Family
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("Z80 Family", "z80")
                .subArchitectures(
                        new String[]{"z80", "z180", "z80n", "ez80_z80", "r800"},
                        new String[]{"Z80", "Z180", "Z80N (ZX Spectrum Next)", "eZ80 (Z80 mode)", "R800 (MSX)"}
                )
                .defaultDevice(null)
                .defaultCCode(
                        "#include <stdint.h>\n\n" +
                        "// Z80 example\n" +
                        "__sfr __at 0x01 IO_PORT;\n\n" +
                        "void main(void) {\n" +
                        "    IO_PORT = 0xFF;\n" +
                        "    while(1) {\n" +
                        "        IO_PORT ^= 0x01;\n" +
                        "        for(uint16_t i=0; i<10000; i++);\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your Z80 C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 5. Rabbit (R2K/R2KA/R3KA)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("Rabbit (R2K/R3K)", "r2k")
                .subArchitectures(
                        new String[]{"r2k", "r2ka", "r3ka"},
                        new String[]{"Rabbit 2000", "Rabbit 2000A", "Rabbit 3000A"}
                )
                .headerIncludeDir("sdcc/include/rab")
                .headerExtension(".h")
                .defaultDevice(null)
                .defaultCCode(
                        "// Rabbit 2000 example\n" +
                        "#include <stdint.h>\n\n" +
                        "void main(void) {\n" +
                        "    while(1) {\n" +
                        "        // Your code here\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your Rabbit C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 6. SM83 (Sharp LR35902 — Game Boy)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("SM83 (Game Boy)", "sm83")
                .defaultDevice(null)
                .defaultCCode(
                        "#include <stdint.h>\n\n" +
                        "// Game Boy SM83 example\n" +
                        "// Hardware registers\n" +
                        "__sfr __at 0x40 LCDC;\n" +
                        "__sfr __at 0x44 LY;\n\n" +
                        "void main(void) {\n" +
                        "    LCDC = 0x91; // Enable LCD\n" +
                        "    while(1) {\n" +
                        "        while(LY != 144); // Wait VBlank\n" +
                        "        // Your code here\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your Game Boy C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 7. TLCS-90 (Toshiba)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("TLCS-90 (Toshiba)", "tlcs90")
                .defaultDevice(null)
                .defaultCCode(
                        "#include <stdint.h>\n\n" +
                        "// Ejemplo básico para Toshiba TLCS-90\n" +
                        "#define P0 (*(volatile uint8_t*)0x0000)\n\n" +
                        "void delay(uint16_t ms) {\n" +
                        "    uint16_t i;\n" +
                        "    while(ms--)\n" +
                        "        for(i = 0; i < 500; i++);\n" +
                        "}\n\n" +
                        "void main(void) {\n" +
                        "    while(1) {\n" +
                        "        P0 ^= 0x01;\n" +
                        "        delay(500);\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your TLCS-90 C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 8. STM8 (STMicroelectronics)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("STM8 (ST)", "stm8")
                .defaultDevice(null)
                .defaultCCode(
                        "#include <stdint.h>\n\n" +
                        "// Ejemplo básico para STM8 (STM8S103)\n" +
                        "#define PB_ODR *(volatile uint8_t*)0x5005\n" +
                        "#define PB_DDR *(volatile uint8_t*)0x5007\n" +
                        "#define PB_CR1 *(volatile uint8_t*)0x5008\n\n" +
                        "void delay(uint16_t ms) {\n" +
                        "    uint16_t i;\n" +
                        "    while(ms--)\n" +
                        "        for(i = 0; i < 500; i++);\n" +
                        "}\n\n" +
                        "void main(void) {\n" +
                        "    PB_DDR = 0x20; // PB5 como salida\n" +
                        "    PB_CR1 = 0x20; // Salida Push-pull\n" +
                        "    while(1) {\n" +
                        "        PB_ODR ^= 0x20;\n" +
                        "        delay(500);\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your STM8 C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 9. HC08 / S08 (Freescale/NXP)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("HC08/S08 (NXP)", "hc08")
                .subArchitectures(
                        new String[]{"hc08", "s08"},
                        new String[]{"HC08", "S08"}
                )
                .headerIncludeDir("sdcc/include/hc08")
                .headerExtension(".h")
                .defaultDevice(null)
                .defaultCCode(
                        "#include <hc08/mc68hc908gp32.h>\n\n" +
                        "// Ejemplo básico para HC08/S08\n" +
                        "void delay(unsigned int ms) {\n" +
                        "    unsigned int i, j;\n" +
                        "    for(i = 0; i < ms; i++)\n" +
                        "        for(j = 0; j < 100; j++);\n" +
                        "}\n\n" +
                        "void main(void) {\n" +
                        "    DDRA = 0xFF;  // Puerto A como salida\n" +
                        "    while(1) {\n" +
                        "        PTA = 0xFF;\n" +
                        "        delay(500);\n" +
                        "        PTA = 0x00;\n" +
                        "        delay(500);\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your HC08/S08 C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 10. PDK (Padauk)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("PDK (Padauk)", "pdk14")
                .subArchitectures(
                        new String[]{"pdk13", "pdk14", "pdk15"},
                        new String[]{"PDK13 (13-bit)", "PDK14 (14-bit)", "PDK15 (15-bit)"}
                )
                .defaultDevice(null)
                .defaultCCode(
                        "#include <stdint.h>\n\n" +
                        "// Ejemplo básico para Padauk PDK14\n" +
                        "__sfr __at (0x10) PA;\n" +
                        "__sfr __at (0x11) PAC;\n\n" +
                        "void delay(void) {\n" +
                        "    uint8_t i;\n" +
                        "    for(i = 0; i < 255; i++);\n" +
                        "}\n\n" +
                        "void main(void) {\n" +
                        "    PAC = 0xFF; // Puerto A como salida\n" +
                        "    while(1) {\n" +
                        "        PA ^= 0x01;\n" +
                        "        delay();\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your Padauk C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 11. MOS 6502
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("MOS 6502", "mos6502")
                .subArchitectures(
                        new String[]{"mos6502", "mos65c02"},
                        new String[]{"MOS 6502", "WDC 65C02"}
                )
                .defaultDevice(null)
                .defaultCCode(
                        "#include <stdint.h>\n\n" +
                        "// Ejemplo básico para MOS 6502 / 65C02\n" +
                        "#define VIA_PORTB (*(volatile uint8_t*)0x6000)\n" +
                        "#define VIA_DDRB  (*(volatile uint8_t*)0x6002)\n\n" +
                        "void delay(void) {\n" +
                        "    uint16_t i;\n" +
                        "    for(i = 0; i < 5000; i++);\n" +
                        "}\n\n" +
                        "void main(void) {\n" +
                        "    VIA_DDRB = 0xFF;\n" +
                        "    while(1) {\n" +
                        "        VIA_PORTB ^= 0x01;\n" +
                        "        delay();\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your 6502 C code here…")
                .build());

        // ═══════════════════════════════════════════════════════════════
        // 12. F8 (Fairchild)
        // ═══════════════════════════════════════════════════════════════
        PORTS.add(new PortConfig.Builder("F8 (Fairchild)", "f8")
                .defaultDevice(null)
                .defaultCCode(
                        "#include <stdint.h>\n\n" +
                        "// Ejemplo básico para Fairchild F8\n" +
                        "#define IO_PORT (*(volatile uint8_t*)0x0000)\n\n" +
                        "void delay(uint16_t count) {\n" +
                        "    while(count--) {\n" +
                        "        for(uint8_t i = 0; i < 200; i++);\n" +
                        "    }\n" +
                        "}\n\n" +
                        "void main(void) {\n" +
                        "    while(1) {\n" +
                        "        IO_PORT ^= 0x01;\n" +
                        "        delay(500);\n" +
                        "    }\n" +
                        "}\n"
                )
                .editorHintC("// Write your F8 C code here…")
                .build());
    }

    /** Devuelve la lista inmutable de puertos registrados */
    public static List<PortConfig> getAllPorts() {
        return Collections.unmodifiableList(PORTS);
    }

    /** Devuelve el puerto en el índice dado */
    public static PortConfig getPort(int index) {
        if (index < 0 || index >= PORTS.size()) return PORTS.get(0);
        return PORTS.get(index);
    }

    /** Devuelve el número de puertos registrados */
    public static int getPortCount() {
        return PORTS.size();
    }

    /** Devuelve los nombres de familia para un spinner */
    public static String[] getFamilyNames() {
        String[] names = new String[PORTS.size()];
        for (int i = 0; i < PORTS.size(); i++) {
            names[i] = PORTS.get(i).familyName;
        }
        return names;
    }

    /** Busca un puerto por su nombre de familia */
    public static int findIndexByFamily(String familyName) {
        for (int i = 0; i < PORTS.size(); i++) {
            if (PORTS.get(i).familyName.equals(familyName)) return i;
        }
        return 0;
    }

    /** Busca un puerto por su sdccArch */
    public static int findIndexByArch(String arch) {
        for (int i = 0; i < PORTS.size(); i++) {
            PortConfig port = PORTS.get(i);
            if (port.sdccArch.equals(arch)) return i;
            if (port.subArchitectures != null) {
                for (String sub : port.subArchitectures) {
                    if (sub.equals(arch)) return i;
                }
            }
        }
        return 0;
    }
}
