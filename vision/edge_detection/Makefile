# Edge Detection Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/simplebmp/simplebmp.mk
include ../../libs/lodepng/lodepng.mk

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

# Edge Detection Host Application
edge_SRCS=./src/edgedetection_app.cpp ./src/main.cpp ./src/sobel_cpuonly.cpp $(simplebmp_SRCS) $(logger_SRCS) $(cmdparser_SRCS) $(xcl_SRCS) $(lodepng_SRCS)
edge_HDRS=./src/sobel_cpuonly.h ./src/edgedetection_app.h $(xcl_HDRS) $(cmdparser_HDRS) $(logger_HDRS) $(simplebmp_HDRS) $(lodepng_HDRS)
edge_EXE=edge_detect
edge_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(simplebmp_INCLUDE) -I$(logger_INCLUDE) -I$(cmdparser_INCLUDE) -I$(xcl_INCLUDE) -I$(lodepng_INCLUDE)
edge_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
edge_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# Edge Detection Kernel
krnl_edge_SRCS=./src/krnl_sobelfilter.cl
krnl_edge_HDRS=
krnl_edge_XCLBIN=sobelfilter
krnl_edge_XFLAGS=

EXES=edge
XCLBINS=krnl_edge

include ../../utility/rules.mk

