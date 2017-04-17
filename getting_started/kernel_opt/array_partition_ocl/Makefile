

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
array_partition_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl2_SRCS)
array_partition_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
array_partition_LDFLAGS=$(opencl_LDFLAGS)

EXES=array_partition

# Kernel
matmul_SRCS=./src/matmul.cl

XOS=matmul

# xclbin
matmul_XOS=matmul

XCLBINS=matmul

EXTRA_CLEAN=./output.png

# check
check_EXE=array_partition
check_XCLBINS=matmul

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
