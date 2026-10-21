package com.diamon.utilidades;

import android.os.Build;
import android.view.View;
import android.view.Window;
import android.view.WindowInsetsController;
import android.view.WindowManager;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.core.view.WindowInsetsControllerCompat;

/**
 * Utilidad para configurar pantalla completa y Edge-to-Edge.
 * 
 * Optimizado para Android 15 (SDK 35+):
 * - Usa EdgeToEdge.enable() de AndroidX Activity
 * - Maneja WindowInsets correctamente
 * - Proporciona retrocompatibilidad con versiones anteriores
 * 
 * Nota: En Android 15+, las apps se muestran edge-to-edge por defecto.
 * setStatusBarColor y setNavigationBarColor están deprecados y no tienen efecto.
 */
public class GestorPantalla {

    private final AppCompatActivity actividad;

    public GestorPantalla(AppCompatActivity actividad) {
        this.actividad = actividad;
    }

    /**
     * Habilita Edge-to-Edge usando la API oficial de AndroidX.
     * 
     * Esta es la forma recomendada para Android 15+ y proporciona
     * retrocompatibilidad automática con versiones anteriores.
     * 
     * Debe llamarse ANTES de setContentView().
     */
    @SuppressWarnings("deprecation")
    public void habilitarEdgeToEdge() {
        try {
            // API oficial recomendada por AndroidX Activity 1.9+ para Android 15+
            EdgeToEdge.enable(actividad);
        } catch (Exception e) {
            // Fallback manual si algo falla
            Window window = actividad.getWindow();
            WindowCompat.setDecorFitsSystemWindows(window, false);
        }

        Window window = actividad.getWindow();
        // Permitir que el contenido se extienda bajo el recorte de pantalla (notch/cutout)
        // evitando el margen negro que genera el sistema en modo inmersivo
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            WindowManager.LayoutParams lp = window.getAttributes();
            lp.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            window.setAttributes(lp);
        }
        window.setStatusBarColor(android.graphics.Color.TRANSPARENT);
        window.setNavigationBarColor(android.graphics.Color.TRANSPARENT);
    }

    /**
     * Aplica window insets a una vista específica.
     * Utiliza directamente la API nativa de Android con salvaguarda total de excepciones
     * para evitar invocar WindowInsetsCompat / TypeImpl34.systemOverlays(), lo que elimina
     * el NoSuchMethodError en compilaciones de Android 14+ y garantiza compatibilidad
     * retroactiva desde API 24 (minSdk) hasta API 37+ (Android 17).
     * 
     * @param view La vista raíz a la que aplicar los insets
     */
    @SuppressWarnings("deprecation")
    public void aplicarWindowInsets(View view) {
        if (view == null) {
            return;
        }
        view.setOnApplyWindowInsetsListener((v, insets) -> {
            int left = 0, top = 0, right = 0, bottom = 0;
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                try {
                    android.graphics.Insets bars = insets.getInsets(android.view.WindowInsets.Type.systemBars());
                    left = bars.left;
                    top = bars.top;
                    right = bars.right;
                    bottom = bars.bottom;
                } catch (Throwable t) {
                    try {
                        left = insets.getSystemWindowInsetLeft();
                        top = insets.getSystemWindowInsetTop();
                        right = insets.getSystemWindowInsetRight();
                        bottom = insets.getSystemWindowInsetBottom();
                    } catch (Throwable ignored) {
                    }
                }
            } else {
                try {
                    left = insets.getSystemWindowInsetLeft();
                    top = insets.getSystemWindowInsetTop();
                    right = insets.getSystemWindowInsetRight();
                    bottom = insets.getSystemWindowInsetBottom();
                } catch (Throwable ignored) {
                }
            }

            v.setPadding(left, top, right, bottom);
            return insets;
        });
    }

    /**
     * Aplica insets solo a la parte inferior de una vista.
     * Utiliza la API nativa sin depender de ViewCompat para máxima estabilidad entre API 24 y 37.
     * 
     * @param view La vista a la que aplicar los insets inferiores
     */
    @SuppressWarnings("deprecation")
    public void aplicarWindowInsetsInferior(View view) {
        if (view == null) {
            return;
        }
        view.setOnApplyWindowInsetsListener((v, insets) -> {
            int bottom = 0;
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                try {
                    android.graphics.Insets bars = insets.getInsets(android.view.WindowInsets.Type.systemBars());
                    bottom = bars.bottom;
                } catch (Throwable t) {
                    try {
                        bottom = insets.getSystemWindowInsetBottom();
                    } catch (Throwable ignored) {
                    }
                }
            } else {
                try {
                    bottom = insets.getSystemWindowInsetBottom();
                } catch (Throwable ignored) {
                }
            }

            v.setPadding(
                    v.getPaddingLeft(),
                    0,
                    v.getPaddingRight(),
                    bottom);

            return insets;
        });
    }

    @SuppressWarnings("deprecation")
    public void ocultarBotonesVirtuales() {
        Window window = actividad.getWindow();
        if (window == null) {
            return;
        }

        // En Android 11+ (API 30+), usar directamente el WindowInsetsController del sistema
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            try {
                WindowInsetsController controller = window.getInsetsController();
                if (controller != null) {
                    controller.hide(android.view.WindowInsets.Type.systemBars());
                    controller.setSystemBarsBehavior(
                            WindowInsetsController.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
                    return;
                }
            } catch (Throwable ignored) {
            }
        }

        // Fallback AndroidX WindowCompat
        try {
            WindowInsetsControllerCompat controller = WindowCompat.getInsetsController(window, window.getDecorView());
            if (controller != null) {
                controller.hide(WindowInsetsCompat.Type.systemBars());
                controller.setSystemBarsBehavior(
                        WindowInsetsControllerCompat.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
                return;
            }
        } catch (Throwable ignored) {
        }

        // Fallback clásico
        try {
            window.getDecorView().setSystemUiVisibility(
                    View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                            | View.SYSTEM_UI_FLAG_FULLSCREEN
                            | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);
        } catch (Throwable ignored) {
        }
    }

    /**
     * Configuración completa de Edge-to-Edge con ocultación de barras.
     * Combina Edge-to-Edge con modo inmersivo.
     */
    public void configurarEdgeToEdgeCompleto() {
        habilitarEdgeToEdge();
        ocultarBotonesVirtuales();
    }

    /**
     * Configura los colores de las barras del sistema para modo claro.
     */
    public void configurarBarrasClaro() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            WindowInsetsController controller = actividad.getWindow().getInsetsController();
            if (controller != null) {
                // Iconos oscuros para fondo claro
                controller.setSystemBarsAppearance(
                        WindowInsetsController.APPEARANCE_LIGHT_STATUS_BARS
                                | WindowInsetsController.APPEARANCE_LIGHT_NAVIGATION_BARS,
                        WindowInsetsController.APPEARANCE_LIGHT_STATUS_BARS
                                | WindowInsetsController.APPEARANCE_LIGHT_NAVIGATION_BARS);
            }
        }
    }

    /**
     * Configura los colores de las barras del sistema para modo oscuro.
     */
    public void configurarBarrasOscuro() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            WindowInsetsController controller = actividad.getWindow().getInsetsController();
            if (controller != null) {
                // Quitar apariencia light para iconos claros en fondo oscuro
                controller.setSystemBarsAppearance(
                        0,
                        WindowInsetsController.APPEARANCE_LIGHT_STATUS_BARS
                                | WindowInsetsController.APPEARANCE_LIGHT_NAVIGATION_BARS);
            }
        }
    }
}
