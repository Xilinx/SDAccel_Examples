

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
loop_pipeline_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
loop_pipeline_HDRS=$(xcl_HDRS)
loop_pipeline_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
loop_pipeline_LDFLAGS=$(opencl_LDFLAGS)

EXES=loop_pipeline

# Kernel
vector_addition_SRCS=./src/vector_addition.cl

XOS=vector_addition

# xclbin
vector_addition_XOS=vector_addition

XCLBINS=vector_addition

# check
check_EXE=$(EXES)
check_XCLBINS=$(XCLBINS)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
