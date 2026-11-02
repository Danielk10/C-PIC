#!/bin/bash
#
# build_picsim_custom.sh
#
# Compila PICsim (https://github.com/lcgamboa/picsim) para Android arm64
# con el NDK, siguiendo la lógica de build_sdcc_custom.sh y
# build_gputils_custom.sh.
#
# Genera:
#   - picsim              CLI (PIE, arm64)
#   - libpicsim_core.so   librería compartida (opcional, para JNI futuro)
#   - libpicsim.so        copia del CLI en jniLibs (ejecutable Android)
#   - headers, COPYING, README, VERSION y ejemplo PIC16F628A en fake_root
#
# Uso:
#   ./build_picsim_custom.sh
#
# Variables opcionales:
#   ANDROID_NDK_HOME   Ruta del NDK (default: /tmp/android-sdk/ndk/30.0.14904198)
#   ANDROID_API        API mínima (default: 24)
#   DESTDIR            Destino fake_root (default: $HOME/fake_root)
#   PICSIM_COMMIT      Commit de PICsim (default: fijado abajo)
#
# Nota legal: PICsim es GPL-2.0-or-later. C-PIC es GPL-3.0; conserva
# COPYING/README y ofrece el código fuente de PICsim si distribuyes el binario.
#
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

APP_PREFIX="/data/data/com.diamon.ptc/files/usr"
DESTDIR="${DESTDIR:-$HOME/fake_root}"
FAKE_USR="$DESTDIR$APP_PREFIX"
BUILD_DIR="${BUILD_DIR:-$HOME/build_picsim}"
JNI_DIR="$SCRIPT_DIR/app/src/main/jniLibs/arm64-v8a"

PICSIM_COMMIT="${PICSIM_COMMIT:-3ee791875e15097a2d219c6afe08a8eadc17b673}"
PICSIM_URL="https://github.com/lcgamboa/picsim/archive/${PICSIM_COMMIT}.tar.gz"
PICSIM_SRC="$BUILD_DIR/picsim-${PICSIM_COMMIT}"

NDK="${ANDROID_NDK_HOME:-${ANDROID_NDK_ROOT:-/tmp/android-sdk/ndk/30.0.14904198}}"
HOST_TAG="linux-x86_64"
TOOLCHAIN="$NDK/toolchains/llvm/prebuilt/$HOST_TAG"
API="${ANDROID_API:-24}"
CC="$TOOLCHAIN/bin/aarch64-linux-android${API}-clang"
AR="$TOOLCHAIN/bin/llvm-ar"
RANLIB="$TOOLCHAIN/bin/llvm-ranlib"
STRIP="$TOOLCHAIN/bin/llvm-strip"
READELF="$TOOLCHAIN/bin/llvm-readelf"

if [ ! -x "$CC" ]; then
  echo "ERROR: no se encontró el compilador NDK: $CC"
  echo "Configura ANDROID_NDK_HOME o revisa: $NDK"
  exit 1
fi

if [ ! -d "$NDK" ]; then
  echo "ERROR: no se encontró el NDK: $NDK"
  exit 1
fi

echo "=== PICsim build ==="
echo "NDK:       $NDK"
echo "API:       $API"
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
file src/picsim
file libpicsim_core.so
"$READELF" -h src/picsim | grep -E 'Class:|Machine:|Type:' || true
"$READELF" -l src/picsim | grep LOAD || true
"$READELF" -d src/picsim | grep NEEDED || true

# ── 6. Instalar en fake_root (misma lógica que SDCC/GPUTILS) ──────────────
echo "=== Instalando en fake_root ==="
install -m 755 src/picsim "$FAKE_USR/bin/picsim"
install -m 755 src/picsim "$FAKE_USR/bin/libpicsim.so"
install -m 755 libpicsim_core.so "$FAKE_USR/lib/libpicsim_core.so"
install -m 644 include/*.h "$FAKE_USR/include/picsim/"

install -m 644 COPYING "$FAKE_USR/share/doc/picsim/COPYING"
install -m 644 README.md "$FAKE_USR/share/doc/picsim/README.md"
install -m 644 VERSION "$FAKE_USR/share/doc/picsim/VERSION"

# Ejemplo mínimo para PIC16F628A (mismo que usa el proyecto)
install -m 644 examples/sdcc/sdcc.hex "$FAKE_USR/share/picsim/examples/pic16f628a/sdcc.hex"
install -m 644 examples/sdcc/sdcc.asm "$FAKE_USR/share/picsim/examples/pic16f628a/sdcc.asm"
install -m 644 examples/sdcc/sdcc.c   "$FAKE_USR/share/picsim/examples/pic16f628a/sdcc.c"

# ── 7. Copiar a jniLibs para que Android lo ejecute desde nativeLibraryDir ─
echo "=== Copiando a jniLibs ==="
# Solo el CLI se necesita en el APK; la librería core queda en fake_root
# para un futuro puente JNI.
rm -f "$JNI_DIR/libpicsim_core.so"
install -m 755 src/picsim "$JNI_DIR/libpicsim.so"

# ── 8. Resumen ────────────────────────────────────────────────────────────
echo
echo "=== Listo ==="
ls -lh "$FAKE_USR/bin/picsim" "$FAKE_USR/bin/libpicsim.so" \
       "$FAKE_USR/lib/libpicsim_core.so" \
       "$JNI_DIR/libpicsim.so"
echo
echo "Prueba local en el dispositivo (ejemplo):"
echo "  adb shell \"printf 'n\\\\n20\\\\nq\\\\n' | \\"
echo "    /data/app/.../lib/arm64/libpicsim.so PIC16F628A /ruta/al/proyecto.hex\""
echo
echo "En la app, el ejecutor debe invocar:"
echo "  libpicsim.so PIC16F628A archivo.hex"
echo "  (stdin: 'n', número de pasos, 'q')"
echo
echo "Procesadores soportados: ejecutar libpicsim.so sin argumentos."
