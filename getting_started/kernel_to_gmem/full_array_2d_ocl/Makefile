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

# Kernel
mmult_SRCS=./src/mmult.cl
mmult_CLFLAGS=-k mmult

EXES=host
XCLBINS=mmult

# check
check_EXE=host
check_XCLBINS=mmult

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk

