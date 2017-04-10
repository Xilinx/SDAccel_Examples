COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# vadd Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# vadd Kernels
vadd_SRCS=./src/vadd.cl
vadd_CLFLAGS=-k vadd

XOS=vadd

# vadd xcl2bin
vadd_XOS=vadd

XCLBINS=vadd

# check
check_EXE=host
check_XCLBINS=vadd
check_DEVICES=$(vadd_DEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

