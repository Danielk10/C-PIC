#!/bin/bash
set -e

cd "$HOME"

export APP_PREFIX=/data/data/com.diamon.ptc/files/usr
export DESTDIR="$HOME/fake_root"
export FAKE_USR="$DESTDIR$APP_PREFIX"

# Preparar directorios limpios
mkdir -p "$FAKE_USR/bin" "$FAKE_USR/lib" "$FAKE_USR/include"
mkdir -p "$HOME/build_gputils"
cd "$HOME/build_gputils"

# Descargar y extraer
echo "=== Descargando gputils 1.5.2 ==="
wget -q -c "https://sourceforge.net/projects/gputils/files/gputils/1.5.0/gputils-1.5.2.tar.bz2/download" -O gputils-1.5.2.tar.bz2
tar -xjf gputils-1.5.2.tar.bz2
cd gputils-1.5.2

# Configurar compiladores (Clang)
export CC=clang
export CXX=clang++
export AR=llvm-ar
export RANLIB=llvm-ranlib

# Banderas de compilación para Android (PIC/PIE y optimización)
export CFLAGS="-fPIC -fPIE -Oz -ffile-prefix-map=$DESTDIR="

# Banderas de enlazado: PIE para ejecutables y alineación estricta de 16KB
export LDFLAGS="-pie -Wl,-z,max-page-size=16384"

echo "=== Configurando gputils (Construcción Completa) ==="
./configure \
  --prefix="$APP_PREFIX" \
  AR="$AR" \
  RANLIB="$RANLIB" \
  CFLAGS="$CFLAGS" \
  LDFLAGS="$LDFLAGS"

echo "=== Compilando gputils ==="
make -j"$(nproc)"

echo "=== Instalando en fake_root ==="
make DESTDIR="$DESTDIR" install

echo "=== Verificando binarios principales ==="
ls -lh "$FAKE_USR/bin/gpasm" || true
ls -lh "$FAKE_USR/bin/gplink" || true
ls -lh "$FAKE_USR/bin/gplib" || true

echo
echo "=== Dependencias dinámicas (gpasm) ==="
readelf -d "$FAKE_USR/bin/gpasm" | grep NEEDED || true

echo
echo "=== Alineación 16KB ==="
readelf -l "$FAKE_USR/bin/gpasm" | grep LOAD || true
