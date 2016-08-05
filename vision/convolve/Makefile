# Convolve Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencv/opencv.mk
include ../../libs/opencl/opencl.mk

# convolve Host Application
convolve_SRCS=src/convolve.cpp $(xcl_SRCS)
convolve_HDRS= $(xcl_HDRS)
convolve_CXXFLAGS=$(xcl_CXXFLAGS) $(opencl_CXXFLAGS) $(opencv_CXXFLAGS)
convolve_LDFLAGS=$(opencv_LDFLAGS)
convolve_X86_LDFLAGS=$(opencl_X86_LDFLAGS)
convolve_POWER_LDFLAGS=$(opencl_POWER_LDFLAGS)

# convolve Kernel
krnl_convolve_SRCS=src/krnl_convolve.cl

EXES=convolve
XCLBINS=krnl_convolve

include ../../utility/rules.mk

