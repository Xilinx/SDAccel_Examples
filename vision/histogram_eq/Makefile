# Histogram Equalization Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencv/opencv.mk
include ../../libs/opencl/opencl.mk

# Equalizer Host Application
equalizer_SRCS=./src/equalizer.cpp $(xcl_SRCS)
equalizer_HDRS=./src/equalizer.h $(xcl_SRCS)
equalizer_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(opencv_CXXFLAGS)
equalizer_LDFLAGS=$(opencv_LDFLAGS) -lopencv_imgproc -lavcodec -lavformat -lavutil -lswscale
equalizer_X86_LDFLAGS=$(opencl_X86_LDFLAGS)
equalizer_POWER_LDFLAGS=$(opencl_POWER_LDFLAGS)

# Equalizer Kernel
krnl_equalizer_SRCS=./src/krnl_equalizer.cl

EXES=equalizer
XCLBINS=krnl_equalizer

include ../../utility/rules.mk

