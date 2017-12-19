

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
array_partition_SRCS=./src/host.cpp $(xcl2_SRCS)
array_partition_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) -std=c++0x
array_partition_LDFLAGS=$(opencl_LDFLAGS)

EXES=array_partition

# Kernel
matmul_naive_SRCS=./src/matmul.cpp
matmul_naive_CLFLAGS= -k matmul_naive

matmul_partition_SRCS=./src/matmul_partition.cpp
matmul_partition_CLFLAGS=-k matmul_partition

XOS=matmul_naive matmul_partition

# xclbin
matmul_XOS=matmul_naive matmul_partition
matmul_NDEVICES=xilinx:kcu1500:dynamic xilinx:vcu1525:dynamic xilinx_kcu1500_dynamic_5_0 xilinx_vcu1525_dynamic_5_0

XCLBINS=matmul

EXTRA_CLEAN=./output.png

# check
check_EXE=array_partition
check_XCLBINS=matmul
check_NDEVICES=$(matmul_NDEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
