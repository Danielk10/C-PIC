package com.diamon.ptc;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

/**
 * Tests de integración y validación local con herramientas reales SDCC y GPUTILS.
 * Valida la compilación de proyectos multi-archivo con cabeceras personalizadas (.h / .inc),
 * generación de objetos (.rel / .o), enlace y verificación del archivo .hex generado.
 */
public class LocalSdccMultiPortCompilationTest {

    private File testDir;
    private boolean hasSdcc;
    private boolean hasGputils;

    @Before
    public void setUp() {
        testDir = new File(System.getProperty("java.io.tmpdir"), "sdcc_test_suite_" + System.currentTimeMillis());
        testDir.mkdirs();

        hasSdcc = isCommandAvailable("sdcc");
        hasGputils = isCommandAvailable("gpasm") && isCommandAvailable("gplink");
    }

    @After
    public void tearDown() {
        if (testDir != null && testDir.exists()) {
            deleteRecursive(testDir);
        }
    }

    private void deleteRecursive(File file) {
        File[] children = file.listFiles();
        if (children != null) {
            for (File c : children) deleteRecursive(c);
        }
        file.delete();
    }

    private boolean isCommandAvailable(String cmd) {
        try {
            Process p = new ProcessBuilder(cmd, "--version").start();
            return p.waitFor() == 0;
        } catch (Exception e) {
            return false;
        }
    }

    private void writeCodeFile(String name, String content) throws IOException {
        File file = new File(testDir, name);
        try (FileOutputStream fos = new FileOutputStream(file)) {
            fos.write(content.getBytes(StandardCharsets.UTF_8));
        }
    }

    @Test
    public void testMcs51MultiFileWithCustomHeaderCompilation() throws Exception {
        if (!hasSdcc) {
            System.out.println("SDCC no disponible en el host; omitiendo test de ejecución real MCS-51.");
            return;
        }

        // 1. Cabecera personalizada
        writeCodeFile("custom_math.h",
                "#ifndef CUSTOM_MATH_H\n" +
                "#define CUSTOM_MATH_H\n" +
                "unsigned char double_val(unsigned char x);\n" +
                "#endif\n");

        // 2. Módulo auxiliar
        writeCodeFile("custom_math.c",
                "#include \"custom_math.h\"\n" +
                "unsigned char double_val(unsigned char x) {\n" +
                "    return x * 2;\n" +
                "}\n");

        // 3. Archivo principal que incluye la cabecera
        writeCodeFile("main.c",
                "#include <8052.h>\n" +
                "#include \"custom_math.h\"\n" +
                "void main(void) {\n" +
                "    P1 = double_val(5);\n" +
                "    while(1);\n" +
                "}\n");

        // Compilar custom_math.c con inclusión local (-I.)
        int c1 = runProcess("sdcc", "-mmcs51", "-I" + testDir.getAbsolutePath(), "-c", "custom_math.c");
        assertEquals("Compilación de custom_math.c debe retornar 0", 0, c1);

        // Compilar main.c con inclusión local (-I.)
        int c2 = runProcess("sdcc", "-mmcs51", "-I" + testDir.getAbsolutePath(), "-c", "main.c");
        assertEquals("Compilación de main.c debe retornar 0", 0, c2);

        // Enlazar objetos
        int l1 = runProcess("sdcc", "-mmcs51", "--out-fmt-ihx", "-I" + testDir.getAbsolutePath(),
                "main.rel", "custom_math.rel", "-o", "output.hex");
        assertEquals("Enlace de objetos MCS-51 debe retornar 0", 0, l1);

        File hexFile = new File(testDir, "output.hex");
        File ihxFile = new File(testDir, "output.ihx");
        File targetHex = hexFile.exists() ? hexFile : ihxFile;
        assertTrue("El archivo .hex o .ihx debe existir", targetHex.exists());

        String hexContent = FileManager.readFile(targetHex);
        assertFalse("El archivo hex no debe estar vacío", hexContent.trim().isEmpty());

        TreeMap<Integer, Byte> memory = IntelHexParser.parse(hexContent);
        assertFalse("El mapa de memoria parseado no debe estar vacío", memory.isEmpty());
    }

    @Test
    public void testZ80MultiFileWithCustomHeaderCompilation() throws Exception {
        if (!hasSdcc) {
            System.out.println("SDCC no disponible en el host; omitiendo test de ejecución real Z80.");
            return;
        }

        writeCodeFile("driver.h",
                "#ifndef DRIVER_H\n" +
                "#define DRIVER_H\n" +
                "#include <stdint.h>\n" +
                "void send_byte(uint8_t b);\n" +
                "#endif\n");

        writeCodeFile("driver.c",
                "#include \"driver.h\"\n" +
                "__sfr __at (0x01) IO_DATA;\n" +
                "void send_byte(uint8_t b) {\n" +
                "    IO_DATA = b;\n" +
                "}\n");

        writeCodeFile("main.c",
                "#include \"driver.h\"\n" +
                "void main(void) {\n" +
                "    send_byte(0x55);\n" +
                "    while(1);\n" +
                "}\n");

        int c1 = runProcess("sdcc", "-mz80", "-I" + testDir.getAbsolutePath(), "-c", "driver.c");
        assertEquals("Compilación de driver.c en Z80 debe retornar 0", 0, c1);

        int c2 = runProcess("sdcc", "-mz80", "-I" + testDir.getAbsolutePath(), "-c", "main.c");
        assertEquals("Compilación de main.c en Z80 debe retornar 0", 0, c2);

        int l1 = runProcess("sdcc", "-mz80", "--out-fmt-ihx", "-I" + testDir.getAbsolutePath(),
                "main.rel", "driver.rel", "-o", "output.hex");
        assertEquals("Enlace Z80 debe retornar 0", 0, l1);

        File hexFile = new File(testDir, "output.hex");
        File ihxFile = new File(testDir, "output.ihx");
        File target = hexFile.exists() ? hexFile : ihxFile;
        assertTrue(target.exists());
    }

    @Test
    public void testPicAsmWithCustomIncludeCompilation() throws Exception {
        if (!hasGputils) {
            System.out.println("GPUTILS no disponible en el host; omitiendo test de ejecución real PIC ASM.");
            return;
        }

        // 1. Archivo de macros/include personalizado
        writeCodeFile("custom_macros.inc",
                "SET_ALL_HIGH MACRO\n" +
                "    MOVLW 0xFF\n" +
                "    MOVWF PORTB\n" +
                "    ENDM\n");

        // 2. Archivo ASM principal que incluye la cabecera personalizada
        writeCodeFile("main.asm",
                "    PROCESSOR 16F628A\n" +
                "    INCLUDE \"P16F628A.INC\"\n" +
                "    INCLUDE \"custom_macros.inc\"\n" +
                "    ORG 0x00\n" +
                "START:\n" +
                "    BANKSEL TRISB\n" +
                "    CLRF TRISB\n" +
                "    SET_ALL_HIGH\n" +
                "LOOP:\n" +
                "    GOTO LOOP\n" +
                "    END\n");

        // Compilar con gpasm usando -I para incluir cabecera local
        int c1 = runProcess("gpasm", "-c", "-p", "16f628a", "-I", testDir.getAbsolutePath(), "main.asm");
        assertEquals("Ensamblado gpasm con cabecera personalizada debe retornar 0", 0, c1);

        File objFile = new File(testDir, "main.o");
        assertTrue("El archivo objeto main.o debe haber sido generado", objFile.exists());

        // Enlazar con gplink
        int l1 = runProcess("gplink", "-o", "output.hex", "main.o");
        assertEquals("Enlace gplink debe retornar 0", 0, l1);

        File hexFile = new File(testDir, "output.hex");
        assertTrue("El archivo output.hex debe haber sido generado por gplink", hexFile.exists());

        String hexContent = FileManager.readFile(hexFile);
        assertFalse(hexContent.trim().isEmpty());
    }

    @Test
    public void testFullCompilationAndOptionalToolsPipeline() throws Exception {
        if (!hasSdcc) {
            System.out.println("SDCC no disponible en el host; omitiendo test de pipeline completo.");
            return;
        }

        // 1. Escribir código C para MCS-51
        writeCodeFile("main_pipeline.c",
                "#include <stdint.h>\n" +
                "volatile uint8_t counter = 0;\n" +
                "void main(void) {\n" +
                "    while(1) { counter++; }\n" +
                "}\n");

        // 2. Compilar con SDCC
        int c1 = runProcess("sdcc", "-mmcs51", "-c", "main_pipeline.c");
        assertEquals("Compilación SDCC debe ser exitosa", 0, c1);
        File relFile = new File(testDir, "main_pipeline.rel");
        assertTrue("Archivo objeto .rel debe existir", relFile.exists());

        // 3. Enlazar con SDCC
        int l1 = runProcess("sdcc", "-mmcs51", "-o", "pipeline.hex", "main_pipeline.rel");
        assertEquals("Enlace SDCC debe ser exitoso", 0, l1);

        File hexFile = new File(testDir, "pipeline.hex");
        if (!hexFile.exists()) {
            File ihxFile = new File(testDir, "pipeline.ihx");
            if (ihxFile.exists()) ihxFile.renameTo(hexFile);
        }
        assertTrue("El archivo .hex debe existir tras enlace", hexFile.exists());

        // 4. Ejecutar packihx sobre el .hex generado
        if (isCommandAvailable("packihx")) {
            ProcessBuilder pb = new ProcessBuilder("packihx", hexFile.getAbsolutePath());
            pb.directory(testDir);
            Process p = pb.start();
            StringBuilder packedOut = new StringBuilder();
            try (BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream(), StandardCharsets.UTF_8))) {
                String line;
                while ((line = r.readLine()) != null) packedOut.append(line).append("\n");
            }
            int packCode = p.waitFor();
            assertEquals("packihx sobre salida SDCC debe retornar 0", 0, packCode);
            assertTrue("packihx debe generar registros válidos", packedOut.toString().contains(":"));
        }

        // 5. Ejecutar makebin sobre el .hex generado
        if (isCommandAvailable("makebin")) {
            File binFile = new File(testDir, "pipeline.bin");
            int makebinCode = runProcess("makebin", "-p", hexFile.getAbsolutePath(), binFile.getAbsolutePath());
            assertEquals("makebin sobre salida SDCC debe retornar 0", 0, makebinCode);
            assertTrue("El archivo .bin generado por makebin debe existir", binFile.exists());
            assertTrue("El binario debe tener tamaño mayor a 0", binFile.length() > 0);

            // Validar que se pueda parsear con IntelHexParser.parseBinary
            byte[] binBytes = Files.readAllBytes(binFile.toPath());
            TreeMap<Integer, Byte> binMem = IntelHexParser.parseBinary(binBytes);
            assertEquals("El mapa de memoria de parseBinary debe tener el mismo tamaño que los bytes",
                    binBytes.length, binMem.size());
        }
    }

    private int runProcess(String... args) throws Exception {
        ProcessBuilder pb = new ProcessBuilder(args);
        pb.directory(testDir);
        pb.redirectErrorStream(true);
        Process p = pb.start();
        return p.waitFor();
    }
}
