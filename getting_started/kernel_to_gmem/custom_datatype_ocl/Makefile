#Repo containing utility and libs repository to use
COMMON_REPO := ../../../

# Custom Data Type Application
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk

CXX:=/tools/batonroot/rodin/devkits/lnx64/gcc-6.2.0/bin/g++
# Host Application
host_SRCS=./src/host.cpp $(bitmap_SRCS) $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)  $(bitmap_HDRS)
host_CXXFLAGS= -I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
rgb_to_hsv_SRCS=./src/rgb_to_hsv.cl
rgb_to_hsv_CLFLAGS= -k rgb_to_hsv -I./src/

XOS=rgb_to_hsv

# xcl2bin
rgb_to_hsv_XOS=rgb_to_hsv

XCLBINS=rgb_to_hsv

EXTRA_CLEAN=./output.bmp 

# check
check_EXE=host
check_XCLBINS=rgb_to_hsv
check_ARGS=./data/input.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

