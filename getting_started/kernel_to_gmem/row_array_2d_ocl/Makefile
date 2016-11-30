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
row_array_2d_SRCS=./src/row_array_2d.cl
#Specify Kernel name
row_array_2d_CLFLAGS=-k row_array_2d

EXES=host
XCLBINS=row_array_2d

include ${COMMON_REPO}/utility/rules.mk
include ${COMMON_REPO}/utility/emu_check.mk
