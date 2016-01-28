#!/bin/bash -e

if [ -d build ]; then
	rm -rf build
fi

UTHASH=uthash-044474afe5a57db4302cc722de476d20d1ab70c7
JANSSON=jansson-2.7
BFGMINER=bfgminer-5.4.1

mkdir build
cd build
unzip ../src/$UTHASH.zip
tar xvzf ../src/$JANSSON.tar.gz
unzip ../src/$BFGMINER.zip

# Nothing to be done for UTHASH
#

cd $JANSSON
./configure --prefix=$PWD
make
make install
cd ..

cd $BFGMINER
cp ../../src/poclbm-69ce3afpga0v4w2048l8pOpenCL1_0.bin .
cp ../../src/ocl.c .
PKG_CONFIG_PATH=$PWD/../$JANSSON/lib/pkgconfig/ CFLAGS=-I$PWD/../$UTHASH/src ./configure --disable-other-drivers --enable-opencl --enable-keccak --enable-sha256d --enable-scrypt
make
cd ..

echo "export LD_LIBRARY_PATH=$PWD/build/$JANSSON/lib:$$LD_LIBRARY_PATH"

