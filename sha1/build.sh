#!/bin/bash

echo "INFO: Building GauntletApps..."

#export SDACCEL_RUNTIME="/opt/Xilinx/SDAccel/2015.1/runtime/"
#export MACHINE="/opt/platform/machine"

export SDACCEL_RUNTIME="/proj/xbuilds/2015.4_sdaccel_daily_latest/installs/lin64/SDAccel/2015.4/runtime"
export MACHINE="/proj/picasso/pourya/shared/machine"

export OpenCL_INCPATH="${SDACCEL_RUNTIME}/include/1_2/"
export OpenCL_LIBPATH="${SDACCEL_RUNTIME}/lib/x86_64/"

export ZeroMQ_ROOT_DIR="${MACHINE}"
export ZMQ_INCLUDE_DIR="${MACHINE}/include"
export ZMQ_LIBRARY="${MACHINE}/lib"



mkdir -p build
pushd ./build
cmake -DZeroMQ_ROOT_DIR="${MACHINE}" ..

make

popd
