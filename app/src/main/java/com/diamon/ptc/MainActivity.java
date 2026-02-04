package com.diamon.ptc;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.widget.TextView;

import com.diamon.ptc.databinding.ActivityMainBinding;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    // Ruta de los assets a extraer (relativa a assets/)
    private static final String ASSETS_PATH = "data/data/com.diamon.ptc/files/usr/share";

    private ActivityMainBinding binding;
    private final ExecutorService executor = Executors.newSingleThreadExecutor();
    private final Handler mainHandler = new Handler(Looper.getMainLooper());

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        TextView tv = binding.sampleText;
        tv.setText("Iniciando GPUTILS...");

        // Ejecutar en hilo secundario para no bloquear la UI
        executor.execute(() -> {
            // Paso 1: Extraer assets si es necesario
            if (!AssetExtractor.areAssetsExtracted(this)) {
                Log.d(TAG, "Extrayendo assets de GPUTILS...");
                updateUI("Extrayendo recursos de GPUTILS...");

                boolean success = AssetExtractor.extractAssets(
                        this,
                        ASSETS_PATH,
                        new java.io.File(getFilesDir(), "usr/share"));

                if (!success) {
                    updateUI("Error: No se pudieron extraer los recursos");
                    return;
                }
                Log.d(TAG, "Assets extraidos correctamente");
            } else {
                Log.d(TAG, "Assets ya extraidos previamente");
            }

            // Paso 2: Ejecutar gpasm -v para obtener version
            Log.d(TAG, "Ejecutando gpasm -v...");
            updateUI("Ejecutando gpasm -v...");

            GpUtilsExecutor gpUtils = new GpUtilsExecutor(this);
            String result = gpUtils.executeGpasm("-v");

            Log.d(TAG, "Resultado: " + result);
            updateUI("GPASM Version:\n" + result);
        });
    }

    /**
     * Actualiza el TextView en el hilo principal
     */
    private void updateUI(String text) {
        mainHandler.post(() -> binding.sampleText.setText(text));
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        executor.shutdown();
    }
}