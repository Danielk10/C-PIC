#!/bin/bash
set -e

cd "$HOME"

export APP_PREFIX=/data/data/com.diamon.ptc/files/usr
export DESTDIR="$HOME/fake_root_n"
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

# Configurar compiladores (Clang)
export CC=clang
export CXX=clang++
export AR=llvm-ar
export RANLIB=llvm-ranlib

# Banderas de compilación combinando tus requerimientos y optimizaciones
export CFLAGS="-fPIC -fPIE -Oz -ffile-prefix-map=$DESTDIR="
export CXXFLAGS="-fPIC -fPIE -Oz -ffile-prefix-map=$DESTDIR="

# Banderas de enlazado: PIE y alineación estricta de 16KB
export LDFLAGS="-pie -Wl,-z,max-page-size=16384"

# !!! SOLUCIÓN AL ERROR !!!
# Agregamos los binarios de gputils (previamente compilados) al PATH
export PATH="$FAKE_USR/bin:$PATH"

echo "=== Configurando SDCC ==="
./configure \
  --prefix="$APP_PREFIX" \
  AR="$AR" \
  RANLIB="$RANLIB" \
  CFLAGS="$CFLAGS" \
  CXXFLAGS="$CXXFLAGS" \
  LDFLAGS="$LDFLAGS" \
  gcc_cv_c_no_fpie=no \
  gcc_cv_no_pie=no

echo "=== Compilando SDCC ==="
make -j"$(nproc)"

echo "=== Instalando SDCC en fake_root_n ==="
make DESTDIR="$DESTDIR" install

echo "=== Verificando binario principal (sdcc) ==="
ls -lh "$FAKE_USR/bin/sdcc" || true

echo
echo "=== Dependencias dinámicas (sdcc) ==="
readelf -d "$FAKE_USR/bin/sdcc" | grep NEEDED || true

echo
echo "=== Alineación 16KB ==="
readelf -l "$FAKE_USR/bin/sdcc" | grep LOAD || true
