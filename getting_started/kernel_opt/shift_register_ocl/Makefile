
COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
shift_register_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
host_HDRS=${xcl_HDRS}
shift_register_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS)
shift_register_LDFLAGS=$(opencl_LDFLAGS)

CXXFLAGS+=-std=c++0x

# Kernel
fir_SRCS=./src/fir.cl

EXES=shift_register
XCLBINS=fir

# check
check_EXE=shift_register
check_XCLBINS=fir

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
