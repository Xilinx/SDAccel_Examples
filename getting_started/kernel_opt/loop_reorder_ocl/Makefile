COMMON_REPO := ../../../
#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
mmult_SRCS=./src/mmult.cl
mmult_CLFLAGS=-k mmult

XOS=mmult
EXES=host
XCLBINS=mmult

mmult_XOS=mmult
# check
check_EXE=host
check_XCLBINS=mmult

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
