#Repo containing utility and libs repository to use
COMMON_REPO := ../../../

# Make file Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk

#set this value to GOOD for better design timing
#or set its value to BAD for degraded design timing
KFLOW:=GOOD

# Host files and setting
host_SRCS=./src/host.cpp $(xcl2_SRCS) $(bitmap_SRCS)
host_HDRS=$(xcl2_HDRS) $(bitmap_HDRS) 
host_CXXFLAGS= -I./src/ -std=c++0x -I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
apply_watermark_BAD_SRCS=./src/apply_watermark.cl
apply_watermark_BAD_CLFLAGS=-DBAD_DESIGN=1

apply_watermark_GOOD_SRCS=./src/apply_watermark.cl
apply_watermark_GOOD_CLFLAGS=-DBAD_DESIGN=0


apply_watermark_GOOD_XOS=apply_watermark_GOOD
apply_watermark_BAD_XOS=apply_watermark_BAD

XOS=apply_watermark_$(KFLOW)
XCLBINS=apply_watermark_$(KFLOW)

# check
check_EXE=host
check_XCLBINS=apply_watermark_$(KFLOW)
check_ARGS=apply_watermark_$(KFLOW) ./data/input.bmp ./data/golden.bmp

CHECKS=check

EXTRA_CLEAN=./output.bmp


CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

