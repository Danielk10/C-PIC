package com.diamon.ptc;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import java.util.List;
import java.util.regex.Pattern;

/**
 * Pruebas de la planificación del resaltado de sintaxis.
 *
 * <p>El ANR de MIUI ocurría porque el editor generaba un span por token de todo
 * el archivo. Estas pruebas garantizan que la ventana y el número de spans
 * quedan acotados incluso con documentos grandes.</p>
 */
public class SyntaxHighlightPlannerTest {

    private static final Pattern INT_PATTERN = Pattern.compile("\\bint\\b");
    private static final int COLOR = 0xFF80CBC4;

    @Test
    public void collectRanges_respectsMaximumBudget() {
        StringBuilder source = new StringBuilder();
        for (int i = 0; i < 5000; i++) {
            source.append("int variable").append(i).append(";\n");
        }

        List<int[]> ranges = SyntaxHighlightPlanner.collectRanges(
                source.toString(), INT_PATTERN, COLOR, 100);

        assertEquals("El resaltado nunca debe superar el presupuesto de spans",
                100, ranges.size());
        for (int[] range : ranges) {
            assertEquals(COLOR, range[2]);
            assertTrue(range[0] < range[1]);
        }
    }

    @Test
    public void collectRanges_returnsExactOffsetsAndColor() {
        String source = "void main(void) { int x = 0; }";
        List<int[]> ranges = SyntaxHighlightPlanner.collectRanges(
                source, INT_PATTERN, COLOR, 10);

        assertEquals(1, ranges.size());
        int[] range = ranges.get(0);
        assertEquals(source.indexOf("int"), range[0]);
        assertEquals(source.indexOf("int") + 3, range[1]);
        assertEquals(COLOR, range[2]);
    }

    @Test
    public void collectRanges_emptyOrInvalidInputReturnsEmptyList() {
        assertTrue(SyntaxHighlightPlanner.collectRanges(null, INT_PATTERN, COLOR, 10).isEmpty());
        assertTrue(SyntaxHighlightPlanner.collectRanges("", INT_PATTERN, COLOR, 10).isEmpty());
        assertTrue(SyntaxHighlightPlanner.collectRanges("int x;", null, COLOR, 10).isEmpty());
        assertTrue(SyntaxHighlightPlanner.collectRanges("int x;", INT_PATTERN, COLOR, 0).isEmpty());
    }

    @Test
    public void visibleWindow_clampsAndAddsMargin() {
        int[] window = SyntaxHighlightPlanner.visibleWindow(1000, 100, 200, 50);
        assertEquals(50, window[0]);
        assertEquals(250, window[1]);

        int[] clampedStart = SyntaxHighlightPlanner.visibleWindow(1000, 10, 20, 100);
        assertEquals(0, clampedStart[0]);

        int[] clampedEnd = SyntaxHighlightPlanner.visibleWindow(1000, 900, 990, 100);
        assertEquals(1000, clampedEnd[1]);

        int[] empty = SyntaxHighlightPlanner.visibleWindow(0, 0, 0, 10);
        assertEquals(0, empty[0]);
        assertEquals(0, empty[1]);
    }

    @Test
    public void alignToWholeLines_expandsBothEdges() {
        String text = "line one\nline two\nline three\n";
        int start = text.indexOf("two");
        int end = start + 3;

        int[] aligned = SyntaxHighlightPlanner.alignToWholeLines(text, start, end);

        assertEquals("line two\n", text.substring(aligned[0], aligned[1]));
    }

    @Test
    public void alignToWholeLines_handlesEdgesAndNull() {
        String text = "abc\ndef";
        int[] all = SyntaxHighlightPlanner.alignToWholeLines(text, 0, text.length());
        assertEquals(0, all[0]);
        assertEquals(text.length(), all[1]);

        int[] nullText = SyntaxHighlightPlanner.alignToWholeLines(null, 5, 10);
        assertEquals(0, nullText[0]);
        assertEquals(0, nullText[1]);
    }

    @Test
    public void collectRanges_largeDocumentStaysFarBelowAnrThreshold() {
        StringBuilder source = new StringBuilder(200_000);
        for (int i = 0; i < 10_000; i++) {
            source.append("int counter").append(i).append(" = ").append(i).append(";\n");
        }

        int total = 0;
        total += SyntaxHighlightPlanner.collectRanges(source.toString(), INT_PATTERN, COLOR, 100).size();
        total += SyntaxHighlightPlanner.collectRanges(source.toString(), Pattern.compile("\\d+"), COLOR, 60).size();

        assertTrue("Con un documento grande el total de spans debe quedar acotado", total <= 160);
    }
}
