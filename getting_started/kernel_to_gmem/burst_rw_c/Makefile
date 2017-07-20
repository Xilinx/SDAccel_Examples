COMMON_REPO := ../../../
#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
vadd_SRCS=./src/vadd.cpp
vadd_CLFLAGS=-k vadd
vadd_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr

XOS=vadd

vadd_XOS=vadd
vadd_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr

XCLBINS=vadd

# check
check_EXE=host
check_XCLBINS=vadd
check_NDEVICES=$(vadd_NDEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

