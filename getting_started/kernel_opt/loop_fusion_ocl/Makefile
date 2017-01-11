

COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
loop_fusion_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl_SRCS)
loop_fusion_HDRS=$(xcl_HDRS)
loop_fusion_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(oclHelper_CXXFLAGS)
loop_fusion_LDFLAGS=$(opencl_LDFLAGS)
CXXFLAGS+=-std=c++0x

# Kernel
nearest_neighbor_SRCS=./src/nearest_neighbor.cl

EXES=loop_fusion
XCLBINS=nearest_neighbor

# check
check_EXE=$(EXES)
check_XCLBINS=$(XCLBINS)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
