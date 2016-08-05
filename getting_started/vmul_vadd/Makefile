# Hello Application
CXXFLAGS:=-O0 -g -std=c++0x
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

# Tool locations
CXX:=$(XILINX_SDACCEL)/Vivado_HLS/lnx64/tools/gcc/bin/g++
CLC:=$(XILINX_SDACCEL)/bin/xocc
CPOWER := $(XILINX_SDACCEL)/gnu/ppc64le/4.9.3/lnx64/bin/powerpc64le-linux-gnu-g++

include ../../utility/boards.mk

# Definition of include file locations
OPENCL12_INCLUDE:= $(XILINX_SDACCEL)/runtime/include/1_2

# Library directories
SDA_LIB:=$(XILINX_SDACCEL)/lib/lnx64.o
OPENCL_LIB:=$(XILINX_SDACCEL)/runtime/lib/x86_64
OPENCL_POWER_LIB:=$(XILINX_SDACCEL)/runtime/lib/ppc64le

# vmulvadd Host Application
vmulvadd_SRCS=./src/main.c
vmulvadd_HDRS=
vmulvadd_EXE=vmulvadd
vmulvadd_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE)
vmulvadd_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
vmulvadd_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# vmul Kernel
krnl_vmul_SRCS=./src/krnl_vmul.cl
krnl_vmul_HDRS=
krnl_vmul_XCLBIN=vmul
krnl_vmul_XFLAGS=

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl
krnl_vadd_HDRS=
krnl_vadd_XCLBIN=vadd
krnl_vadd_XFLAGS=

EXES=vmulvadd
XCLBINS=krnl_vmul krnl_vadd

include ../../utility/rules.mk

