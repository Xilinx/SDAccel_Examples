COMMON_REPO := ../../../
#Common Includes
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl2/xcl2.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall
# Switch between GOOD/BAD Examples
KFLOW:=GOOD

EXES=host

XOS=nearest_GOOD nearest_BAD

# nearest kernels
nearest_GOOD_SRCS=./src/nearest_good.cl
nearest_GOOD_CLFLAGS=-k nearest_good -I./src
nearest_GOOD_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr

nearest_BAD_SRCS=./src/nearest_bad.cl
nearest_BAD_CLFLAGS=-k nearest_bad -I./src
nearest_BAD_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr

# nearest xclbin
nearest_XOS=nearest_GOOD nearest_BAD

nearest_GOOD_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr
nearest_BAD_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr

XCLBINS=nearest

# check
check_EXE=host
check_XCLBINS=nearest
check_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk
