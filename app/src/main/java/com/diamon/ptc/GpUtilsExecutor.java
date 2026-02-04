package com.diamon.ptc;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.util.Log;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * Clase para ejecutar los binarios de GPUTILS (gpasm, gpdasm, gplink, etc.)
 * Los binarios se extraen del APK y se ejecutan via ProcessBuilder.
 */
public class GpUtilsExecutor {
    private static final String TAG = "GpUtilsExecutor";
    private static final int BUFFER_SIZE = 8192;

    private final Context context;
    private final File workDir;
    private final File binDir;
    private final File gpUtilsShareDir;

    public GpUtilsExecutor(Context context) {
        this.context = context;
        this.workDir = context.getFilesDir();
        this.binDir = new File(workDir, "bin");
        this.gpUtilsShareDir = new File(workDir, "usr/share/gputils");
    }

    /**
     * Extrae los binarios de GPUTILS del APK al directorio de la app.
     * Solo se hace una vez.
     */
    public boolean extractBinaries() {
        if (binDir.exists() && new File(binDir, "gpasm").exists()) {
            Log.d(TAG, "Binarios ya extraidos");
            return true;
        }

        if (!binDir.exists() && !binDir.mkdirs()) {
            Log.e(TAG, "No se pudo crear directorio bin");
            return false;
        }

        try {
            ApplicationInfo appInfo = context.getApplicationInfo();
            String apkPath = appInfo.sourceDir;

            // Determinar la arquitectura del dispositivo
            String abi = android.os.Build.SUPPORTED_ABIS[0];
            String libPath = "lib/" + abi + "/";

            Log.d(TAG, "Extrayendo binarios desde APK, ABI: " + abi);

            try (ZipFile apk = new ZipFile(apkPath)) {
                String[] binaries = { "libgpasm.so", "libgpdasm.so", "libgplib.so",
                        "libgplink.so", "libgpstrip.so", "libgpvc.so", "libgpvo.so" };

                for (String libName : binaries) {
                    ZipEntry entry = apk.getEntry(libPath + libName);
                    if (entry == null) {
                        // Intentar con arm64-v8a si no encuentra la arquitectura exacta
                        entry = apk.getEntry("lib/arm64-v8a/" + libName);
                    }

                    if (entry != null) {
                        // Nombre sin prefijo lib y sin extension .so
                        String binName = libName.substring(3, libName.length() - 3);
                        File outFile = new File(binDir, binName);

                        try (InputStream in = apk.getInputStream(entry);
                                FileOutputStream out = new FileOutputStream(outFile)) {
                            byte[] buffer = new byte[BUFFER_SIZE];
                            int read;
                            while ((read = in.read(buffer)) != -1) {
                                out.write(buffer, 0, read);
                            }
                        }

                        // Hacer el archivo ejecutable
                        outFile.setExecutable(true, false);
                        Log.d(TAG, "Extraido: " + binName);
                    } else {
                        Log.w(TAG, "No se encontro " + libName + " en el APK");
                    }
                }
            }
            return true;

        } catch (IOException e) {
            Log.e(TAG, "Error extrayendo binarios: " + e.getMessage());
            return false;
        }
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
     * @param binaryName Nombre del binario (sin extension)
     * @param args       Argumentos del comando
     * @return Salida del comando
     */
    public String executeBinary(String binaryName, String... args) {
        File binaryFile = new File(binDir, binaryName);

        if (!binaryFile.exists()) {
            return "Error: No se encontro el binario " + binaryFile.getAbsolutePath() +
                    ". Ejecuta extractBinaries() primero.";
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
