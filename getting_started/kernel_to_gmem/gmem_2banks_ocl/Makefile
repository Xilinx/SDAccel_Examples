#Repo containing utility and libs repository to use
COMMON_REPO := ../../../

# Make file Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk

# Host files and setting
host_SRCS=./src/host.cpp $(xcl_SRCS) $(bitmap_SRCS)
host_HDRS=$(xcl_HDRS) $(bitmap_HDRS) 
host_CXXFLAGS= -I./src/ -g -std=c++0x -I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
apply_watermark_SRCS=./src/apply_watermark.cl
apply_watermark_CLFLAGS=-s -g -I./src --max_memory_ports apply_watermark
apply_watermark_DEVICES=xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XOS=apply_watermark

# xclbin
apply_watermark_XOS=apply_watermark
apply_watermark_LDCLFLAGS=--xp misc:map_connect=add.kernel.apply_watermark_1.M_AXI_GMEM0.core.OCL_REGION_0.M00_AXI --xp misc:map_connect=add.kernel.apply_watermark_1.M_AXI_GMEM1.core.OCL_REGION_0.M01_AXI
apply_watermark_DEVICES=xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XCLBINS=apply_watermark

EXTRA_CLEAN=./output.bmp

# check
check_EXE=host
check_XCLBINS=apply_watermark
check_ARGS=./data/input.bmp ./data/golden.bmp
check_DEVICES=$(apply_watermark_DEVICES)

CHECKS=check

#changing Default Device for this example
DEVICES=xilinx:adm-pcie-ku3:2ddr-xpr:3.3
include $(COMMON_REPO)/utility/rules.mk

