COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
N_stage_Adders_SRCS=./src/N_stage_adders.cpp
N_stage_Adders_CLFLAGS= -k N_stage_Adders

XOS=N_stage_Adders

# xclbin
N_stage_Adders_XOS=N_stage_Adders

XCLBINS=N_stage_Adders

# check
check_EXE=host
check_XCLBINS=N_stage_Adders

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

