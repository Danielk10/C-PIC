package com.diamon.ptc;

import org.junit.Test;
import static org.junit.Assert.*;

import java.util.TreeMap;

/**
 * Tests unitarios para el analizador de archivos Intel HEX (IntelHexParser).
 */
public class IntelHexParserTest {

    @Test
    public void testParseStandardDataRecord() {
        // Record 00: 4 bytes at address 0x0000: 02, 00, 43, 32
        String hex = ":040000000200433285\n:00000001FF\n";
        TreeMap<Integer, Byte> memory = IntelHexParser.parse(hex);

        assertNotNull(memory);
        assertEquals(4, memory.size());
        assertEquals((byte) 0x02, (byte) memory.get(0));
        assertEquals((byte) 0x00, (byte) memory.get(1));
        assertEquals((byte) 0x43, (byte) memory.get(2));
        assertEquals((byte) 0x32, (byte) memory.get(3));
    }

    @Test
    public void testParseExtendedLinearAddressRecord() {
        // Record 04 (Extended Linear Address): Base 0x00010000
        // Record 00: 2 bytes at 0x0010 -> Full address 0x00010010
        String hex = ":020000040001F9\n:02001000AABB8D\n:00000001FF\n";
        TreeMap<Integer, Byte> memory = IntelHexParser.parse(hex);

        assertNotNull(memory);
        assertEquals(2, memory.size());
        int fullAddr = 0x00010010;
        assertTrue(memory.containsKey(fullAddr));
        assertTrue(memory.containsKey(fullAddr + 1));
        assertEquals((byte) 0xAA, (byte) memory.get(fullAddr));
        assertEquals((byte) 0xBB, (byte) memory.get(fullAddr + 1));
    }

    @Test
    public void testParseEmptyOrMalformedInput() {
        TreeMap<Integer, Byte> emptyMem = IntelHexParser.parse("");
        assertNotNull(emptyMem);
        assertTrue(emptyMem.isEmpty());

        String malformed = "This is not a hex file\n:INVALID\n";
        TreeMap<Integer, Byte> malformedMem = IntelHexParser.parse(malformed);
        assertNotNull(malformedMem);
        assertTrue(malformedMem.isEmpty());
    }
}
