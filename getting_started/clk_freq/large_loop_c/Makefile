COMMON_REPO := ../../../

# wide Memory Access Application
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# cnn Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall

# Switch between GOOD/BAD Examples
KFLOW:=GOOD

# cnn Kernels
ifeq ($(KFLOW), GOOD)
    # Add good kernel
    cnn_SRCS:=./src/cnn_convolution.cpp
    # Enable multiple compute units
    cnn_CLFLAGS=--nk cnn:4
    host_CXXFLAGS += -DGOOD
else
    cnn_SRCS:=./src/cnn_convolution_bad.cpp
endif

cnn_CLFLAGS+=-k cnn
cnn_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2

EXES=host
XCLBINS=cnn

# check
check_EXE=host
check_XCLBINS=cnn
check_DEVICES=$(cnn_DEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
