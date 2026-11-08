package com.diamon.ptc;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Lógica pura (sin Android) para planificar el resaltado de sintaxis del editor.
 *
 * <p>El editor creaba un {@code ForegroundColorSpan} por cada coincidencia de
 * cada patrón sobre el documento completo en cada pulsación. En archivos
 * grandes eso produce miles de spans y hace que {@code SpannableStringBuilder}
 * recorra todos ellos cada vez que MIUI calcula el rectángulo de la selección
 * ({@code Layout.getParagraphSpans} → {@code countSpans}), provocando el ANR
 * {@code miuix.toolbar.FloatingActionModeHelper.onGetContentRect}.</p>
 *
 * <p>Esta clase calcula una ventana de texto acotada alrededor de la zona
 * visible, la alinea a líneas completas y limita el número de rangos por
 * patrón. Así el número total de spans queda acotado sin importar el tamaño
 * del archivo.</p>
 */
final class SyntaxHighlightPlanner {

    private SyntaxHighlightPlanner() {
    }

    /**
     * Recorta la ventana solicitada a los límites del texto y la amplía con un
     * margen de caracteres para no cortar comentarios o cadenas largas.
     */
    static int[] visibleWindow(int textLength, int layoutStart, int layoutEnd, int charMargin) {
        int length = Math.max(0, textLength);
        int start = Math.max(0, Math.min(layoutStart, length));
        int end = Math.max(start, Math.min(layoutEnd, length));
        int margin = Math.max(0, charMargin);

        start = Math.max(0, start - margin);
        end = Math.min(length, end + margin);
        return new int[]{start, end};
    }

    /**
     * Extiende el rango hasta los límites de línea para que los patrones con
     * {@code ^} y {@code $} (preprocesador, etiquetas, comentarios ASM) sigan
     * funcionando igual que sobre el documento completo.
     */
    static int[] alignToWholeLines(CharSequence text, int start, int end) {
        if (text == null) {
            return new int[]{0, 0};
        }
        int length = text.length();
        int safeStart = Math.max(0, Math.min(start, length));
        int safeEnd = Math.max(safeStart, Math.min(end, length));

        while (safeStart > 0 && text.charAt(safeStart - 1) != '\n') {
            safeStart--;
        }
        while (safeEnd < length && safeEnd > 0 && text.charAt(safeEnd - 1) != '\n') {
            safeEnd++;
        }
        return new int[]{safeStart, safeEnd};
    }

    /**
     * Devuelve como máximo {@code maxRanges} rangos {@code {inicio, fin, color}}
     * para el patrón indicado. El límite evita que un archivo con muchísimos
     * tokens vuelva a generar una cantidad ilimitada de spans.
     */
    static List<int[]> collectRanges(String source, Pattern pattern, int color, int maxRanges) {
        if (source == null || source.isEmpty() || pattern == null || maxRanges <= 0) {
            return Collections.emptyList();
        }
        List<int[]> ranges = new ArrayList<>(Math.min(maxRanges, 128));
        Matcher matcher = pattern.matcher(source);
        while (matcher.find() && ranges.size() < maxRanges) {
            if (matcher.start() < matcher.end()) {
                ranges.add(new int[]{matcher.start(), matcher.end(), color});
            }
        }
        return ranges;
    }
}
