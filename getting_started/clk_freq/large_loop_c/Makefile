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

EXES=host

# cnn Kernels
cnn_GOOD_SRCS=./src/cnn_convolution.cpp
cnn_GOOD_CLFLAGS=-k cnn -I./src/
cnn_GOOD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

cnn_BAD_SRCS=./src/cnn_convolution_bad.cpp
cnn_BAD_CLFLAGS=-k cnn -I./src/
cnn_BAD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

XOS=cnn_GOOD cnn_BAD

# cnn xclbins

cnn_GOOD_XOS=cnn_GOOD
cnn_GOOD_LDCLFLAGS=--nk cnn:4
cnn_GOOD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

cnn_BAD_XOS=cnn_BAD
cnn_BAD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

XCLBINS=cnn_GOOD cnn_BAD

# check
check_EXE=host
check_XCLBINS=cnn_GOOD cnn_BAD
check_DEVICES=$(cnn_GOOD_DEVICES)

CHECKS=check

DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0
include $(COMMON_REPO)/utility/rules.mk
