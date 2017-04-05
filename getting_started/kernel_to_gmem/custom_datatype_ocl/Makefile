#Repo containing utility and libs repository to use
COMMON_REPO := ../../../

# Custom Data Type Application
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk

# Host Application
host_SRCS=./src/host.cpp $(bitmap_SRCS) $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)  $(bitmap_HDRS)
host_CXXFLAGS= -I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
rgb_to_hsv_SRCS=./src/rgb_to_hsv.cl
rgb_to_hsv_CLFLAGS= -k rgb_to_hsv -I./src/

XOS=rgb_to_hsv

# xclbin
rgb_to_hsv_XOS=rgb_to_hsv

XCLBINS=rgb_to_hsv

EXTRA_CLEAN=./output.bmp 

# check
check_EXE=host
check_XCLBINS=rgb_to_hsv
check_ARGS=./data/input.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

