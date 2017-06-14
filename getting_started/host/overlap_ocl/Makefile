
COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
overlap_SRCS=./src/host.cpp $(xcl_SRCS)
overlap_HDRS=$(xcl_HDRS)
overlap_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) -std=c++0x
overlap_LDFLAGS=$(opencl_LDFLAGS)

EXES=overlap

# Kernel
vector_addition_SRCS=./src/vector_addition.cl

XOS=vector_addition

# xclbins
vector_addition_XOS=vector_addition

XCLBINS=vector_addition

# check
check_EXE=overlap
check_XCLBINS=vector_addition

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
