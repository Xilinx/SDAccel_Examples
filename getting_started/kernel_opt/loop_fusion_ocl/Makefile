COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
loop_fusion_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl2_SRCS)
loop_fusion_HDRS=$(xcl2_HDRS)
loop_fusion_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
loop_fusion_LDFLAGS=$(opencl_LDFLAGS)

EXES=loop_fusion

# Kernel
nearest_neighbor_SRCS=./src/nearest_neighbor.cl

XOS=nearest_neighbor

# xclbin
nearest_neighbor_XOS=nearest_neighbor

XCLBINS=nearest_neighbor

# check
check_EXE=$(EXES)
check_XCLBINS=$(XCLBINS)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
