package com.diamon.ptc;

/**
 * Utilidades para interpretar códigos de salida de procesos nativos.
 * Sin dependencias de Android para poder probarse con JUnit puro.
 */
public final class ProcessExitCodes {

    private ProcessExitCodes() {
        // Clase de utilidades.
    }

    /**
     * Detecta si un código de salida corresponde a una señal POSIX (128 + signal).
     * Devuelve una descripción legible o {@code null} si no es una señal válida.
     */
    public static String describeSignal(int exitCode) {
        if (exitCode <= 128) {
            return null;
        }
        int signal = exitCode - 128;
        // Linux solo usa señales 1..64; 255 (128+127) es el -1 de PICsim,
        // no una señal real.
        if (signal < 1 || signal > 64) {
            return null;
        }
        switch (signal) {
            case 4:  return "SIGILL (instruccion ilegal)";
            case 6:  return "SIGABRT (proceso abortado)";
            case 7:  return "SIGBUS (error de acceso a memoria)";
            case 8:  return "SIGFPE (error aritmetico)";
            case 9:  return "SIGKILL (proceso terminado por el sistema)";
            case 11: return "SIGSEGV (acceso a memoria no valido)";
            case 14: return "SIGALRM (timeout)";
            case 15: return "SIGTERM (proceso terminado)";
            default: return "señal " + signal;
        }
    }
}
