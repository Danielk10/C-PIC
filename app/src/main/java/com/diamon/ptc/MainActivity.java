package com.diamon.ptc;

import android.app.AlertDialog;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.provider.DocumentsContract;
import android.text.Editable;
import android.text.Spannable;
import android.text.SpannableStringBuilder;
import android.text.TextWatcher;
import android.text.method.LinkMovementMethod;
import android.text.style.ForegroundColorSpan;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.PopupWindow;
import android.widget.TextView;

import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.ColorInt;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.text.HtmlCompat;
import androidx.documentfile.provider.DocumentFile;

import com.diamon.ptc.databinding.ActivityMainBinding;
import com.diamon.ptc.policy.PolicyActivity;
import com.google.android.material.button.MaterialButton;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Date;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;
import java.util.TreeMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    private static final String PREFS_NAME = "CPicPrefs";
    private static final String KEY_EXPORT_URI = "export_uri";
    private static final String KEY_ASM_COUNTER = "asm_counter";
    private static final String KEY_C_COUNTER = "c_counter";

    private static final String DEFAULT_ASM_FILE = "main.asm";
    private static final String DEFAULT_C_FILE = "main.c";

    private static final String DEFAULT_ASM = "; Ejemplo PIC16F628A\n" +
            "    PROCESSOR 16F628A\n" +
            "    INCLUDE \"P16F628A.INC\"\n\n" +
            "    __CONFIG _INTRC_OSC_NOCLKOUT & _WDT_OFF & _PWRTE_ON & _MCLRE_ON & _BODEN_OFF & _LVP_OFF & _CP_OFF\n\n" +
            "    ORG 0x00\n" +
            "START:\n" +
            "    BANKSEL TRISB\n" +
            "    CLRF TRISB\n" +
            "LOOP:\n" +
            "    MOVLW 0xFF\n" +
            "    MOVWF PORTB\n" +
            "    GOTO LOOP\n" +
            "    END\n";

    private static final String DEFAULT_C = "#include <pic14/pic16f628a.h>\n\n" +
            "void main(void) {\n" +
            "    TRISB = 0x00;\n" +
            "    while (1) {\n" +
            "        PORTB = 0xFF;\n" +
            "    }\n" +
            "}\n";

    private static final Pattern C_PATTERN = Pattern.compile("\\b(void|int|char|unsigned|if|else|while|for|return|static|const|struct|switch|case|break|volatile|typedef|enum|union|signed|long|short)\\b", Pattern.CASE_INSENSITIVE);
    private static final Pattern C_PREPROCESSOR_PATTERN = Pattern.compile("(?m)^\\s*#\\s*(include|define|ifdef|ifndef|if|elif|else|endif|pragma|error|warning|undef)\\b", Pattern.CASE_INSENSITIVE);
    private static final Pattern C_COMMENT_PATTERN = Pattern.compile("//.*$|/\\*.*?\\*/", Pattern.MULTILINE | Pattern.DOTALL);
    private static final Pattern ASM_PATTERN = Pattern.compile("\\b(PROCESSOR|INCLUDE|ORG|END|MOVLW|MOVWF|GOTO|CALL|CLRF|BSF|BCF|BANKSEL|EQU|CONFIG|__CONFIG|TRIS[A-E]?|PORT[A-E]?)\\b", Pattern.CASE_INSENSITIVE);
    private static final Pattern ASM_COMMENT_PATTERN = Pattern.compile(";.*$", Pattern.MULTILINE);

    private static class ModuleState {
        final LinkedHashMap<String, String> files = new LinkedHashMap<>();
        String activeFile;
        String lastProjectName;
    }

    private ActivityMainBinding binding;
    private final ExecutorService executor = Executors.newFixedThreadPool(4);
    private final Handler mainHandler = new Handler(Looper.getMainLooper());
    private GpUtilsExecutor gpUtils;
    private SdccExecutor sdcc;
    private ActivityResultLauncher<Intent> folderPickerLauncher;

    private final ModuleState asmState = new ModuleState();
    private final ModuleState cState = new ModuleState();
    private boolean isApplyingHighlight;
    private boolean currentModeIsC;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        setSupportActionBar(binding.toolbar);

        gpUtils = new GpUtilsExecutor(this);
        sdcc = new SdccExecutor(this);

        initModuleStates();
        currentModeIsC = binding.toggleLanguage.getCheckedButtonId() == binding.btnLangC.getId();
        setupFolderPicker();
        setupListeners();
        renderCurrentModule();
        initResources();
    }

    private void initModuleStates() {
        asmState.files.put(DEFAULT_ASM_FILE, DEFAULT_ASM);
        asmState.activeFile = DEFAULT_ASM_FILE;

        cState.files.put(DEFAULT_C_FILE, DEFAULT_C);
        cState.activeFile = DEFAULT_C_FILE;
    }

    private void setupFolderPicker() {
        folderPickerLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                result -> {
                    if (result.getResultCode() == RESULT_OK && result.getData() != null && result.getData().getData() != null) {
                        Uri uri = result.getData().getData();
                        saveExportUri(uri);
                        updateLogs("Carpeta de exportación actualizada: " + uri);
                        exportToSelectedFolder(uri);
                    }
                });
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
            binding.textLogs.setText("Logs reiniciados.");
            updateLogs("Sistema listo.");
            return true;
        } else if (id == R.id.action_clear_editor) {
            confirmClearEditor();
            return true;
        } else if (id == R.id.action_about) {
            showAboutDialog();
            return true;
        } else if (id == R.id.action_change_export_folder) {
            launchFolderPicker(true);
            return true;
        } else if (id == R.id.action_policy) {
            startActivity(new Intent(this, PolicyActivity.class));
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    private void setupListeners() {
        binding.btnAssemble.setOnClickListener(v -> assembleCode());
        binding.btnViewHex.setOnClickListener(v -> viewGeneratedFile(".hex"));
        binding.btnExport.setOnClickListener(v -> exportFiles());
        binding.btnAddFile.setOnClickListener(v -> showAddFileDialog());

        binding.editAsm.addTextChangedListener(new TextWatcher() {
            @Override public void beforeTextChanged(CharSequence s, int start, int count, int after) { }
            @Override public void onTextChanged(CharSequence s, int start, int before, int count) { }
            @Override public void afterTextChanged(Editable s) {
                if (isApplyingHighlight) return;
                saveActiveEditorContent();
                updateLineNumbers();
                applySyntaxHighlighting();
            }
        });

        binding.toggleLanguage.addOnButtonCheckedListener((group, checkedId, isChecked) -> {
            if (!isChecked) return;
            boolean targetIsC = checkedId == binding.btnLangC.getId();
            if (targetIsC == currentModeIsC) return;

            saveActiveEditorContentForMode(currentModeIsC);
            currentModeIsC = targetIsC;
            renderCurrentModule();
            updateLogs(isCurrentCMode() ? "Modo C (SDCC)" : "Modo ASM (GPUTILS)");
        });
    }

    private ModuleState getCurrentState() {
        return isCurrentCMode() ? cState : asmState;
    }

    private void renderCurrentModule() {
        ModuleState state = getCurrentState();
        binding.btnAssemble.setText(isCurrentCMode() ? "COMPILAR" : "ENSAMBLAR");

        if (state.lastProjectName != null) {
            binding.editProjectName.setText(state.lastProjectName);
        } else {
            binding.editProjectName.setText("");
        }

        refreshTabs();
        loadActiveFileInEditor();
    }

    private void refreshTabs() {
        ModuleState state = getCurrentState();
        binding.layoutTabs.removeAllViews();
        for (String fileName : state.files.keySet()) {
            android.widget.LinearLayout tabContainer = new android.widget.LinearLayout(this);
            tabContainer.setOrientation(android.widget.LinearLayout.HORIZONTAL);
            tabContainer.setPadding(0, 0, 12, 0);

            MaterialButton tab = new MaterialButton(this, null, com.google.android.material.R.attr.materialButtonOutlinedStyle);
            tab.setText(fileName);
            tab.setTextSize(11f);
            tab.setAllCaps(false);
            tab.setPadding(16, 8, 16, 8);
            if (fileName.equals(state.activeFile)) {
                tab.setStrokeWidth(3);
            }
            tab.setOnClickListener(v -> {
                saveActiveEditorContent();
                state.activeFile = fileName;
                refreshTabs();
                loadActiveFileInEditor();
            });

            MaterialButton closeBtn = new MaterialButton(this, null, com.google.android.material.R.attr.materialButtonOutlinedStyle);
            closeBtn.setText("✕");
            closeBtn.setTextSize(11f);
            closeBtn.setAllCaps(false);
            closeBtn.setMinWidth(0);
            closeBtn.setMinimumWidth(0);
            closeBtn.setPadding(12, 8, 12, 8);
            closeBtn.setOnClickListener(v -> confirmCloseTab(fileName));

            tabContainer.addView(tab);
            tabContainer.addView(closeBtn);
            binding.layoutTabs.addView(tabContainer);
        }
    }

    private void confirmCloseTab(String fileName) {
        new AlertDialog.Builder(this)
                .setTitle("Cerrar archivo")
                .setMessage("¿Eliminar la pestaña '" + fileName + "'?")
                .setPositiveButton("Cerrar", (d, w) -> closeFileTab(fileName))
                .setNegativeButton("Cancelar", null)
                .show();
    }

    private void closeFileTab(String fileName) {
        ModuleState state = getCurrentState();
        if (state.files.size() == 1) {
            updateLogs("Debe quedar al menos un archivo abierto.");
            return;
        }

        state.files.remove(fileName);
        if (fileName.equals(state.activeFile)) {
            state.activeFile = state.files.keySet().iterator().next();
        }

        refreshTabs();
        loadActiveFileInEditor();
    }

    private void showAddFileDialog() {
        final android.widget.EditText input = new android.widget.EditText(this);
        input.setHint(isCurrentCMode() ? "ej: main.c, utils.c, defs.h" : "ej: main.asm, macros.inc");
        new AlertDialog.Builder(this)
                .setTitle("Nuevo archivo")
                .setView(input)
                .setPositiveButton("Agregar", (d, w) -> {
                    String name = input.getText().toString().trim();
                    if (name.isEmpty()) {
                        updateLogs("Nombre de archivo inválido.");
                        return;
                    }

                    if (!isValidExtensionForCurrentMode(name)) {
                        updateLogs(isCurrentCMode()
                                ? "En modo C solo se permiten .c y .h"
                                : "En modo ASM solo se permiten .asm y .inc");
                        return;
                    }

                    ModuleState state = getCurrentState();
                    if (state.files.containsKey(name)) {
                        updateLogs("Ese archivo ya existe en el proyecto.");
                        return;
                    }

                    state.files.put(name, "");
                    state.activeFile = name;
                    refreshTabs();
                    loadActiveFileInEditor();
                })
                .setNegativeButton("Cancelar", null)
                .show();
    }

    private boolean isValidExtensionForCurrentMode(String name) {
        String lower = name.toLowerCase(Locale.ROOT);
        if (isCurrentCMode()) {
            return lower.endsWith(".c") || lower.endsWith(".h");
        }
        return lower.endsWith(".asm") || lower.endsWith(".inc");
    }

    private void confirmClearEditor() {
        new AlertDialog.Builder(this)
                .setTitle("Limpiar Editor")
                .setMessage("¿Borrar el contenido del archivo activo?")
                .setPositiveButton("Sí", (d, w) -> {
                    binding.editAsm.setText("");
                    saveActiveEditorContent();
                })
                .setNegativeButton("Cancelar", null)
                .show();
    }

    private void showAboutDialog() {
        String message = "<b>C PIC Compiler</b><br><br>" +
                "GUI para <b>GPUTILS</b> y <b>SDCC</b>.<br><br>" +
                "GPUTILS: <a href='https://sourceforge.net/projects/gputils/'>sourceforge.net/projects/gputils/</a><br><br>" +
                "SDCC: <a href='https://sourceforge.net/projects/sdcc/'>sourceforge.net/projects/sdcc/</a><br><br>" +
                "Licencia: <b>GNU GPL v3.0</b>.";

        AlertDialog dialog = new AlertDialog.Builder(this)
                .setTitle("Acerca de / Licencias")
                .setMessage(HtmlCompat.fromHtml(message, HtmlCompat.FROM_HTML_MODE_COMPACT))
                .setPositiveButton("Cerrar", null)
                .show();

        TextView textView = dialog.findViewById(android.R.id.message);
        if (textView != null) {
            textView.setMovementMethod(LinkMovementMethod.getInstance());
        }
    }

    private void saveActiveEditorContent() {
        saveActiveEditorContentForMode(currentModeIsC);
    }

    private void saveActiveEditorContentForMode(boolean isCMode) {
        ModuleState state = isCMode ? cState : asmState;
        if (state.activeFile != null) {
            state.files.put(state.activeFile, binding.editAsm.getText().toString());
        }
    }

    private void loadActiveFileInEditor() {
        ModuleState state = getCurrentState();
        String content = state.files.getOrDefault(state.activeFile, "");
        binding.editAsm.setText(content);
        binding.editAsm.setSelection(binding.editAsm.getText().length());
        applySyntaxHighlighting();
        updateLineNumbers();
    }

    private void updateLineNumbers() {
        String text = binding.editAsm.getText() == null ? "" : binding.editAsm.getText().toString();
        int lines = 1;
        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) == '\n') lines++;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= lines; i++) {
            sb.append(i).append('\n');
        }
        binding.textLineNumbers.setText(sb.toString());
    }

    private void applySyntaxHighlighting() {
        Editable editable = binding.editAsm.getText();
        if (editable == null) return;

        isApplyingHighlight = true;
        try {
            int start = binding.editAsm.getSelectionStart();
            int end = binding.editAsm.getSelectionEnd();

            SpannableStringBuilder spannable = new SpannableStringBuilder(editable);
            ForegroundColorSpan[] old = spannable.getSpans(0, spannable.length(), ForegroundColorSpan.class);
            for (ForegroundColorSpan span : old) {
                spannable.removeSpan(span);
            }

            Pattern keywordPattern = isCurrentCMode() ? C_PATTERN : ASM_PATTERN;
            Pattern commentPattern = isCurrentCMode() ? C_COMMENT_PATTERN : ASM_COMMENT_PATTERN;
            @ColorInt int keywordColor = 0xFF80CBC4;
            @ColorInt int commentColor = 0xFF7F8C8D;

            Matcher keywordMatcher = keywordPattern.matcher(spannable.toString());
            while (keywordMatcher.find()) {
                spannable.setSpan(new ForegroundColorSpan(keywordColor), keywordMatcher.start(), keywordMatcher.end(), Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
            }

            if (isCurrentCMode()) {
                Matcher preprocessorMatcher = C_PREPROCESSOR_PATTERN.matcher(spannable.toString());
                while (preprocessorMatcher.find()) {
                    spannable.setSpan(new ForegroundColorSpan(keywordColor), preprocessorMatcher.start(), preprocessorMatcher.end(), Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
                }
            }

            Matcher commentMatcher = commentPattern.matcher(spannable.toString());
            while (commentMatcher.find()) {
                spannable.setSpan(new ForegroundColorSpan(commentColor), commentMatcher.start(), commentMatcher.end(), Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
            }

            editable.replace(0, editable.length(), spannable);
            int safeStart = Math.max(0, Math.min(start, binding.editAsm.length()));
            int safeEnd = Math.max(0, Math.min(end, binding.editAsm.length()));
            binding.editAsm.setSelection(safeStart, safeEnd);
        } finally {
            isApplyingHighlight = false;
        }
    }

    private boolean isCurrentCMode() {
        return currentModeIsC;
    }

    private void initResources() {
        executor.execute(() -> {
            boolean extracted = AssetExtractor.areAssetsExtracted(this);
            if (!extracted) {
                mainHandler.post(() -> binding.loadingOverlay.setVisibility(View.VISIBLE));
                updateLogs("Preparando recursos (GPUTILS + SDCC)...");
                boolean success = AssetExtractor.extractAssets(this, "data/data/com.diamon.ptc/files/usr", new File(getFilesDir(), "usr"));
                mainHandler.post(() -> binding.loadingOverlay.setVisibility(View.GONE));
                updateLogs(success ? "Recursos extraídos correctamente." : "Error al extraer recursos.");
            }
            loadPicList();
        });
    }

    private void loadPicList() {
        File headerDir = new File(getFilesDir(), "usr/share/gputils/header");
        List<String> pics = new ArrayList<>();
        String[] files = headerDir.list();
        if (files != null) {
            for (String file : files) {
                if (file.toLowerCase(Locale.ROOT).endsWith(".inc")) {
                    String name = file.substring(0, file.length() - 4);
                    if (name.toLowerCase(Locale.ROOT).startsWith("p")) name = name.substring(1);
                    pics.add(name.toUpperCase(Locale.ROOT));
                }
            }
        }

        Collections.sort(pics);
        if (pics.isEmpty()) pics.add("16F628A");

        mainHandler.post(() -> {
            ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, pics);
            adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            binding.spinnerPic.setAdapter(adapter);

            int index = pics.indexOf("16F628A");
            if (index < 0) index = pics.indexOf("16F84A");
            if (index >= 0) {
                binding.spinnerPic.setSelection(index);
            }
        });
    }

    private void assembleCode() {
        saveActiveEditorContent();
        ModuleState state = getCurrentState();

        if (state.files.isEmpty()) {
            updateLogs("No hay archivos para compilar.");
            return;
        }

        if (!runToolchainPreflightChecks(isCurrentCMode())) {
            updateLogs("Prechequeo de herramientas falló. Revisa los logs.");
            return;
        }

        String selectedPic = binding.spinnerPic.getSelectedItem() != null
                ? binding.spinnerPic.getSelectedItem().toString()
                : "16F628A";

        String projectName = resolveProjectName(true);
        File projectDir = getProjectDir(projectName);
        if (!projectDir.exists() && !projectDir.mkdirs()) {
            updateLogs("No se pudo crear directorio de proyecto.");
            return;
        }

        LinkedHashMap<String, String> snapshotFiles = new LinkedHashMap<>(state.files);
        for (String fileName : snapshotFiles.keySet()) {
            boolean saved = FileManager.writeToFile(new File(projectDir, fileName), snapshotFiles.get(fileName));
            if (!saved) {
                updateLogs("No se pudo guardar fuente: " + fileName);
                return;
            }
        }

        if (isCurrentCMode()) {
            compileCProject(projectDir, selectedPic, snapshotFiles);
        } else {
            assembleAsmProject(projectDir, selectedPic, snapshotFiles);
        }
    }

    private boolean runToolchainPreflightChecks(boolean forCModule) {
        List<String> issues = forCModule ? sdcc.getSetupIssues() : gpUtils.getSetupIssues();
        if (issues.isEmpty()) {
            updateLogs("Prechequeo " + (forCModule ? "SDCC" : "GPUTILS") + " OK.");
            return true;
        }
        for (String issue : issues) {
            updateLogs("Prechequeo: " + issue);
        }
        return false;
    }

    private void assembleAsmProject(File projectDir, String selectedPic, LinkedHashMap<String, String> snapshotFiles) {
        executor.execute(() -> {
            String mainFile = pickMainFile(snapshotFiles, ".asm");
            if (mainFile == null) {
                updateLogs("Agrega un archivo principal .asm para ensamblar.");
                return;
            }

            updateLogs("Ensamblando " + mainFile + " para " + selectedPic + "...");
            String result = gpUtils.executeGpasm(projectDir,
                    "-I", projectDir.getAbsolutePath(),
                    "-p", selectedPic.toLowerCase(Locale.ROOT),
                    mainFile);
            updateLogs("Log GPASM:\n" + result);
            checkGenerationSuccess(projectDir, ".hex");
        });
    }

    private void compileCProject(File projectDir, String selectedPic, LinkedHashMap<String, String> snapshotFiles) {
        executor.execute(() -> {
            List<String> cFiles = new ArrayList<>();
            for (String file : snapshotFiles.keySet()) {
                if (file.toLowerCase(Locale.ROOT).endsWith(".c")) {
                    cFiles.add(file);
                }
            }

            if (cFiles.isEmpty()) {
                updateLogs("Agrega al menos un archivo .c para compilar.");
                return;
            }

            String arch = selectedPic.toUpperCase(Locale.ROOT).startsWith("18") ? "pic16" : "pic14";
            List<String> args = new ArrayList<>(Arrays.asList(
                    "-m" + arch,
                    "-p" + selectedPic.toLowerCase(Locale.ROOT),
                    "--use-non-free",
                    "-I" + projectDir.getAbsolutePath()));
            args.addAll(cFiles);

            String result = sdcc.executeSdcc(projectDir, args.toArray(new String[0]));
            updateLogs("Log SDCC:\n" + result);
            checkGenerationSuccess(projectDir, ".hex");
        });
    }

    private String pickMainFile(LinkedHashMap<String, String> files, String ext) {
        String expected = "main" + ext;
        for (String file : files.keySet()) {
            if (file.equalsIgnoreCase(expected)) return file;
        }
        for (String file : files.keySet()) {
            if (file.toLowerCase(Locale.ROOT).endsWith(ext)) return file;
        }
        return null;
    }

    private void checkGenerationSuccess(File projectDir, String extension) {
        File[] files = projectDir.listFiles();
        if (files == null) {
            updateLogs("No se encontró salida para " + extension);
            return;
        }

        for (File file : files) {
            if (file.getName().toLowerCase(Locale.ROOT).endsWith(extension)) {
                updateLogs("Generado: " + file.getName());
                return;
            }
        }
        updateLogs("No se generó salida esperada. Revisa logs.");
    }

    private File getProjectDir(String projectName) {
        return new File(new File(getFilesDir(), "projects"), projectName);
    }

    private String resolveProjectName(boolean createIfMissing) {
        ModuleState state = getCurrentState();
        String uiValue = binding.editProjectName.getText() == null ? "" : binding.editProjectName.getText().toString().trim();
        boolean isC = isCurrentCMode();

        if (!uiValue.isEmpty()) {
            String normalized = normalizeProjectName(uiValue, isC);
            state.lastProjectName = normalized;
            binding.editProjectName.setText(normalized);
            return normalized;
        }

        if (state.lastProjectName != null) {
            binding.editProjectName.setText(state.lastProjectName);
            return state.lastProjectName;
        }

        if (!createIfMissing) {
            return null;
        }

        android.content.SharedPreferences prefs = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        int next;
        String generated;
        if (isC) {
            next = prefs.getInt(KEY_C_COUNTER, 0) + 1;
            prefs.edit().putInt(KEY_C_COUNTER, next).apply();
            generated = "c_project" + next;
        } else {
            next = prefs.getInt(KEY_ASM_COUNTER, 0) + 1;
            prefs.edit().putInt(KEY_ASM_COUNTER, next).apply();
            generated = "asm_project" + next;
        }

        state.lastProjectName = generated;
        binding.editProjectName.setText(generated);
        return generated;
    }

    private String normalizeProjectName(String name, boolean isC) {
        String prefix = isC ? "c_" : "asm_";
        if (!name.startsWith(prefix)) {
            if (isC && name.startsWith("asm_")) name = name.substring(4);
            else if (!isC && name.startsWith("c_")) name = name.substring(2);
            name = prefix + name;
        }
        return name;
    }

    private void viewGeneratedFile(String extension) {
        String projectName = resolveProjectName(false);
        if (projectName == null) {
            updateLogs("Primero compila o ensambla un proyecto.");
            return;
        }

        File projectDir = getProjectDir(projectName);
        File target = findFirstWithExtension(projectDir, extension);
        if (target == null) {
            updateLogs("No existe archivo " + extension + " para el proyecto actual.");
            return;
        }

        String content = FileManager.readFile(target);
        if (content.isEmpty()) {
            updateLogs("Archivo vacío: " + target.getName());
            return;
        }

        if (target.getName().toLowerCase(Locale.ROOT).endsWith(".hex")) {
            showAdvancedHexViewer(content);
        } else {
            showSimpleTextViewer(target.getName(), content);
        }
    }

    private File findFirstWithExtension(File dir, String extension) {
        File[] files = dir.listFiles();
        if (files == null) return null;
        for (File file : files) {
            if (file.getName().toLowerCase(Locale.ROOT).endsWith(extension)) {
                return file;
            }
        }
        return null;
    }

    private void showSimpleTextViewer(String title, String content) {
        new AlertDialog.Builder(this)
                .setTitle(title)
                .setMessage(content)
                .setPositiveButton("Cerrar", null)
                .show();
    }

    private void showAdvancedHexViewer(String content) {
        View popupView = LayoutInflater.from(this).inflate(R.layout.popup_hex_viewer, null);
        PopupWindow popupWindow = new PopupWindow(
                popupView,
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.MATCH_PARENT,
                true);

        ListView listView = popupView.findViewById(R.id.list_hex);
        List<String[]> rows = new ArrayList<>();
        TreeMap<Integer, Byte> memory = IntelHexParser.parse(content);

        if (!memory.isEmpty()) {
            List<Integer> addresses = new ArrayList<>(memory.keySet());
            Collections.sort(addresses);

            int currentStartAddr = addresses.get(0);
            List<Byte> currentBytes = new ArrayList<>();

            for (int addr : addresses) {
                byte val = memory.get(addr);
                if (currentBytes.size() == 8 || addr != currentStartAddr + currentBytes.size()) {
                    rows.add(formatHexRow(currentStartAddr, currentBytes));
                    currentStartAddr = addr;
                    currentBytes.clear();
                }
                currentBytes.add(val);
            }
            if (!currentBytes.isEmpty()) {
                rows.add(formatHexRow(currentStartAddr, currentBytes));
            }
        }

        listView.setAdapter(new BaseAdapter() {
            @Override public int getCount() { return rows.size(); }
            @Override public Object getItem(int position) { return rows.get(position); }
            @Override public long getItemId(int position) { return position; }

            @Override
            public View getView(int position, View convertView, ViewGroup parent) {
                if (convertView == null) {
                    convertView = getLayoutInflater().inflate(R.layout.item_hex_row, parent, false);
                }
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

    private String[] formatHexRow(int startAddr, List<Byte> bytes) {
        StringBuilder hexStr = new StringBuilder();
        StringBuilder ansi = new StringBuilder();

        for (byte b : bytes) {
            hexStr.append(String.format(Locale.ROOT, "%02X ", b));
            ansi.append((b >= 32 && b <= 126) ? (char) b : '.');
        }

        while (hexStr.length() < 24) {
            hexStr.append("   ");
        }

        return new String[] { String.format(Locale.ROOT, "%04X:", startAddr), hexStr.toString().trim(), ansi.toString() };
    }

    private void exportFiles() {
        saveActiveEditorContent();
        Uri uri = getSavedExportUri();
        if (uri == null || !hasPersistedPermission(uri)) {
            launchFolderPicker(false);
        } else {
            exportToSelectedFolder(uri);
        }
    }

    private void launchFolderPicker(boolean forceChange) {
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT_TREE);
        intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION
                | Intent.FLAG_GRANT_WRITE_URI_PERMISSION
                | Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION);

        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
            Uri downloadsDir = DocumentsContract.buildTreeDocumentUri("com.android.externalstorage.documents", "primary:Download");
            intent.putExtra(DocumentsContract.EXTRA_INITIAL_URI, downloadsDir);
        }

        if (forceChange) {
            clearSavedExportUri();
        }

        folderPickerLauncher.launch(intent);
    }

    private void exportToSelectedFolder(Uri treeUri) {
        String projectName = resolveProjectName(false);
        if (projectName == null) {
            updateLogs("Primero compila o ensambla para exportar.");
            return;
        }

        File projectDir = getProjectDir(projectName);
        persistCurrentModuleSources(projectDir);

        executor.execute(() -> {
            File[] files = projectDir.listFiles();
            if (files == null || files.length == 0) {
                updateLogs("No hay archivos en el proyecto para exportar.");
                return;
            }

            int count = 0;
            for (File file : files) {
                String exportName = projectName + "__" + file.getName();
                if (saveFileToDocumentTree(treeUri, exportName, file)) {
                    count++;
                }
            }

            int finalCount = count;
            updateLogs(finalCount > 0
                    ? "Exportación exitosa: " + finalCount + " archivos."
                    : "No fue posible exportar archivos.");
        });
    }

    private boolean saveFileToDocumentTree(Uri treeUri, String displayName, File sourceFile) {
        try {
            DocumentFile root = DocumentFile.fromTreeUri(this, treeUri);
            if (root == null) return false;

            DocumentFile file = root.findFile(displayName);
            if (file == null) {
                file = root.createFile(getMimeType(displayName), displayName);
            }
            if (file == null) return false;

            try (InputStream in = new FileInputStream(sourceFile);
                 OutputStream out = getContentResolver().openOutputStream(file.getUri(), "w")) {
                if (out == null) return false;
                byte[] buffer = new byte[8192];
                int len;
                while ((len = in.read(buffer)) > 0) {
                    out.write(buffer, 0, len);
                }
                return true;
            }
        } catch (SecurityException sec) {
            Log.e(TAG, "Permiso SAF perdido", sec);
            clearSavedExportUri();
            updateLogs("Permiso de carpeta perdido. Selecciona nuevamente una carpeta de destino.");
            mainHandler.post(() -> launchFolderPicker(false));
            return false;
        } catch (Exception e) {
            Log.e(TAG, "Error guardando archivo", e);
            return false;
        }
    }

    private String getMimeType(String fileName) {
        String lower = fileName.toLowerCase(Locale.ROOT);
        if (lower.endsWith(".c") || lower.endsWith(".h") || lower.endsWith(".asm") || lower.endsWith(".inc") || lower.endsWith(".lst") || lower.endsWith(".err") || lower.endsWith(".map") || lower.endsWith(".sym") || lower.endsWith(".adb") || lower.endsWith(".mem")) {
            return "text/plain";
        }
        if (lower.endsWith(".hex") || lower.endsWith(".cod") || lower.endsWith(".o") || lower.endsWith(".obj") || lower.endsWith(".ihx") || lower.endsWith(".rel") || lower.endsWith(".lib") || lower.endsWith(".bin")) {
            return "application/octet-stream";
        }
        return "*/*";
    }

    private void persistCurrentModuleSources(File projectDir) {
        if (!projectDir.exists() && !projectDir.mkdirs()) {
            updateLogs("No se pudo preparar directorio para exportación.");
            return;
        }

        ModuleState state = getCurrentState();
        LinkedHashMap<String, String> snapshotFiles = new LinkedHashMap<>(state.files);
        for (String fileName : snapshotFiles.keySet()) {
            boolean saved = FileManager.writeToFile(new File(projectDir, fileName), snapshotFiles.get(fileName));
            if (!saved) {
                updateLogs("No se pudo guardar fuente para exportar: " + fileName);
            }
        }
    }

    private void saveExportUri(Uri uri) {
        getContentResolver().takePersistableUriPermission(uri,
                Intent.FLAG_GRANT_READ_URI_PERMISSION | Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
        getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                .edit()
                .putString(KEY_EXPORT_URI, uri.toString())
                .apply();
    }

    private Uri getSavedExportUri() {
        String uri = getSharedPreferences(PREFS_NAME, MODE_PRIVATE).getString(KEY_EXPORT_URI, null);
        return uri == null ? null : Uri.parse(uri);
    }

    private boolean hasPersistedPermission(Uri uri) {
        for (android.content.UriPermission permission : getContentResolver().getPersistedUriPermissions()) {
            if (permission.getUri().equals(uri) && permission.isWritePermission()) {
                return true;
            }
        }
        return false;
    }

    private void clearSavedExportUri() {
        getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                .edit()
                .remove(KEY_EXPORT_URI)
                .apply();
    }

    private void updateLogs(String text) {
        mainHandler.post(() -> {
            String time = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss", Locale.getDefault()).format(new Date());
            String current = binding.textLogs.getText().toString();
            binding.textLogs.setText(current + "\n[" + time + "] " + text);
            binding.scrollLogs.post(() -> binding.scrollLogs.fullScroll(View.FOCUS_DOWN));
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        executor.shutdown();
    }
}
