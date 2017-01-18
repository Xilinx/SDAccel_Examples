# Histogram Equalization Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencv/opencv.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Equalizer Host Application
equalizer_SRCS=./src/equalizer.cpp $(xcl_SRCS)
equalizer_HDRS=./src/equalizer.h $(xcl_SRCS)
equalizer_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(opencv_CXXFLAGS)
equalizer_LDFLAGS=$(opencl_LDFLAGS) $(opencv_LDFLAGS) -lopencv_imgproc -lavcodec -lavformat -lavutil -lswscale

# Equalizer Kernel
krnl_equalizer_SRCS=./src/krnl_equalizer.cl

EXES=equalizer
XCLBINS=krnl_equalizer

# check
check_EXE=equalizer
check_XCLBINS=krnl_equalizer
check_ARGS=data/race_2k.bmp
CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

