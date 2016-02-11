#!/bin/bash
checkabortfailed() 
{
	if [ $1 -eq 0 ]
	then
	  echo "INFO: Step finished successfully"
	else
	  echo "ERROR: An error occurred. aborting..."
	  exit $1
	fi
}

############################################################

echo "INFO: detect sdaccel path..."
which sdaccel
checkabortfailed $?

export SDACCEL_ROOT=`which sdaccel`
export SDACCEL_ROOT=$(dirname $SDACCEL_ROOT)
export SDACCEL_ROOT=$(dirname $SDACCEL_ROOT)
export SDACCEL_RUNTIME="${SDACCEL_ROOT}/runtime"
export OpenCL_INCPATH="${SDACCEL_RUNTIME}/include/1_2/"
##export OpenCL_LIBPATH="${SDACCEL_RUNTIME}/lib/x86_64/"
export OpenCL_LIBPATH="${SDACCEL_RUNTIME}/lib/zynq/"
echo "OpenCL_LIBPATH = ${OpenCL_LIBPATH}"

echo "INFO: detected SDAccel root at ${SDACCEL_ROOT}" 


export OVERRIDE_COMPILER=0
export CC=${SDACCEL_ROOT}/gnu/arm/2013.11/lin/bin/arm-xilinx-linux-gnueabi-gcc
export CXX=${SDACCEL_ROOT}/gnu/arm/2013.11/lin/bin/arm-xilinx-linux-gnueabi-g++
export HOST_ARCH="arm-xilinx-linux-gnueabi"
export RUNTIME_LIB_DIR="zynq"

export LD_LIBRARY_PATH=${OpenCL_LIBPATH}:${LD_LIBRARY_PATH}


mkdir -p bin
pushd bin 

cmake ..
make

popd
