package com.diamon.ptc;

import android.app.Application;
import android.util.Log;

import androidx.annotation.NonNull;

/**
 * Clase Application personalizada para inicialización global y blindaje
 * contra fallos de librerías de terceros (Google Play Services, Play Protect HSDP y Billing).
 */
public class CPicApplication extends Application {

    private static final String TAG = "CPicApplication";

    @Override
    public void onCreate() {
        super.onCreate();
        instalarManejadorExcepcionesSeguro();
    }

    /**
     * Instala un manejador de excepciones no capturadas que mitiga fallos internos
     * conocidos de librerías de terceros (como HsdpShimActivity en pruebas automatizadas
     * de Google Play o incompatibilidades de desugaring en ProxyBillingActivity),
     * permitiendo que los errores normales sigan reportándose a Crashlytics.
     */
    private void instalarManejadorExcepcionesSeguro() {
        final Thread.UncaughtExceptionHandler defaultHandler = Thread.getDefaultUncaughtExceptionHandler();

        Thread.setDefaultUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() {
            @Override
            public void uncaughtException(@NonNull Thread thread, @NonNull Throwable throwable) {
                if (esExcepcionConocidaDeTerceros(throwable)) {
                    Log.w(TAG, "Excepción conocida de librerías del sistema/Google Play mitigada con éxito: " + throwable);
                    return;
                }

                if (defaultHandler != null) {
                    defaultHandler.uncaughtException(thread, throwable);
                }
            }
        });
    }

    /**
     * Identifica si una excepción proviene de un bug interno conocido de librerías del sistema
     * o de los bots de verificación automatizada de Google Play.
     */
    private boolean esExcepcionConocidaDeTerceros(Throwable throwable) {
        if (throwable == null) {
            return false;
        }

        Throwable current = throwable;
        while (current != null) {
            String msg = current.getMessage();

            // 1. Crash de HsdpShimActivity en escaneos automáticos de Google Play Protect
            if (current instanceof IllegalStateException && msg != null && msg.contains("targetPackageName is null")) {
                for (StackTraceElement element : current.getStackTrace()) {
                    if (element.getClassName().contains("HsdpShimActivity")
                            || element.getClassName().contains("com.google.android.play.core.hsdp")) {
                        return true;
                    }
                }
            }

            // 2. Crash de NoSuchMethodError en ProxyBillingActivity
            if (current instanceof NoSuchMethodError && msg != null && msg.contains("setPendingIntentBackgroundActivityStartMode")) {
                for (StackTraceElement element : current.getStackTrace()) {
                    if (element.getClassName().contains("ProxyBillingActivity")) {
                        return true;
                    }
                }
            }

            // 3. Crash de NoSuchMethodError en WindowInsets.Type.systemOverlays
            if (current instanceof NoSuchMethodError && msg != null && msg.contains("systemOverlays")) {
                for (StackTraceElement element : current.getStackTrace()) {
                    if (element.getClassName().contains("WindowInsetsCompat") || element.getClassName().contains("WindowInsets")) {
                        return true;
                    }
                }
            }

            current = current.getCause();
        }

        return false;
    }
}
