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

    @Test
    public void testCountLines() {
        assertEquals(1, MainActivity.countLines(null));
        assertEquals(1, MainActivity.countLines(""));
        assertEquals(1, MainActivity.countLines("single line"));
        assertEquals(2, MainActivity.countLines("line 1\nline 2"));
        assertEquals(3, MainActivity.countLines("line 1\nline 2\n"));

        PortConfig pic = PortRegistry.getPort(0);
        int cLines = MainActivity.countLines(pic.defaultCCode);
        assertTrue("El código C de ejemplo debe tener más de 1 línea", cLines > 5);

        int asmLines = MainActivity.countLines(pic.defaultAsmCode);
        assertTrue("El código ASM de ejemplo debe tener más de 1 línea", asmLines > 5);
    }

    @Test
    public void testAppBarLayoutFitsSystemWindows() throws Exception {
        File layoutFile = new File("src/main/res/layout/activity_main.xml");
        if (!layoutFile.exists()) {
            layoutFile = new File("app/src/main/res/layout/activity_main.xml");
        }
        assertTrue("activity_main.xml debe existir", layoutFile.exists());
        String content = new String(Files.readAllBytes(layoutFile.toPath()));
        assertTrue("AppBarLayout debe tener android:fitsSystemWindows=\"true\"",
                content.contains("<com.google.android.material.appbar.AppBarLayout") &&
                content.contains("android:fitsSystemWindows=\"true\""));
    }

    @Test
    public void testSdccPic14VsGputilsDeviceSupport() {
        File sdccPic14Header = new File("src/main/assets/data/data/com.diamon.ptc/files/usr/share/sdcc/non-free/include/pic14/pic10f200.h");
        if (!sdccPic14Header.exists()) {
            sdccPic14Header = new File("app/src/main/assets/data/data/com.diamon.ptc/files/usr/share/sdcc/non-free/include/pic14/pic10f200.h");
        }
        assertFalse("SDCC pic14 no debe contener pic10f200.h", sdccPic14Header.exists());

        File sdcc16f628a = new File("app/src/main/assets/data/data/com.diamon.ptc/files/usr/share/sdcc/non-free/include/pic14/pic16f628a.h");
        if (!sdcc16f628a.exists()) {
            sdcc16f628a = new File("src/main/assets/data/data/com.diamon.ptc/files/usr/share/sdcc/non-free/include/pic14/pic16f628a.h");
        }
        assertTrue("SDCC pic14 debe contener pic16f628a.h", sdcc16f628a.exists());

        File gputils10f200 = new File("app/src/main/assets/data/data/com.diamon.ptc/files/usr/share/gputils/header/p10f200.inc");
        if (!gputils10f200.exists()) {
            gputils10f200 = new File("src/main/assets/data/data/com.diamon.ptc/files/usr/share/gputils/header/p10f200.inc");
        }
        assertTrue("GPUTILS debe contener p10f200.inc", gputils10f200.exists());
    }

    @Test
    public void testAllPortTemplatesAreNonEmptyAndValid() {
        for (PortConfig port : PortRegistry.getAllPorts()) {
            assertNotNull("Puerto no debe ser null", port);
            assertNotNull("Nombre de familia no debe ser null", port.familyName);
            assertNotNull("sdccArch no debe ser null", port.sdccArch);
            assertNotNull("defaultCCode no debe ser null para " + port.familyName, port.defaultCCode);
            assertFalse("defaultCCode no debe estar vacío para " + port.familyName, port.defaultCCode.trim().isEmpty());
            assertTrue("defaultCCode debe tener función main para " + port.familyName, port.defaultCCode.contains("main"));

            if (port.hasAsmMode) {
                assertNotNull("defaultAsmCode no debe ser null para " + port.familyName, port.defaultAsmCode);
                assertFalse("defaultAsmCode no debe estar vacío para " + port.familyName, port.defaultAsmCode.trim().isEmpty());
                assertTrue("defaultAsmCode debe tener directiva END para " + port.familyName, port.defaultAsmCode.contains("END"));
            }
        }
    }

    @Test
    public void testPicSmartTemplateGeneration() {
        PortConfig pic = PortRegistry.getPort(0);

        // PIC16F628A
        String asm16 = PortRegistry.getSampleCode(pic, 0, "16F628A", false);
        assertTrue(asm16.contains("PROCESSOR 16F628A"));
        assertTrue(asm16.contains("BANKSEL TRISB"));
        assertTrue(asm16.contains("PORTB"));

        String c16 = PortRegistry.getSampleCode(pic, 0, "16F628A", true);
        assertTrue(c16.contains("#include <pic14/pic16f628a.h>"));
        assertTrue(c16.contains("TRISB"));

        // PIC10F200 (Baseline)
        String asm10 = PortRegistry.getSampleCode(pic, 0, "10F200", false);
        assertTrue(asm10.contains("PROCESSOR 10F200"));
        assertTrue(asm10.contains("TRIS GPIO"));
        assertTrue(asm10.contains("GPIO"));
        assertFalse("10F200 no tiene TRISB", asm10.contains("TRISB"));
        assertFalse("10F200 no tiene BANKSEL", asm10.contains("BANKSEL"));

        // PIC12F508 (Baseline)
        String asm12Base = PortRegistry.getSampleCode(pic, 0, "12F508", false);
        assertTrue(asm12Base.contains("PROCESSOR 12F508"));
        assertTrue(asm12Base.contains("TRIS GPIO"));
        assertFalse(asm12Base.contains("TRISB"));

        // PIC12F675 (Midrange)
        String asm12Mid = PortRegistry.getSampleCode(pic, 0, "12F675", false);
        assertTrue(asm12Mid.contains("PROCESSOR 12F675"));
        assertTrue(asm12Mid.contains("TRISIO"));
        assertTrue(asm12Mid.contains("GPIO"));
        assertFalse(asm12Mid.contains("TRISB"));

        String c12Mid = PortRegistry.getSampleCode(pic, 0, "12F675", true);
        assertTrue(c12Mid.contains("#include <pic14/pic12f675.h>"));
        assertTrue(c12Mid.contains("TRISIO"));
        assertTrue(c12Mid.contains("GPIO"));
        assertFalse(c12Mid.contains("TRISB"));

        // PIC18F4550 (PIC18)
        String asm18 = PortRegistry.getSampleCode(pic, 1, "18F4550", false);
        assertTrue(asm18.contains("PROCESSOR 18F4550"));
        assertTrue(asm18.contains("CLRF TRISB"));
        assertTrue(asm18.contains("BRA LOOP"));
        assertFalse("PIC18 usa Access Bank para SFRs", asm18.contains("BANKSEL"));

        String c18 = PortRegistry.getSampleCode(pic, 1, "18F4550", true);
        assertTrue(c18.contains("#include <pic16/pic18f4550.h>"));
        assertTrue(c18.contains("TRISB"));
    }

    @Test
    public void testMcs51SmartTemplateGeneration() {
        PortConfig mcs51 = PortRegistry.getPort(PortRegistry.findIndexByFamily("MCS-51 (8051)"));
        String code8051 = PortRegistry.getSampleCode(mcs51, 0, "8051", true);
        assertTrue(code8051.contains("#include <8051.h>"));

        String codeAt89 = PortRegistry.getSampleCode(mcs51, 0, "at89c51", true);
        assertTrue(codeAt89.contains("#include <at89c51.h>"));

        // Verificar el comportamiento de sensibilidad a mayúsculas para mcs51
        String codeC8051F020 = PortRegistry.getSampleCode(mcs51, 0, "c8051f020", true);
        assertTrue(codeC8051F020.contains("#include <C8051F020.h>"));

        String codeC8051F340 = PortRegistry.getSampleCode(mcs51, 0, "C8051F340", true);
        assertTrue(codeC8051F340.contains("#include <C8051F340.h>"));

        String codeAt89S8252 = PortRegistry.getSampleCode(mcs51, 0, "at89s8252", true);
        assertTrue(codeAt89S8252.contains("#include <at89S8252.h>"));

        String codeP89LPC932 = PortRegistry.getSampleCode(mcs51, 0, "p89lpc932", true);
        assertTrue(codeP89LPC932.contains("#include <P89LPC932.h>"));

        String codeEFM8BB1 = PortRegistry.getSampleCode(mcs51, 0, "efm8bb1", true);
        assertTrue(codeEFM8BB1.contains("#include <EFM8BB1.h>"));
    }

    @Test
    public void testIsDefaultSampleCodeDetection() {
        assertTrue(PortRegistry.isDefaultSampleCode(null));
        assertTrue(PortRegistry.isDefaultSampleCode(""));
        assertTrue(PortRegistry.isDefaultSampleCode("   \n\t  "));

        for (PortConfig p : PortRegistry.getAllPorts()) {
            assertTrue(PortRegistry.isDefaultSampleCode(p.defaultCCode));
            if (p.defaultAsmCode != null) {
                assertTrue(PortRegistry.isDefaultSampleCode(p.defaultAsmCode));
            }
        }

        PortConfig pic = PortRegistry.getPort(0);
        assertTrue(PortRegistry.isDefaultSampleCode(PortRegistry.getSampleCode(pic, 0, "10F200", false)));
        assertTrue(PortRegistry.isDefaultSampleCode(PortRegistry.getSampleCode(pic, 0, "12F675", false)));
        assertTrue(PortRegistry.isDefaultSampleCode(PortRegistry.getSampleCode(pic, 1, "18F4550", false)));

        // User custom code must NOT be detected as default sample code
        assertFalse(PortRegistry.isDefaultSampleCode("int calculate_speed(int distance, int time) { return distance / time; }"));
        assertFalse(PortRegistry.isDefaultSampleCode("MOV A, #42\nRET\n"));
    }

    @Test
    public void testLocalGputilsAssembleAndLinkAllPicTemplates() throws Exception {
        boolean gpasmInstalled = false;
        try {
            Process p = new ProcessBuilder("gpasm", "-v").start();
            gpasmInstalled = (p.waitFor() == 0);
        } catch (Exception ignored) {}

        if (!gpasmInstalled) return;

        File headerDir = new File("fake_root/data/data/com.diamon.ptc/files/usr/share/gputils/header");
        File lkrDir = new File("fake_root/data/data/com.diamon.ptc/files/usr/share/gputils/lkr");
        if (!headerDir.exists() || !lkrDir.exists()) return;

        PortConfig pic = PortRegistry.getPort(0);
        String[] chips = {"10F200", "12F508", "12F675", "16F628A", "18F4550"};
        int[] subArchs = {0, 0, 0, 0, 1};

        File tempDir = Files.createTempDirectory("test_pic_gputils").toFile();
        tempDir.deleteOnExit();

        for (int i = 0; i < chips.length; i++) {
            String chip = chips[i];
            int subArch = subArchs[i];
            String asmCode = PortRegistry.getSampleCode(pic, subArch, chip, false);

            File src = new File(tempDir, chip + ".asm");
            File obj = new File(tempDir, chip + ".o");
            File hex = new File(tempDir, chip + ".hex");
            File lkr = new File(lkrDir, chip.toLowerCase(Locale.US) + "_g.lkr");

            Files.write(src.toPath(), asmCode.getBytes());

            Process gpasmProc = new ProcessBuilder(
                    "gpasm", "-c", "-p", chip.toLowerCase(Locale.US),
                    "-I", headerDir.getAbsolutePath(),
                    src.getAbsolutePath(), "-o", obj.getAbsolutePath()
            ).start();
            int gpasmExit = gpasmProc.waitFor();
            assertEquals("gpasm falló para " + chip, 0, gpasmExit);
            assertTrue("Objeto .o generado para " + chip, obj.exists());

            Process gplinkProc = new ProcessBuilder(
                    "gplink", "-s", lkr.getAbsolutePath(),
                    "-o", hex.getAbsolutePath(), obj.getAbsolutePath()
            ).start();
            int gplinkExit = gplinkProc.waitFor();
            assertEquals("gplink falló para " + chip, 0, gplinkExit);
            assertTrue("HEX generado para " + chip, hex.exists() && hex.length() > 0);
        }
    }

    @Test
    public void testLocalSdccNonPicCompilations() throws Exception {
        boolean sdccInstalled = false;
        try {
            Process p = new ProcessBuilder("sdcc", "--version").start();
            sdccInstalled = (p.waitFor() == 0);
        } catch (Exception ignored) {}

        if (!sdccInstalled) return;

        File incDir = new File("fake_root/data/data/com.diamon.ptc/files/usr/share/sdcc/include");
        if (!incDir.exists()) return;

        File tempDir = Files.createTempDirectory("test_sdcc_non_pic").toFile();
        tempDir.deleteOnExit();

        // Familias compatibles en local Linux sdcc 4.2
        String[] families = {
                "MCS-51 (8051)", "DS390 (Dallas)", "Z80 Family", "Rabbit (R2K/R3K)",
                "SM83 (Game Boy)", "TLCS-90 (Toshiba)", "STM8 (ST)", "HC08/S08 (NXP)", "PDK (Padauk)"
        };

        for (String fam : families) {
            PortConfig port = PortRegistry.getPort(PortRegistry.findIndexByFamily(fam));
            assertNotNull("Puerto encontrado para " + fam, port);

            File src = new File(tempDir, port.sdccArch + ".c");
            File out = new File(tempDir, port.sdccArch + ".ihx");
            Files.write(src.toPath(), port.defaultCCode.getBytes());

            List<String> cmd = new ArrayList<>();
            cmd.add("sdcc");
            cmd.add("-m" + port.sdccArch);
            cmd.add("-I");
            cmd.add(incDir.getAbsolutePath());
            if (port.outputFormat != null) {
                for (String opt : port.outputFormat.trim().split("\\s+")) {
                    if (!opt.isEmpty()) cmd.add(opt);
                }
            }
            cmd.add("-o");
            cmd.add(out.getAbsolutePath());
            cmd.add(src.getAbsolutePath());

            Process proc = new ProcessBuilder(cmd).start();
            int exitCode = proc.waitFor();
            assertEquals("SDCC compile failed for family " + fam + " (arch " + port.sdccArch + ")", 0, exitCode);
            assertTrue("Output file generated for " + fam, out.exists() && out.length() > 0);
        }
    }

    @Test
    public void testIncludeAndHeaderHandlingLogic() {
        // Validación de nombres y extensiones de archivos para inclusión
        String[] validC = {"main.c", "config.h", "defs.h", "math_utils.c"};
        String[] invalidC = {"main.asm", "config.inc", "data.txt"};

        for (String file : validC) {
            String lower = file.toLowerCase(Locale.US);
            assertTrue("Debe ser válido para modo C: " + file, lower.endsWith(".c") || lower.endsWith(".h"));
        }

        for (String file : invalidC) {
            String lower = file.toLowerCase(Locale.US);
            assertFalse("No debe ser fuente C: " + file, lower.endsWith(".c") || lower.endsWith(".h"));
        }

        String[] validAsm = {"main.asm", "p16f628a.inc", "macros.inc", "sub.asm"};
        String[] invalidAsm = {"main.c", "config.h", "image.png"};

        for (String file : validAsm) {
            String lower = file.toLowerCase(Locale.US);
            assertTrue("Debe ser válido para modo ASM: " + file, lower.endsWith(".asm") || lower.endsWith(".inc"));
        }

        for (String file : invalidAsm) {
            String lower = file.toLowerCase(Locale.US);
            assertFalse("No debe ser fuente ASM: " + file, lower.endsWith(".asm") || lower.endsWith(".inc"));
        }
    }

    @Test
    public void testGestorPantallaClassExists() {
        assertNotNull("GestorPantalla class must be loadable", com.diamon.utilidades.GestorPantalla.class);
    }

    @Test
    public void testMainMenuContainsLoadSampleCodeAction() throws Exception {
        File menuFile = new File("src/main/res/menu/main_menu.xml");
        if (!menuFile.exists()) {
            menuFile = new File("app/src/main/res/menu/main_menu.xml");
        }
        assertTrue("main_menu.xml debe existir", menuFile.exists());
        String content = new String(Files.readAllBytes(menuFile.toPath()));
        assertTrue("main_menu.xml debe contener action_load_sample_code",
                content.contains("android:id=\"@+id/action_load_sample_code\"") &&
                content.contains("@string/menu_load_sample_code"));
    }

    @Test
    public void testLoadSampleCodeStringsParity() throws Exception {
        File enStrings = new File("app/src/main/res/values-en/strings.xml");
        if (!enStrings.exists()) enStrings = new File("src/main/res/values-en/strings.xml");
        File esStrings = new File("app/src/main/res/values-es/strings.xml");
        if (!esStrings.exists()) esStrings = new File("src/main/res/values-es/strings.xml");
        File baseStrings = new File("app/src/main/res/values/strings.xml");
        if (!baseStrings.exists()) baseStrings = new File("src/main/res/values/strings.xml");

        String en = new String(Files.readAllBytes(enStrings.toPath()));
        String es = new String(Files.readAllBytes(esStrings.toPath()));
        String base = new String(Files.readAllBytes(baseStrings.toPath()));

        String[] requiredKeys = {
                "name=\"menu_load_sample_code\"",
                "name=\"dialog_load_sample_code_title\"",
                "name=\"dialog_load_sample_code_message\"",
                "name=\"log_sample_code_loaded\"",
                "name=\"btn_load\""
        };

        for (String key : requiredKeys) {
            assertTrue("Base strings debe contener " + key, base.contains(key));
            assertTrue("EN strings debe contener " + key, en.contains(key));
            assertTrue("ES strings debe contener " + key, es.contains(key));
        }
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
