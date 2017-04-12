COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
host_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
vector_addition_SRCS=./src/vector_addition.cl

XOS=vector_addition

vector_addition_XOS=vector_addition

XCLBINS=vector_addition

# check
check_EXE=host
check_XCLBINS=vector_addition

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
