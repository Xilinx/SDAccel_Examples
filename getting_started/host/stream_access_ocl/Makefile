COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
stream_access_SRCS=./src/host.cpp $(xcl_SRCS)
stream_access_HDRS=$(xcl_HDRS)
stream_access_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) -std=c++0x
stream_access_LDFLAGS=$(opencl_LDFLAGS)

EXES=stream_access

# Kernel
vector_addition_SRCS=./src/vector_addition.cl

XOS=vector_addition

# xclbins
vector_addition_XOS=vector_addition

XCLBINS=vector_addition

# check
check_EXE=stream_access
check_XCLBINS=vector_addition
check_ARGS=./data/input1.txt ./data/input2.txt

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
