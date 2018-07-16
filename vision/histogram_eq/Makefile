# Histogram Equalization Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencv/opencv.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Equalizer Host Application
equalizer_SRCS=./src/equalizer.cpp $(xcl2_SRCS)
equalizer_HDRS=./src/equalizer.h $(xcl2_SRCS)
equalizer_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(opencv_CXXFLAGS)
equalizer_LDFLAGS=$(opencl_LDFLAGS) $(opencv_LDFLAGS) -lopencv_imgproc -lavcodec -lavformat -lavutil -lswscale

EXES=equalizer

# Equalizer Kernel
krnl_equalizer_SRCS=./src/krnl_equalizer.cl
krnl_equalizer_CLFLAGS=-I./src/
krnl_equalizer_CLFLAGS+=--xp "param:compiler.version=31"

XOS=krnl_equalizer

# Equalizer xclbin
krnl_equalizer_XOS=krnl_equalizer

XCLBINS=krnl_equalizer

# check
check_EXE=equalizer
check_XCLBINS=krnl_equalizer
check_ARGS=data/race_2k.bmp

EXTRA_CLEAN=out.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

