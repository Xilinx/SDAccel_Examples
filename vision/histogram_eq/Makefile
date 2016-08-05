# Histogram Equalization Application
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
OPENCV_LIB:=$(XILINX_SDACCEL)/lnx64/tools/opencv

# Equalizer Host Application
equalizer_SRCS=./src/equalizer.cpp $(xcl_SRCS)
equalizer_HDRS=./src/equalizer.h $(xcl_SRCS)
equalizer_EXE=equalizer
equalizer_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(xcl_INCLUDE) -I$(XILINX_SDACCEL)/include
equalizer_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -L$(OPENCV_LIB) -lOpenCL -pthread -lopencv_core -lopencv_highgui -lopencv_imgproc -lavcodec -lavformat -lavutil -lswscale
equalizer_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# Equalizer Kernel
krnl_equalizer_SRCS=./src/krnl_equalizer.cl
krnl_equalizer_HDRS=
krnl_equalizer_XCLBIN=rsa
krnl_equalizer_XFLAGS=

EXES=equalizer
XCLBINS=krnl_equalizer

include ../../utility/rules.mk

