#Repo containing utility and libs repository to use
COMMON_REPO := ../../../

# Custom Data Type Application
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk
include ${COMMON_REPO}/libs/bitmap/bitmap.mk

# Host Application
host_SRCS=./src/host.cpp ${bitmap_SRCS} ${xcl_SRCS}
host_HDRS=${xcl_HDRS}
host_CXXFLAGS= -D USE_IN_HOST -I./src/ ${xcl_CXXFLAGS} ${opencl_CXXFLAGS} ${bitmap_CXXFLAGS} 
host_LDFLAGS=${opencl_LDFLAGS}

# Kernel
rgb_to_hsv_SRCS=./src/rgb_to_hsv.cpp
rgb_to_hsv_CLFLAGS= -k rgb_to_hsv

EXES=host
XCLBINS=rgb_to_hsv
EXTRA_CLEAN=./output.bmp 


include ${COMMON_REPO}/utility/rules.mk
include ${COMMON_REPO}/utility/emu_check.mk

RUN_TIME_ARGS += ./data/input.bmp

