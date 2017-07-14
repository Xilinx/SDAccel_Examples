# Convolve Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencv/opencv.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# convolve Host Application
convolve_SRCS=src/convolve.cpp $(xcl_SRCS)
convolve_HDRS= $(xcl_HDRS)
convolve_CXXFLAGS=$(xcl_CXXFLAGS) $(opencl_CXXFLAGS) $(opencv_CXXFLAGS)
convolve_LDFLAGS=$(opencl_LDFLAGS) $(opencv_LDFLAGS)

EXES=convolve

# convolve Kernel
krnl_convolve_SRCS=src/krnl_convolve.cl
krnl_convolve_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr

XOS=krnl_convolve

# convolve xclbin
krnl_convolve_XOS=krnl_convolve
krnl_convolve_CLFLAGS=--nk krnl_convolve:3
krnl_convolve_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr

XCLBINS=krnl_convolve

# check
check_EXE=convolve
check_XCLBINS=krnl_convolve
check_ARGS=data/input_buffer_raw.txt data/filter_buffer_raw.txt data/output_buffer_raw.txt
check_NDEVICES=$(krnl_convolve_NDEVICES)

CHECKS=check

DEVICES=xilinx:adm-pcie-ku3:2ddr-xpr

include $(COMMON_REPO)/utility/rules.mk

