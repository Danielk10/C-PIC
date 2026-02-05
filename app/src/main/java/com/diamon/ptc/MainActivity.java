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
import com.diamon.ptc.policy.PolicyActivity;

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

    private static final String PREFS_NAME = "CPicPrefs";
    private static final String KEY_EXPORT_URI = "export_uri";
    private static final String KEY_ASM_COUNTER = "asm_counter";
    private static final String KEY_C_COUNTER = "c_counter";

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
                        saveExportUri(uri);
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
        } else if (id == R.id.action_policy) {
            startActivity(new Intent(this, PolicyActivity.class));
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

    @SuppressWarnings("deprecation")
    private void showAboutDialog() {
        String message = "<b>C PIC Compiler</b><br><br>" +
                "Esta aplicación es una interfaz gráfica (GUI) profesional para las herramientas <b>GPUTILS</b> y <b>SDCC</b>.<br><br>"
                +
                "<b>GPUTILS:</b><br>" +
                "Colección de herramientas de código abierto para microcontroladores Microchip PIC.<br>" +
                "Sitio web: <a href='https://sourceforge.net/projects/gputils/'>sourceforge.net/projects/gputils/</a><br><br>"
                +
                "<b>SDCC (Small Device C Compiler):</b><br>" +
                "Compilador de C para microcontroladores de 8 bits.<br>" +
                "Sitio web: <a href='https://sourceforge.net/projects/sdcc/'>sourceforge.net/projects/sdcc/</a><br><br>"
                +
                "<b>Licencia del Proyecto:</b><br>" +
                "C-PIC-Compiler es software libre y está bajo la licencia <b>GNU GPL v3.0</b>.<br><br>" +
                "Los binarios incluidos de GPUTILS y SDCC también se distribuyen bajo sus propias licencias GPL.";

        AlertDialog dialog = new AlertDialog.Builder(this)
                .setTitle("Acerca de / Licencias")
                .setMessage(android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.N
                        ? android.text.Html.fromHtml(message, android.text.Html.FROM_HTML_MODE_COMPACT)
                        : android.text.Html.fromHtml(message))
                .setPositiveButton("Cerrar", null)
                .show();

        // Hacer que los enlaces sean clickeables
        TextView textView = dialog.findViewById(android.R.id.message);
        if (textView != null) {
            textView.setMovementMethod(android.text.method.LinkMovementMethod.getInstance());
        }
    }

    private void setupListeners() {
        binding.btnAssemble.setOnClickListener(v -> assembleCode());
        binding.btnViewHex.setOnClickListener(v -> {
            viewGeneratedFile(getFinalProjectName() + ".hex");
        });
        binding.btnExport.setOnClickListener(v -> exportFiles());

        binding.toggleLanguage.addOnButtonCheckedListener((group, checkedId, isChecked) -> {
            if (isChecked) {
                String currentName = binding.editProjectName.getText().toString();
                if (checkedId == binding.btnLangAsm.getId()) {
                    binding.editAsm.setText(DEFAULT_ASM);
                    binding.btnAssemble.setText("ENSAMBLAR");
                    if (currentName.startsWith("c_project"))
                        binding.editProjectName.setText("");
                    updateLogs("Modo: Ensamblador (ASM)");
                } else if (checkedId == binding.btnLangC.getId()) {
                    binding.editAsm.setText(DEFAULT_C);
                    binding.btnAssemble.setText("COMPILAR");
                    if (currentName.startsWith("asm_project"))
                        binding.editProjectName.setText("");
                    updateLogs("Modo: Lenguaje C (SDCC)");
                }
            }
        });
    }

    private void saveExportUri(android.net.Uri uri) {
        getContentResolver().takePersistableUriPermission(uri,
                android.content.Intent.FLAG_GRANT_READ_URI_PERMISSION |
                        android.content.Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
        getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                .edit()
                .putString(KEY_EXPORT_URI, uri.toString())
                .apply();
    }

    private android.net.Uri getSavedExportUri() {
        String uriString = getSharedPreferences(PREFS_NAME, MODE_PRIVATE).getString(KEY_EXPORT_URI, null);
        if (uriString != null) {
            return android.net.Uri.parse(uriString);
        }
        return null;
    }

    private void initResources() {
        executor.execute(() -> {
            boolean extracted = AssetExtractor.areAssetsExtracted(this);
            if (!extracted) {
                mainHandler.post(() -> binding.loadingOverlay.setVisibility(android.view.View.VISIBLE));
                updateLogs("Preparando recursos (GPUTILS + SDCC)...");

                // Extraer estructura usr completa (bin, libexec, share)
                String usrAssetsPath = "data/data/com.diamon.ptc/files/usr";
                boolean success = AssetExtractor.extractAssets(this, usrAssetsPath, new File(getFilesDir(), "usr"));

                // Limpieza: eliminar bín antiguo si existe (está ahora en usr/bin)
                File oldBin = new File(getFilesDir(), "bin");
                if (oldBin.exists()) {
                    deleteRecursive(oldBin);
                }

                mainHandler.post(() -> binding.loadingOverlay.setVisibility(android.view.View.GONE));

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

        String projectName = getFinalProjectName();
        binding.editProjectName.setText(projectName);
        boolean isC = binding.toggleLanguage.getCheckedButtonId() == binding.btnLangC.getId();

        // El nombre ya viene con prefijo desde getFinalProjectName() y se muestra en el
        // UI
        if (binding.editProjectName.getText().toString().trim().equals("asm_project") ||
                binding.editProjectName.getText().toString().trim().equals("c_project")) {
            android.content.SharedPreferences prefs = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
            if (isC) {
                int counter = prefs.getInt(KEY_C_COUNTER, 0) + 1;
                projectName = "c_project" + counter;
                prefs.edit().putInt(KEY_C_COUNTER, counter).apply();
            } else {
                int counter = prefs.getInt(KEY_ASM_COUNTER, 0) + 1;
                projectName = "asm_project" + counter;
                prefs.edit().putInt(KEY_ASM_COUNTER, counter).apply();
            }
            binding.editProjectName.setText(projectName);
        }

        if (isC) {
            compileCCode(code, selectedPic, projectName);
        } else {
            runGpasm(code, selectedPic, projectName);
        }
    }

    private void runGpasm(String code, String selectedPic, String projectName) {
        updateLogs("Iniciando ensamblado ASM para " + selectedPic + "...");
        final String finalProjectName = projectName;
        executor.execute(() -> {
            String fileName = finalProjectName + ".asm";
            String hexName = finalProjectName + ".hex";

            // 1. Guardar archivo ASM
            if (FileManager.writeInternalFile(this, fileName, code)) {
                // 2. Ejecutar GPASM
                String result = gpUtils.executeGpasm("-p", selectedPic.toLowerCase(), fileName);
                updateLogs("Log de GPASM:\n" + result);

                checkGenerationSuccess(hexName);
            } else {
                updateLogs("Error: No se pudo guardar el archivo ASM.");
            }
        });
    }

    private void compileCCode(String code, String selectedPic, String projectName) {
        updateLogs("Iniciando compilación C (SDCC) para " + selectedPic + "...");
        final String finalProjectName = projectName;
        executor.execute(() -> {
            String fileName = finalProjectName + ".c";
            String hexName = finalProjectName + ".hex";

            // 1. Guardar archivo C
            if (FileManager.writeInternalFile(this, fileName, code)) {
                // 2. Determinar arquitectura (pic14 para 16F, pic16 para 18F)
                String arch = selectedPic.toUpperCase().startsWith("18") ? "pic16" : "pic14";

                // 3. Ejecutar SDCC
                String result = sdcc.executeSdcc(
                        "-m" + arch,
                        "-p" + selectedPic.toLowerCase(),
                        "--use-non-free",
                        fileName);

                updateLogs("Log de SDCC:\n" + result);

                checkGenerationSuccess(hexName);
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

        if (!addresses.isEmpty()) {
            int currentStartAddr = addresses.get(0);
            List<Byte> currentBytes = new ArrayList<>();

            for (int i = 0; i < addresses.size(); i++) {
                int addr = addresses.get(i);
                byte val = memory.get(addr);

                // Si hay un salto en la memoria (no consecutivo) o ya tenemos 8 bytes
                if (addr != currentStartAddr + currentBytes.size() || currentBytes.size() >= 8) {
                    // Agregar fila actual
                    rows.add(formatHexRow(currentStartAddr, currentBytes));

                    // Iniciar nueva fila
                    currentStartAddr = addr;
                    currentBytes.clear();
                }
                currentBytes.add(val);
            }
            // Agregar última fila si queda algo
            if (!currentBytes.isEmpty()) {
                rows.add(formatHexRow(currentStartAddr, currentBytes));
            }
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

    private String[] formatHexRow(int startAddr, java.util.List<Byte> bytes) {
        StringBuilder hexStr = new StringBuilder();
        StringBuilder ansi = new StringBuilder();

        for (byte b : bytes) {
            hexStr.append(String.format("%02X ", b));
            ansi.append((b >= 32 && b <= 126) ? (char) b : '.');
        }

        // Rellenar espacios vacios si la fila tiene menos de 8 bytes
        while (hexStr.length() < 24) { // 8 bytes * 3 chars (2 hex + 1 space)
            hexStr.append("   ");
        }

        return new String[] { String.format("%04X:", startAddr), hexStr.toString().trim(), ansi.toString() };
    }

    private void exportFiles() {
        android.net.Uri savedUri = getSavedExportUri();
        if (savedUri != null) {
            exportToSelectedFolder(savedUri);
        } else {
            folderPickerLauncher.launch(null);
        }
    }

    private void exportToSelectedFolder(android.net.Uri treeUri) {
        executor.execute(() -> {
            String projectName = getFinalProjectName();

            String[] extensions = { ".hex", ".lst", ".err", ".cod", ".asm", ".c" };
            int count = 0;

            for (String ext : extensions) {
                String fileName = projectName + ext;
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

    private String getFinalProjectName() {
        String name = binding.editProjectName.getText().toString().trim();
        if (name.isEmpty()) {
            boolean isC = binding.toggleLanguage.getCheckedButtonId() == binding.btnLangC.getId();
            return isC ? "c_project" : "asm_project";
        }

        boolean isC = binding.toggleLanguage.getCheckedButtonId() == binding.btnLangC.getId();
        String prefix = isC ? "c_" : "asm_";

        if (!name.startsWith(prefix)) {
            // Eliminar prefijo contrario si existe
            if (isC && name.startsWith("asm_"))
                name = name.substring(4);
            else if (!isC && name.startsWith("c_"))
                name = name.substring(2);

            name = prefix + name;
        }
        return name;
    }
}
