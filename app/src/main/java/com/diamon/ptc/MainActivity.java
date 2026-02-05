package com.diamon.ptc;

import android.app.AlertDialog;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.PopupWindow;
import android.view.Gravity;
import android.view.ViewGroup;
import android.content.Intent;
import android.net.Uri;
import androidx.documentfile.provider.DocumentFile;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;
import java.util.Collections;

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

    private static final String DEFAULT_C = "#include <pic14/pic16f84a.h>\n\n" +
            "// Ejemplo basico para PIC16F84A\n" +
            "void main(void) {\n" +
            "    TRISB = 0x00; // Puerto B como salida\n" +
            "    while(1) {\n" +
            "        PORTB = 0xFF;\n" +
            "        for(unsigned int i=0; i<1000; i++); // Retardo\n" +
            "        PORTB = 0x00;\n" +
            "        for(unsigned int i=0; i<1000; i++);\n" +
            "    }\n" +
            "}";

    private ActivityMainBinding binding;
    private final ExecutorService executor = Executors.newFixedThreadPool(4);
    private final Handler mainHandler = new Handler(Looper.getMainLooper());
    private GpUtilsExecutor gpUtils;
    private SdccExecutor sdcc;
    private androidx.activity.result.ActivityResultLauncher<android.net.Uri> folderPickerLauncher;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        setSupportActionBar(binding.toolbar);

        folderPickerLauncher = registerForActivityResult(
                new androidx.activity.result.contract.ActivityResultContracts.OpenDocumentTree(),
                uri -> {
                    if (uri != null) {
                        exportToSelectedFolder(uri);
                    }
                });

        gpUtils = new GpUtilsExecutor(this);
        sdcc = new SdccExecutor(this);
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

        binding.toggleLanguage.addOnButtonCheckedListener((group, checkedId, isChecked) -> {
            if (isChecked) {
                if (checkedId == R.id.btn_lang_asm) {
                    binding.editAsm.setText(DEFAULT_ASM);
                    updateLogs("Modo: Ensamblador (ASM)");
                } else if (checkedId == R.id.btn_lang_c) {
                    binding.editAsm.setText(DEFAULT_C);
                    updateLogs("Modo: Lenguaje C (SDCC)");
                }
            }
        });
    }

    private void initResources() {
        executor.execute(() -> {
            boolean extracted = AssetExtractor.areAssetsExtracted(this);
            if (!extracted) {
                updateLogs("Preparando recursos (GPUTILS + SDCC)...");

                // Extraer estructura usr completa (bin, libexec, share)
                String usrAssetsPath = "data/data/com.diamon.ptc/files/usr";
                boolean success = AssetExtractor.extractAssets(this, usrAssetsPath, new File(getFilesDir(), "usr"));

                // Limpieza: eliminar bín antiguo si existe (está ahora en usr/bin)
                File oldBin = new File(getFilesDir(), "bin");
                if (oldBin.exists()) {
                    deleteRecursive(oldBin);
                }

                if (success) {
                    updateLogs("Recursos extraídos correctamente.");
                    loadPicList();
                } else {
                    updateLogs("Error al extraer recursos. Revisa el espacio en disco.");
                }
            } else {
                updateLogs("Sistema listo. GPUTILS y SDCC cargados.");
                loadPicList();
            }
        });
    }

    private void loadPicList() {
        File headerDir = new File(getFilesDir(), "usr/share/gputils/header");
        if (!headerDir.exists())
            return;

        String[] files = headerDir.list();
        java.util.List<String> pics = new java.util.ArrayList<>();

        if (files != null) {
            for (String file : files) {
                if (file.toLowerCase().endsWith(".inc")) {
                    String name = file.substring(0, file.length() - 4);
                    if (name.toLowerCase().startsWith("p")) {
                        name = name.substring(1);
                    }
                    pics.add(name.toUpperCase());
                }
            }
            java.util.Collections.sort(pics);
        }

        if (pics.isEmpty()) {
            pics.add("16F84A");
        }

        mainHandler.post(() -> {
            android.widget.ArrayAdapter<String> adapter = new android.widget.ArrayAdapter<>(
                    this, android.R.layout.simple_spinner_item, pics);
            adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            binding.spinnerPic.setAdapter(adapter);

            int index = pics.indexOf("16F84A");
            if (index != -1)
                binding.spinnerPic.setSelection(index);
        });
    }

    private void assembleCode() {
        String code = binding.editAsm.getText().toString();
        if (code.trim().isEmpty()) {
            updateLogs("Error: Escribe código primero");
            return;
        }

        String selectedPic = binding.spinnerPic.getSelectedItem() != null
                ? binding.spinnerPic.getSelectedItem().toString()
                : "16F84A";

        boolean isC = binding.toggleLanguage.getCheckedButtonId() == R.id.btn_lang_c;

        if (isC) {
            compileCCode(code, selectedPic);
        } else {
            runGpasm(code, selectedPic);
        }
    }

    private void runGpasm(String code, String selectedPic) {
        updateLogs("Iniciando ensamblado ASM para " + selectedPic + "...");
        executor.execute(() -> {
            // 1. Guardar archivo ASM
            if (FileManager.writeInternalFile(this, "project.asm", code)) {
                // 2. Ejecutar GPASM
                String result = gpUtils.executeGpasm("-p", selectedPic.toLowerCase(), "project.asm");
                updateLogs("Log de GPASM:\n" + result);

                checkGenerationSuccess("project.hex");
            } else {
                updateLogs("Error: No se pudo guardar el archivo ASM.");
            }
        });
    }

    private void compileCCode(String code, String selectedPic) {
        updateLogs("Iniciando compilación C (SDCC) para " + selectedPic + "...");
        executor.execute(() -> {
            // 1. Guardar archivo C
            if (FileManager.writeInternalFile(this, "project.c", code)) {
                // 2. Determinar arquitectura (pic14 para 16F, pic16 para 18F)
                String arch = selectedPic.toUpperCase().startsWith("18") ? "pic16" : "pic14";

                // 3. Ejecutar SDCC
                // --use-non-free es necesario para muchos PICs en SDCC
                String result = sdcc.executeSdcc(
                        "-m" + arch,
                        "-p" + selectedPic.toLowerCase(),
                        "--use-non-free",
                        "project.c");

                updateLogs("Log de SDCC:\n" + result);

                checkGenerationSuccess("project.hex");
            } else {
                updateLogs("Error: No se pudo guardar el archivo C.");
            }
        });
    }

    private void checkGenerationSuccess(String fileName) {
        File file = new File(getFilesDir(), fileName);
        mainHandler.post(() -> {
            if (file.exists()) {
                updateLogs("¡Operación exitosa! Archivo generado: " + fileName);
            } else {
                updateLogs("Compilación/Ensamblado fallido. Revisa los logs.");
            }
        });
    }

    private void viewGeneratedFile(String fileName) {
        String content = FileManager.readInternalFile(this, fileName);
        if (content.isEmpty()) {
            updateLogs("Error: Archivo no encontrado o vacío: " + fileName);
            return;
        }

        if (fileName.toLowerCase().endsWith(".hex")) {
            showAdvancedHexViewer(content);
        } else {
            showSimpleTextViewer(fileName, content);
        }
    }

    private void showSimpleTextViewer(String title, String content) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        TextView textView = new TextView(this);
        textView.setText(content);
        textView.setPadding(32, 32, 32, 32);
        textView.setTextSize(12);
        textView.setBackgroundColor(0xFF0A0A0B);
        textView.setTextColor(0xFFE0E0E0);
        textView.setTypeface(android.graphics.Typeface.MONOSPACE);

        builder.setTitle(title)
                .setView(textView)
                .setPositiveButton("Cerrar", null)
                .show();
    }

    private void showAdvancedHexViewer(String hexContent) {
        TreeMap<Integer, Byte> memory = IntelHexParser.parse(hexContent);
        if (memory.isEmpty()) {
            updateLogs("Error: No se pudo parsear el archivo HEX o está mal formado.");
            return;
        }

        View popupView = getLayoutInflater().inflate(R.layout.popup_hex_viewer, null);
        PopupWindow popupWindow = new PopupWindow(popupView,
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.MATCH_PARENT, true);

        ListView listView = popupView.findViewById(R.id.list_hex);
        List<Integer> addresses = new ArrayList<>(memory.keySet());
        List<String[]> rows = new ArrayList<>();

        for (int i = 0; i < addresses.size(); i += 2) {
            int addr = addresses.get(i);
            byte b1 = memory.get(addr);
            byte b2 = (i + 1 < addresses.size()) ? memory.get(addresses.get(i + 1)) : 0;

            // Little Endian: b2 (high), b1 (low)
            String hexStr = String.format("%02X%02X", b2 & 0xFF, b1 & 0xFF);
            StringBuilder ansi = new StringBuilder();
            ansi.append((b1 >= 32 && b1 <= 126) ? (char) b1 : '.');
            if (i + 1 < addresses.size())
                ansi.append((b2 >= 32 && b2 <= 126) ? (char) b2 : '.');

            rows.add(new String[] { String.format("%04X", addr), hexStr, ansi.toString() });
        }

        listView.setAdapter(new BaseAdapter() {
            @Override
            public int getCount() {
                return rows.size();
            }

            @Override
            public Object getItem(int position) {
                return rows.get(position);
            }

            @Override
            public long getItemId(int position) {
                return position;
            }

            @Override
            public View getView(int position, View convertView, ViewGroup parent) {
                if (convertView == null)
                    convertView = getLayoutInflater().inflate(R.layout.item_hex_row, parent, false);
                String[] data = rows.get(position);
                ((TextView) convertView.findViewById(R.id.tv_addr)).setText(data[0]);
                ((TextView) convertView.findViewById(R.id.tv_hex)).setText(data[1]);
                ((TextView) convertView.findViewById(R.id.tv_ansi)).setText(data[2]);
                return convertView;
            }
        });

        popupView.findViewById(R.id.btn_close_popup).setOnClickListener(v -> popupWindow.dismiss());
        popupWindow.showAtLocation(binding.getRoot(), Gravity.CENTER, 0, 0);
    }

    private void exportFiles() {
        folderPickerLauncher.launch(null);
    }

    private void exportToSelectedFolder(Uri treeUri) {
        executor.execute(() -> {
            String[] filesToExport = { "project.hex", "project.lst", "project.err", "project.cod", "project.asm" };
            int count = 0;

            for (String fileName : filesToExport) {
                File file = new File(getFilesDir(), fileName);
                if (file.exists()) {
                    if (saveFileToDocumentTree(treeUri, fileName, file)) {
                        count++;
                    }
                }
            }

            final int finalCount = count;
            mainHandler.post(() -> {
                if (finalCount > 0) {
                    updateLogs("¡Exportación exitosa! " + finalCount + " archivos guardados.");
                } else {
                    updateLogs("No se encontraron archivos para exportar.");
                }
            });
        });
    }

    private boolean saveFileToDocumentTree(Uri treeUri, String displayName, File sourceFile) {
        try {
            DocumentFile root = DocumentFile.fromTreeUri(this, treeUri);
            if (root == null)
                return false;

            DocumentFile file = root.findFile(displayName);
            if (file == null) {
                file = root.createFile("*/*", displayName);
            }

            if (file != null) {
                try (InputStream in = new FileInputStream(sourceFile);
                        OutputStream out = getContentResolver().openOutputStream(file.getUri())) {
                    byte[] buffer = new byte[1024];
                    int len;
                    while ((len = in.read(buffer)) > 0) {
                        out.write(buffer, 0, len);
                    }
                    return true;
                }
            }
        } catch (Exception e) {
            Log.e(TAG, "Error guardando archivo", e);
        }
        return false;
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

    private void deleteRecursive(File fileOrDirectory) {
        if (fileOrDirectory.isDirectory()) {
            for (File child : fileOrDirectory.listFiles()) {
                deleteRecursive(child);
            }
        }
        fileOrDirectory.delete();
    }
}
