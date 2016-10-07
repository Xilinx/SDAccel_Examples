# Vadd Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencl/opencl.mk

# vadd Host Application
vadd_SRCS=./src/vadd.cpp $(xcl_SRCS)
vadd_HDRS=$(xcl_HDRS)
vadd_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
vadd_LDFLAGS=$(opencl_LDFLAGS)

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl

EXES=vadd
XCLBINS=krnl_vadd

include ../../utility/rules.mk

