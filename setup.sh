#!/bin/bash -v
CompilerHome="$1"
Target_gcc="$2"
Target_binutils="$3"
TARGET="$4"
PREFIX="$(pwd)/$5"

# cd into cross compiler directory
mkdir -p "$CompilerHome/src"
cd "$CompilerHome/src"

# Make neccessary subdirectories
mkdir build-binutils
mkdir build-gcc

#extract tarballs
tar xf  $Target_gcc.tar.xz
tar xf $Target_binutils.tar.xz


#compile binutils
pushd build-binutils
../$Target_binutils/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
popd

#compile gcc
pushd build-gcc
../$Target_gcc/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
popd
