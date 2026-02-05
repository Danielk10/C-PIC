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
 * Ejecutor para el compilador SDCC.
 */
public class SdccExecutor {
    private static final String TAG = "SdccExecutor";

    private final Context context;
    private final File workDir;
    private final File nativeLibDir;
    private final File sdccShareDir;
    private final File gpUtilsShareDir;

    public SdccExecutor(Context context) {
        this.context = context;
        this.workDir = context.getFilesDir();
        this.nativeLibDir = new File(context.getApplicationInfo().nativeLibraryDir);
        this.sdccShareDir = new File(workDir, "usr/share/sdcc");
        this.gpUtilsShareDir = new File(workDir, "usr/share/gputils");
    }

    /**
     * Ejecuta sdcc con los argumentos especificados.
     *
     * @param args Argumentos para sdcc
     * @return Salida del comando
     */
    public String executeSdcc(String... args) {
        return executeBinary("sdcc", args);
    }

    /**
     * Ejecuta un binario de SDCC.
     */
    public String executeBinary(String binaryName, String... args) {
        File binaryFile = new File(nativeLibDir, "lib" + binaryName + ".so");

        if (!binaryFile.exists()) {
            return "Error: No se encontro el binario " + binaryFile.getAbsolutePath();
        }

        List<String> command = new ArrayList<>();
        command.add(binaryFile.getAbsolutePath());

        // Agregar rutas por defecto de SDCC si no estan
        command.add("-I" + new File(sdccShareDir, "include").getAbsolutePath());
        command.add("-I" + new File(sdccShareDir, "non-free/include").getAbsolutePath());
        command.add("-L" + new File(sdccShareDir, "lib").getAbsolutePath());
        command.add("-L" + new File(sdccShareDir, "non-free/lib").getAbsolutePath());

        // Apuntar a los binarios de GPUTILS que ahora se llaman lib*.so
        command.add("--asm=" + new File(nativeLibDir, "libgpasm.so").getAbsolutePath());
        command.add("--aslink=" + new File(nativeLibDir, "libgplink.so").getAbsolutePath());

        for (String arg : args) {
            command.add(arg);
        }

        Log.d(TAG, "Ejecutando SDCC: " + String.join(" ", command));

        setupSymlinks();

        try {
            ProcessBuilder pb = new ProcessBuilder(command);
            pb.directory(workDir);
            pb.redirectErrorStream(true);

            Map<String, String> env = pb.environment();

            // Configurar SDCC_HOME para que encuentre libexec/ y bin/
            env.put("SDCC_HOME", new File(workDir, "usr").getAbsolutePath());

            // SDCC usa internamente cc1 (libcc1.so)
            // Necesitamos que el sistema encuentre las librerias nativas
            env.put("LD_LIBRARY_PATH", nativeLibDir.getAbsolutePath());

            // Tambien rutas de GPUTILS ya que SDCC las invoca
            env.put("GPUTILS_HEADER_PATH", new File(gpUtilsShareDir, "header").getAbsolutePath());
            env.put("GPUTILS_LKR_PATH", new File(gpUtilsShareDir, "lkr").getAbsolutePath());

            // Intentar agregar jniLibs al PATH para que SDCC encuentre sus componentes
            String path = env.get("PATH");
            String binPath = new File(workDir, "usr/bin").getAbsolutePath();
            env.put("PATH", binPath + ":" + nativeLibDir.getAbsolutePath() + (path != null ? ":" + path : ""));

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
            Log.d(TAG, "SDCC Exit Code: " + exitCode);

            return output.toString().trim();

        } catch (Exception e) {
            Log.e(TAG, "Error ejecutando SDCC: " + e.getMessage());
            return "Error: " + e.getMessage();
        }
    }

    /**
     * Crea enlaces simbolicos para que SDCC encuentre sus componentes internos
     * (cc1, sdcpp)
     * que han sido renombrados a lib*.so.
     */
    private void setupSymlinks() {
        try {
            File usrDir = new File(workDir, "usr");
            File libexecBase = new File(usrDir, "libexec/sdcc/aarch64-unknown-linux-gnu/12.1.0");
            if (!libexecBase.exists()) {
                if (!libexecBase.mkdirs()) {
                    Log.e(TAG, "No se pudo crear directorio libexec: " + libexecBase.getAbsolutePath());
                }
            }

            // Enlace para cc1
            File cc1Symlink = new File(libexecBase, "cc1");
            if (!cc1Symlink.exists()) {
                android.system.Os.symlink(
                        new File(nativeLibDir, "libcc1.so").getAbsolutePath(),
                        cc1Symlink.getAbsolutePath());
                Log.d(TAG, "Symlink creado: cc1 -> libcc1.so");
            }

            // Enlace para sdcpp en usr/bin
            File binDir = new File(usrDir, "bin");
            if (!binDir.exists())
                binDir.mkdirs();

            File sdcppSymlink = new File(binDir, "sdcpp");
            if (!sdcppSymlink.exists()) {
                android.system.Os.symlink(
                        new File(nativeLibDir, "libsdcpp.so").getAbsolutePath(),
                        sdcppSymlink.getAbsolutePath());
                Log.d(TAG, "Symlink creado: sdcpp -> libsdcpp.so");
            }

        } catch (Exception e) {
            Log.e(TAG, "Error al configurar symlinks: " + e.getMessage());
        }
    }
}
