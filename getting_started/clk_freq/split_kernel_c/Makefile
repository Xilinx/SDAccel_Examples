COMMON_REPO := ../../../
#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk

# Host Application
host_SRCS=./src/host.cpp $(bitmap_SRCS) $(xcl_SRCS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS) 
host_CXXFLAGS+=-Wall
# Switch between GOOD/BAD Examples
KFLOW:=GOOD

# Kernel
ifeq ($(KFLOW),GOOD)
    sketch_SRCS:=./src/sketch.cpp
else
    sketch_SRCS:=./src/sketch_bad.cpp
endif

sketch_CLFLAGS=-k process_image

EXES=host
XCLBINS=sketch
EXTRA_CLEAN=./output.bmp 

# check
check_EXE=host
check_XCLBINS=sketch
check_ARGS=./data/car_128x128.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
