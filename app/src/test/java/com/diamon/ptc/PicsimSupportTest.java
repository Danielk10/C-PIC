package com.diamon.ptc;

import org.junit.Test;

import java.util.Set;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

/**
 * Tests unitarios para la integración de PICsim.
 * La lista debe coincidir con el commit fijado en build_picsim_custom.sh.
 */
public class PicsimSupportTest {

    @Test
    public void testSupportedProcessorListMatchesPinnedPicsim() {
        Set<String> supported = PicsimSupport.getSupportedProcessors();
        assertEquals("PICsim del commit fijado implementa 33 procesadores", 33, supported.size());

        assertTrue(supported.contains("PIC16F628A"));
        assertTrue(supported.contains("PIC16F84A"));
        assertTrue(supported.contains("PIC16F877A"));
        assertTrue(supported.contains("PIC18F452"));
        assertTrue(supported.contains("PIC18F4550"));
        assertTrue(supported.contains("PIC18F45K50"));
        assertTrue(supported.contains("PIC18F46J50"));

        assertFalse("PIC10F200 no está implementado en PICsim", supported.contains("PIC10F200"));
        assertFalse("PIC12F683 no está implementado en PICsim", supported.contains("PIC12F683"));
        assertFalse("PIC18F46K80 no está implementado en PICsim", supported.contains("PIC18F46K80"));
    }

    @Test
    public void testPicPortUsesPicsimAndDefaultDeviceIsSupported() {
        PortConfig pic = PortRegistry.getPort(
                PortRegistry.findIndexByFamily("PIC (Microchip)"));
        assertTrue("El puerto PIC debe usar PICsim",
                PicsimSupport.isPicsim(pic.simulatorBinary));
        assertTrue("El dispositivo PIC por defecto debe estar soportado por PICsim",
                PicsimSupport.isSupported(
                        PicsimSupport.normalizeProcessor(pic.defaultDevice)));
    }

    @Test
    public void testNormalizeProcessor() {
        assertEquals("PIC16F628A", PicsimSupport.normalizeProcessor("16F628A"));
        assertEquals("PIC16F628A", PicsimSupport.normalizeProcessor("pic16f628a"));
        assertEquals("PIC16F628A", PicsimSupport.normalizeProcessor(" PIC-16F628A "));
        assertEquals("PIC18F4550", PicsimSupport.normalizeProcessor("18F4550"));
        assertNull(PicsimSupport.normalizeProcessor(null));
        assertNull(PicsimSupport.normalizeProcessor(""));
        assertNull(PicsimSupport.normalizeProcessor("   "));
    }

    @Test
    public void testIsSupported() {
        assertTrue(PicsimSupport.isSupported("PIC16F628A"));
        assertTrue(PicsimSupport.isSupported("pic16f628a"));
        assertTrue(PicsimSupport.isSupported(" PIC-18F4550 "));
        assertTrue("También debe aceptar el nombre sin prefijo PIC",
                PicsimSupport.isSupported("16F628A"));
        assertFalse(PicsimSupport.isSupported("PIC10F200"));
        assertFalse(PicsimSupport.isSupported("8052"));
        assertFalse(PicsimSupport.isSupported(null));
        assertFalse(PicsimSupport.isSupported(""));
    }

    @Test
    public void testIsPicsim() {
        assertTrue(PicsimSupport.isPicsim("picsim"));
        assertTrue(PicsimSupport.isPicsim("PICSim"));
        assertTrue(PicsimSupport.isPicsim(" picsim "));
        assertFalse(PicsimSupport.isPicsim("s51"));
        assertFalse(PicsimSupport.isPicsim("ucsim_z80"));
        assertFalse(PicsimSupport.isPicsim(null));
        assertFalse(PicsimSupport.isPicsim(""));
    }

    @Test
    public void testStripSerialNoise() {
        String noise = "/dev/tnt2: No such file or directory";
        assertEquals("pc=000000", PicsimSupport.stripSerialNoise(noise + "\npc=000000"));
        assertEquals("pc=000000", PicsimSupport.stripSerialNoise(noise + "\r\npc=000000"));
        assertEquals("", PicsimSupport.stripSerialNoise(noise));
        assertEquals("", PicsimSupport.stripSerialNoise(null));
        assertEquals("pc=000000", PicsimSupport.stripSerialNoise("pc=000000"));
    }

    @Test
    public void testClassifySuccessfulRun() {
        // PICsim devuelve 1 después de pic_end(), no 0.
        assertEquals(PicsimSupport.RESULT_OK,
                PicsimSupport.classifyExitCode(1, "pc=0x0000 ... Simulación completada"));
        assertEquals(PicsimSupport.RESULT_OK,
                PicsimSupport.classifyExitCode(1, null));
    }

    @Test
    public void testClassifyInitError() {
        // pic_init() falla y main() devuelve 0.
        assertEquals(PicsimSupport.RESULT_INIT_ERROR,
                PicsimSupport.classifyExitCode(0, "Pic_init error n=1\n"));
        // Un 0 sin texto también es el camino de error de PICsim.
        assertEquals(PicsimSupport.RESULT_INIT_ERROR,
                PicsimSupport.classifyExitCode(0, ""));
    }

    @Test
    public void testClassifyInvalidProcessor() {
        // return -1 se convierte en 255 al salir del proceso.
        assertEquals(PicsimSupport.RESULT_INVALID_PROCESSOR,
                PicsimSupport.classifyExitCode(255,
                        "Error: Invalid processor (PIC10F200)\n"));
    }

    @Test
    public void testSuccessfulExitWinsOverProgramOutput() {
        // Un programa simulado podría imprimir texto que parezca un error;
        // el código 1 de PICsim sigue siendo una ejecución correcta.
        assertEquals(PicsimSupport.RESULT_OK,
                PicsimSupport.classifyExitCode(1,
                        "Pic_init error\nError: Invalid processor\n"));
    }

    @Test
    public void testClassifyCrashOrLaunchFailure() {
        assertEquals(PicsimSupport.RESULT_LAUNCH_ERROR,
                PicsimSupport.classifyExitCode(139, "Segmentation fault"));
        assertEquals(PicsimSupport.RESULT_LAUNCH_ERROR,
                PicsimSupport.classifyExitCode(-1, ""));
    }

    @Test
    public void testDescribeSignalIgnoresPicSimInvalidProcessorCode() {
        // 255 = 128 + 127; no es una señal POSIX válida y no debe reportarse como tal.
        assertNull(ProcessExitCodes.describeSignal(255));
        assertEquals("SIGSEGV (acceso a memoria no valido)", ProcessExitCodes.describeSignal(139));
    }
}
