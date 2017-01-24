# Nearest Neighbor Search Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Nearest Neighbor Search Application
nearest_SRCS=./src/linear_search.c $(xcl_SRCS)
nearest_HDRS=./src/linear_search.h $(xcl_HDRS)
nearest_CXXFLAGS=-I./src/ -I$(XILINX_SDACCEL)/Vivado_HLS/include/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
nearest_LDFLAGS=$(opencl_LDFLAGS)

# Nearest Neighbor Kernel
krnl_nearest_SRCS=./src/krnl_linear_search.cpp
krnl_nearest_CLFLAGS=--kernel krnl_linear_search --nk krnl_linear_search:3
krnl_nearest_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

EXES=nearest
XCLBINS=krnl_nearest

# check
check_EXE=nearest
check_XCLBINS=krnl_nearest
check_ARGS=data/queries.txt data/queries.txt
check_DEVICES=$(krnl_nearest_DEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

