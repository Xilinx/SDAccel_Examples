# Vadd Application
CXXFLAGS:=-O0 -g -std=c++0x
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

# Additional Libraries
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

# vadd Host Application
vadd_SRCS=./src/vadd.cpp $(xcl_SRCS)
vadd_HDRS=$(xcl_HDRS)
vadd_EXE=vadd
vadd_CXXFLAGS:=-I./src/ -I$(xcl_INCLUDE) -I$(OPENCL12_INCLUDE)
vadd_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
vadd_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl
krnl_vadd_HDRS=
krnl_vadd_XCLBIN=vadd
krnl_vadd_XFLAGS=

EXES=vadd
XCLBINS=krnl_vadd

include ../../utility/rules.mk

