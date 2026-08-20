package com.diamon.ptc;

import android.app.AlertDialog;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.provider.DocumentsContract;
import android.text.Editable;
import android.text.Spannable;
import android.text.SpannableStringBuilder;
import android.text.TextUtils;
import android.text.TextWatcher;
import android.text.method.LinkMovementMethod;
import android.text.style.ForegroundColorSpan;
import android.util.Log;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.PopupWindow;
import android.widget.TextView;
import android.view.MenuItem;
import android.widget.Toast;

import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.ColorInt;
import androidx.appcompat.app.AppCompatActivity;
import androidx.annotation.NonNull;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.interstitial.InterstitialAd;
import com.google.android.gms.ads.interstitial.InterstitialAdLoadCallback;
import androidx.core.text.HtmlCompat;
import androidx.documentfile.provider.DocumentFile;

import com.diamon.ptc.databinding.ActivityMainBinding;
import com.diamon.ptc.policy.PolicyActivity;
import com.google.android.material.button.MaterialButton;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
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
    private static final String KEY_SELECTED_LANGUAGE = "selected_language";
    private static final String KEY_SELECTED_PIC = "selected_pic";
    private static final String KEY_OPT_PACKIHX = "pref_opt_packihx";
    private static final String KEY_OPT_MAKEBIN = "pref_opt_makebin";
    private static final String KEY_OPT_AUTO_APPLY = "pref_opt_auto_apply";

    private static final String DEFAULT_ASM = "; Código de prueba para PIC16F628A\n" +
            "    PROCESSOR 16F628A\n" +
            "    INCLUDE \"P16F628A.INC\"\n\n" +
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
            "// Ejemplo básico para PIC16F628A\n" +
            "void main(void) {\n" +
            "    TRISB = 0x00; // Puerto B como salida\n" +
            "    while(1) {\n" +
            "        PORTB = 0xFF;\n" +
            "        for(unsigned int i=0; i<1000; i++); // Retardo\n" +
            "        PORTB = 0x00;\n" +
            "        for(unsigned int i=0; i<1000; i++);\n" +
            "    }\n" +
            "}\n";

    private static final Pattern C_PATTERN = Pattern.compile("\\b(void|int|char|unsigned|if|else|while|for|return|static|const|struct|switch|case|break|volatile|typedef|enum|union|signed|long|short|float|double|sizeof|do|goto|extern|register|continue|default|auto|inline|restrict|_Bool|_Complex|_Imaginary)\\b", Pattern.CASE_INSENSITIVE);
    private static final Pattern C_PREPROCESSOR_PATTERN = Pattern.compile("(?m)^\\s*#\\s*(include|define|ifdef|ifndef|if|elif|else|endif|pragma|error|warning|undef)\\b", Pattern.CASE_INSENSITIVE);
    private static final Pattern C_COMMENT_PATTERN = Pattern.compile("(?s)/\\*.*?\\*/|//[^\\n\\r]*");
    private static final Pattern C_STRING_PATTERN = Pattern.compile("\"(?:\\\\.|[^\"\\\\])*\"|'(?:\\\\.|[^'\\\\])*'");
    private static final Pattern C_NUMBER_PATTERN = Pattern.compile("\\b(0x[0-9a-fA-F]+|0b[01]+|0[0-7]+|\\d+(?:\\.\\d+)?)\\b");
    private static final Pattern C_FUNCTION_PATTERN = Pattern.compile("\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\()", Pattern.MULTILINE);

    private static final Pattern ASM_PATTERN = Pattern.compile("\\b(PROCESSOR|INCLUDE|ORG|END|MOVLW|MOVWF|GOTO|CALL|CLRF|BSF|BCF|BANKSEL|EQU|CONFIG|__CONFIG|TRIS[A-E]?|PORT[A-E]?|BTFSC|BTFSS|INCF|DECF|DECFSZ|RLF|RRF|NOP|RETLW|MOVF|ADDWF|SUBWF|ANDWF|IORWF|XORWF|COMF|SWAPF|RLF|RRF|BC|BZ|BNZ|BRA|RETURN|RETFIE|CLRW|CLRWDT|SLEEP|ADDLW|SUBLW|ANDLW|IORLW|XORLW|RETLW|DT|DB|DW|RES|SETC|CLRC|SKPNC|SKPC|SKPNZ|SKPZ)\\b", Pattern.CASE_INSENSITIVE);
    private static final Pattern ASM_COMMENT_PATTERN = Pattern.compile(";.*$", Pattern.MULTILINE);
    private static final Pattern ASM_LABEL_PATTERN = Pattern.compile("(?m)^\\s*([a-zA-Z_][a-zA-Z0-9_]*)\\s*:");
    private static final Pattern ASM_NUMBER_PATTERN = Pattern.compile("\\b(0x[0-9a-fA-F]+|0b[01]+|[0-9]+[Hh]|[0-9]+)\\b");
    private static final Pattern ASM_DIRECTIVE_PATTERN = Pattern.compile("(?m)^\\s*(#[a-zA-Z_][a-zA-Z0-9_]*|__[a-zA-Z_][a-zA-Z0-9_]*|\\.[a-zA-Z_][a-zA-Z0-9_]*)\\b");
    private static final Pattern ASM_STRING_PATTERN = Pattern.compile("\"(?:\\\\.|[^\"\\\\])*\"");

    private static class ModuleState {
        final LinkedHashMap<String, String> files = new LinkedHashMap<>();
        String activeFile;
        String currentProjectName; // Nombre efectivo actual (visual y lógico)
        String genericBaseName;    // Nombre genérico base (ej: asm_project1) reservado
    }

    private ActivityMainBinding binding;
    private final ExecutorService executor = Executors.newFixedThreadPool(4);
    private final Handler mainHandler = new Handler(Looper.getMainLooper());
    private GpUtilsExecutor gpUtils;
    private SdccExecutor sdcc;
    private ActivityResultLauncher<Intent> folderPickerLauncher;
    private ActivityResultLauncher<Intent> sourceFilePickerLauncher;

    private final ModuleState asmState = new ModuleState();
    private final ModuleState cState = new ModuleState();
    private boolean isApplyingHighlight;
    private boolean isUpdatingProjectName; // Flag para evitar bucles infinitos en el TextWatcher
    private boolean currentModeIsC;
    private InterstitialAd mInterstitialAd;
    private BillingManager billingManager;
    private String adsPrice = null;

    // Multi-port architecture support
    private static final String KEY_SELECTED_ARCH = "selected_arch";
    private static final String KEY_SELECTED_SUB_ARCH = "selected_sub_arch";
    private PortConfig currentPort = PortRegistry.getPort(0);
    private int currentSubArchIndex = 0;

    private final List<StringBuilder> consoleLines = new ArrayList<>();
    private int currentLineIndex = -1;
    private boolean cursorAtStartOfLine = false;
    private final Handler logHandler = new Handler(Looper.getMainLooper());
    private boolean isLogUpdatePending = false;
    private volatile boolean isCompiling = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        enableImmersiveMode();
        setSupportActionBar(binding.toolbar);

        gpUtils = new GpUtilsExecutor(this);
        sdcc = new SdccExecutor(this);

        initInitialGenericNames();
        initModuleStates();

        currentModeIsC = getSharedPreferences(PREFS_NAME, MODE_PRIVATE).getBoolean(KEY_SELECTED_LANGUAGE, false);
        binding.toggleLanguage.check(currentModeIsC ? binding.btnLangC.getId() : binding.btnLangAsm.getId());

        setupFolderPicker();
        setupSourceFilePicker();
        setupListeners();
        setupLogCopySupport();
        renderCurrentModule();
        initResources();
        setupArchitectureSpinner();

        log(getString(R.string.log_app_started));
        log(getString(currentModeIsC ? R.string.log_mode_c_active : R.string.log_mode_asm_active));

        // Initialize BillingManager for in-app purchases
        billingManager = new BillingManager(this, new BillingManager.BillingListener() {
            @Override
            public void onAdsRemovedChanged(boolean adsRemoved) {
                runOnUiThread(() -> {
                    if (adsRemoved) {
                        // Ocultar banner y detener intersticiales
                        binding.adViewBanner.setVisibility(View.GONE);
                        mInterstitialAd = null;
                        Toast.makeText(MainActivity.this, getString(R.string.iap_purchase_success), Toast.LENGTH_LONG).show();
                    }
                    // Actualizar menú para ocultar/mostrar el ítem de compra
                    invalidateOptionsMenu();
                });
            }

            @Override
            public void onPriceLoaded(String formattedPrice) {
                runOnUiThread(() -> {
                    adsPrice = formattedPrice;
                    invalidateOptionsMenu();
                });
            }

            @Override
            public void onPurchasesRestored() {
                runOnUiThread(() -> {
                    binding.adViewBanner.setVisibility(View.GONE);
                    mInterstitialAd = null;
                    Toast.makeText(MainActivity.this, getString(R.string.iap_purchase_restored), Toast.LENGTH_SHORT).show();
                    invalidateOptionsMenu();
                });
            }
        });
        billingManager.startConnection();

        // Initialize AdMob only if ads should be shown
        if (BillingManager.shouldShowAds(this)) {
            MobileAds.initialize(this, initializationStatus -> {
                AdRequest adRequest = new AdRequest.Builder().build();
                binding.adViewBanner.loadAd(adRequest);
            });
            loadInterstitialAd();
        } else {
            binding.adViewBanner.setVisibility(View.GONE);
        }
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            enableImmersiveMode();
        }
    }

    /** Activa modo inmersivo: oculta barra de navegación, mantiene barra de estado visible. */
    private void enableImmersiveMode() {
        androidx.core.view.WindowInsetsControllerCompat controller = 
            new androidx.core.view.WindowInsetsControllerCompat(getWindow(), getWindow().getDecorView());
        controller.hide(androidx.core.view.WindowInsetsCompat.Type.navigationBars());
        controller.setSystemBarsBehavior(androidx.core.view.WindowInsetsControllerCompat.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
    }

    private void initInitialGenericNames() {
        // Calcular nombres genéricos al inicio. Se incrementan para que sean únicos.
        int nextAsm = resolveNextProjectIndex("asm_project", KEY_ASM_COUNTER);
        int nextC = resolveNextProjectIndex("c_project", KEY_C_COUNTER);

        // Guardamos el nuevo contador para la próxima vez
        getSharedPreferences(PREFS_NAME, MODE_PRIVATE).edit()
                .putInt(KEY_ASM_COUNTER, nextAsm)
                .putInt(KEY_C_COUNTER, nextC)
                .apply();

        asmState.genericBaseName = "asm_project" + nextAsm;
        asmState.currentProjectName = asmState.genericBaseName;

        cState.genericBaseName = "c_project" + nextC;
        cState.currentProjectName = cState.genericBaseName;
    }

    private void initModuleStates() {
        // Iniciamos con el archivo principal usando el nombre genérico calculado
        String asmFile = asmState.genericBaseName + ".asm";
        asmState.files.put(asmFile, DEFAULT_ASM);
        asmState.activeFile = asmFile;

        String cFile = cState.genericBaseName + ".c";
        cState.files.put(cFile, DEFAULT_C);
        cState.activeFile = cFile;
    }
    
    private void setupLogCopySupport() {
        binding.textLogs.setTextIsSelectable(true);
        binding.textLogs.setLongClickable(true);
        binding.textLogs.setOnLongClickListener(v -> {
            String logs = binding.textLogs.getText() == null ? "" : binding.textLogs.getText().toString();
            if (logs.trim().isEmpty()) {
                Toast.makeText(this, getString(R.string.toast_no_log_text), Toast.LENGTH_SHORT).show();
                return true;
            }

            ClipboardManager clipboard = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
            if (clipboard == null) {
                Toast.makeText(this, getString(R.string.toast_clipboard_fail), Toast.LENGTH_SHORT).show();
                return true;
            }

            clipboard.setPrimaryClip(ClipData.newPlainText("logs", logs));
            Toast.makeText(this, getString(R.string.toast_logs_copied), Toast.LENGTH_SHORT).show();
            return true;
        });
    }

    private void setupFolderPicker() {
        folderPickerLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                result -> {
                    if (result.getResultCode() == RESULT_OK && result.getData() != null && result.getData().getData() != null) {
                        Uri uri = result.getData().getData();
                        saveExportUri(uri);
                        log(getString(R.string.log_export_folder_updated, uri.toString()));
                        exportToSelectedFolder(uri);
                    }
                });
    }

    private void setupSourceFilePicker() {
        sourceFilePickerLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                result -> {
                    if (result.getResultCode() != RESULT_OK || result.getData() == null) {
                        return;
                    }
                    List<Uri> uris = new ArrayList<>();
                    Intent data = result.getData();
                    if (data.getData() != null) {
                        uris.add(data.getData());
                    }
                    if (data.getClipData() != null) {
                        for (int i = 0; i < data.getClipData().getItemCount(); i++) {
                            Uri uri = data.getClipData().getItemAt(i).getUri();
                            if (uri != null) {
                                uris.add(uri);
                            }
                        }
                    }
                    importSourceFiles(uris);
                });
    }

    @Override
    public boolean onCreateOptionsMenu(android.view.Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        // Ocultar "Quitar Anuncios" si ya se compró
        MenuItem removeAdsItem = menu.findItem(R.id.action_remove_ads);
        if (removeAdsItem != null) {
            removeAdsItem.setVisible(BillingManager.shouldShowAds(this));
            if (adsPrice != null) {
                removeAdsItem.setTitle(getString(R.string.menu_remove_ads) + " (" + adsPrice + ")");
            }
        }
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(android.view.MenuItem item) {
        int id = item.getItemId();
        if (id == R.id.action_clear_editor) {
            confirmClearEditor();
            return true;
        } else if (id == R.id.action_about) {
            showAboutDialog();
            return true;
        } else if (id == R.id.action_import_sources) {
            launchSourceFilePicker();
            return true;
        } else if (id == R.id.action_optional_tools) {
            showOptionalToolsDialog();
            return true;
        } else if (id == R.id.action_change_export_folder) {
            launchFolderPicker(true);
            return true;
        } else if (id == R.id.action_remove_ads) {
            handleRemoveAdsPurchase();
            return true;
        } else if (id == R.id.action_policy) {
            startActivity(new Intent(this, PolicyActivity.class));
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    private boolean isTerminalExpanded = false;

    private void setupListeners() {
        if (binding.btnClearLogs != null) {
            binding.btnClearLogs.setOnClickListener(v -> clearTerminal());
        }
        if (binding.btnToggleTerminalSize != null) {
            binding.btnToggleTerminalSize.setOnClickListener(v -> toggleTerminalSize());
        }
        binding.btnAssemble.setOnClickListener(v -> assembleCode());
        binding.btnViewHex.setOnClickListener(v -> viewGeneratedFile(".hex"));
        binding.btnExport.setOnClickListener(v -> exportFiles());
        
        // Listener para el nombre del proyecto (Sincronización en tiempo real)
        binding.editProjectName.addTextChangedListener(new TextWatcher() {
            @Override public void beforeTextChanged(CharSequence s, int start, int count, int after) { }
            @Override public void onTextChanged(CharSequence s, int start, int before, int count) { }
            
            @Override
            public void afterTextChanged(Editable s) {
                if (isUpdatingProjectName) return;
                
                String inputName = s.toString().trim();
                syncProjectNameAndRenameTab(inputName);
            }
        });

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
            getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                    .edit()
                    .putBoolean(KEY_SELECTED_LANGUAGE, currentModeIsC)
                    .apply();
            renderCurrentModule();
            log(getString(isCurrentCMode() ? R.string.log_mode_c_selected : R.string.log_mode_asm_selected));
        });
    }
    
    /**
     * Sincroniza el nombre del proyecto con la pestaña principal en tiempo real.
     */
    private void syncProjectNameAndRenameTab(String inputName) {
        ModuleState state = getCurrentState();
        String oldEffectiveName = state.currentProjectName;
        String newEffectiveName;
        
        // Si el usuario borra todo el texto, volvemos al nombre genérico (ej. asm_project1)
        if (inputName.isEmpty()) {
            newEffectiveName = state.genericBaseName;
        } else {
            // Si el usuario escribe algo, ese es el nuevo nombre
            newEffectiveName = normalizeProjectName(inputName, isCurrentCMode());
        }
        
        if (newEffectiveName.equals(oldEffectiveName)) return;

        // Intentar renombrar la pestaña que coincide con el nombre anterior
        // Esto asegura que la pestaña principal siempre tenga el nombre del proyecto
        String ext = isCurrentCMode() ? ".c" : ".asm";
        String oldFileName = oldEffectiveName + ext;
        String newFileName = newEffectiveName + ext;

        if (state.files.containsKey(oldFileName)) {
            // Renombrar la clave en el mapa preservando el contenido
            String content = state.files.remove(oldFileName);
            
            // Colocamos el contenido en la nueva clave (nuevo nombre)
            if (content != null) {
                state.files.put(newFileName, content);
            }

            // Si el archivo activo era el que renombramos, actualizamos la referencia
            if (oldFileName.equals(state.activeFile)) {
                state.activeFile = newFileName;
            }
            
            // Actualizamos el nombre actual del proyecto en el estado
            state.currentProjectName = newEffectiveName;

            refreshTabs();
        }
    }

    private ModuleState getCurrentState() {
        return isCurrentCMode() ? cState : asmState;
    }

    private void renderCurrentModule() {
        isUpdatingProjectName = true; // Evitar disparar el TextWatcher
        ModuleState state = getCurrentState();
        
        if (currentPort != null && currentPort.hasAsmMode && !currentModeIsC) {
            binding.btnAssemble.setText(getString(R.string.btn_assemble));
            binding.editAsm.setHint(currentPort.editorHintAsm != null ? currentPort.editorHintAsm : getString(R.string.hint_editor_asm));
        } else {
            binding.btnAssemble.setText(getString(R.string.btn_compile));
            binding.editAsm.setHint(currentPort != null && currentPort.editorHintC != null ? currentPort.editorHintC : getString(R.string.hint_editor_c));
        }

        // Configurar el EditText con el nombre del usuario.
        // Si el nombre actual es el genérico, dejamos el campo vacío (o con hint)
        // para indicar que no hay un nombre personalizado aún.
        if (state.currentProjectName.equals(state.genericBaseName)) {
            binding.editProjectName.setText("");
            binding.editProjectName.setHint(state.genericBaseName);
        } else {
            binding.editProjectName.setText(state.currentProjectName);
        }

        refreshTabs();
        loadActiveFileInEditor();
        isUpdatingProjectName = false;
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

        MaterialButton addTab = new MaterialButton(this, null, com.google.android.material.R.attr.materialButtonOutlinedStyle);
        addTab.setText("+");
        addTab.setTextSize(14f);
        addTab.setAllCaps(false);
        addTab.setMinWidth(0);
        addTab.setMinimumWidth(0);
        addTab.setPadding(18, 8, 18, 8);
        addTab.setOnClickListener(v -> showAddFileDialog());
        binding.layoutTabs.addView(addTab);
    }

    private void confirmCloseTab(String fileName) {
        new AlertDialog.Builder(this)
                .setTitle(getString(R.string.dialog_close_file_title))
                .setMessage(getString(R.string.dialog_close_file_msg, fileName))
                .setPositiveButton(getString(R.string.btn_close), (d, w) -> closeFileTab(fileName))
                .setNegativeButton(getString(R.string.btn_cancel), null)
                .show();
    }

    private void closeFileTab(String fileName) {
        ModuleState state = getCurrentState();
        removeSourceFromProjectIfExists(fileName);
        state.files.remove(fileName);

        if (state.files.isEmpty()) {
            // Si se cierra todo, se crea un nuevo archivo con el nombre ACTUAL del proyecto.
            // Esto respeta si el usuario puso un nombre o si está usando el genérico.
            String ext = isCurrentCMode() ? ".c" : ".asm";
            String defaultName = state.currentProjectName + ext;
            
            state.files.put(defaultName, "");
            state.activeFile = defaultName;
            log(getString(R.string.log_default_tab_created, defaultName));
        } else if (fileName.equals(state.activeFile)) {
            state.activeFile = state.files.keySet().iterator().next();
        }

        refreshTabs();
        loadActiveFileInEditor();
    }

    private void removeSourceFromProjectIfExists(String fileName) {
        String projectName = resolveProjectName(); // Obtener nombre actual
        if (projectName == null) {
            return;
        }

        File file = new File(getProjectDir(projectName), fileName);
        if (file.exists()) {
            if (file.delete()) {
                log(getString(R.string.log_file_detached, fileName));
            }
        }
    }

    private void showAddFileDialog() {
        final EditText input = new EditText(this);
        input.setHint(isCurrentCMode() ? getString(R.string.hint_new_file_c) : getString(R.string.hint_new_file_asm));
        input.setTextColor(0xFF121212);
        input.setHintTextColor(0xFF5F6368);
        input.setBackgroundResource(android.R.drawable.editbox_background_normal);
        int horizontalPadding = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, 12f, getResources().getDisplayMetrics());
        int verticalPadding = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, 10f, getResources().getDisplayMetrics());
        input.setPadding(horizontalPadding, verticalPadding, horizontalPadding, verticalPadding);
        input.setTextSize(TypedValue.COMPLEX_UNIT_SP, 14f);
        input.setSingleLine();
        new AlertDialog.Builder(this)
                .setTitle(getString(R.string.dialog_new_file_title))
                .setView(input)
                .setPositiveButton(getString(R.string.btn_add), (d, w) -> {
                    String rawName = input.getText().toString().trim();
                    if (rawName.isEmpty()) {
                        log(getString(R.string.log_invalid_filename));
                        return;
                    }

                    String name = applyDefaultExtensionIfMissing(rawName);
                    
                    if (!isValidExtensionForCurrentMode(name)) {
                        log(getString(isCurrentCMode()
                                ? R.string.log_ext_allowed_c
                                : R.string.log_ext_allowed_asm));
                        return;
                    }

                    ModuleState state = getCurrentState();
                    if (state.files.containsKey(name)) {
                        log(getString(R.string.log_file_already_exists));
                        return;
                    }

                    state.files.put(name, "");
                    state.activeFile = name;
                    refreshTabs();
                    loadActiveFileInEditor();
                })
                .setNegativeButton(getString(R.string.btn_cancel), null)
                .show();
    }

    private String applyDefaultExtensionIfMissing(String fileName) {
        String normalized = fileName.trim();
        int dot = normalized.lastIndexOf('.');
        boolean hasExplicitExtension = dot > 0 && dot < normalized.length() - 1;
        if (hasExplicitExtension) {
            return normalized;
        }

        while (normalized.endsWith(".")) {
            normalized = normalized.substring(0, normalized.length() - 1).trim();
        }

        if (normalized.isEmpty()) {
            return fileName.trim();
        }

        return normalized + (isCurrentCMode() ? ".c" : ".asm");
    }

    private boolean isValidExtensionForCurrentMode(String name) {
        if (isCurrentCMode()) {
            return isCSourceFile(name);
        }
        return isAsmSourceFile(name);
    }

    private boolean isCSourceFile(String name) {
        String lower = name.toLowerCase(Locale.US);
        return lower.endsWith(".c") || lower.endsWith(".h");
    }

    private boolean isAsmSourceFile(String name) {
        String lower = name.toLowerCase(Locale.US);
        return lower.endsWith(".asm") || lower.endsWith(".inc");
    }

    private void launchSourceFilePicker() {
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        intent.addCategory(Intent.CATEGORY_OPENABLE);
        intent.setType("*/*");
        intent.putExtra(Intent.EXTRA_ALLOW_MULTIPLE, true);
        sourceFilePickerLauncher.launch(intent);
    }

    private void importSourceFiles(List<Uri> uris) {
        if (uris == null || uris.isEmpty()) {
            log(getString(R.string.log_no_files_selected_import));
            return;
        }

        int importedToC = 0;
        int importedToAsm = 0;
        String lastImportedInCurrent = null;
        boolean importedInCurrentModule = false;
        boolean importedInOtherModule = false;
        ModuleState currentState = getCurrentState();

        for (Uri uri : uris) {
            String name = resolveDisplayName(uri);
            if (name == null || name.trim().isEmpty()) {
                log(getString(R.string.log_cant_identify_filename, uri.toString()));
                continue;
            }

            boolean isCFile = isCSourceFile(name);
            boolean isAsmFile = isAsmSourceFile(name);
            if (!isCFile && !isAsmFile) {
                log(getString(R.string.log_file_skipped_ext, name));
                continue;
            }

            ModuleState targetState = isCFile ? cState : asmState;
            String content = readTextFromUri(uri);
            String uniqueName = makeUniqueFileName(targetState, name);
            targetState.files.put(uniqueName, content);
            targetState.activeFile = uniqueName;

            if (targetState == currentState) {
                lastImportedInCurrent = uniqueName;
                importedInCurrentModule = true;
            } else {
                importedInOtherModule = true;
            }

            if (isCFile) {
                importedToC++;
                log(getString(R.string.log_file_imported_c, uniqueName));
            } else {
                importedToAsm++;
                log(getString(R.string.log_file_imported_asm, uniqueName));
            }
        }

        int totalImported = importedToC + importedToAsm;
        if (totalImported > 0) {
            if (!importedInCurrentModule && importedInOtherModule) {
                if (importedToC > 0 && importedToAsm == 0 && !isCurrentCMode()) {
                    currentModeIsC = true;
                    binding.toggleLanguage.check(binding.btnLangC.getId());
                } else if (importedToAsm > 0 && importedToC == 0 && isCurrentCMode()) {
                    currentModeIsC = false;
                    binding.toggleLanguage.check(binding.btnLangAsm.getId());
                }
            }
            refreshTabs();
            loadActiveFileInEditor();
            log(getString(R.string.log_import_success, totalImported));
        } else {
            log(getString(R.string.log_no_valid_files_imported));
        }
    }

    private String resolveDisplayName(Uri uri) {
        String fallback = uri.getLastPathSegment();
        try (android.database.Cursor cursor = getContentResolver().query(uri,
                new String[]{android.provider.OpenableColumns.DISPLAY_NAME},
                null,
                null,
                null)) {
            if (cursor != null && cursor.moveToFirst()) {
                int idx = cursor.getColumnIndex(android.provider.OpenableColumns.DISPLAY_NAME);
                if (idx >= 0) {
                    String name = cursor.getString(idx);
                    if (name != null && !name.trim().isEmpty()) return name.trim();
                }
            }
        } catch (Exception e) {
            Log.e(TAG, "No se pudo leer nombre del archivo", e);
        }
        return fallback == null ? null : fallback.trim();
    }

    private String readTextFromUri(Uri uri) {
        StringBuilder builder = new StringBuilder();
        try (InputStream in = getContentResolver().openInputStream(uri);
             BufferedReader reader = in == null ? null : new BufferedReader(new InputStreamReader(in, StandardCharsets.UTF_8))) {
            if (reader == null) {
                return "";
            }
            String line;
            while ((line = reader.readLine()) != null) {
                builder.append(line).append('\n');
            }
        } catch (Exception e) {
            Log.e(TAG, "No se pudo leer archivo importado", e);
            log(getString(R.string.log_cant_read_uri, uri.toString()));
        }
        return builder.toString();
    }

    private String makeUniqueFileName(ModuleState state, String originalName) {
        if (!state.files.containsKey(originalName)) {
            return originalName;
        }
        String base = originalName;
        String ext = "";
        int dot = originalName.lastIndexOf('.');
        if (dot > 0) {
            base = originalName.substring(0, dot);
            ext = originalName.substring(dot);
        }
        int i = 1;
        while (state.files.containsKey(base + "_" + i + ext)) {
            i++;
        }
        return base + "_" + i + ext;
    }

    private void confirmClearEditor() {
        new AlertDialog.Builder(this)
                .setTitle(getString(R.string.dialog_clear_editor_title))
                .setMessage(getString(R.string.dialog_clear_editor_msg))
                .setPositiveButton(getString(R.string.btn_yes), (d, w) -> {
                    binding.editAsm.setText("");
                    saveActiveEditorContent();
                })
                .setNegativeButton(getString(R.string.btn_cancel), null)
                .show();
    }

    private void showAboutDialog() {
        String message = getString(R.string.dialog_about_message);

        AlertDialog dialog = new AlertDialog.Builder(this)
                .setTitle(getString(R.string.dialog_about_title))
                .setMessage(HtmlCompat.fromHtml(message, HtmlCompat.FROM_HTML_MODE_COMPACT))
                .setPositiveButton(getString(R.string.btn_close), null)
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
        int lines = Math.max(1, binding.editAsm.getLineCount());
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= lines; i++) {
            sb.append(i);
            if (i < lines) {
                sb.append('\n');
            }
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

            @ColorInt int keywordColor = 0xFF80CBC4;
            @ColorInt int preprocessorColor = 0xFFBA68C8;
            @ColorInt int numberColor = 0xFFFFB74D;
            @ColorInt int stringColor = 0xFFE6EE9C;
            @ColorInt int symbolColor = 0xFF64B5F6;
            @ColorInt int commentColor = 0xFF7F8C8D;

            String source = spannable.toString();
            if (isCurrentCMode()) {
                applyPatternColor(spannable, source, C_PATTERN, keywordColor);
                applyPatternColor(spannable, source, C_PREPROCESSOR_PATTERN, preprocessorColor);
                applyPatternColor(spannable, source, C_NUMBER_PATTERN, numberColor);
                applyPatternColor(spannable, source, C_STRING_PATTERN, stringColor);
                applyPatternColor(spannable, source, C_FUNCTION_PATTERN, symbolColor);
                applyPatternColor(spannable, source, C_COMMENT_PATTERN, commentColor);
            } else {
                applyPatternColor(spannable, source, ASM_PATTERN, keywordColor);
                applyPatternColor(spannable, source, ASM_DIRECTIVE_PATTERN, preprocessorColor);
                applyPatternColor(spannable, source, ASM_LABEL_PATTERN, symbolColor);
                applyPatternColor(spannable, source, ASM_NUMBER_PATTERN, numberColor);
                applyPatternColor(spannable, source, ASM_STRING_PATTERN, stringColor);
                applyPatternColor(spannable, source, ASM_COMMENT_PATTERN, commentColor);
            }

            editable.replace(0, editable.length(), spannable);
            int safeStart = Math.max(0, Math.min(start, binding.editAsm.length()));
            int safeEnd = Math.max(0, Math.min(end, binding.editAsm.length()));
            binding.editAsm.setSelection(safeStart, safeEnd);
        } finally {
            isApplyingHighlight = false;
        }
    }

    private void applyPatternColor(SpannableStringBuilder spannable, String source, Pattern pattern, @ColorInt int color) {
        Matcher matcher = pattern.matcher(source);
        while (matcher.find()) {
            spannable.setSpan(new ForegroundColorSpan(color), matcher.start(), matcher.end(), Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
        }
    }

    private boolean isCurrentCMode() {
        if (currentPort != null && !currentPort.hasAsmMode) {
            return true;
        }
        return currentModeIsC;
    }

    /** Precarga el anuncio intersticial para tenerlo listo al cerrar el visor hex. */
    private void loadInterstitialAd() {
        // No cargar intersticiales si los anuncios fueron eliminados
        if (!BillingManager.shouldShowAds(this)) return;

        AdRequest adRequest = new AdRequest.Builder().build();
        InterstitialAd.load(this, getString(R.string.ad_interstitial_id), adRequest,
            new InterstitialAdLoadCallback() {
                @Override
                public void onAdLoaded(@NonNull InterstitialAd interstitialAd) {
                    mInterstitialAd = interstitialAd;
                    Log.d(TAG, "Interstitial ad loaded.");
                }
                @Override
                public void onAdFailedToLoad(@NonNull LoadAdError loadAdError) {
                    mInterstitialAd = null;
                    Log.d(TAG, "Interstitial ad failed to load: " + loadAdError.getMessage());
                }
            });
    }

    private void initResources() {
        executor.execute(() -> {
            boolean extracted = AssetExtractor.areAssetsExtracted(this);
            if (!extracted) {
                mainHandler.post(() -> binding.loadingOverlay.setVisibility(View.VISIBLE));
                log(getString(R.string.log_preparing_resources));
                boolean success = AssetExtractor.extractAssets(this, "data/data/com.diamon.ptc/files/usr", new File(getFilesDir(), "usr"));
                mainHandler.post(() -> binding.loadingOverlay.setVisibility(View.GONE));
                log(getString(success ? R.string.log_resources_extracted : R.string.log_resources_extract_error));
            }
            if (sdcc != null) {
                sdcc.setupSymlinks();
            }
            loadDeviceList();
        });
    }

    // ═══════════════════════════════════════════════════════════════════
    // Multi-port architecture management
    // ═══════════════════════════════════════════════════════════════════

    private void setupArchitectureSpinner() {
        String[] families = PortRegistry.getFamilyNames();
        ArrayAdapter<String> archAdapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, families);
        archAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        binding.spinnerArch.setAdapter(archAdapter);

        int savedArch = getSharedPreferences(PREFS_NAME, MODE_PRIVATE).getInt(KEY_SELECTED_ARCH, 0);
        if (savedArch >= 0 && savedArch < families.length) {
            binding.spinnerArch.setSelection(savedArch);
        }

        binding.spinnerArch.setOnItemSelectedListener(new android.widget.AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(android.widget.AdapterView<?> parent, View view, int position, long id) {
                getSharedPreferences(PREFS_NAME, MODE_PRIVATE).edit().putInt(KEY_SELECTED_ARCH, position).apply();
                onArchitectureChanged(position);
            }
            @Override
            public void onNothingSelected(android.widget.AdapterView<?> parent) {}
        });
    }

    private void onArchitectureChanged(int portIndex) {
        currentPort = PortRegistry.getPort(portIndex);

        // Sub-architecture spinner
        if (currentPort.hasSubArchitectures()) {
            binding.rowSubArch.setVisibility(View.VISIBLE);
            binding.dividerSubArch.setVisibility(View.VISIBLE);
            ArrayAdapter<String> subAdapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, currentPort.subArchLabels);
            subAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
            binding.spinnerSubArch.setAdapter(subAdapter);

            int savedSub = getSharedPreferences(PREFS_NAME, MODE_PRIVATE).getInt(KEY_SELECTED_SUB_ARCH, 0);
            if (savedSub >= 0 && savedSub < currentPort.subArchLabels.length) {
                binding.spinnerSubArch.setSelection(savedSub);
            }
            binding.spinnerSubArch.setOnItemSelectedListener(new android.widget.AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(android.widget.AdapterView<?> parent, View view, int position, long id) {
                    currentSubArchIndex = position;
                    getSharedPreferences(PREFS_NAME, MODE_PRIVATE).edit().putInt(KEY_SELECTED_SUB_ARCH, position).apply();
                    if (currentPort.hasDeviceSelector()) {
                        loadDeviceList();
                    }
                }
                @Override
                public void onNothingSelected(android.widget.AdapterView<?> parent) {}
            });
        } else {
            binding.rowSubArch.setVisibility(View.GONE);
            binding.dividerSubArch.setVisibility(View.GONE);
            currentSubArchIndex = 0;
        }

        // Device selector
        if (currentPort.hasDeviceSelector()) {
            binding.rowDevice.setVisibility(View.VISIBLE);
            binding.dividerDevice.setVisibility(View.VISIBLE);
            binding.labelDevice.setText(currentPort.hasAsmMode ? getString(R.string.label_pic) : getString(R.string.label_device));
            loadDeviceList();
        } else {
            binding.rowDevice.setVisibility(View.GONE);
            binding.dividerDevice.setVisibility(View.GONE);
        }

        // Language toggle (ASM/C) — only for PIC
        if (currentPort.hasAsmMode) {
            binding.rowLanguage.setVisibility(View.VISIBLE);
            binding.dividerLanguage.setVisibility(View.VISIBLE);
        } else {
            binding.rowLanguage.setVisibility(View.GONE);
            binding.dividerLanguage.setVisibility(View.GONE);
            currentModeIsC = true;
        }

        // Update button text and editor hint
        if (currentPort.hasAsmMode && !currentModeIsC) {
            binding.btnAssemble.setText(getString(R.string.btn_assemble));
            binding.editAsm.setHint(currentPort.editorHintAsm != null ? currentPort.editorHintAsm : getString(R.string.hint_editor_asm));
        } else {
            binding.btnAssemble.setText(getString(R.string.btn_compile));
            binding.editAsm.setHint(currentPort.editorHintC != null ? currentPort.editorHintC : getString(R.string.hint_editor_c));
        }

        // Si el archivo activo contiene solo código de ejemplo o está vacío, cargar el template del nuevo puerto
        ModuleState state = getCurrentState();
        if (state.activeFile != null && state.files.containsKey(state.activeFile)) {
            String currentContent = state.files.get(state.activeFile);
            if (isDefaultSampleCode(currentContent)) {
                String newCode = (currentPort.hasAsmMode && !currentModeIsC && currentPort.defaultAsmCode != null)
                        ? currentPort.defaultAsmCode
                        : currentPort.defaultCCode;
                if (newCode != null && !newCode.isEmpty()) {
                    state.files.put(state.activeFile, newCode);
                }
            }
        }

        renderCurrentModule();
    }

    private boolean isDefaultSampleCode(String content) {
        if (content == null || content.trim().isEmpty()) return true;
        if (content.equals(DEFAULT_C) || content.equals(DEFAULT_ASM)) return true;
        for (PortConfig p : PortRegistry.getAllPorts()) {
            if (content.equals(p.defaultCCode)) return true;
            if (p.defaultAsmCode != null && content.equals(p.defaultAsmCode)) return true;
        }
        return false;
    }

    private void loadDeviceList() {
        if (currentPort == null || !currentPort.hasDeviceSelector()) return;

        executor.execute(() -> {
            File headerDir = new File(getFilesDir(), "usr/share/" + currentPort.headerIncludeDir);
            List<String> devices = new ArrayList<>();
            String[] files = headerDir.list();
            if (files != null) {
                for (String file : files) {
                    if (file.toLowerCase(Locale.US).endsWith(currentPort.headerExtension)) {
                        String name = file.substring(0, file.length() - currentPort.headerExtension.length());
                        if (currentPort.headerPrefix != null && !currentPort.headerPrefix.isEmpty()
                                && name.toLowerCase(Locale.US).startsWith(currentPort.headerPrefix.toLowerCase(Locale.US))) {
                            name = name.substring(currentPort.headerPrefix.length());
                        }
                        if (currentPort.headerUpperCase) {
                            name = name.toUpperCase(Locale.US);
                        }
                        if (!name.isEmpty()) {
                            devices.add(name);
                        }
                    }
                }
            }

            Collections.sort(devices);
            if (devices.isEmpty() && currentPort.defaultDevice != null) {
                devices.add(currentPort.defaultDevice);
            }

            List<String> finalDevices = devices;
            mainHandler.post(() -> {
                ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, finalDevices);
                adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
                binding.spinnerPic.setAdapter(adapter);

                String savedDevice = getSharedPreferences(PREFS_NAME, MODE_PRIVATE).getString(KEY_SELECTED_PIC, null);
                int index = savedDevice == null ? -1 : finalDevices.indexOf(savedDevice);
                if (index < 0 && currentPort.defaultDevice != null) {
                    index = finalDevices.indexOf(currentPort.defaultDevice);
                }
                if (index < 0 && !finalDevices.isEmpty()) index = 0;
                if (index >= 0) {
                    binding.spinnerPic.setSelection(index);
                }

                binding.spinnerPic.setOnItemSelectedListener(new android.widget.AdapterView.OnItemSelectedListener() {
                    @Override
                    public void onItemSelected(android.widget.AdapterView<?> parent, View view, int position, long id) {
                        String selected = adapter.getItem(position);
                        if (selected == null) return;
                        getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                                .edit()
                                .putString(KEY_SELECTED_PIC, selected)
                                .apply();
                    }
                    @Override
                    public void onNothingSelected(android.widget.AdapterView<?> parent) {}
                });
            });
        });
    }

    private void assembleCode() {
        saveActiveEditorContent();
        ModuleState state = getCurrentState();

        if (state.files.isEmpty()) {
            log(getString(R.string.log_no_files_to_compile));
            return;
        }

        if (!hasAtLeastOneNonEmptySource(state)) {
            log(getString(R.string.log_no_valid_input_files));
            return;
        }

        if (!runToolchainPreflightChecks(isCurrentCMode())) {
            log(getString(R.string.log_preflight_failed));
            return;
        }

        String selectedDevice = null;
        if (currentPort != null && currentPort.hasDeviceSelector() && binding.spinnerPic.getSelectedItem() != null) {
            selectedDevice = binding.spinnerPic.getSelectedItem().toString();
        } else if (currentPort != null && currentPort.defaultDevice != null) {
            selectedDevice = currentPort.defaultDevice;
        }

        String projectName = resolveProjectName();

        File projectDir = getProjectDir(projectName);
        if (!projectDir.exists() && !projectDir.mkdirs()) {
            log(getString(R.string.log_cant_create_project_dir));
            return;
        }

        // Limpiar archivos anteriores para asegurar una compilación limpia
        cleanupProjectDir(projectDir);

        LinkedHashMap<String, String> snapshotFiles = new LinkedHashMap<>(state.files);
        for (String fileName : snapshotFiles.keySet()) {
            boolean saved = FileManager.writeToFile(new File(projectDir, fileName), snapshotFiles.get(fileName));
            if (!saved) {
                log(getString(R.string.log_cant_save_source, fileName));
                return;
            }
        }

        if (currentPort != null && currentPort.hasAsmMode && !currentModeIsC) {
            assembleAsmProject(projectDir, selectedDevice != null ? selectedDevice : "16F628A", snapshotFiles, state.activeFile, projectName);
        } else {
            compileCProject(projectDir, selectedDevice, snapshotFiles, state.activeFile, projectName);
        }
    }

    private void cleanupProjectDir(File projectDir) {
        File[] files = projectDir.listFiles();
        if (files == null) return;
        for (File f : files) {
            String name = f.getName().toLowerCase(Locale.US);
            if (name.endsWith(".hex") || name.endsWith(".o") || name.endsWith(".rel") || name.endsWith(".ihx") || name.endsWith(".cod")) {
                f.delete();
            }
        }
    }

    private boolean hasAtLeastOneNonEmptySource(ModuleState state) {
        for (String content : state.files.values()) {
            if (content != null && !content.trim().isEmpty()) {
                return true;
            }
        }
        return false;
    }

    private boolean runToolchainPreflightChecks(boolean forCModule) {
        List<String> issues = forCModule ? sdcc.getSetupIssues() : gpUtils.getSetupIssues();
        if (issues.isEmpty()) {
            return true;
        }
        for (String issue : issues) {
            log(getString(R.string.log_precheck_issue, issue));
        }
        return false;
    }

    private void assembleAsmProject(File projectDir, String selectedPic, LinkedHashMap<String, String> snapshotFiles,
                                    String activeFileName, String projectName) {
        executor.execute(() -> {
            isCompiling = true;
            try {
                List<String> asmFiles = collectSourceFiles(snapshotFiles, ".asm");
                if (asmFiles.isEmpty()) {
                    log(getString(R.string.log_add_asm_source));
                    return;
                }

                String projectMain = projectName + ".asm";
                String preferredEntry = (activeFileName != null && activeFileName.endsWith(".asm")) 
                                        ? activeFileName 
                                        : projectMain;
                                        
                prioritizeMainSource(asmFiles, preferredEntry);

                String outputBaseName = projectName;

                List<String> objectFiles = new ArrayList<>();
                for (String asmFile : asmFiles) {
                    if (!new File(projectDir, asmFile).exists()) {
                        log(getString(R.string.log_source_not_found, asmFile));
                        return;
                    }

                    List<String> visibleArgs = new ArrayList<>(Arrays.asList(
                            "-c",
                            "-p", selectedPic.toLowerCase(Locale.US),
                            asmFile
                    ));

                    List<String> extraArgs = new ArrayList<>(Arrays.asList(
                            "-I", projectDir.getAbsolutePath()
                    ));

                    log("$ gpasm " + String.join(" ", visibleArgs));
                    int exitCode = gpUtils.executeGpasmStreaming(projectDir, visibleArgs, extraArgs, this::logRaw);

                    if (exitCode != 0) {
                        log(getString(R.string.log_gpasm_failed, asmFile, exitCode));
                        return;
                    }

                    String objectName = getBaseName(asmFile) + ".o";
                    File objectFile = new File(projectDir, objectName);
                    if (!objectFile.exists()) {
                        log(getString(R.string.log_object_not_generated, objectName));
                        return;
                    }
                    objectFiles.add(objectName);
                }

                if (objectFiles.isEmpty()) {
                    log(getString(R.string.log_no_asm_objects_to_link));
                    return;
                }

                List<String> linkArgs = new ArrayList<>();
                linkArgs.add("-o");
                linkArgs.add(outputBaseName + ".hex");
                linkArgs.addAll(objectFiles);

                log("$ gplink " + String.join(" ", linkArgs));
                int linkResult = gpUtils.executeGplinkStreaming(projectDir, linkArgs, null, this::logRaw);
                if (linkResult != 0) {
                    log(getString(R.string.log_gplink_failed, linkResult));
                    return;
                }

                applyOptionalPostProcessing(projectDir, outputBaseName);
                checkGenerationSuccess(projectDir, ".hex", false);
            } finally {
                isCompiling = false;
            }
        });
    }

    private void compileCProject(File projectDir, String selectedDevice, LinkedHashMap<String, String> snapshotFiles,
                                 String activeFileName, String projectName) {
        executor.execute(() -> {
            isCompiling = true;
            try {
                List<String> cFiles = collectSourceFiles(snapshotFiles, ".c");

                if (cFiles.isEmpty()) {
                    log(getString(R.string.log_add_c_source));
                    return;
                }

                String arch;
                if (currentPort != null && currentPort.hasAsmMode) {
                    // PIC: auto-detect pic16 or pic14 based on device name or sub-arch
                    if (selectedDevice != null && selectedDevice.toUpperCase(Locale.US).startsWith("18")) {
                        arch = "pic16";
                    } else if (currentSubArchIndex == 1) {
                        arch = "pic16";
                    } else {
                        arch = "pic14";
                    }
                } else if (currentPort != null) {
                    arch = currentPort.resolveArch(currentSubArchIndex);
                } else {
                    arch = "pic14";
                }
                
                String projectMain = projectName + ".c";
                String preferredEntry = (activeFileName != null && activeFileName.endsWith(".c")) 
                                        ? activeFileName 
                                        : projectMain;
                prioritizeMainSource(cFiles, preferredEntry);

                String outputBaseName = projectName;
                
                List<String> objFiles = new ArrayList<>();
                for (String cFile : cFiles) {
                    if (!new File(projectDir, cFile).exists()) {
                        log(getString(R.string.log_source_not_found, cFile));
                        return;
                    }

                    List<String> visibleArgs = new ArrayList<>();
                    visibleArgs.add("-m" + arch);
                    if (currentPort != null && currentPort.hasProcessorFlag && selectedDevice != null && !selectedDevice.isEmpty()) {
                        visibleArgs.add("-p" + selectedDevice.toLowerCase(Locale.US));
                    }
                    if (currentPort != null && currentPort.useNonFree) {
                        visibleArgs.add("--use-non-free");
                    }
                    visibleArgs.add("-c");
                    visibleArgs.add(cFile);

                    List<String> extraArgs = new ArrayList<>(Arrays.asList(
                            "-I" + projectDir.getAbsolutePath()
                    ));

                    log("$ sdcc " + String.join(" ", visibleArgs));
                    int compileResult = sdcc.executeSdccStreaming(projectDir, visibleArgs, extraArgs, this::logRaw);
                    
                    if (compileResult != 0) {
                        log(getString(R.string.log_sdcc_compile_failed, cFile, compileResult));
                        return;
                    }

                    String baseName = getBaseName(cFile);
                    File objFile = new File(projectDir, baseName + ".o");
                    
                    // Si no encontramos el .o, buscar .rel
                    if (!objFile.exists()) {
                         File relFile = new File(projectDir, baseName + ".rel");
                         if (relFile.exists()) {
                             objFile = relFile;
                         }
                    }

                    if (!objFile.exists()) {
                        log(getString(R.string.log_sdcc_object_not_generated, cFile));
                        return;
                    }
                    
                    objFiles.add(objFile.getName());
                }

                if (objFiles.isEmpty()) {
                    log(getString(R.string.log_no_c_objects_to_link));
                    return;
                }

                List<String> linkArgs = new ArrayList<>();
                linkArgs.add("-m" + arch);
                if (currentPort != null && currentPort.hasProcessorFlag && selectedDevice != null && !selectedDevice.isEmpty()) {
                    linkArgs.add("-p" + selectedDevice.toLowerCase(Locale.US));
                }
                if (currentPort != null && currentPort.useNonFree) {
                    linkArgs.add("--use-non-free");
                }
                if (currentPort != null && currentPort.outputFormat != null) {
                    linkArgs.add(currentPort.outputFormat);
                }
                linkArgs.addAll(objFiles);
                linkArgs.add("-o");
                linkArgs.add(outputBaseName + ".hex");

                List<String> extraLinkArgs = new ArrayList<>(Arrays.asList(
                        "-I" + projectDir.getAbsolutePath()
                ));

                log("$ sdcc " + String.join(" ", linkArgs));
                int result = sdcc.executeSdccStreaming(projectDir, linkArgs, extraLinkArgs, this::logRaw);
                if (result != 0) {
                    log(getString(R.string.log_sdcc_link_failed, result));
                    return;
                }

                // Normalizar salidas
                normalizeCOutputArtifacts(projectDir, outputBaseName);
                applyOptionalPostProcessing(projectDir, outputBaseName);
                checkGenerationSuccess(projectDir, ".hex", true);
            } finally {
                isCompiling = false;
            }
        });
    }

    private List<String> collectSourceFiles(LinkedHashMap<String, String> snapshotFiles, String extension) {
        List<String> sources = new ArrayList<>();
        for (String file : snapshotFiles.keySet()) {
            if (file.toLowerCase(Locale.US).endsWith(extension) && !snapshotFiles.getOrDefault(file, "").trim().isEmpty()) {
                sources.add(file);
            }
        }
        return sources;
    }

    private void prioritizeMainSource(List<String> sourceFiles, String preferredFileName) {
        if (preferredFileName == null) {
            return;
        }
        for (int i = 0; i < sourceFiles.size(); i++) {
            if (sourceFiles.get(i).equalsIgnoreCase(preferredFileName)) {
                if (i > 0) {
                    String main = sourceFiles.remove(i);
                    sourceFiles.add(0, main);
                }
                return;
            }
        }
    }

    private String getBaseName(String fileName) {
        int dot = fileName.lastIndexOf('.');
        return dot > 0 ? fileName.substring(0, dot) : fileName;
    }

    private boolean didCommandFail(String commandOutput) {
        Matcher matcher = Pattern.compile("Código de salida:\\s*(-?\\d+)").matcher(commandOutput == null ? "" : commandOutput);
        if (!matcher.find()) {
            return true;
        }
        try {
            return Integer.parseInt(matcher.group(1)) != 0;
        } catch (NumberFormatException e) {
            return true;
        }
    }

    private void normalizeCOutputArtifacts(File projectDir, String outputBaseName) {
        File hexTarget = new File(projectDir, outputBaseName + ".hex");
        
        // Buscar cualquier .ihx o .HEX que coincida con lo que SDCC pudo haber generado
        File[] files = projectDir.listFiles();
        if (files == null) return;

        for (File f : files) {
            String name = f.getName();
            if (name.equalsIgnoreCase(outputBaseName + ".ihx") || 
                name.equalsIgnoreCase(outputBaseName + ".HEX")) {
                
                if (!name.equals(hexTarget.getName())) {
                     if (hexTarget.exists()) hexTarget.delete();
                     f.renameTo(hexTarget);
                     log(getString(R.string.log_renamed_output, name, hexTarget.getName()));
                }
            }
        }
    }

    private void checkGenerationSuccess(File projectDir, String extension, boolean isCModule) {
        File[] files = projectDir.listFiles();
        if (files == null) {
            log(getString(R.string.log_no_output_found, extension));
            return;
        }

        List<String> generatedFiles = new ArrayList<>();
        File expectedFile = null;
        
        for (File file : files) {
            String lowerName = file.getName().toLowerCase(Locale.US);
            if (lowerName.endsWith(extension)) {
                 expectedFile = file;
            }
            if (lowerName.endsWith(".hex") || lowerName.endsWith(".ihx") || lowerName.endsWith(".cod") || lowerName.endsWith(".lst")
                    || lowerName.endsWith(".asm") || lowerName.endsWith(".c") || lowerName.endsWith(".inc")
                    || lowerName.endsWith(".h") || lowerName.endsWith(".rel") || lowerName.endsWith(".o")) {
                generatedFiles.add(file.getName());
            }
        }

        Collections.sort(generatedFiles);
        if (!generatedFiles.isEmpty()) {
            log(getString(R.string.log_project_files, TextUtils.join(", ", generatedFiles)));
        }

        if (expectedFile != null) {
            log(getString(isCModule ? R.string.log_compile_success : R.string.log_assemble_success));
            log(getString(R.string.log_generated_output, expectedFile.getName()));
            return;
        }
        log(getString(R.string.log_no_expected_output, extension));
    }

    private File getProjectDir(String projectName) {
        return new File(new File(getFilesDir(), "projects"), projectName);
    }

    /**
     * Devuelve el nombre actual del proyecto. 
     * Si el usuario escribió algo, devuelve eso (sanitizado).
     * Si no, devuelve el genérico (ej. asm_project1).
     */
    private String resolveProjectName() {
        return getCurrentState().currentProjectName;
    }

    private String normalizeProjectName(String name, boolean isC) {
        String trimmed = name.trim().replaceAll("[^a-zA-Z0-9_]", "_");
        if (trimmed.isEmpty()) {
            // Esto no debería ocurrir gracias a la lógica del TextWatcher, pero por seguridad:
            return isC ? cState.genericBaseName : asmState.genericBaseName;
        }
        return trimmed;
    }

    private int resolveNextProjectIndex(String projectPrefix, String counterKey) {
        android.content.SharedPreferences prefs = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        int max = prefs.getInt(counterKey, 0);
        File projectsDir = new File(getFilesDir(), "projects");
        File[] dirs = projectsDir.listFiles();
        if (dirs != null) {
            for (File dir : dirs) {
                if (!dir.isDirectory()) continue;
                String name = dir.getName();
                if (!name.startsWith(projectPrefix)) continue;
                String suffix = name.substring(projectPrefix.length());
                if (suffix.isEmpty()) continue;
                boolean allDigits = true;
                for (int i = 0; i < suffix.length(); i++) {
                    if (!Character.isDigit(suffix.charAt(i))) {
                        allDigits = false;
                        break;
                    }
                }
                if (!allDigits) continue;
                try {
                    int n = Integer.parseInt(suffix);
                    if (n > max) max = n;
                } catch (NumberFormatException ignored) {
                }
            }
        }
        return max + 1;
    }

    private void applyOptionalPostProcessing(File projectDir, String outputBaseName) {
        android.content.SharedPreferences prefs = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        boolean optPackihx = prefs.getBoolean(KEY_OPT_PACKIHX, false);
        boolean optMakebin = prefs.getBoolean(KEY_OPT_MAKEBIN, false);
        boolean optAutoApply = prefs.getBoolean(KEY_OPT_AUTO_APPLY, true);

        if (!optAutoApply && !optPackihx && !optMakebin) {
            return;
        }

        File hexTarget = new File(projectDir, outputBaseName + ".hex");
        if (!hexTarget.exists()) {
            hexTarget = findFirstWithExtension(projectDir, ".hex");
            if (hexTarget == null) {
                hexTarget = findFirstWithExtension(projectDir, ".ihx");
            }
        }

        if (hexTarget == null || !hexTarget.exists()) {
            return;
        }

        if (optPackihx) {
            log(getString(R.string.log_packihx_started, hexTarget.getName()));
            int packResult = sdcc.executePackihx(projectDir, hexTarget, hexTarget, this::logRaw);
            if (packResult == 0) {
                log(getString(R.string.log_packihx_success, hexTarget.getName()));
            } else {
                log(getString(R.string.log_packihx_failed, packResult));
            }
        }

        if (optMakebin) {
            log(getString(R.string.log_makebin_started, hexTarget.getName()));
            boolean isGameBoy = currentPort != null && "sm83".equalsIgnoreCase(currentPort.sdccArch);
            File binTarget = new File(projectDir, outputBaseName + ".bin");
            int binResult = sdcc.executeMakebin(projectDir, isGameBoy, hexTarget, binTarget, this::logRaw);
            if (binResult == 0 && binTarget.exists()) {
                log(getString(R.string.log_makebin_success, binTarget.getName(), binTarget.length()));
            } else {
                log(getString(R.string.log_makebin_failed, binResult));
            }
        }
    }

    private void showOptionalToolsDialog() {
        android.content.SharedPreferences prefs = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        View view = LayoutInflater.from(this).inflate(R.layout.dialog_optional_tools, null);

        com.google.android.material.checkbox.MaterialCheckBox chkPackihx = view.findViewById(R.id.chk_packihx);
        com.google.android.material.checkbox.MaterialCheckBox chkMakebin = view.findViewById(R.id.chk_makebin);
        com.google.android.material.checkbox.MaterialCheckBox chkAutoApply = view.findViewById(R.id.chk_auto_apply);

        chkPackihx.setChecked(prefs.getBoolean(KEY_OPT_PACKIHX, false));
        chkMakebin.setChecked(prefs.getBoolean(KEY_OPT_MAKEBIN, false));
        chkAutoApply.setChecked(prefs.getBoolean(KEY_OPT_AUTO_APPLY, true));

        chkPackihx.setOnCheckedChangeListener((btn, isChecked) -> {
            prefs.edit().putBoolean(KEY_OPT_PACKIHX, isChecked).apply();
        });
        chkMakebin.setOnCheckedChangeListener((btn, isChecked) -> {
            prefs.edit().putBoolean(KEY_OPT_MAKEBIN, isChecked).apply();
        });
        chkAutoApply.setOnCheckedChangeListener((btn, isChecked) -> {
            prefs.edit().putBoolean(KEY_OPT_AUTO_APPLY, isChecked).apply();
        });

        AlertDialog dialog = new AlertDialog.Builder(this)
                .setTitle(R.string.dialog_optional_tools_title)
                .setView(view)
                .setPositiveButton(R.string.btn_close, null)
                .create();

        View btnPackihx = view.findViewById(R.id.btn_run_packihx_action);
        if (btnPackihx != null) {
            btnPackihx.setOnClickListener(v -> {
                dialog.dismiss();
                runPackihxNow();
            });
        }

        View btnMakebin = view.findViewById(R.id.btn_run_makebin_action);
        if (btnMakebin != null) {
            btnMakebin.setOnClickListener(v -> {
                dialog.dismiss();
                runMakebinNow();
            });
        }

        View btnSim = view.findViewById(R.id.btn_run_simulator_action);
        if (btnSim != null) {
            btnSim.setOnClickListener(v -> {
                dialog.dismiss();
                runSimulatorNow();
            });
        }

        dialog.show();
    }

    private void runPackihxNow() {
        String projectName = resolveProjectName();
        if (projectName == null) {
            log(getString(R.string.log_compile_first));
            return;
        }
        File projectDir = getProjectDir(projectName);
        File hexFile = findFirstWithExtension(projectDir, ".hex");
        if (hexFile == null) {
            hexFile = findFirstWithExtension(projectDir, ".ihx");
        }
        if (hexFile == null || !hexFile.exists()) {
            log(getString(R.string.log_no_hex_for_tool));
            return;
        }

        File finalHex = hexFile;
        executor.execute(() -> {
            log(getString(R.string.log_packihx_started, finalHex.getName()));
            int result = sdcc.executePackihx(projectDir, finalHex, finalHex, this::logRaw);
            if (result == 0) {
                log(getString(R.string.log_packihx_success, finalHex.getName()));
            } else {
                log(getString(R.string.log_packihx_failed, result));
            }
        });
    }

    private void runMakebinNow() {
        String projectName = resolveProjectName();
        if (projectName == null) {
            log(getString(R.string.log_compile_first));
            return;
        }
        File projectDir = getProjectDir(projectName);
        File hexFile = findFirstWithExtension(projectDir, ".hex");
        if (hexFile == null) {
            hexFile = findFirstWithExtension(projectDir, ".ihx");
        }
        if (hexFile == null || !hexFile.exists()) {
            log(getString(R.string.log_no_hex_for_tool));
            return;
        }

        File finalHex = hexFile;
        executor.execute(() -> {
            log(getString(R.string.log_makebin_started, finalHex.getName()));
            boolean isGameBoy = currentPort != null && "sm83".equalsIgnoreCase(currentPort.sdccArch);
            File binTarget = new File(projectDir, projectName + ".bin");
            int result = sdcc.executeMakebin(projectDir, isGameBoy, finalHex, binTarget, this::logRaw);
            if (result == 0 && binTarget.exists()) {
                log(getString(R.string.log_makebin_success, binTarget.getName(), binTarget.length()));
            } else {
                log(getString(R.string.log_makebin_failed, result));
            }
        });
    }

    private void runSimulatorNow() {
        String projectName = resolveProjectName();
        if (projectName == null) {
            log(getString(R.string.log_compile_first));
            return;
        }
        File projectDir = getProjectDir(projectName);
        File hexFile = findFirstWithExtension(projectDir, ".hex");
        if (hexFile == null) {
            hexFile = findFirstWithExtension(projectDir, ".ihx");
        }
        if (hexFile == null || !hexFile.exists()) {
            log(getString(R.string.log_no_hex_for_tool));
            return;
        }

        String simName = (currentPort != null && currentPort.simulatorBinary != null) 
                         ? currentPort.simulatorBinary 
                         : "s51";
        String familyName = (currentPort != null) ? currentPort.familyName : "MCS-51";

        File finalHex = hexFile;
        executor.execute(() -> {
            log(getString(R.string.log_simulator_started, simName, familyName));
            int result = sdcc.executeSimulator(projectDir, simName, finalHex, "step 20; state; quit", this::logRaw);
            if (result == 0) {
                log(getString(R.string.log_simulator_finished, result));
            } else {
                log(getString(R.string.log_simulator_failed, simName));
            }
        });
    }

    private void viewGeneratedFile(String extension) {
        String projectName = resolveProjectName();
        if (projectName == null) {
            log(getString(R.string.log_compile_first));
            return;
        }

        File projectDir = getProjectDir(projectName);
        File hexTarget = new File(projectDir, projectName + ".hex");
        if (!hexTarget.exists()) hexTarget = findFirstWithExtension(projectDir, ".hex");
        if (hexTarget == null) hexTarget = findFirstWithExtension(projectDir, ".ihx");

        File binTarget = new File(projectDir, projectName + ".bin");
        if (!binTarget.exists()) binTarget = findFirstWithExtension(projectDir, ".bin");

        if (hexTarget != null && hexTarget.exists() && binTarget != null && binTarget.exists()) {
            final File finalHex = hexTarget;
            final File finalBin = binTarget;
            new AlertDialog.Builder(this)
                    .setTitle(R.string.dialog_select_viewer_format)
                    .setItems(new CharSequence[]{
                            getString(R.string.format_hex_file) + " (" + finalHex.getName() + ")",
                            getString(R.string.format_bin_file) + " (" + finalBin.getName() + ")"
                    }, (d, which) -> {
                        if (which == 0) {
                            displayHexOrBinFile(finalHex);
                        } else {
                            displayHexOrBinFile(finalBin);
                        }
                    })
                    .setNegativeButton(R.string.btn_cancel, null)
                    .show();
            return;
        }

        File target = new File(projectDir, projectName + extension);
        if (!target.exists()) {
            target = findFirstWithExtension(projectDir, extension);
        }
        if (target == null && ".hex".equalsIgnoreCase(extension)) {
            target = binTarget;
        }

        if (target == null || !target.exists()) {
            log(getString(R.string.log_no_file_for_project, extension));
            return;
        }

        displayHexOrBinFile(target);
    }

    private void displayHexOrBinFile(File target) {
        if (target.getName().toLowerCase(Locale.US).endsWith(".bin")) {
            try {
                byte[] data = java.nio.file.Files.readAllBytes(target.toPath());
                if (data.length == 0) {
                    log(getString(R.string.log_empty_file, target.getName()));
                    return;
                }
                TreeMap<Integer, Byte> memory = IntelHexParser.parseBinary(data);
                showAdvancedHexViewer(memory);
            } catch (Exception e) {
                log(getString(R.string.log_error_reading_file, target.getName(), e.getMessage()));
            }
        } else if (target.getName().toLowerCase(Locale.US).endsWith(".hex") || target.getName().toLowerCase(Locale.US).endsWith(".ihx")) {
            String content = FileManager.readFile(target);
            if (content.isEmpty()) {
                log(getString(R.string.log_empty_file, target.getName()));
                return;
            }
            TreeMap<Integer, Byte> memory = IntelHexParser.parse(content);
            showAdvancedHexViewer(memory);
        } else {
            String content = FileManager.readFile(target);
            showSimpleTextViewer(target.getName(), content);
        }
    }

    private File findFirstWithExtension(File dir, String extension) {
        File[] files = dir.listFiles();
        if (files == null) return null;
        for (File file : files) {
            if (file.getName().toLowerCase(Locale.US).endsWith(extension)) {
                return file;
            }
        }
        return null;
    }

    private void showSimpleTextViewer(String title, String content) {
        new AlertDialog.Builder(this)
                .setTitle(title)
                .setMessage(content)
                .setPositiveButton(getString(R.string.btn_close), null)
                .show();
    }

    private void showAdvancedHexViewer(String content) {
        TreeMap<Integer, Byte> memory = IntelHexParser.parse(content);
        showAdvancedHexViewer(memory);
    }

    private void showAdvancedHexViewer(TreeMap<Integer, Byte> memory) {
        View popupView = LayoutInflater.from(this).inflate(R.layout.popup_hex_viewer, null);
        PopupWindow popupWindow = new PopupWindow(
                popupView,
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.MATCH_PARENT,
                true);

        ListView listView = popupView.findViewById(R.id.list_hex);
        List<String[]> rows = new ArrayList<>();
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

        popupView.findViewById(R.id.btn_close_popup).setOnClickListener(v -> {
            // Solo mostrar intersticial si se deben mostrar anuncios
            if (BillingManager.shouldShowAds(this) && mInterstitialAd != null) {
                mInterstitialAd.setFullScreenContentCallback(new FullScreenContentCallback() {
                    @Override
                    public void onAdDismissedFullScreenContent() {
                        popupWindow.dismiss();
                        loadInterstitialAd();
                    }
                    @Override
                    public void onAdFailedToShowFullScreenContent(@NonNull com.google.android.gms.ads.AdError adError) {
                        popupWindow.dismiss();
                        loadInterstitialAd();
                    }
                });
                mInterstitialAd.show(MainActivity.this);
                mInterstitialAd = null;
            } else {
                popupWindow.dismiss();
            }
        });
        popupWindow.showAtLocation(binding.getRoot(), Gravity.CENTER, 0, 0);
    }

    private String[] formatHexRow(int startAddr, List<Byte> bytes) {
        StringBuilder hexStr = new StringBuilder();
        StringBuilder ansi = new StringBuilder();

        for (byte b : bytes) {
            hexStr.append(String.format(Locale.US, "%02X ", b));
            ansi.append((b >= 32 && b <= 126) ? (char) b : '.');
        }

        while (hexStr.length() < 24) {
            hexStr.append("   ");
        }

        return new String[] { String.format(Locale.US, "%04X:", startAddr), hexStr.toString().trim(), ansi.toString() };
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
                | Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION
                | Intent.FLAG_GRANT_PREFIX_URI_PERMISSION);
        intent.putExtra("android.provider.extra.SHOW_ADVANCED", true);

        if (forceChange) {
            clearSavedExportUri();
        }

        Uri initialUri = resolveInitialFolderUri();
        if (initialUri != null && android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
            intent.putExtra(DocumentsContract.EXTRA_INITIAL_URI, initialUri);
        }

        folderPickerLauncher.launch(intent);
    }

    private Uri resolveInitialFolderUri() {
        Uri saved = getSavedExportUri();
        if (saved != null) {
            return saved;
        }

        try {
            return DocumentsContract.buildTreeDocumentUri("com.android.externalstorage.documents", "primary:Download");
        } catch (Exception ignore) {
            return null;
        }
    }

    private void exportToSelectedFolder(Uri treeUri) {
        String projectName = resolveProjectName();
        // Nota: Ya no forzamos rename aquí, confiamos en la sincronización en tiempo real.
        
        refreshTabs();
        loadActiveFileInEditor();

        File projectDir = getProjectDir(projectName);
        persistCurrentModuleSources(projectDir);

        executor.execute(() -> {
            List<File> filesToExport = collectProjectFilesForExport(projectDir, projectName);
            if (filesToExport.isEmpty()) {
                log(getString(R.string.log_no_files_to_export));
                return;
            }

            int count = 0;
            for (File file : filesToExport) {
                String exportName = file.getName();
                if (saveFileToDocumentTree(treeUri, exportName, file)) {
                    count++;
                }
            }

            int finalCount = count;
            log(finalCount > 0
                    ? getString(R.string.log_export_success, finalCount)
                    : getString(R.string.log_export_failed));
        });
    }

    private List<File> collectProjectFilesForExport(File projectDir, String projectName) {
        List<File> files = new ArrayList<>();
        ModuleState state = getCurrentState();

        // 1. Exportar fuentes actuales (ya tienen los nombres correctos)
        for (String sourceName : state.files.keySet()) {
            File source = new File(projectDir, sourceName);
            if (source.exists() && source.isFile()) {
                files.add(source);
            }
        }

        // 2. Exportar artefactos generados (hex, lst, etc.) que coincidan con el nombre del proyecto
        // o con los archivos fuente
        File[] projectEntries = projectDir.listFiles();
        if (projectEntries != null) {
            for (File file : projectEntries) {
                if (!file.isFile()) continue;
                String name = file.getName();
                
                // Si el archivo ya fue añadido (es fuente), saltar
                boolean alreadyAdded = false;
                for (File existing : files) {
                    if (existing.getName().equals(name)) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (alreadyAdded) continue;

                // Criterio de inclusión para artefactos:
                // Coincide con nombre del proyecto O coincide con nombre de algún archivo fuente (sin ext)
                if (name.startsWith(projectName + ".")) {
                    files.add(file);
                    continue;
                }
                
                // Chequear si corresponde a un fuente secundario (ej: utils.asm -> utils.o)
                for (String sourceName : state.files.keySet()) {
                    String base = getBaseName(sourceName);
                    if (name.startsWith(base + ".")) {
                        files.add(file);
                        break;
                    }
                }
            }
        }

        return files;
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
            log(getString(R.string.log_saf_permission_lost));
            mainHandler.post(() -> launchFolderPicker(false));
            return false;
        } catch (Exception e) {
            Log.e(TAG, "Error guardando archivo", e);
            return false;
        }
    }

    private String getMimeType(String fileName) {
        return "application/octet-stream";
    }

    private void persistCurrentModuleSources(File projectDir) {
        if (!projectDir.exists() && !projectDir.mkdirs()) {
            log(getString(R.string.log_cant_prep_export_dir));
            return;
        }

        ModuleState state = getCurrentState();
        LinkedHashMap<String, String> snapshotFiles = new LinkedHashMap<>(state.files);
        for (String fileName : snapshotFiles.keySet()) {
            boolean saved = FileManager.writeToFile(new File(projectDir, fileName), snapshotFiles.get(fileName));
            if (!saved) {
                log(getString(R.string.log_cant_save_source_export, fileName));
            }
        }
    }

    private void saveExportUri(Uri uri) {
        try {
            Uri previous = getSavedExportUri();
            if (previous != null && !previous.equals(uri)) {
                try {
                    getContentResolver().releasePersistableUriPermission(previous,
                            Intent.FLAG_GRANT_READ_URI_PERMISSION | Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
                } catch (Exception ignored) {
                }
            }

            getContentResolver().takePersistableUriPermission(uri,
                    Intent.FLAG_GRANT_READ_URI_PERMISSION | Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
            getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                    .edit()
                    .putString(KEY_EXPORT_URI, uri.toString())
                    .apply();
        } catch (SecurityException sec) {
            Log.e(TAG, "No se pudo persistir permiso SAF", sec);
            log(getString(R.string.log_cant_save_saf_permission));
        }
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
        Uri previous = getSavedExportUri();
        if (previous != null) {
            try {
                getContentResolver().releasePersistableUriPermission(previous,
                        Intent.FLAG_GRANT_READ_URI_PERMISSION | Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
            } catch (Exception ignored) {
            }
        }

        getSharedPreferences(PREFS_NAME, MODE_PRIVATE)
                .edit()
                .remove(KEY_EXPORT_URI)
                .apply();
    }

    private boolean isScrollAtBottom() {
        if (binding.scrollLogs == null || binding.textLogs == null) return true;
        int scrollY = binding.scrollLogs.getScrollY();
        int scrollHeight = binding.scrollLogs.getHeight();
        int contentHeight = binding.textLogs.getHeight();
        if (contentHeight == 0) return true;
        return (scrollY + scrollHeight) >= (contentHeight - 100);
    }

    private final Runnable logUpdater = new Runnable() {
        @Override
        public void run() {
            if (isFinishing() || isDestroyed()) {
                isLogUpdatePending = false;
                return;
            }
            String fullLogs;
            synchronized (consoleLines) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < consoleLines.size(); i++) {
                    if (i > 0) {
                        sb.append("\n");
                    }
                    sb.append(consoleLines.get(i).toString());
                }
                fullLogs = sb.toString();
                isLogUpdatePending = false;
            }

            final boolean wasAtBottom = isScrollAtBottom();
            final int scrollY = binding.scrollLogs.getScrollY();

            binding.textLogs.setText(fullLogs);

            boolean shouldScrollToBottom = wasAtBottom || isCompiling;

            if (shouldScrollToBottom) {
                binding.scrollLogs.post(() -> binding.scrollLogs.fullScroll(View.FOCUS_DOWN));
            } else {
                binding.scrollLogs.post(() -> binding.scrollLogs.setScrollY(scrollY));
            }
        }
    };

    public void log(String message) {
        if (Looper.myLooper() == Looper.getMainLooper()) {
            appendLogOnUi(message);
        } else {
            runOnUiThread(() -> appendLogOnUi(message));
        }
    }

    public void logRaw(String chunk) {
        if (Looper.myLooper() == Looper.getMainLooper()) {
            appendRawLogOnUi(chunk);
        } else {
            runOnUiThread(() -> appendRawLogOnUi(chunk));
        }
    }

    private void appendLogOnUi(String message) {
        appendRawLogOnUi(message + "\n");
    }

    private void appendRawLogOnUi(String text) {
        synchronized (consoleLines) {
            if (consoleLines.isEmpty()) {
                consoleLines.add(new StringBuilder());
                currentLineIndex = 0;
            }

            for (int i = 0; i < text.length(); i++) {
                char c = text.charAt(i);
                if (c == '\n') {
                    consoleLines.add(new StringBuilder());
                    currentLineIndex = consoleLines.size() - 1;
                    cursorAtStartOfLine = false;
                } else if (c == '\r') {
                    cursorAtStartOfLine = true;
                } else if (c == '\b') {
                    StringBuilder currentLine = consoleLines.get(currentLineIndex);
                    if (currentLine.length() > 0) {
                        currentLine.setLength(currentLine.length() - 1);
                    }
                } else {
                    StringBuilder currentLine = consoleLines.get(currentLineIndex);
                    if (cursorAtStartOfLine) {
                        currentLine.setLength(0);
                        cursorAtStartOfLine = false;
                    }
                    currentLine.append(c);
                }
            }

            while (consoleLines.size() > 1000) {
                consoleLines.remove(0);
                currentLineIndex--;
            }
            if (currentLineIndex < 0) {
                currentLineIndex = 0;
            }
        }

        if (!isLogUpdatePending) {
            isLogUpdatePending = true;
            logHandler.postDelayed(logUpdater, 80);
        }
    }

    public void clearTerminal() {
        synchronized (consoleLines) {
            consoleLines.clear();
            currentLineIndex = -1;
            cursorAtStartOfLine = false;
        }
        binding.textLogs.setText("");
        log(getString(R.string.terminal_reset));
    }

    public void toggleTerminalSize() {
        isTerminalExpanded = !isTerminalExpanded;
        if (isTerminalExpanded) {
            binding.cardEditor.setVisibility(View.GONE);
            if (binding.cardPicSelector != null) {
                binding.cardPicSelector.setVisibility(View.GONE);
            }
            if (binding.btnToggleTerminalSize != null) {
                binding.btnToggleTerminalSize.setText(R.string.btn_restore_terminal);
            }
        } else {
            binding.cardEditor.setVisibility(View.VISIBLE);
            if (binding.cardPicSelector != null) {
                binding.cardPicSelector.setVisibility(View.VISIBLE);
            }
            if (binding.btnToggleTerminalSize != null) {
                binding.btnToggleTerminalSize.setText(R.string.btn_expand_terminal);
            }
        }
    }

    private void updateLogs(String text) {
        log(text);
    }

    static {
        System.loadLibrary("ptc");
    }

    public native String stringFromJNI();

    /**
     * Maneja el clic en el ítem de menú "Quitar Anuncios".
     * Verifica el estado del billing y lanza el flujo de compra.
     */
    private void handleRemoveAdsPurchase() {
        if (!BillingManager.shouldShowAds(this)) {
            Toast.makeText(this, getString(R.string.iap_already_purchased), Toast.LENGTH_SHORT).show();
            return;
        }

        if (billingManager == null || !billingManager.isServiceConnected()) {
            Toast.makeText(this, getString(R.string.iap_billing_unavailable), Toast.LENGTH_SHORT).show();
            return;
        }

        if (!billingManager.isProductAvailable()) {
            Toast.makeText(this, getString(R.string.iap_product_unavailable), Toast.LENGTH_SHORT).show();
            return;
        }

        boolean launched = billingManager.launchPurchaseFlow(this);
        if (!launched) {
            Toast.makeText(this, getString(R.string.iap_purchase_error), Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        executor.shutdown();
        if (billingManager != null) {
            billingManager.destroy();
        }
        if (binding != null) {
            binding.adViewBanner.destroy();
        }
    }
}