

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
array_partition_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
array_partition_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS)
array_partition_LDFLAGS=$(opencl_LDFLAGS)
CXXFLAGS+=-std=c++0x

# Kernel
matmul_SRCS=./src/matmul.cl

EXES=array_partition
XCLBINS=matmul
EXTRA_CLEAN=./output.png

# check
check_EXE=array_partition
check_XCLBINS=matmul

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
