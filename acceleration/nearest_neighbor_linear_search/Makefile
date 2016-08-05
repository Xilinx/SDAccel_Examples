# Nearest Neighbor Search Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk

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

# Nearest Neighbor Search Application
nearest_SRCS=./src/linear_search.c ./src/xcl.c
nearest_HDRS=./src/linear_search.h ./src/xcl.h
nearest_EXE=nearest
nearest_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(XILINX_SDACCEL)/include/
nearest_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
nearest_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# Nearest Neighbor  Kernel
krnl_nearest_SRCS=./src/krnl_linear_search.cpp
krnl_nearest_HDRS=
krnl_nearest_XCLBIN=nearest
krnl_nearest_XFLAGS= --kernel krnl_linear_search

EXES=nearest
XCLBINS=krnl_nearest

include ../../utility/rules.mk

