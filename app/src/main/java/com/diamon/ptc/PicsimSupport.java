package com.diamon.ptc;

import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedHashSet;
import java.util.Locale;
import java.util.Set;

/**
 * Utilidades para el emulador PICsim.
 *
 * <p>PICsim solo implementa un subconjunto de dispositivos PIC. Esta clase
 * contiene la lista exacta de procesadores del commit fijado en
 * {@code build_picsim_custom.sh} (3ee791875e15097a2d219c6afe08a8eadc17b673)
 * y traduce los códigos de salida rotos del CLI de PICsim a resultados
 * interpretables por la app.</p>
 *
 * <p>El {@code main()} de PICsim devuelve {@code 1} tras una simulación
 * correcta, {@code 0} cuando {@code pic_init()} falla (HEX inválido o
 * inexistente) y {@code -1} (255 en Android) cuando el procesador no existe.
 * Por eso no se puede usar el código de salida directamente como éxito/fallo.</p>
 */
public final class PicsimSupport {

    /** Nombre del binario configurado en {@link PortRegistry} para PIC. */
    public static final String BINARY_NAME = "picsim";

    /** Aviso que PICsim escribe en stderr al intentar abrir el puerto serie. */
    private static final String SERIAL_NOISE = "/dev/tnt2: No such file or directory";

    /** La simulación terminó correctamente. */
    public static final int RESULT_OK = 0;

    /** No se pudo lanzar el proceso o terminó de forma anómala. */
    public static final int RESULT_LAUNCH_ERROR = -1;

    /** PICsim no pudo cargar el HEX ({@code Pic_init error}). */
    public static final int RESULT_INIT_ERROR = -2;

    /** PICsim no reconoce el procesador solicitado. */
    public static final int RESULT_INVALID_PROCESSOR = -3;

    /**
     * Procesadores implementados por PICsim en el commit fijado.
     * Extraído de {@code src/modules.h} y {@code src/pics/*.c}.
     */
    private static final Set<String> SUPPORTED_PROCESSORS =
            Collections.unmodifiableSet(new LinkedHashSet<>(Arrays.asList(
                    "PIC16F1516",
                    "PIC16F1619",
                    "PIC16F1788",
                    "PIC16F1789",
                    "PIC16F1827",
                    "PIC16F1829",
                    "PIC16F18324",
                    "PIC16F1847",
                    "PIC16F18855",
                    "PIC16F1939",
                    "PIC16F1947",
                    "PIC16F628A",
                    "PIC16F648A",
                    "PIC16F688",
                    "PIC16F777",
                    "PIC16F819",
                    "PIC16F84A",
                    "PIC16F877A",
                    "PIC16F886",
                    "PIC16F887",
                    "PIC18F24Q10",
                    "PIC18F26K80",
                    "PIC18F27K40",
                    "PIC18F452",
                    "PIC18F4520",
                    "PIC18F4550",
                    "PIC18F4580",
                    "PIC18F45K50",
                    "PIC18F4620",
                    "PIC18F46J50",
                    "PIC18F47K40",
                    "PIC18F67J60",
                    "PIC18F67J94"
            )));

    private PicsimSupport() {
        // Clase de utilidades.
    }

    /** Devuelve la lista inmutable de procesadores soportados por PICsim. */
    public static Set<String> getSupportedProcessors() {
        return SUPPORTED_PROCESSORS;
    }

    /**
     * Normaliza el nombre de un dispositivo PIC al formato que espera PICsim.
     *
     * <p>Acepta valores como {@code "16F628A"}, {@code "pic16f628a"} o
     * {@code "PIC-16F628A"} y devuelve {@code "PIC16F628A"}. Devuelve
     * {@code null} si no hay ningún nombre utilizable.</p>
     */
    public static String normalizeProcessor(String device) {
        if (device == null) {
            return null;
        }
        String value = device.trim().toUpperCase(Locale.US).replaceAll("[^A-Z0-9]", "");
        if (value.isEmpty()) {
            return null;
        }
        return value.startsWith("PIC") ? value : "PIC" + value;
    }

    /** Indica si el dispositivo o procesador está implementado en PICsim. */
    public static boolean isSupported(String processor) {
        String value = normalizeProcessor(processor);
        return value != null && SUPPORTED_PROCESSORS.contains(value);
    }

    /** Indica si el binario de simulador configurado corresponde a PICsim. */
    public static boolean isPicsim(String simulatorBinary) {
        return simulatorBinary != null
                && BINARY_NAME.equalsIgnoreCase(simulatorBinary.trim());
    }

    /**
     * Quita el aviso de `/dev/tnt2` que PICsim escribe al arrancar aunque la
     * simulación funcione correctamente.
     */
    public static String stripSerialNoise(String text) {
        if (text == null) {
            return "";
        }
        return text
                .replace(SERIAL_NOISE + "\r\n", "")
                .replace(SERIAL_NOISE + "\n", "")
                .replace(SERIAL_NOISE, "");
    }

    /**
     * Convierte el código de salida crudo de PICsim en un resultado de la app.
     *
     * @param rawExitCode código devuelto por {@link Process#waitFor()}
     * @param output      salida completa capturada (stdout + stderr)
     */
    public static int classifyExitCode(int rawExitCode, String output) {
        // PICsim devuelve 1 tras una ejecución normal. Se comprueba primero
        // para que un mensaje del programa simulado no se confunda con un error.
        if (rawExitCode == 1) {
            return RESULT_OK;
        }
        String text = (output != null) ? output : "";
        if (text.contains("Error: Invalid processor")) {
            return RESULT_INVALID_PROCESSOR;
        }
        if (text.contains("Pic_init error")) {
            return RESULT_INIT_ERROR;
        }
        if (rawExitCode == 0) {
            return RESULT_INIT_ERROR;
        }
        return RESULT_LAUNCH_ERROR;
    }
}
