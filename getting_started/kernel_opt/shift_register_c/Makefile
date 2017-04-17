COMMON_REPO := ../../../

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=${xcl2_HDRS}
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) 
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall
CXXFLAGS+=-std=c++0x

EXES=host

# Kernel

fir_sr_SRCS=./src/fir_shift_register.cpp
fir_sr_CLFLAGS=-k fir_shift_register -I./src/
	
fir_naive_SRCS=./src/fir_naive.cpp
fir_naive_CLFLAGS=-k fir_naive -I./src/

XOS=fir_sr fir_naive

# xclbin
fir_XOS=fir_sr fir_naive

XCLBINS=fir

check_EXE=host
check_XCLBINS=fir

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
