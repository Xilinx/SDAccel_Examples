COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
errors_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
errors_HDRS=$(xcl_HDRS)
errors_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
errors_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
vector_addition_SRCS=./src/vector_addition.cl

EXES=errors
XCLBINS=vector_addition

# check
check_EXE=errors
check_XCLBINS=vector_addition
check_ARGS=$(XCLBIN_GOALS)

CHECKS=check


include $(COMMON_REPO)/utility/rules.mk
