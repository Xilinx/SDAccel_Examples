COMMON_REPO := ../../../

include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
N_stage_Adders_SRCS=./src/N_stage_adders.cpp
N_stage_Adders_CLFLAGS= -k N_stage_Adders 

EXES=host
XCLBINS=N_stage_Adders

# check
check_EXE=host
check_XCLBINS=N_stage_Adders

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk

