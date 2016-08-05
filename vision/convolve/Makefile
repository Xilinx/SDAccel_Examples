# Convolve Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk

# Tool locations
CXX:=$(XILINX_SDACCEL)/Vivado_HLS/lnx64/tools/gcc/bin/g++
CLC:=$(XILINX_SDACCEL)/bin/xocc
CPOWER := $(XILINX_SDACCEL)/gnu/ppc64le/4.9.3/lnx64/bin/powerpc64le-linux-gnu-g++

# Definition of include file locations
OPENCL12_INCLUDE:= $(XILINX_SDACCEL)/runtime/include/1_2

# Library directories
SDA_LIB:=$(XILINX_SDACCEL)/lib/lnx64.o
OPENCL_LIB:=$(XILINX_SDACCEL)/runtime/lib/x86_64
OPENCL_POWER_LIB:=$(XILINX_SDACCEL)/runtime/lib/ppc64le

# OpenCV Library Locations
OPENCV_INCLUDE:=$(XILINX_SDACCEL)/include
OPENCV_LIB:=$(XILINX_SDACCEL)/lnx64/tools/opencv

# convolve Host Application
convolve_SRCS=src/convolve.cpp $(xcl_SRCS)
convolve_HDRS= $(xcl_HDRS)
convolve_EXE=convolve
convolve_CXXFLAGS:= -I$(xcl_INCLUDE) -I$(OPENCL12_INCLUDE) -I$(OPENCV_INCLUDE)
convolve_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread -L$(OPENCV_LIB) -lopencv_core -lopencv_highgui
convolve_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0 -L$(OPENCV_LIB) -lopencv_core -lopencv_highgui

# convolve Kernel
krnl_convolve_SRCS=src/krnl_convolve.cl
krnl_convolve_HDRS=
krnl_convolve_XCLBIN=convolve
krnl_convolve_XFLAGS=

EXES=convolve
XCLBINS=krnl_convolve

include ../../utility/rules.mk

