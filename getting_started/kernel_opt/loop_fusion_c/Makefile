COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
loop_fusion_SRCS=./src/host.cpp $(oclHelper_SRCS) $(xcl2_SRCS)
loop_fusion_HDRS=$(xcl2_HDRS)
loop_fusion_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
loop_fusion_LDFLAGS=$(opencl_LDFLAGS)

EXES=loop_fusion

# Kernel
nn_good_SRCS=./src/nearest_neighbor.cpp
nn_good_CLFLAGS=-k nearest_neighbor_loop_fusion

nn_bad_SRCS=./src/nearest_neighbor_bad.cpp
nn_bad_CLFLAGS=-k nearest_neighbor 

XOS=nn_good nn_bad

# xclbin
nearest_neighbor_XOS=nn_good nn_bad
nearest_neighbor_NDEVICES=xilinx:kcu1500:dynamic xilinx_kcu1500_dynamic_5_0

XCLBINS=nearest_neighbor

# check
check_EXE=$(EXES)
check_XCLBINS=$(XCLBINS)
check_NDEVICES=$(nearest_neighbor_NDEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
