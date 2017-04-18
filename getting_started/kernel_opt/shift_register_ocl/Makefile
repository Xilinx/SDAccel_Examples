COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
shift_register_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
shift_register_HDRS=${xcl_HDRS}
shift_register_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
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
