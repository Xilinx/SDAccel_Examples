COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
host_SRCS=./src/host.cpp $(bitmap_SRCS) $(oclHelper_SRCS) $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS) $(bitmap_HDRS)
host_CXXFLAGS= -I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS) 
host_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
mean_value_SRCS=./src/mean_value.cpp
mean_value_CLFLAGS=-k mean_value

EXES=host
XCLBINS=mean_value

# check
check_EXE=host
check_XCLBINS=mean_value

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

