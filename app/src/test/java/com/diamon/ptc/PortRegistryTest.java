package com.diamon.ptc;

import org.junit.Test;
import static org.junit.Assert.*;

import java.util.List;

/**
 * Tests unitarios para PortRegistry y PortConfig.
 * Valida la cobertura de las 12 familias y las 24 arquitecturas de SDCC 4.5.0.
 */
public class PortRegistryTest {

    @Test
    public void testAllTwelveFamiliesPresent() {
        List<PortConfig> ports = PortRegistry.getAllPorts();
        assertEquals("Deben existir exactamente 12 familias de puertos registradas", 12, ports.size());
        assertEquals("El número de puertos de getPortCount() debe ser 12", 12, PortRegistry.getPortCount());

        String[] familyNames = PortRegistry.getFamilyNames();
        assertEquals(12, familyNames.length);
        assertEquals("PIC (Microchip)", familyNames[0]);
        assertEquals("MCS-51 (8051)", familyNames[1]);
        assertEquals("DS390 (Dallas)", familyNames[2]);
        assertEquals("Z80 Family", familyNames[3]);
        assertEquals("Rabbit (R2K/R3K)", familyNames[4]);
        assertEquals("SM83 (Game Boy)", familyNames[5]);
        assertEquals("TLCS-90 (Toshiba)", familyNames[6]);
        assertEquals("STM8 (ST)", familyNames[7]);
        assertEquals("HC08/S08 (NXP)", familyNames[8]);
        assertEquals("PDK (Padauk)", familyNames[9]);
        assertEquals("MOS 6502", familyNames[10]);
        assertEquals("F8 (Fairchild)", familyNames[11]);
    }

    @Test
    public void testOnlyPicHasAsmMode() {
        for (int i = 0; i < PortRegistry.getPortCount(); i++) {
            PortConfig port = PortRegistry.getPort(i);
            if ("PIC (Microchip)".equals(port.familyName)) {
                assertTrue("PIC debe soportar modo ASM", port.hasAsmMode);
                assertNotNull("PIC debe tener defaultAsmCode", port.defaultAsmCode);
                assertTrue(port.defaultAsmCode.contains("PROCESSOR"));
            } else {
                assertFalse("La familia " + port.familyName + " no debe tener modo ASM", port.hasAsmMode);
            }
        }
    }

    @Test
    public void testAllTwentyFourArchitecturesCovered() {
        String[] allExpectedArchs = {
                "pic14", "pic16",
                "mcs51",
                "ds390", "ds400",
                "z80", "z180", "z80n", "ez80_z80", "r800",
                "r2k", "r2ka", "r3ka",
                "sm83",
                "tlcs90",
                "stm8",
                "hc08", "s08",
                "pdk13", "pdk14", "pdk15",
                "mos6502", "mos65c02",
                "f8"
        };

        for (String arch : allExpectedArchs) {
            int index = PortRegistry.findIndexByArch(arch);
            assertTrue("La arquitectura " + arch + " debe ser encontrada en el registro", index >= 0);
            PortConfig port = PortRegistry.getPort(index);
            assertNotNull("El puerto para " + arch + " no debe ser nulo", port);

            boolean matches = port.sdccArch.equals(arch);
            if (!matches && port.subArchitectures != null) {
                for (String sub : port.subArchitectures) {
                    if (sub.equals(arch)) {
                        matches = true;
                        break;
                    }
                }
            }
            assertTrue("El puerto en el índice " + index + " debe contener la arquitectura " + arch, matches);
        }
    }

    @Test
    public void testSubArchitectureResolution() {
        // Test Z80 Family
        PortConfig z80Port = PortRegistry.getPort(PortRegistry.findIndexByFamily("Z80 Family"));
        assertTrue(z80Port.hasSubArchitectures());
        assertEquals("z80", z80Port.resolveArch(0));
        assertEquals("z180", z80Port.resolveArch(1));
        assertEquals("z80n", z80Port.resolveArch(2));
        assertEquals("ez80_z80", z80Port.resolveArch(3));
        assertEquals("r800", z80Port.resolveArch(4));
        assertEquals("z80", z80Port.resolveArch(99)); // Fallback a default

        // Test Rabbit
        PortConfig rabbitPort = PortRegistry.getPort(PortRegistry.findIndexByFamily("Rabbit (R2K/R3K)"));
        assertTrue(rabbitPort.hasSubArchitectures());
        assertEquals("r2k", rabbitPort.resolveArch(0));
        assertEquals("r2ka", rabbitPort.resolveArch(1));
        assertEquals("r3ka", rabbitPort.resolveArch(2));

        // Test Padauk
        PortConfig pdkPort = PortRegistry.getPort(PortRegistry.findIndexByFamily("PDK (Padauk)"));
        assertTrue(pdkPort.hasSubArchitectures());
        assertEquals("pdk13", pdkPort.resolveArch(0));
        assertEquals("pdk14", pdkPort.resolveArch(1));
        assertEquals("pdk15", pdkPort.resolveArch(2));

        // Test MOS 6502
        PortConfig mosPort = PortRegistry.getPort(PortRegistry.findIndexByFamily("MOS 6502"));
        assertTrue(mosPort.hasSubArchitectures());
        assertEquals("mos6502", mosPort.resolveArch(0));
        assertEquals("mos65c02", mosPort.resolveArch(1));

        // Test non-sub-architecture port (STM8)
        PortConfig stm8Port = PortRegistry.getPort(PortRegistry.findIndexByFamily("STM8 (ST)"));
        assertFalse(stm8Port.hasSubArchitectures());
        assertEquals("stm8", stm8Port.resolveArch(0));
    }

    @Test
    public void testDefaultCodeTemplatesValid() {
        for (int i = 0; i < PortRegistry.getPortCount(); i++) {
            PortConfig port = PortRegistry.getPort(i);
            assertNotNull("El puerto " + port.familyName + " debe tener defaultCCode", port.defaultCCode);
            assertFalse("defaultCCode no debe estar vacío para " + port.familyName, port.defaultCCode.trim().isEmpty());
            assertTrue("defaultCCode debe contener la función main() para " + port.familyName,
                    port.defaultCCode.contains("main"));
            assertNotNull("El hint C no debe ser nulo para " + port.familyName, port.editorHintC);
        }
    }

    @Test
    public void testDeviceSelectorsConfiguredCorrectly() {
        PortConfig picPort = PortRegistry.getPort(0);
        assertTrue("PIC debe tener selector de dispositivos", picPort.hasDeviceSelector());
        assertEquals("gputils/header", picPort.headerIncludeDir);
        assertEquals(".inc", picPort.headerExtension);
        assertEquals("16F628A", picPort.defaultDevice);

        PortConfig mcs51Port = PortRegistry.getPort(1);
        assertTrue("MCS-51 debe tener selector de dispositivos", mcs51Port.hasDeviceSelector());
        assertEquals("sdcc/include/mcs51", mcs51Port.headerIncludeDir);
        assertEquals(".h", mcs51Port.headerExtension);
        assertEquals("8052", mcs51Port.defaultDevice);

        PortConfig sm83Port = PortRegistry.getPort(PortRegistry.findIndexByFamily("SM83 (Game Boy)"));
        assertFalse("SM83 no tiene selector de cabeceras individuales", sm83Port.hasDeviceSelector());
    }

    @Test
    public void testFindByFamilyInvalidReturnsDefault() {
        int index = PortRegistry.findIndexByFamily("NonExistentFamily");
        assertEquals(0, index);

        int archIndex = PortRegistry.findIndexByArch("invalid_arch");
        assertEquals(0, archIndex);

        PortConfig outOfBounds = PortRegistry.getPort(-1);
        assertNotNull(outOfBounds);
        assertEquals("PIC (Microchip)", outOfBounds.familyName);

        PortConfig outOfBoundsHigh = PortRegistry.getPort(999);
        assertNotNull(outOfBoundsHigh);
        assertEquals("PIC (Microchip)", outOfBoundsHigh.familyName);
    }
}
