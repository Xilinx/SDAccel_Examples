COMMON_REPO := ../../../
#Common Includes
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall

EXES=host

# nearest kernels
nearest_GOOD_SRCS=./src/nearest_good.cpp
nearest_GOOD_CLFLAGS=-k nearest

nearest_BAD_SRCS=./src/nearest_bad.cpp
nearest_BAD_CLFLAGS=-k nearest

XOS=nearest_GOOD nearest_BAD

# nearest xclbin
nearest_GOOD_XOS=nearest_GOOD

nearest_BAD_XOS=nearest_BAD

XCLBINS=nearest_GOOD nearest_BAD

# check
check_EXE=host
check_XCLBINS=nearest_GOOD nearest_BAD

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk
