#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Ajuste obligatorio de ASlink (sdld) para Android de 32 bits.

Los binarios de SDCC se empaquetan en Android como ``libsdld*.so`` para cumplir
la politica de Google Play.  La funcion ``init_target()`` de ASlink comprueba
el nombre del ejecutable con ``strncmp(basename(argv[0]), "sdld", 4)``; como el
nombre real empieza por ``lib``, la comprobacion falla, ``is_sdld`` queda a 0 y
la arquitectura objetivo no se inicializa (error ``Undefined Global 'l_IRAM'``
al enlazar MCS-51, entre otros).

Este script aplica el ajuste descrito en ``GEMINI.md`` seccion 7.3 sobre la
variante ``armeabi-v7a``:

1. Sustituye la llamada a ``strncmp`` por ``strstr(base, "sdld")``.
2. Invierte el valor de ``is_sdld`` para que sea 1 cuando ``strstr`` encuentra
   el nombre.
3. Salta la asignacion de objetivo cuando el nombre no contiene ``sdld``.
4. Si ninguna subarquitectura coincide, asigna ``target = 4`` (MCS-51), que ya
   esta precargado en ``r6``.

Los binarios ``arm64-v8a`` actuales ya incluyen este ajuste y no se tocan.

Uso:
    python3 patch_sdld_android.py [directorio]

Por defecto usa ``app/src/main/jniLibs/armeabi-v7a``.
"""

from __future__ import annotations

import struct
import sys
from pathlib import Path

# Offsets y valores esperados en el binario ARM32 de SDCC 4.5.0.
# VA == offset de fichero porque .text empieza en 0x1aac0.
PATCHES = (
    # bl strncmp -> bl strstr
    (0x2BEF0, 0xEB00053A, 0xEB0005AE, "strncmp -> strstr"),
    # lsr r1, r1, #5 -> rsb r1, r1, #1 (invierte is_sdld)
    (0x2BF08, 0xE1A012A1, 0xE2611001, "is_sdld invertido"),
    # bne (nombre no empieza por sdld) -> beq (strstr no encontro sdld)
    (0x2BF18, 0x1A000013, 0x0A000013, "salto si no contiene sdld"),
    # beq 0x2bf50 (sin subarquitectura) -> beq 0x2bf60 (guarda target=4)
    (0x2BF30, 0x0A000006, 0x0A00000A, "target por defecto MCS-51"),
)

ELF_MAGIC = b"\x7fELF"


def patch_file(path: Path) -> bool | None:
    """Devuelve True si parchea, False si ya estaba, None si se omite."""
    data = bytearray(path.read_bytes())
    if data[:4] != ELF_MAGIC:
        print(f"  omitido (no es ELF): {path.name}")
        return None
    if data[4] != 1:  # EI_CLASS: 1 = ELF32
        print(f"  omitido (no es ELF32): {path.name}")
        return None

    # Verificar todos los bytes antes de modificar nada.
    pending = []
    for offset, expected, replacement, description in PATCHES:
        current = struct.unpack_from("<I", data, offset)[0]
        if current == replacement:
            continue  # ya aplicado
        if current != expected:
            raise SystemExit(
                f"ERROR en {path.name}: offset 0x{offset:x} contiene "
                f"0x{current:08x}, se esperaba 0x{expected:08x} ({description})"
            )
        pending.append((offset, replacement))

    if not pending:
        print(f"  ya parcheado: {path.name}")
        return False

    for offset, replacement in pending:
        struct.pack_into("<I", data, offset, replacement)

    path.write_bytes(data)
    print(f"  parcheado: {path.name}")
    return True


def main() -> int:
    root = Path(__file__).resolve().parent
    target_dir = Path(sys.argv[1]) if len(sys.argv) > 1 else root / "app/src/main/jniLibs/armeabi-v7a"
    if not target_dir.is_dir():
        print(f"ERROR: no existe el directorio {target_dir}")
        return 1

    candidates = sorted(target_dir.glob("libsdld*.so"))
    if not candidates:
        print(f"ERROR: no se encontraron libsdld*.so en {target_dir}")
        return 1

    print(f"Parcheando ASlink de 32 bits en {target_dir}:")
    patched = 0
    already = 0
    for path in candidates:
        result = patch_file(path)
        if result is True:
            patched += 1
        elif result is False:
            already += 1
    print(f"Listo: {patched} parcheado(s), {already} ya estaban parcheados.")
    return 0 if patched + already else 1


if __name__ == "__main__":
    raise SystemExit(main())
