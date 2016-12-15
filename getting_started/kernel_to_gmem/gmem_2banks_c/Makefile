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

# Kernel
apply_watermark_SRCS=./src/apply_watermark.cpp
apply_watermark_CLFLAGS=-k apply_watermark -s -g -I./src --max_memory_ports apply_watermark --xp misc:map_connect=add.kernel.apply_watermark_1.M_AXI_GMEM0.core.OCL_REGION_0.M00_AXI --xp misc:map_connect=add.kernel.apply_watermark_1.M_AXI_GMEM1.core.OCL_REGION_0.M01_AXI

EXES=host
XCLBINS=apply_watermark
EXTRA_CLEAN=./output.bmp 

# check
check_EXE=host
check_XCLBINS=apply_watermark
check_ARGS=./data/input.bmp ./data/golden.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

