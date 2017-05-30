# Nearest Neighbor Search Application
COMMON_REPO=../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Nearest Neighbor Search Application
nearest_SRCS=./src/linear_search.c $(xcl_SRCS)
nearest_HDRS=./src/linear_search.h $(xcl_HDRS)
nearest_CXXFLAGS=-I./src/ -I$(XILINX_SDACCEL)/Vivado_HLS/include/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
nearest_LDFLAGS=$(opencl_LDFLAGS)

EXES=nearest

# Nearest Neighbor Kernel
krnl_nearest_SRCS=./src/krnl_linear_search.cpp
krnl_nearest_CLFLAGS=--kernel krnl_linear_search -I./src/
krnl_nearest_NDEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:xil-accel-rd-ku115:4ddr-xpr

XOS=krnl_nearest

# Nearest Neighbor xclbin
krnl_nearest_XOS=krnl_nearest
krnl_nearest_LDCLFLAGS=--nk krnl_linear_search:3
krnl_nearest_NDEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:xil-accel-rd-ku115:4ddr-xpr

XCLBINS=krnl_nearest

# check
check_EXE=nearest
check_XCLBINS=krnl_nearest
check_ARGS=data/queries.txt data/queries.txt
check_NDEVICES=$(krnl_nearest_NDEVICES)

CHECKS=check

DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr

include $(COMMON_REPO)/utility/rules.mk

