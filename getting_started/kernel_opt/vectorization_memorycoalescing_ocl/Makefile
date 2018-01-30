COMMON_REPO := ../../../
#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
vector_addition_SRCS=./src/vector_addition.cl
vector_addition_CLFLAGS=-k vec_add

XOS=vector_addition
XCLBINS=vector_addition

vector_addition_XOS=vector_addition

# check
check_EXE=host
check_XCLBINS=vector_addition

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
