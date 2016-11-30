# Vadd Application
COMMON_REPO:=../../../
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# vadd Host Application
vadd_SRCS=./src/vadd.cpp $(xcl_SRCS)
vadd_HDRS=$(xcl_HDRS)
vadd_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
vadd_LDFLAGS=$(opencl_LDFLAGS)

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl

EXES=vadd
XCLBINS=krnl_vadd

include ${COMMON_REPO}/utility/rules.mk
include ${COMMON_REPO}/utility/emu_check.mk
