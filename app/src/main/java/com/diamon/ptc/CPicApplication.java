package com.diamon.ptc;

import android.app.Application;

/**
 * Application de C PIC Compiler.
 *
 * <p>No se instala un {@code UncaughtExceptionHandler} que absorba excepciones:
 * si se traga un fallo del hilo principal, el looper de Android queda muerto y
 * el proceso termina en {@code DestroyJavaVM} esperando a los hilos no-daemon,
 * lo que produce un ANR (Crashlytics ad004d1ef57fa8db88a9373446c84b3c).</p>
 *
 * <p>Los fallos conocidos de HSDP y Play Billing se corrigen fijando las
 * versiones de esas dependencias en {@code gradle/libs.versions.toml}.</p>
 */
public class CPicApplication extends Application {
}
