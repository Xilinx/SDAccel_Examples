

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
array_partition_SRCS=./src/host.cpp  $(xcl2_SRCS)
array_partition_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) -std=c++0x
array_partition_LDFLAGS=$(opencl_LDFLAGS)

EXES=array_partition

# Kernel
matmul_SRCS=./src/matmul.cl
matmul_NDEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:xil-accel-rd-vu9p:4ddr-xpr

XOS=matmul

# xclbin
matmul_XOS=matmul
matmul_NDEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:xil-accel-rd-vu9p:4ddr-xpr

XCLBINS=matmul

EXTRA_CLEAN=./output.png

# check
check_EXE=array_partition
check_XCLBINS=matmul
check_NDEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:xil-accel-rd-vu9p:4ddr-xpr

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
