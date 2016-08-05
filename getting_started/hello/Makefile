# Hello Application
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

# hello Host Application
hello_SRCS=./src/hello.cpp $(xcl_SRCS)
hello_HDRS= $(xcl_HDRS)
hello_EXE=hello
hello_CXXFLAGS:=-I./src/ -I$(xcl_INCLUDE) -I$(OPENCL12_INCLUDE)
hello_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
hello_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0


# hello Kernel
krnl_hello_SRCS=./src/krnl_hello.cl
krnl_hello_HDRS=
krnl_hello_XCLBIN=hello
krnl_hello_XFLAGS=

EXES=hello
XCLBINS=krnl_hello

include ../../utility/rules.mk

