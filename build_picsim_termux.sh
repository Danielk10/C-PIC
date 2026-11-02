#!/bin/bash
#
# build_picsim_termux.sh
#
# Compila PICsim (https://github.com/lcgamboa/picsim) de forma NATIVA en
# Termux (aarch64/Android) y lo integra en C-PIC.
#
# Es el equivalente Termux de build_sdcc_custom.sh y build_gputils_custom.sh:
# usa el clang de Termux, instala en fake_root y copia el ejecutable a jniLibs.
#
# Requisitos en Termux:
#   pkg install clang make wget tar
#
# Uso:
#   ./build_picsim_termux.sh
#
# Variables opcionales:
#   DESTDIR        fake_root (default: $HOME/fake_root)
#   BUILD_DIR      directorio de compilación (default: $HOME/build_picsim_termux)
#   PICSIM_COMMIT  commit de PICsim (default: fijado abajo)
#   PICSIM_ALLOW_HOST=1  permite probar el script fuera de aarch64 (no usar
#                        para el APK; genera un binario de otra arquitectura)
#
# Nota legal: PICsim es GPL-2.0-or-later. C-PIC es GPL-3.0; conserva
# COPYING/README y ofrece el código fuente de PICsim si distribuyes el binario.
#
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

APP_PREFIX="/data/data/com.diamon.ptc/files/usr"
DESTDIR="${DESTDIR:-$HOME/fake_root}"
FAKE_USR="$DESTDIR$APP_PREFIX"
BUILD_DIR="${BUILD_DIR:-$HOME/build_picsim_termux}"
JNI_DIR="${JNI_DIR:-$SCRIPT_DIR/app/src/main/jniLibs/arm64-v8a}"

PICSIM_COMMIT="${PICSIM_COMMIT:-3ee791875e15097a2d219c6afe08a8eadc17b673}"
PICSIM_URL="https://github.com/lcgamboa/picsim/archive/${PICSIM_COMMIT}.tar.gz"
PICSIM_SRC="$BUILD_DIR/picsim-${PICSIM_COMMIT}"

CC="${CC:-clang}"
AR="${AR:-llvm-ar}"
RANLIB="${RANLIB:-llvm-ranlib}"
STRIP="${STRIP:-llvm-strip}"
if command -v llvm-readelf >/dev/null 2>&1; then
  READELF="${READELF:-llvm-readelf}"
else
  READELF="${READELF:-readelf}"
fi

if [ "$(uname -m)" != "aarch64" ] && [ "${PICSIM_ALLOW_HOST:-0}" != "1" ]; then
  echo "ERROR: este script está pensado para Termux aarch64."
  echo "En un PC usa build_picsim_custom.sh (NDK) o exporta PICSIM_ALLOW_HOST=1 solo para probar."
  exit 1
fi

for tool in "$CC" "$AR" "$RANLIB" "$STRIP" make wget tar; do
  if ! command -v "$tool" >/dev/null 2>&1; then
    echo "ERROR: falta '$tool'. En Termux: pkg install clang make wget tar"
    exit 1
  fi
done

echo "=== PICsim Termux build ==="
echo "CC:        $CC"
echo "Commit:    $PICSIM_COMMIT"
echo "Destino:   $FAKE_USR"
echo "JNI:       $JNI_DIR"
echo

# ── 1. Descargar y extraer ────────────────────────────────────────────────
mkdir -p "$BUILD_DIR" "$FAKE_USR/bin" "$FAKE_USR/lib" \
         "$FAKE_USR/include/picsim" "$FAKE_USR/share/doc/picsim" \
         "$FAKE_USR/share/picsim/examples/pic16f628a" "$JNI_DIR"

cd "$BUILD_DIR"
if [ ! -d "$PICSIM_SRC" ]; then
  echo "=== Descargando PICsim ($PICSIM_COMMIT) ==="
  wget -q -c "$PICSIM_URL" -O "picsim-${PICSIM_COMMIT}.tar.gz"
  tar -xzf "picsim-${PICSIM_COMMIT}.tar.gz"
fi

cd "$PICSIM_SRC"

# ── 2. Limpiar y compilar la librería estática ────────────────────────────
echo "=== Limpiando objetos anteriores ==="
make -C src clean >/dev/null 2>&1 || true

# PICsim usa FLAGS (no CFLAGS). Para la librería: -fPIC.
CFLAGS_LIB="-fPIC -Oz -ffile-prefix-map=$DESTDIR= -fsigned-char -D_GNU_SOURCE -I../include -I."
CFLAGS_CLI="-fPIE -Oz -ffile-prefix-map=$DESTDIR= -fsigned-char -D_GNU_SOURCE -I../include -I."
LDFLAGS="-pie -Wl,-z,max-page-size=16384"

echo "=== Compilando libpicsim.a ==="
make -C src libpicsim.a \
  CC="$CC" \
  AR="$AR" \
  RANLIB="$RANLIB" \
  FLAGS="$CFLAGS_LIB"

# ── 3. Enlazar CLI (PIE) ──────────────────────────────────────────────────
echo "=== Enlazando picsim (CLI PIE) ==="
(
  cd src
  "$CC" $CFLAGS_CLI $LDFLAGS picsim.c libpicsim.a -o picsim -lm
)

# ── 4. Enlazar librería compartida (opcional para JNI) ─────────────────────
echo "=== Enlazando libpicsim_core.so ==="
OBJS=$(find src -name '*.o' ! -name 'picsim.o' | sort)
if [ -z "$OBJS" ]; then
  echo "ERROR: no se generaron objetos para libpicsim_core.so"
  exit 1
fi
"$CC" -shared -fPIC -Oz -Wl,-soname,libpicsim_core.so \
  -Wl,-z,max-page-size=16384 \
  -o libpicsim_core.so $OBJS -lm

# ── 5. Strip + verificación ───────────────────────────────────────────────
"$STRIP" --strip-unneeded src/picsim
"$STRIP" --strip-unneeded libpicsim_core.so

echo "=== Verificación ELF ==="
file src/picsim || true
file libpicsim_core.so || true
if command -v "$READELF" >/dev/null 2>&1; then
  "$READELF" -h src/picsim | grep -E 'Class:|Machine:|Type:' || true
  "$READELF" -l src/picsim | grep LOAD || true
  "$READELF" -d src/picsim | grep NEEDED || true
fi

# ── 6. Instalar en fake_root ──────────────────────────────────────────────
echo "=== Instalando en fake_root ==="
install -m 755 src/picsim "$FAKE_USR/bin/picsim"
install -m 755 src/picsim "$FAKE_USR/bin/libpicsim.so"
install -m 755 libpicsim_core.so "$FAKE_USR/lib/libpicsim_core.so"
install -m 644 include/*.h "$FAKE_USR/include/picsim/"

install -m 644 COPYING "$FAKE_USR/share/doc/picsim/COPYING"
install -m 644 README.md "$FAKE_USR/share/doc/picsim/README.md"
install -m 644 VERSION "$FAKE_USR/share/doc/picsim/VERSION"

install -m 644 examples/sdcc/sdcc.hex "$FAKE_USR/share/picsim/examples/pic16f628a/sdcc.hex"
install -m 644 examples/sdcc/sdcc.asm "$FAKE_USR/share/picsim/examples/pic16f628a/sdcc.asm"
install -m 644 examples/sdcc/sdcc.c   "$FAKE_USR/share/picsim/examples/pic16f628a/sdcc.c"

# ── 7. Copiar a jniLibs ───────────────────────────────────────────────────
echo "=== Copiando a jniLibs ==="
rm -f "$JNI_DIR/libpicsim_core.so"
install -m 755 src/picsim "$JNI_DIR/libpicsim.so"

# ── 8. Resumen ────────────────────────────────────────────────────────────
echo
echo "=== Listo ==="
ls -lh "$FAKE_USR/bin/picsim" "$FAKE_USR/bin/libpicsim.so" \
       "$FAKE_USR/lib/libpicsim_core.so" \
       "$JNI_DIR/libpicsim.so"
echo
echo "Prueba local en Termux (sin Android UI):"
echo "  printf 'n\\\\n14\\\\nq\\\\n' | ./picsim PIC16F628A archivo.hex"
echo
echo "En la app:"
echo "  libpicsim.so PIC16F628A archivo.hex"
echo "  (stdin: 'n', pasos en hex, 'q')"
echo
echo "Procesadores soportados: ejecutar picsim sin argumentos."
