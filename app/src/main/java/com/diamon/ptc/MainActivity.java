package com.diamon.ptc;

import android.app.AlertDialog;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.diamon.ptc.databinding.ActivityMainBinding;

import java.io.File;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";
    private static final String ASSETS_PATH = "data/data/com.diamon.ptc/files/usr/share";
    private static final String DEFAULT_ASM = "; Código de prueba para PIC\n" +
            "    PROCESSOR 16F84A\n" +
            "    INCLUDE \"P16F84A.INC\"\n" +
            "\n" +
            "    ORG 0x00\n" +
            "START:\n" +
            "    MOVLW 0xFF\n" +
            "    MOVWF PORTB\n" +
            "    GOTO START\n" +
            "    END";

    private ActivityMainBinding binding;
    private final ExecutorService executor = Executors.newSingleThreadExecutor();
    private final Handler mainHandler = new Handler(Looper.getMainLooper());
    private GpUtilsExecutor gpUtils;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        setSupportActionBar(binding.toolbar);

        gpUtils = new GpUtilsExecutor(this);
        binding.editAsm.setText(DEFAULT_ASM);

        setupListeners();
        initResources();
    }

    @Override
    public boolean onCreateOptionsMenu(android.view.Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(android.view.MenuItem item) {
        int id = item.getItemId();
        if (id == R.id.action_clear_logs) {
            binding.textLogs.setText("Logs limpiados.");
            return true;
        } else if (id == R.id.action_clear_editor) {
            confirmClearEditor();
            return true;
        } else if (id == R.id.action_about) {
            showAboutDialog();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    private void confirmClearEditor() {
        new AlertDialog.Builder(this)
                .setTitle("Limpiar Editor")
                .setMessage("¿Estás seguro de que deseas borrar todo el código?")
                .setPositiveButton("Sí, borrar", (dialog, which) -> binding.editAsm.setText(""))
                .setNegativeButton("Cancelar", null)
                .show();
    }

    private void showAboutDialog() {
        String message = "<b>C-PIC Assembler</b><br><br>" +
                "Esta aplicación es una interfaz para el conjunto de herramientas <b>GPUTILS</b>.<br><br>" +
                "<b>Licencia:</b><br>" +
                "Este proyecto y los binarios incluidos de GPUTILS están bajo la licencia <b>GNU GPL v3.0</b>.<br><br>"
                +
                "GPUTILS es un conjunto de herramientas de código abierto para microcontroladores Microchip PIC.<br><br>"
                +
                "Puedes encontrar el código fuente de GPUTILS en: <a href='https://gputils.sourceforge.io/'>gputils.sourceforge.io</a>";

        new AlertDialog.Builder(this)
                .setTitle("Acerca de / Licencia")
                .setMessage(android.text.Html.fromHtml(message, android.text.Html.FROM_HTML_MODE_COMPACT))
                .setPositiveButton("Cerrar", null)
                .show();
    }

    private void setupListeners() {
        binding.btnAssemble.setOnClickListener(v -> assembleCode());
        binding.btnViewHex.setOnClickListener(v -> viewGeneratedFile("project.hex"));
        binding.btnExport.setOnClickListener(v -> exportFiles());
    }

    private void initResources() {
        executor.execute(() -> {
            if (!AssetExtractor.areAssetsExtracted(this)) {
                updateLogs("Preparando recursos de GPUTILS (esto solo ocurre una vez)...");
                boolean success = AssetExtractor.extractAssets(
                        this,
                        ASSETS_PATH,
                        new File(getFilesDir(), "usr/share"));

                if (success) {
                    updateLogs("Recursos listos.");
                } else {
                    updateLogs("Error al preparar recursos.");
                }
            } else {
                updateLogs("Sistema listo. GPUTILS cargado correctamente.");
            }
        });
    }

    private void assembleCode() {
        String code = binding.editAsm.getText().toString();
        if (code.trim().isEmpty()) {
            Toast.makeText(this, "Escribe código primero", Toast.LENGTH_SHORT).show();
            return;
        }

        updateLogs("Iniciando ensamblado...");
        executor.execute(() -> {
            // 1. Guardar archivo ASM
            if (FileManager.writeInternalFile(this, "project.asm", code)) {
                // 2. Ejecutar GPASM
                // Argumentos: -c (crear objeto), -p (procesador), etc.
                // Usamos el nombre del archivo directamente
                String result = gpUtils.executeGpasm("project.asm");

                updateLogs("Log de compilación:\n" + result);

                // Verificar si se generó el hex
                File hexFile = new File(getFilesDir(), "project.hex");
                if (hexFile.exists()) {
                    mainHandler.post(
                            () -> Toast.makeText(MainActivity.this, "¡Ensamblado exitoso!", Toast.LENGTH_LONG).show());
                } else {
                    mainHandler.post(() -> Toast
                            .makeText(MainActivity.this, "Ensamblado fallido. Revisa los logs.", Toast.LENGTH_LONG)
                            .show());
                }
            } else {
                updateLogs("Error: No se pudo guardar el archivo ASM.");
            }
        });
    }

    private void viewGeneratedFile(String fileName) {
        String content = FileManager.readInternalFile(this, fileName);
        if (content.isEmpty()) {
            Toast.makeText(this, "Archivo no encontrado o vacío.", Toast.LENGTH_SHORT).show();
            return;
        }

        AlertDialog.Builder builder = new AlertDialog.Builder(this,
                android.R.style.Theme_DeviceDefault_NoActionBar_Fullscreen);
        View dialogView = LayoutInflater.from(this).inflate(R.layout.activity_main, null);
        // Podríamos crear un layout específico para el visor, pero por ahora reusaremos
        // o solo mostraremos texto

        TextView textView = new TextView(this);
        textView.setText(content);
        textView.setPadding(32, 32, 32, 32);
        textView.setBackgroundColor(0xFF121212);
        textView.setTextColor(0xFFE0E0E0);
        textView.setTypeface(android.graphics.Typeface.MONOSPACE);

        builder.setTitle(fileName)
                .setView(textView)
                .setPositiveButton("Cerrar", null)
                .show();
    }

    private void exportFiles() {
        executor.execute(() -> {
            boolean hexSuccess = FileManager.exportToDownloads(this, "project.hex");
            boolean lstSuccess = FileManager.exportToDownloads(this, "project.lst");

            mainHandler.post(() -> {
                if (hexSuccess) {
                    new AlertDialog.Builder(this)
                            .setTitle("Exportación Exitosa")
                            .setMessage("Archivos guardados en Descargas/C-PIC.\n\n¿Deseas abrir la carpeta?")
                            .setPositiveButton("Abrir Carpeta", (dialog, which) -> openDownloadsFolder())
                            .setNegativeButton("Cerrar", null)
                            .show();
                } else {
                    Toast.makeText(this, "No hay archivos para exportar (Ensambla primero)", Toast.LENGTH_SHORT).show();
                }
            });
        });
    }

    private void openDownloadsFolder() {
        android.content.Intent intent = new android.content.Intent(android.app.DownloadManager.ACTION_VIEW_DOWNLOADS);
        intent.addFlags(android.content.Intent.FLAG_ACTIVITY_NEW_TASK);
        try {
            startActivity(intent);
        } catch (Exception e) {
            Toast.makeText(this, "No se pudo abrir el administrador de archivos", Toast.LENGTH_SHORT).show();
        }
    }

    private void updateLogs(String text) {
        mainHandler.post(() -> {
            String current = binding.textLogs.getText().toString();
            binding.textLogs.setText(current + "\n> " + text);
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        executor.shutdown();
    }
}