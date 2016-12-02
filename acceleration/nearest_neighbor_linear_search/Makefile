# Nearest Neighbor Search Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencl/opencl.mk

# Nearest Neighbor Search Application
nearest_SRCS=./src/linear_search.c $(xcl_SRCS)
nearest_HDRS=./src/linear_search.h $(xcl_HDRS)
nearest_CXXFLAGS=-I./src/ -I$(XILINX_SDACCEL)/Vivado_HLS/include/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
nearest_LDFLAGS=$(opencl_LDFLAGS)

# Nearest Neighbor Kernel
krnl_nearest_SRCS=./src/krnl_linear_search.cpp
krnl_nearest_CLFLAGS=--kernel krnl_linear_search

EXES=nearest
XCLBINS=krnl_nearest

# check
check_EXE=nearest
check_XCLBINS=krnl_nearest
check_ARGS=data/queries.txt data/queries.txt

CHECKS=check

include ../../utility/rules.mk

