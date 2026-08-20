package com.diamon.ptc;

import android.content.Context;
import android.util.Log;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Clase para ejecutar los binarios de GPUTILS (gpasm, gpdasm, gplink, etc.).
 */
public class GpUtilsExecutor {
    private static final String TAG = "GpUtilsExecutor";

    private final File workDir;
    private final File nativeLibDir;
    private final File gpUtilsShareDir;

    public GpUtilsExecutor(Context context) {
        this.workDir = context.getFilesDir();
        this.nativeLibDir = new File(context.getApplicationInfo().nativeLibraryDir);
        this.gpUtilsShareDir = new File(workDir, "usr/share/gputils");
    }

    public interface ProcessListener {
        void onProcessOutput(String chunk);
    }

    public int executeGpasmStreaming(File workingDir, List<String> visibleArgs, List<String> extraArgs, ProcessListener listener) {
        return executeBinaryStreaming(workingDir, "gpasm", visibleArgs, extraArgs, listener);
    }

    public int executeGplinkStreaming(File workingDir, List<String> visibleArgs, List<String> extraArgs, ProcessListener listener) {
        return executeBinaryStreaming(workingDir, "gplink", visibleArgs, extraArgs, listener);
    }

    public int executeBinaryStreaming(File workingDir, String binaryName, List<String> visibleArgs, List<String> extraArgs, ProcessListener listener) {
        File binaryFile = new File(nativeLibDir, "lib" + binaryName + ".so");
        if (!binaryFile.exists()) {
            String err = "Error: No se encontro el binario " + binaryFile.getAbsolutePath() + "\n";
            Log.e(TAG, err);
            if (listener != null) listener.onProcessOutput(err);
            return -1;
        }

        setupSymlinks();

        List<String> command = new ArrayList<>();
        command.add(binaryFile.getAbsolutePath());
        if (extraArgs != null) {
            command.addAll(extraArgs);
        }
        if (visibleArgs != null) {
            command.addAll(visibleArgs);
        }

        try {
            ProcessBuilder pb = new ProcessBuilder(command);
            pb.directory(workingDir != null ? workingDir : workDir);
            pb.redirectErrorStream(true);

            Map<String, String> env = pb.environment();
            env.put("GPUTILS_HEADER_PATH", new File(gpUtilsShareDir, "header").getAbsolutePath());
            env.put("GPUTILS_LKR_PATH", new File(gpUtilsShareDir, "lkr").getAbsolutePath());
            env.put("LD_LIBRARY_PATH", nativeLibDir.getAbsolutePath() + ":" + new File(workDir, "usr/lib").getAbsolutePath());

            String path = env.get("PATH");
            String binPath = new File(workDir, "usr/bin").getAbsolutePath();
            env.put("PATH", binPath + ":" + nativeLibDir.getAbsolutePath() + (path != null ? ":" + path : ""));

            Process process = pb.start();

            try (java.io.InputStream in = process.getInputStream();
                 InputStreamReader reader = new InputStreamReader(in, java.nio.charset.StandardCharsets.UTF_8)) {
                char[] buffer = new char[512];
                int read;
                while ((read = reader.read(buffer)) != -1) {
                    String chunk = new String(buffer, 0, read);
                    if (listener != null) {
                        listener.onProcessOutput(chunk);
                    }
                }
            }

            return process.waitFor();
        } catch (Exception e) {
            Log.e(TAG, "Error ejecutando " + binaryName + ": " + e.getMessage(), e);
            if (listener != null) {
                listener.onProcessOutput("Error: " + e.getMessage() + "\n");
            }
            return -1;
        }
    }

    public String executeGpasm(String... args) {
        return executeBinary(workDir, "gpasm", args);
    }

    public String executeGpasm(File workingDir, String... args) {
        return executeBinary(workingDir, "gpasm", args);
    }

    public String executeGpdasm(String... args) {
        return executeBinary(workDir, "gpdasm", args);
    }

    public String executeGplink(String... args) {
        return executeBinary(workDir, "gplink", args);
    }

    public String executeGplib(String... args) {
        return executeBinary(workDir, "gplib", args);
    }

    public String executeBinary(String binaryName, String... args) {
        return executeBinary(workDir, binaryName, args);
    }

    public String executeBinary(File workingDir, String binaryName, String... args) {
        File binaryFile = new File(nativeLibDir, "lib" + binaryName + ".so");

        if (!binaryFile.exists()) {
            String[] files = nativeLibDir.list();
            String available = files != null ? String.join(", ", files) : "ninguno";
            Log.e(TAG, "Binario no encontrado: " + binaryFile.getAbsolutePath());
            return "Error: No se encontro el binario " + binaryFile.getAbsolutePath() + "\nDisponibles: " + available;
        }

        setupSymlinks();

        List<String> command = new ArrayList<>();
        command.add(binaryFile.getAbsolutePath());
        for (String arg : args) {
            command.add(arg);
        }

        Log.d(TAG, "Ejecutando: " + String.join(" ", command));

        try {
            ProcessBuilder pb = new ProcessBuilder(command);
            pb.directory(workingDir);
            pb.redirectErrorStream(true);

            Map<String, String> env = pb.environment();
            env.put("GPUTILS_HEADER_PATH", new File(gpUtilsShareDir, "header").getAbsolutePath());
            env.put("GPUTILS_LKR_PATH", new File(gpUtilsShareDir, "lkr").getAbsolutePath());
            env.put("LD_LIBRARY_PATH", nativeLibDir.getAbsolutePath() + ":" + new File(workDir, "usr/lib").getAbsolutePath());

            String path = env.get("PATH");
            String binPath = new File(workDir, "usr/bin").getAbsolutePath();
            env.put("PATH", binPath + ":" + nativeLibDir.getAbsolutePath() + (path != null ? ":" + path : ""));

            Process process = pb.start();
            StringBuilder output = new StringBuilder();

            try (BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    output.append(line).append("\n");
                    Log.d(TAG, binaryName + " > " + line);
                }
            }

            int exitCode = process.waitFor();
            Log.d(TAG, "Codigo de salida: " + exitCode);

            String result = output.toString().trim();
            StringBuilder fullLog = new StringBuilder();
            fullLog.append("Comando: ").append(String.join(" ", command)).append("\n");
            fullLog.append("Código de salida: ").append(exitCode);
            if (!result.isEmpty()) {
                fullLog.append("\n").append(result);
            }
            return fullLog.toString().trim();

        } catch (Exception e) {
            Log.e(TAG, "Error ejecutando " + binaryName + ": " + e.getMessage());
            return "Error: " + e.getMessage();
        }
    }

    public List<String> getSetupIssues() {
        List<String> issues = new ArrayList<>();
        if (!new File(nativeLibDir, "libgpasm.so").exists()) {
            issues.add("Falta libgpasm.so en jniLibs");
        }
        if (!new File(gpUtilsShareDir, "header").exists()) {
            issues.add("Falta carpeta de headers gputils (usr/share/gputils/header)");
        }
        if (!new File(gpUtilsShareDir, "lkr").exists()) {
            issues.add("Falta carpeta lkr gputils (usr/share/gputils/lkr)");
        }
        return issues;
    }

    public void setupSymlinks() {
        try {
            File usrDir = new File(workDir, "usr");
            File binDir = new File(usrDir, "bin");
            if (!binDir.exists()) binDir.mkdirs();

            File libDir = new File(usrDir, "lib");
            if (!libDir.exists()) libDir.mkdirs();

            File[] nativeFiles = nativeLibDir.listFiles();
            if (nativeFiles != null) {
                for (File file : nativeFiles) {
                    String name = file.getName();
                    if (name.startsWith("lib") && name.endsWith(".so")) {
                        String baseName = name.substring(3, name.length() - 3);
                        if (!isSharedLibrary(baseName)) {
                            createSymlink(new File(binDir, baseName), file.getAbsolutePath());
                        }
                    }
                }
            }

            linkSharedLib(libDir, "libncursesw.so", "libncursesw.so.6");
            linkSharedLib(libDir, "libpanelw.so", "libpanelw.so.6");
            linkSharedLib(libDir, "libreadline.so", "libreadline.so.8");
            linkSharedLib(libDir, "libzstd.so", "libzstd.so.1");

            String targetZ = new File("/system/lib64/libz.so").exists() ? "/system/lib64/libz.so" : "/system/lib/libz.so";
            File localZ = new File(nativeLibDir, "libz.so");
            createSymlink(new File(libDir, "libz.so.1"), localZ.exists() ? localZ.getAbsolutePath() : targetZ);

            linkSharedLib(libDir, "libiconv.so", "libiconv.so");
            linkSharedLib(libDir, "libisl.so", "libisl.so");
            linkSharedLib(libDir, "libgmp.so", "libgmp.so");
            linkSharedLib(libDir, "libgc.so", "libgc.so");
            linkSharedLib(libDir, "libfl.so", "libfl.so");
            linkSharedLib(libDir, "libandroid-support.so", "libandroid-support.so");
            linkSharedLib(libDir, "libc++_shared.so", "libc++_shared.so");
        } catch (Exception e) {
            Log.e(TAG, "Error al configurar symlinks en GpUtilsExecutor: " + e.getMessage());
        }
    }

    private boolean isSharedLibrary(String name) {
        return name.equals("android-support") || name.equals("c++_shared") || name.equals("fl")
                || name.equals("gc") || name.equals("gmp") || name.equals("iconv") || name.equals("isl")
                || name.equals("ncursesw") || name.equals("panelw") || name.equals("readline")
                || name.equals("z") || name.equals("zstd") || name.equals("ptc");
    }

    private void linkSharedLib(File libDir, String libName, String symlinkName) {
        File target = new File(nativeLibDir, libName);
        if (target.exists()) {
            createSymlink(new File(libDir, symlinkName), target.getAbsolutePath());
            if (!symlinkName.equals(libName)) {
                createSymlink(new File(libDir, libName), target.getAbsolutePath());
            }
        }
    }

    private void createSymlink(File symlink, String targetPath) {
        try {
            if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
                if (symlink.exists() || Files.isSymbolicLink(symlink.toPath())) {
                    symlink.delete();
                }
            } else {
                symlink.delete();
            }
            android.system.Os.symlink(targetPath, symlink.getAbsolutePath());
            Log.d(TAG, "Symlink creado: " + symlink.getName() + " -> " + targetPath);
        } catch (Exception e) {
            Log.e(TAG, "Error al crear enlace " + symlink.getName() + ": " + e.getMessage());
        }
    }
}
