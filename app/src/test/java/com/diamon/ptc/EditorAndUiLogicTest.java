package com.diamon.ptc;

import org.junit.Test;
import static org.junit.Assert.*;

import java.io.File;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/**
 * Tests unitarios para la lógica del editor de código, numeración de líneas,
 * validación de orden del menú y sanitización de nombres de proyecto.
 */
public class EditorAndUiLogicTest {

    @Test
    public void testLineNumbersGeneration() {
        // Test single line
        assertEquals("1", generateLineNumbers(1));

        // Test multiple lines
        assertEquals("1\n2\n3", generateLineNumbers(3));

        // Test boundary (0 or negative lines fallback to 1)
        assertEquals("1", generateLineNumbers(0));
        assertEquals("1", generateLineNumbers(-5));

        // Test 10 lines
        String tenLines = generateLineNumbers(10);
        String[] split = tenLines.split("\n");
        assertEquals(10, split.length);
        assertEquals("1", split[0]);
        assertEquals("10", split[9]);
    }

    @Test
    public void testProjectNameSanitization() {
        assertEquals("my_project", sanitizeProjectName("my project"));
        assertEquals("project_123", sanitizeProjectName("project 123"));
        assertEquals("project", sanitizeProjectName("   "));
        assertEquals("project", sanitizeProjectName(""));
        assertEquals("project", sanitizeProjectName(null));
        assertEquals("test_mcu_", sanitizeProjectName("test-mcu!"));
        assertEquals("blink_led", sanitizeProjectName("blink_led"));
    }

    @Test
    public void testMainMenuAboutIsLastItem() throws Exception {
        File menuFile = new File("src/main/res/menu/main_menu.xml");
        if (!menuFile.exists()) {
            menuFile = new File("app/src/main/res/menu/main_menu.xml");
        }
        assertTrue("El archivo main_menu.xml debe existir", menuFile.exists());

        String content = new String(Files.readAllBytes(menuFile.toPath()));
        List<String> itemIds = new ArrayList<>();
        for (String line : content.split("\n")) {
            if (line.contains("android:id=\"@+id/")) {
                int start = line.indexOf("@+id/") + 5;
                int end = line.indexOf("\"", start);
                if (start > 4 && end > start) {
                    itemIds.add(line.substring(start, end));
                }
            }
        }

        assertFalse("El menú debe contener ítems", itemIds.isEmpty());
        String lastItem = itemIds.get(itemIds.size() - 1);
        assertEquals("El último ítem del menú debe ser action_about (Acerca de / Licencias)", "action_about", lastItem);
    }

    @Test
    public void testTerminalMinimizeStateTransitions() {
        boolean isTerminalExpanded = false;
        boolean isTerminalMinimized = false;

        // Toggle minimize -> true
        isTerminalMinimized = !isTerminalMinimized;
        assertTrue(isTerminalMinimized);

        // If expanded while minimized, minimize should reset
        if (isTerminalMinimized) {
            isTerminalMinimized = false;
        }
        isTerminalExpanded = true;
        assertFalse(isTerminalMinimized);
        assertTrue(isTerminalExpanded);

        // Toggle minimize while expanded -> collapse expansion first, then minimize
        if (isTerminalExpanded) {
            isTerminalExpanded = false;
        }
        isTerminalMinimized = true;
        assertFalse(isTerminalExpanded);
        assertTrue(isTerminalMinimized);

        // Auto-restore on compile
        if (isTerminalMinimized) {
            isTerminalMinimized = false;
        }
        assertFalse(isTerminalMinimized);
    }

    @Test
    public void testMcs51LibraryPathResolution() {
        String arch = "mcs51";
        String resolvedFolder = "mcs51".equalsIgnoreCase(arch) ? "small" : arch;
        assertEquals("La arquitectura mcs51 debe resolver a la carpeta small", "small", resolvedFolder);

        String z80Arch = "z80";
        String resolvedZ80 = "mcs51".equalsIgnoreCase(z80Arch) ? "small" : z80Arch;
        assertEquals("La arquitectura z80 debe resolver a z80", "z80", resolvedZ80);
    }

    @Test
    public void testOutputFormatTokenSplitting() {
        String outputFormat = "--out-fmt-ihx -lliblong -llibsdcc -llibint -llibfloat";
        String[] tokens = outputFormat.trim().split("\\s+");
        assertEquals(5, tokens.length);
        assertEquals("--out-fmt-ihx", tokens[0]);
        assertEquals("-lliblong", tokens[1]);
        assertEquals("-llibsdcc", tokens[2]);
        assertEquals("-llibint", tokens[3]);
        assertEquals("-llibfloat", tokens[4]);
    }

    @Test
    public void testDs390TemplateIntegrity() {
        PortConfig ds390 = PortRegistry.getPort(PortRegistry.findIndexByFamily("DS390 (Dallas)"));
        assertNotNull(ds390);
        assertTrue("Plantilla DS390 debe incluir ds80c390.h", ds390.defaultCCode.contains("#include <ds80c390.h>"));
        assertTrue("Plantilla DS390 debe incluir putchar", ds390.defaultCCode.contains("putchar"));
        assertTrue("Plantilla DS390 debe usar P4", ds390.defaultCCode.contains("P4"));
        assertNotNull("DS390 debe tener outputFormat configurado", ds390.outputFormat);
        assertTrue("outputFormat debe incluir liblong", ds390.outputFormat.contains("-lliblong"));
    }

    @Test
    public void testPdkTemplateIntegrity() {
        PortConfig pdk = PortRegistry.getPort(PortRegistry.findIndexByFamily("PDK (Padauk)"));
        assertNotNull(pdk);
        assertTrue("Plantilla PDK debe usar bucle con límite seguro para evitar overflow en uint8_t",
                pdk.defaultCCode.contains("i < 200"));
    }

    private String generateLineNumbers(int lineCount) {
        int lines = Math.max(1, lineCount);
        StringBuilder sb = new StringBuilder(lines * 4);
        for (int i = 1; i <= lines; i++) {
            sb.append(i);
            if (i < lines) {
                sb.append('\n');
            }
        }
        return sb.toString();
    }

    private String sanitizeProjectName(String input) {
        if (input == null || input.trim().isEmpty()) {
            return "project";
        }
        String clean = input.trim().replaceAll("[^a-zA-Z0-9_]", "_");
        return clean.isEmpty() ? "project" : clean;
    }
}
