#!/bin/bash
set -e

cd "$HOME"

export APP_PREFIX=/data/data/com.diamon.ptc/files/usr
export DESTDIR="$HOME/fake_root"
export FAKE_USR="$DESTDIR$APP_PREFIX"

# Preparar directorios limpios
mkdir -p "$FAKE_USR/bin" "$FAKE_USR/lib" "$FAKE_USR/include"
mkdir -p "$HOME/build_sdcc"
cd "$HOME/build_sdcc"

# Descargar y extraer
echo "=== Descargando SDCC 4.5.0 ==="
wget -q -c "https://sourceforge.net/projects/sdcc/files/sdcc/4.5.0/sdcc-src-4.5.0.tar.bz2/download" -O sdcc-src-4.5.0.tar.bz2
tar -xjf sdcc-src-4.5.0.tar.bz2

cd sdcc-4.5.0

# Configurar compiladores
export CC=clang
export CXX=clang++
export AR=llvm-ar
export RANLIB=llvm-ranlib

# Banderas de compilación combinando PIE, alineación estricta y mapeo de funciones unlocked
export CFLAGS="-fPIC -fPIE -Oz -ffile-prefix-map=$DESTDIR= -Dfputc_unlocked=fputc -Dputc_unlocked=putc -Dgetc_unlocked=getc -Dgetchar_unlocked=getchar -Dputchar_unlocked=putchar -Dclearerr_unlocked=clearerr -Dfeof_unlocked=feof -Dferror_unlocked=ferror -Dfflush_unlocked=fflush"
export CXXFLAGS="-fPIC -fPIE -Oz -ffile-prefix-map=$DESTDIR= -Dfputc_unlocked=fputc -Dputc_unlocked=putc -Dgetc_unlocked=getc -Dgetchar_unlocked=getchar -Dputchar_unlocked=putchar -Dclearerr_unlocked=clearerr -Dfeof_unlocked=feof -Dferror_unlocked=ferror -Dfflush_unlocked=fflush"
export LDFLAGS="-pie -Wl,-z,max-page-size=16384"

echo "=== Configurando entorno GPUTILS en fake_root ==="
# Agregamos los binarios al PATH
export PATH="$FAKE_USR/bin:$PATH"

# Apuntamos gputils a sus directorios en fake_root para que no falle al ser llamado por SDCC
export GPUTILS_HEADER_PATH="$FAKE_USR/share/gputils/header"
export GPUTILS_LKR_PATH="$FAKE_USR/share/gputils/lkr"
export GPUTILS_LIBPATH="$FAKE_USR/share/gputils/lib"

# Verificamos que gpasm funcione y encuentre sus archivos
echo "Probando gpasm..."
gpasm --version
gpasm --list-chips | head -n 5

echo "=== Configurando SDCC ==="
# Nota sobre isl: no se pasa --with-isl ni --without-isl, así que configure lo
# autodetecta. Si la máquina de compilación no tiene libisl + cabeceras, cc1 se
# construye sin Graphite (lleva el mensaje "isl is not available") y no enlaza
# libisl.so; si las tiene, cc1 enlaza dinámicamente contra libisl.so (que a su
# vez necesita libgmp.so). Por eso los paquetes de 32 y 64 bits difieren en esa
# dependencia. No afecta al código PIC generado: isl solo habilita -fgraphite y
# los -floop-* del compilador anfitrión, que SDCC no usa. Para forzar paridad,
# añade --without-isl (o --with-isl si isl está instalado).
./configure \
  --prefix="$APP_PREFIX" \
  --enable-libgc \
  AR="$AR" \
  RANLIB="$RANLIB" \
  CFLAGS="$CFLAGS" \
  CXXFLAGS="$CXXFLAGS" \
  LDFLAGS="$LDFLAGS" \
  gcc_cv_c_no_fpie=no \
  gcc_cv_no_pie=no

echo "=== Compilando SDCC ==="
make -j"$(nproc)"

echo "=== Instalando SDCC en fake_root ==="
make DESTDIR="$DESTDIR" install

echo "=== Verificando binario principal (sdcc) ==="
ls -lh "$FAKE_USR/bin/sdcc" || true

echo
echo "=== Dependencias dinámicas (sdcc) ==="
readelf -d "$FAKE_USR/bin/sdcc" | grep NEEDED || true

echo
echo "=== Alineación 16KB ==="
readelf -l "$FAKE_USR/bin/sdcc" | grep LOAD || true
