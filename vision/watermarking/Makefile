#Repo containing utility and libs repository to use
COMMON_REPO := ../../

# Make file Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk

# Host files and setting
watermark_SRCS=./src/watermarking.cpp $(xcl_SRCS) $(bitmap_SRCS)
watermark_HDRS=$(xcl_HDRS) $(bitmap_HDRS) 
watermark_CXXFLAGS= -I./src/ -std=c++0x -I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) 
watermark_LDFLAGS=$(opencl_LDFLAGS)

EXES=watermark

# Kernel
apply_watermark_SRCS=./src/krnl_watermarking.cl
apply_watermark_CLFLAGS=-s -I./src --max_memory_ports apply_watermark
apply_watermark_NDEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

XOS=apply_watermark

# xclbin
apply_watermark_XOS=apply_watermark
apply_watermark_LDCLFLAGS=--xp misc:map_connect=add.kernel.apply_watermark_1.M_AXI_GMEM0.core.OCL_REGION_0.M00_AXI --xp misc:map_connect=add.kernel.apply_watermark_1.M_AXI_GMEM1.core.OCL_REGION_0.M01_AXI
apply_watermark_NDEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

XCLBINS=apply_watermark

EXTRA_CLEAN=./output.bmp 

# check
check_EXE=watermark
check_XCLBINS=apply_watermark
check_ARGS=./data/inputImage.bmp ./data/golden.bmp
check_NDEVICES=$(apply_watermark_NDEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

