package com.diamon.ptc;

import org.junit.Test;
import static org.junit.Assert.*;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

/**
 * Tests unitarios para las herramientas opcionales de post-procesamiento
 * (packihx, makebin, ucSim) y su integración en el pipeline de compilación.
 */
public class OptionalToolsTest {

    @Test
    public void testMakebinModePerPort() {
        for (int i = 0; i < PortRegistry.getPortCount(); i++) {
            PortConfig port = PortRegistry.getPort(i);
            boolean isGameBoy = "sm83".equalsIgnoreCase(port.sdccArch);
            if ("SM83 (Game Boy)".equals(port.familyName)) {
                assertTrue("SM83 debe activar el modo Game Boy (-Z) en makebin", isGameBoy);
            } else {
                assertFalse("El puerto " + port.familyName + " debe usar modo binario plano (-p) en makebin", isGameBoy);
            }
        }
    }

    @Test
    public void testHexAndBinMemoryConsistency() {
        // Un archivo Intel HEX válido
        String hex = ":040000000200433285\n:00000001FF\n";
        TreeMap<Integer, Byte> hexMem = IntelHexParser.parse(hex);
        assertEquals(4, hexMem.size());

        // Simulación de la conversión binaria plana generada a partir de la misma dirección
        byte[] flatBin = new byte[]{(byte) 0x02, (byte) 0x00, (byte) 0x43, (byte) 0x32};
        TreeMap<Integer, Byte> binMem = IntelHexParser.parseBinary(flatBin);
        assertEquals(4, binMem.size());

        for (int addr = 0; addr < 4; addr++) {
            assertEquals("El byte en dirección " + addr + " debe coincidir entre HEX y BIN",
                    hexMem.get(addr), binMem.get(addr));
        }
    }

    @Test
    public void testLocalPackihxExecutionIfAvailable() throws Exception {
        File packihxBin = findExecutable("packihx");
        if (packihxBin == null) {
            System.out.println("packihx no está instalado en el sistema local; omitiendo prueba de ejecución.");
            return;
        }

        File tempDir = Files.createTempDirectory("packihx_test").toFile();
        try {
            File inputHex = new File(tempDir, "input.hex");
            File outputHex = new File(tempDir, "output.hex");

            String rawHex = ":020000000102FB\n:020002000304F5\n:00000001FF\n";
            try (FileOutputStream fos = new FileOutputStream(inputHex)) {
                fos.write(rawHex.getBytes(StandardCharsets.UTF_8));
            }

            ProcessBuilder pb = new ProcessBuilder(packihxBin.getAbsolutePath(), inputHex.getAbsolutePath());
            pb.directory(tempDir);
            Process process = pb.start();

            StringBuilder outBuf = new StringBuilder();
            try (BufferedReader r = new BufferedReader(new InputStreamReader(process.getInputStream(), StandardCharsets.UTF_8))) {
                String line;
                while ((line = r.readLine()) != null) {
                    outBuf.append(line).append("\n");
                }
            }
            int exitCode = process.waitFor();
            assertEquals("packihx debe terminar exitosamente (código 0)", 0, exitCode);
            assertTrue("packihx debe generar contenido Intel HEX empaquetado", outBuf.toString().contains(":"));

            try (FileOutputStream fos = new FileOutputStream(outputHex)) {
                fos.write(outBuf.toString().getBytes(StandardCharsets.UTF_8));
            }

            // Validar que el contenido de memoria después del empaquetado es idéntico
            TreeMap<Integer, Byte> origMem = IntelHexParser.parse(rawHex);
            TreeMap<Integer, Byte> packedMem = IntelHexParser.parse(outBuf.toString());
            assertEquals(origMem.size(), packedMem.size());
            for (int addr : origMem.keySet()) {
                assertEquals(origMem.get(addr), packedMem.get(addr));
            }
        } finally {
            deleteRecursive(tempDir);
        }
    }

    @Test
    public void testLocalMakebinExecutionIfAvailable() throws Exception {
        File makebinBin = findExecutable("makebin");
        if (makebinBin == null) {
            System.out.println("makebin no está instalado en el sistema local; omitiendo prueba de ejecución.");
            return;
        }

        File tempDir = Files.createTempDirectory("makebin_test").toFile();
        try {
            File inputHex = new File(tempDir, "input.hex");
            File outputBin = new File(tempDir, "output.bin");

            String rawHex = ":0400000001020304F2\n:00000001FF\n";
            try (FileOutputStream fos = new FileOutputStream(inputHex)) {
                fos.write(rawHex.getBytes(StandardCharsets.UTF_8));
            }

            ProcessBuilder pb = new ProcessBuilder(
                    makebinBin.getAbsolutePath(),
                    "-p",
                    inputHex.getAbsolutePath(),
                    outputBin.getAbsolutePath()
            );
            pb.directory(tempDir);
            Process process = pb.start();
            int exitCode = process.waitFor();

            assertEquals("makebin debe terminar exitosamente (código 0)", 0, exitCode);
            assertTrue("El archivo binario generado debe existir", outputBin.exists());
            assertEquals("El archivo binario debe tener exactamente 4 bytes", 4, outputBin.length());

            byte[] binBytes = Files.readAllBytes(outputBin.toPath());
            assertArrayEquals(new byte[]{0x01, 0x02, 0x03, 0x04}, binBytes);
        } finally {
            deleteRecursive(tempDir);
        }
    }

    private File findExecutable(String name) {
        String[] paths = System.getenv("PATH").split(":");
        for (String p : paths) {
            File f = new File(p, name);
            if (f.exists() && f.canExecute()) return f;
        }
        return null;
    }

    private void deleteRecursive(File file) {
        if (file.isDirectory()) {
            File[] children = file.listFiles();
            if (children != null) {
                for (File c : children) deleteRecursive(c);
            }
        }
        file.delete();
    }
}
