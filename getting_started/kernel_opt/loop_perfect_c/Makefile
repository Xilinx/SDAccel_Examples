COMMON_REPO := ../../../
#Common Includes
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl2/xcl2.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall
CXXFLAGS+=-std=c++0x


EXES=host

# nearest kernels
nearest_GOOD_SRCS=./src/nearest_good.cpp
nearest_GOOD_CLFLAGS=-k nearest_good -I./src

nearest_BAD_SRCS=./src/nearest_bad.cpp
nearest_BAD_CLFLAGS=-k nearest_bad -I./src

XOS=nearest_GOOD nearest_BAD

# nearest xclbin
nearest_XOS=nearest_GOOD nearest_BAD

XCLBINS=nearest

# check
check_EXE=host
check_XCLBINS=nearest

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk
