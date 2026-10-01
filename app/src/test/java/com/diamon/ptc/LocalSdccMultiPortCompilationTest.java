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

        // Enlazar objetos con --iram-size 256 para resolver el símbolo l_IRAM
        int l1 = runProcess("sdcc", "-mmcs51", "--out-fmt-ihx", "--iram-size", "256", "-I" + testDir.getAbsolutePath(),
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
                "    INCLUDE \"p16f628a.inc\"\n" +
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
    public void testPicLinkingWithSdccPic14Libraries() throws Exception {
        if (!hasGputils) {
            System.out.println("GPUTILS no disponible en el host; omitiendo test de enlace PIC.");
            return;
        }

        File pic14Lib = resolveProjectFile("fake_root/data/data/com.diamon.ptc/files/usr/share/sdcc/lib/pic14");
        File pic14NonFree = resolveProjectFile("fake_root/data/data/com.diamon.ptc/files/usr/share/sdcc/non-free/lib/pic14");
        File lkrDir = resolveProjectFile("fake_root/data/data/com.diamon.ptc/files/usr/share/gputils/lkr");
        File lkrFile = new File(lkrDir, "16f628a_g.lkr");

        if (!pic14Lib.exists() || !pic14NonFree.exists() || !lkrFile.exists()) {
            System.out.println("Archivos de fake_root no disponibles; omitiendo verificación de bibliotecas PIC.");
            return;
        }

        writeCodeFile("test_pic.asm",
                "    PROCESSOR 16F628A\n" +
                "    INCLUDE \"p16f628a.inc\"\n" +
                "    GLOBAL main\n" +
                "    CODE\n" +
                "main:\n" +
                "    movlw 0xFF\n" +
                "    return\n" +
                "    END\n");

        int asmCode = runProcess("gpasm", "-c", "-p", "16f628a", "-I", testDir.getAbsolutePath(), "test_pic.asm");
        assertEquals("Ensamblado test_pic.asm debe retornar 0", 0, asmCode);

        // Enlace usando solo las rutas de PIC (sin lib/small)
        int linkCode = runProcess("gplink",
                "-s", lkrFile.getAbsolutePath(),
                "-I", pic14Lib.getAbsolutePath(),
                "-I", pic14NonFree.getAbsolutePath(),
                "-I", lkrDir.getAbsolutePath(),
                "test_pic.o",
                "libsdcc.lib",
                "pic16f628a.lib",
                "-o", "output_pic.hex");
        assertEquals("Enlace gplink con librerías pic14 debe retornar 0", 0, linkCode);

        File hexFile = new File(testDir, "output_pic.hex");
        assertTrue("El archivo output_pic.hex debe existir", hexFile.exists());
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

    @Test
    public void testPortRegistryCanonicalHeaderResolution() {
        assertEquals("ADuC84x", PortRegistry.getMcs51HeaderName("ADuC84X"));
        assertEquals("ADuC84x", PortRegistry.getMcs51HeaderName("aduc84x"));
        assertEquals("uPSD32xx", PortRegistry.getMcs51HeaderName("upsd32xx"));
        assertEquals("uPSD33xx", PortRegistry.getMcs51HeaderName("upsd33xx"));
        assertEquals("AT89C513xA", PortRegistry.getMcs51HeaderName("at89c513xa"));
        assertEquals("EFM8BB1", PortRegistry.getMcs51HeaderName("efm8bb1"));
        assertEquals("P89c51RD2", PortRegistry.getMcs51HeaderName("p89c51rd2"));
        assertEquals("P89LPC901", PortRegistry.getMcs51HeaderName("p89lpc901"));
        assertEquals("SST89x5xRDx", PortRegistry.getMcs51HeaderName("sst89x5xrdx"));
        assertEquals("XC866", PortRegistry.getMcs51HeaderName("xc866"));
    }

    @Test
    public void testNonDeviceHeaderFilter() {
        PortConfig mcs51Port = PortRegistry.getPort(1);
        assertTrue(PortRegistry.isNonDeviceHeader(mcs51Port, "serial"));
        assertTrue(PortRegistry.isNonDeviceHeader(mcs51Port, "serial.h"));
        assertTrue(PortRegistry.isNonDeviceHeader(mcs51Port, "compiler"));
        assertTrue(PortRegistry.isNonDeviceHeader(mcs51Port, "lint"));
        assertTrue(PortRegistry.isNonDeviceHeader(mcs51Port, "ser"));
        assertTrue(PortRegistry.isNonDeviceHeader(mcs51Port, "ser_ir"));
        assertTrue(PortRegistry.isNonDeviceHeader(mcs51Port, "serial_io"));
        assertTrue(PortRegistry.isNonDeviceHeader(mcs51Port, "mcs51reg"));

        assertFalse(PortRegistry.isNonDeviceHeader(mcs51Port, "8051"));
        assertFalse(PortRegistry.isNonDeviceHeader(mcs51Port, "8052"));
        assertFalse(PortRegistry.isNonDeviceHeader(mcs51Port, "ADuC84x"));
        assertFalse(PortRegistry.isNonDeviceHeader(mcs51Port, "C8051F340"));
        assertFalse(PortRegistry.isNonDeviceHeader(mcs51Port, "EFM8BB1"));

        PortConfig picPort = PortRegistry.getPort(0);
        assertTrue(PortRegistry.isNonDeviceHeader(picPort, "14regs"));
        assertTrue(PortRegistry.isNonDeviceHeader(picPort, "18fam"));
        assertTrue(PortRegistry.isNonDeviceHeader(picPort, "coff"));
        assertTrue(PortRegistry.isNonDeviceHeader(picPort, "memory"));
        assertTrue(PortRegistry.isNonDeviceHeader(picPort, "migrate"));
    }

    @Test
    public void testPic18CodeTemplateContainsXinstDisable() {
        String pic18Code = PortRegistry.getPicSampleCodeC("18F4550", 1);
        assertTrue("Plantilla PIC18 debe contener #pragma config XINST = OFF para SDCC",
                pic18Code.contains("#pragma config XINST = OFF"));
        assertTrue(pic18Code.contains("<pic16/pic18f4550.h>"));

        String defaultC = PortRegistry.PIC18_DEFAULT_C;
        assertTrue(defaultC.contains("#pragma config XINST = OFF"));

        String defaultAsm = PortRegistry.getPicSampleCodeAsm("18F4550", 1);
        assertTrue("Plantilla PIC18 ASM debe incluir archivo en minúsculas",
                defaultAsm.contains("p18f4550.inc"));
    }

    @Test
    public void testPicSubfamilyTemplates() {
        // PIC18
        String c18 = PortRegistry.getPicSampleCodeC("18F4550", 1);
        assertTrue(c18.contains("#pragma config XINST = OFF"));
        assertTrue(c18.contains("pic16/pic18f4550.h"));
        assertTrue(c18.contains("TRISB"));
        String asm18 = PortRegistry.getPicSampleCodeAsm("18F4550", 1);
        assertTrue(asm18.contains("CLRF TRISB"));
        assertTrue(asm18.contains("BRA LOOP"));

        // PIC14 standard (16F628A)
        String c16 = PortRegistry.getPicSampleCodeC("16F628A", 0);
        assertTrue(c16.contains("pic14/pic16f628a.h"));
        assertTrue(c16.contains("TRISB"));
        String asm16 = PortRegistry.getPicSampleCodeAsm("16F628A", 0);
        assertTrue(asm16.contains("BANKSEL TRISB"));
        assertTrue(asm16.contains("PORTB"));

        // PIC14 enhanced 8-pin (10F320, 12F1840)
        String c10 = PortRegistry.getPicSampleCodeC("10F320", 0);
        assertTrue(c10.contains("pic14/pic10f320.h"));
        assertTrue(c10.contains("TRISA"));
        String asm10 = PortRegistry.getPicSampleCodeAsm("10F320", 0);
        assertTrue(asm10.contains("BANKSEL TRISA"));
        assertTrue(asm10.contains("PORTA"));

        // PIC12 classic midrange (12F675)
        String c12 = PortRegistry.getPicSampleCodeC("12F675", 0);
        assertTrue(c12.contains("pic14/pic12f675.h"));
        assertTrue(c12.contains("TRISIO"));
        String asm12 = PortRegistry.getPicSampleCodeAsm("12F675", 0);
        assertTrue(asm12.contains("BANKSEL TRISIO"));
        assertTrue(asm12.contains("GPIO"));

        // Baseline PIC 8-pin (10F200)
        String asmBase10 = PortRegistry.getPicSampleCodeAsm("10F200", 0);
        assertTrue(asmBase10.contains("TRIS GPIO"));
        assertTrue(asmBase10.contains("GPIO"));

        // Baseline PIC 18-pin (16F54)
        String asmBase16 = PortRegistry.getPicSampleCodeAsm("16F54", 0);
        assertTrue(asmBase16.contains("TRIS PORTB"));
        assertTrue(asmBase16.contains("PORTB"));
    }

    @Test
    public void testAllMcs51DeviceTemplatesCompileAndLinkWithRealSdcc() throws Exception {
        if (!hasSdcc) {
            System.out.println("SDCC no disponible en el host; omitiendo test exhaustivo MCS-51.");
            return;
        }

        File mcs51HeaderDir = resolveProjectFile("app/src/main/assets/data/data/com.diamon.ptc/files/usr/share/sdcc/include/mcs51");
        File[] headerFiles = mcs51HeaderDir.listFiles((dir, name) -> name.endsWith(".h"));
        assertNotNull(headerFiles);

        PortConfig mcs51Port = PortRegistry.getPort(1);

        for (File hFile : headerFiles) {
            String rawName = hFile.getName().substring(0, hFile.getName().length() - 2);
            if (PortRegistry.isNonDeviceHeader(mcs51Port, rawName)) {
                continue; // No es un microcontrolador para el spinner
            }

            String sampleCode = PortRegistry.getSampleCode(mcs51Port, 0, rawName, true);
            assertNotNull("Código para " + rawName + " no debe ser nulo", sampleCode);
            assertFalse(sampleCode.trim().isEmpty());

            File srcFile = new File(testDir, "test_" + rawName + ".c");
            try (FileOutputStream fos = new FileOutputStream(srcFile)) {
                fos.write(sampleCode.getBytes(StandardCharsets.UTF_8));
            }

            File relFile = new File(testDir, "test_" + rawName + ".rel");
            File hexFile = new File(testDir, "test_" + rawName + ".hex");

            int compileCode = runProcess("sdcc", "-mmcs51", "-I" + mcs51HeaderDir.getAbsolutePath(),
                    "-c", srcFile.getName(), "-o", relFile.getName());
            assertEquals("Compilación de plantilla para " + rawName + " debe ser 0", 0, compileCode);
            assertTrue("Objeto .rel debe existir para " + rawName, relFile.exists());

            int linkCode = runProcess("sdcc", "-mmcs51", "--out-fmt-ihx", "--iram-size", "256",
                    relFile.getName(), "-o", hexFile.getName());
            assertEquals("Enlace de plantilla para " + rawName + " debe ser 0", 0, linkCode);
            File ihx = new File(testDir, "test_" + rawName + ".ihx");
            assertTrue("Archivo .hex o .ihx debe existir para " + rawName, hexFile.exists() || ihx.exists());
        }
    }

    private static File resolveProjectFile(String relativePath) {
        File f1 = new File(relativePath);
        if (f1.exists()) return f1;
        File f2 = new File("../" + relativePath);
        if (f2.exists()) return f2;
        if (relativePath.startsWith("app/")) {
            File f3 = new File(relativePath.substring(4));
            if (f3.exists()) return f3;
        }
        return f1;
    }

    private int runProcess(String... args) throws Exception {
        ProcessBuilder pb = new ProcessBuilder(args);
        pb.directory(testDir);
        pb.redirectErrorStream(true);
        Process p = pb.start();
        return p.waitFor();
    }
}
