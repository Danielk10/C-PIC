package com.diamon.ptc;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

import java.io.File;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;

/**
 * Tests unitarios para la lógica de gestión de fuentes, cabeceras personalizadas,
 * priorización de archivos principales y normalización de artefactos compilados.
 */
public class ProjectSourceProcessingTest {

    private File tempTestDir;

    @Before
    public void setUp() {
        tempTestDir = new File(System.getProperty("java.io.tmpdir"), "cpic_test_proj_" + System.currentTimeMillis());
        tempTestDir.mkdirs();
    }

    @After
    public void tearDown() {
        if (tempTestDir != null && tempTestDir.exists()) {
            File[] files = tempTestDir.listFiles();
            if (files != null) {
                for (File f : files) f.delete();
            }
            tempTestDir.delete();
        }
    }

    @Test
    public void testCollectSourceFilesFiltering() {
        LinkedHashMap<String, String> files = new LinkedHashMap<>();
        files.put("main.c", "void main() {}");
        files.put("helpers.c", "void helper() {}");
        files.put("config.h", "#define MAX 10");
        files.put("readme.txt", "This is documentation");
        files.put("empty.c", "   ");

        // Collect .c files (should ignore .h, .txt, and empty content)
        List<String> cSources = new ArrayList<>();
        for (String f : files.keySet()) {
            if (f.toLowerCase(Locale.US).endsWith(".c") && !files.getOrDefault(f, "").trim().isEmpty()) {
                cSources.add(f);
            }
        }
        assertEquals(2, cSources.size());
        assertTrue(cSources.contains("main.c"));
        assertTrue(cSources.contains("helpers.c"));
        assertFalse(cSources.contains("config.h"));
        assertFalse(cSources.contains("empty.c"));

        // Collect .h headers
        List<String> headers = new ArrayList<>();
        for (String f : files.keySet()) {
            if (f.toLowerCase(Locale.US).endsWith(".h") && !files.getOrDefault(f, "").trim().isEmpty()) {
                headers.add(f);
            }
        }
        assertEquals(1, headers.size());
        assertTrue(headers.contains("config.h"));
    }

    @Test
    public void testPrioritizeMainSource() {
        List<String> sourceFiles = new ArrayList<>();
        sourceFiles.add("utils.c");
        sourceFiles.add("drivers.c");
        sourceFiles.add("main.c");

        // Prioritize "main.c"
        String preferred = "main.c";
        for (int i = 0; i < sourceFiles.size(); i++) {
            if (sourceFiles.get(i).equalsIgnoreCase(preferred)) {
                if (i > 0) {
                    String main = sourceFiles.remove(i);
                    sourceFiles.add(0, main);
                }
                break;
            }
        }

        assertEquals("main.c", sourceFiles.get(0));
        assertEquals("utils.c", sourceFiles.get(1));
        assertEquals("drivers.c", sourceFiles.get(2));
    }

    @Test
    public void testCustomHeaderFileWritingAndReading() {
        File headerFile = new File(tempTestDir, "custom_math.h");
        String headerContent = "#ifndef CUSTOM_MATH_H\n#define CUSTOM_MATH_H\nint add(int a, int b);\n#endif\n";

        boolean written = FileManager.writeToFile(headerFile, headerContent);
        assertTrue("El archivo de cabecera personalizada debe escribirse con éxito", written);
        assertTrue("El archivo de cabecera debe existir en el disco", headerFile.exists());

        String readBack = FileManager.readFile(headerFile);
        assertEquals("El contenido leído de la cabecera debe coincidir exactamente", headerContent, readBack);

        File mainFile = new File(tempTestDir, "main.c");
        String mainContent = "#include \"custom_math.h\"\nvoid main(void) { int r = add(2, 3); }\n";
        FileManager.writeToFile(mainFile, mainContent);

        assertTrue(mainFile.exists());
        assertTrue(FileManager.readFile(mainFile).contains("#include \"custom_math.h\""));
    }

    @Test
    public void testNormalizeCOutputArtifactsIhxToHex() {
        String outputBaseName = "test_project";
        File ihxFile = new File(tempTestDir, outputBaseName + ".ihx");
        FileManager.writeToFile(ihxFile, ":03000000020000F7\n:00000001FF\n");

        File hexTarget = new File(tempTestDir, outputBaseName + ".hex");
        assertFalse(hexTarget.exists());

        // Simular lógica de normalizeCOutputArtifacts
        File[] files = tempTestDir.listFiles();
        assertNotNull(files);
        for (File f : files) {
            String name = f.getName();
            if (name.equalsIgnoreCase(outputBaseName + ".ihx") || name.equalsIgnoreCase(outputBaseName + ".HEX")) {
                if (!name.equals(hexTarget.getName())) {
                    if (hexTarget.exists()) hexTarget.delete();
                    f.renameTo(hexTarget);
                }
            }
        }

        assertTrue("El archivo .ihx debe haberse renombrado a .hex", hexTarget.exists());
        assertFalse("El archivo .ihx original no debe existir tras renombrarse", ihxFile.exists());
        assertTrue("El contenido del archivo .hex debe ser válido", FileManager.readFile(hexTarget).contains(":00000001FF"));
    }

    @Test
    public void testFileExtensionValidation() {
        // C mode allowed extensions
        assertTrue(isValidCExtension("main.c"));
        assertTrue(isValidCExtension("DRIVER.C"));
        assertTrue(isValidCExtension("config.h"));
        assertTrue(isValidCExtension("DEFS.H"));
        assertFalse(isValidCExtension("main.asm"));
        assertFalse(isValidCExtension("pic.inc"));
        assertFalse(isValidCExtension("data.txt"));

        // ASM mode allowed extensions
        assertTrue(isValidAsmExtension("main.asm"));
        assertTrue(isValidAsmExtension("START.ASM"));
        assertTrue(isValidAsmExtension("macros.inc"));
        assertTrue(isValidAsmExtension("P16F628A.INC"));
        assertFalse(isValidAsmExtension("main.c"));
        assertFalse(isValidAsmExtension("header.h"));
    }

    @Test
    public void testCollectProjectFilesForExport() {
        String projectName = "led_blink";
        LinkedHashMap<String, String> projectFiles = new LinkedHashMap<>();
        projectFiles.put("led_blink.c", "void main() {}");
        projectFiles.put("led_blink.h", "#define LED 1");
        projectFiles.put("delay.c", "void delay() {}");

        // Create sources in disk
        for (String f : projectFiles.keySet()) {
            FileManager.writeToFile(new File(tempTestDir, f), projectFiles.get(f));
        }

        // Create generated artifacts in disk
        FileManager.writeToFile(new File(tempTestDir, "led_blink.hex"), ":00000001FF\n");
        FileManager.writeToFile(new File(tempTestDir, "led_blink.map"), "MAP FILE CONTENT");
        FileManager.writeToFile(new File(tempTestDir, "led_blink.lst"), "LISTING CONTENT");
        FileManager.writeToFile(new File(tempTestDir, "led_blink.rel"), "REL OBJECT CONTENT");
        FileManager.writeToFile(new File(tempTestDir, "led_blink.lk"), "LINKER SCRIPT");
        FileManager.writeToFile(new File(tempTestDir, "delay.rel"), "DELAY OBJECT");
        FileManager.writeToFile(new File(tempTestDir, "delay.lst"), "DELAY LIST");

        // Create unrelated file that should NOT be exported
        FileManager.writeToFile(new File(tempTestDir, "unrelated.hex"), ":00000001FF\n");

        // Simular lógica de collectProjectFilesForExport
        List<File> filesToExport = new ArrayList<>();
        for (String sourceName : projectFiles.keySet()) {
            File source = new File(tempTestDir, sourceName);
            if (source.exists() && source.isFile()) {
                filesToExport.add(source);
            }
        }

        File[] projectEntries = tempTestDir.listFiles();
        assertNotNull(projectEntries);
        for (File file : projectEntries) {
            if (!file.isFile()) continue;
            String name = file.getName();

            boolean alreadyAdded = false;
            for (File existing : filesToExport) {
                if (existing.getName().equals(name)) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (alreadyAdded) continue;

            if (name.startsWith(projectName + ".")) {
                filesToExport.add(file);
                continue;
            }

            for (String sourceName : projectFiles.keySet()) {
                int dot = sourceName.lastIndexOf('.');
                String base = dot > 0 ? sourceName.substring(0, dot) : sourceName;
                if (name.startsWith(base + ".")) {
                    filesToExport.add(file);
                    break;
                }
            }
        }

        // Validaciones
        List<String> exportedNames = new ArrayList<>();
        for (File f : filesToExport) exportedNames.add(f.getName());

        assertTrue(exportedNames.contains("led_blink.c"));
        assertTrue(exportedNames.contains("led_blink.h"));
        assertTrue(exportedNames.contains("delay.c"));
        assertTrue(exportedNames.contains("led_blink.hex"));
        assertTrue(exportedNames.contains("led_blink.map"));
        assertTrue(exportedNames.contains("led_blink.lst"));
        assertTrue(exportedNames.contains("led_blink.rel"));
        assertTrue(exportedNames.contains("led_blink.lk"));
        assertTrue(exportedNames.contains("delay.rel"));
        assertTrue(exportedNames.contains("delay.lst"));
        assertFalse("El archivo unrelated.hex no debe ser exportado", exportedNames.contains("unrelated.hex"));
    }

    private boolean isValidCExtension(String name) {
        String lower = name.toLowerCase(Locale.US);
        return lower.endsWith(".c") || lower.endsWith(".h");
    }

    private boolean isValidAsmExtension(String name) {
        String lower = name.toLowerCase(Locale.US);
        return lower.endsWith(".asm") || lower.endsWith(".inc");
    }
}

