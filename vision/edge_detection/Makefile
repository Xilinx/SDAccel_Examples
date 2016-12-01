# Edge Detection Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencv/opencv.mk
include ../../libs/opencl/opencl.mk

# Edge Detection Host Application
edge_SRCS=./src/edge.cpp $(xcl_SRCS)
edge_HDRS=./src/edge.h $(xcl_HDRS)
edge_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencv_CXXFLAGS) $(opencl_CXXFLAGS)
edge_LDFLAGS=$(opencl_LDFLAGS) $(opencv_LDFLAGS)

# Edge Detection Kernel
krnl_edge_SRCS=./src/krnl_sobelfilter.cl
krnl_edge_HDRS=./src/edge.h

EXES=edge
XCLBINS=krnl_edge

# check
check_EXE=edge
check_XCLBINS=krnl_edge

CHECKS=check

include ../../utility/rules.mk

