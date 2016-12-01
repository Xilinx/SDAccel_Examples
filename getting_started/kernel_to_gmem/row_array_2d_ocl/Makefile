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
row_array_2d_SRCS=./src/row_array_2d.cl
#Specify Kernel name
row_array_2d_CLFLAGS=-k row_array_2d

EXES=host
XCLBINS=row_array_2d

# check
check_EXE=host
check_XCLBINS=row_array_2d

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk

