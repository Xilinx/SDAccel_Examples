# Edge Detection Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencv/opencv.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Edge Detection Host Application
edge_SRCS=./src/edge.cpp $(xcl_SRCS)
edge_HDRS=./src/edge.h $(xcl_HDRS)
edge_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencv_CXXFLAGS) $(opencl_CXXFLAGS)
edge_LDFLAGS=$(opencl_LDFLAGS) $(opencv_LDFLAGS)

EXES=edge

# Edge Detection Kernel
krnl_edge_SRCS=./src/krnl_sobelfilter.cl
krnl_edge_HDRS=./src/edge.h
krnl_edge_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr
krnl_edge_CLFLAGS=-I./src/

XOS=krnl_edge

# Edge Detection xclbin
krnl_edge_XOS=krnl_edge
krnl_edge_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr

XCLBINS=krnl_edge

# check
check_EXE=edge
check_XCLBINS=krnl_edge
check_ARGS=data/input/eiffel.bmp
check_NDEVICES=$(krnl_edge_NDEVICES)

CHECKS=check

DEVICES=xilinx:adm-pcie-ku3:2ddr-xpr

include $(COMMON_REPO)/utility/rules.mk

