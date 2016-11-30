COMMON_REPO := ../../../

# wide Memory Access Application
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# vadd Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

# vadd Kernels
vadd_SRCS=./src/vadd.cl
vadd_CLFLAGS=-k vadd

EXES=host
XCLBINS=vadd

include ${COMMON_REPO}/utility/rules.mk
include ${COMMON_REPO}/utility/emu_check.mk
