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
vadd_SRCS=./src/vadd.cl
vadd_CLFLAGS=-k vadd --xp param:compiler.interfaceWrBurstLen=256 --xp param:compiler.interfaceRdBurstLen=256

XOS=vadd

vadd_XOS=vadd

XCLBINS=vadd

# check
check_EXE=host
check_XCLBINS=vadd

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

