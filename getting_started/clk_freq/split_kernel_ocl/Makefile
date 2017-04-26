COMMON_REPO := ../../../
#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk

# Host Application
host_SRCS=./src/host.cpp $(bitmap_SRCS) $(xcl2_SRCS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall

EXES=host

# Kernel
sketch_GOOD_SRCS:=./src/sketch.cl
sketch_GOOD_CLFLAGS=-k process_image -I./src/
sketch_GOOD_CLFLAGS+=--xp "param:compiler.xclDataflowFifoDepth=16"

sketch_BAD_SRCS:=./src/sketch_bad.cl
sketch_BAD_CLFLAGS=-k process_image -I./src/
sketch_BAD_CLFLAGS+=--xp "param:compiler.xclDataflowFifoDepth=16"

XOS=sketch_GOOD sketch_BAD

# xclbin
sketch_GOOD_XOS=sketch_GOOD
sketch_BAD_XOS=sketch_BAD

XCLBINS=sketch_GOOD sketch_BAD

EXTRA_CLEAN=./output.bmp

# check
check_EXE=host
check_XCLBINS=sketch_GOOD sketch_BAD
check_ARGS=./data/car_128x128.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
