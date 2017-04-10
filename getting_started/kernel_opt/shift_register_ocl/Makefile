COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
shift_register_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl2_SRCS)
shift_register_HDRS=${xcl2_HDRS}
shift_register_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
shift_register_LDFLAGS=$(opencl_LDFLAGS)

EXES=shift_register

# Kernel
fir_SRCS=./src/fir.cl

XOS=fir

# xclbin
fir_XOS=fir

XCLBINS=fir

# check
check_EXE=shift_register
check_XCLBINS=fir

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
