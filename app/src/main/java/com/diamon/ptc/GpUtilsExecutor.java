package com.diamon.ptc;

import android.content.Context;
import android.util.Log;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Clase para ejecutar los binarios de GPUTILS (gpasm, gpdasm, gplink, etc.)
 * Los binarios .so estan en el directorio nativo de la app y se ejecutan via
 * ProcessBuilder.
 * 
 * Requiere: android:extractNativeLibs="true" en AndroidManifest.xml
 */
public class GpUtilsExecutor {
    private static final String TAG = "GpUtilsExecutor";

    private final Context context;
    private final File workDir;
    private final File nativeLibDir;
    private final File gpUtilsShareDir;

    public GpUtilsExecutor(Context context) {
        this.context = context;
        this.workDir = context.getFilesDir();
        this.nativeLibDir = new File(context.getApplicationInfo().nativeLibraryDir);
        this.gpUtilsShareDir = new File(workDir, "usr/share/gputils");
    }

    /**
     * Ejecuta gpasm con los argumentos especificados.
     * 
     * @param args Argumentos para gpasm (ej: "-v", "-c", "archivo.asm")
     * @return Salida del comando (stdout + stderr)
     */
    public String executeGpasm(String... args) {
        return executeBinary("gpasm", args);
    }

    /**
     * Ejecuta gpdasm con los argumentos especificados.
     */
    public String executeGpdasm(String... args) {
        return executeBinary("gpdasm", args);
    }

    /**
     * Ejecuta gplink con los argumentos especificados.
     */
    public String executeGplink(String... args) {
        return executeBinary("gplink", args);
    }

    /**
     * Ejecuta gplib con los argumentos especificados.
     */
    public String executeGplib(String... args) {
        return executeBinary("gplib", args);
    }

    /**
     * Ejecuta un binario de GPUTILS.
     *
     * @param binaryName Nombre del binario (sin prefijo lib y sin extension .so)
     * @param args       Argumentos del comando
     * @return Salida del comando
     */
    public String executeBinary(String binaryName, String... args) {
        // Los binarios estan en nativeLibraryDir con prefijo "lib" y extension ".so"
        File binaryFile = new File(nativeLibDir, "lib" + binaryName + ".so");

        if (!binaryFile.exists()) {
            // Listar archivos disponibles para debug
            String[] files = nativeLibDir.list();
            String available = files != null ? String.join(", ", files) : "ninguno";
            Log.e(TAG, "Binario no encontrado: " + binaryFile.getAbsolutePath());
            Log.e(TAG, "Archivos disponibles en " + nativeLibDir + ": " + available);
            return "Error: No se encontro el binario " + binaryFile.getAbsolutePath() +
                    "\nDisponibles: " + available;
        }

        // Construir comando
        List<String> command = new ArrayList<>();
        command.add(binaryFile.getAbsolutePath());
        for (String arg : args) {
            command.add(arg);
        }

        Log.d(TAG, "Ejecutando: " + String.join(" ", command));

        try {
            ProcessBuilder pb = new ProcessBuilder(command);
            pb.directory(workDir);
            pb.redirectErrorStream(true);

            // Configurar variables de entorno para GPUTILS
            Map<String, String> env = pb.environment();
            // Ruta a los headers (.inc files)
            env.put("GPUTILS_HEADER_PATH", new File(gpUtilsShareDir, "header").getAbsolutePath());
            // Ruta a los linker scripts (.lkr files)
            env.put("GPUTILS_LKR_PATH", new File(gpUtilsShareDir, "lkr").getAbsolutePath());

            Process process = pb.start();

            StringBuilder output = new StringBuilder();
            try (BufferedReader reader = new BufferedReader(
                    new InputStreamReader(process.getInputStream()))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    output.append(line).append("\n");
                }
            }

            int exitCode = process.waitFor();
            Log.d(TAG, "Codigo de salida: " + exitCode);

            if (output.length() == 0) {
                return "Ejecutado con codigo de salida: " + exitCode;
            }

            return output.toString().trim();

        } catch (Exception e) {
            Log.e(TAG, "Error ejecutando " + binaryName + ": " + e.getMessage());
            return "Error: " + e.getMessage();
        }
    }
}
