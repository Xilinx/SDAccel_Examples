# vdotprod Application
CXXFLAGS:=-O0 -g -std=c++0x
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

# Additional Libraries
include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl.mk

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

# vdotprod Host Application
vdotprod_SRCS=./src/vdotprod.cpp $(xcl_SRCS)
vdotprod_HDRS=./src/vdotprod.h $(xcl_HDRS)
vdotprod_EXE=vdotprod
vdotprod_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(xcl_INCLUDE)
vdotprod_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
vdotprod_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# hello Kernel
krnl_vdotprod_SRCS=./src/krnl_vdotprod.cl
krnl_vdotprod_HDRS=
krnl_vdotprod_XCLBIN=vdotprod
krnl_vdotprod_XFLAGS=

EXES=vdotprod
XCLBINS=krnl_vdotprod

include ../../utility/rules.mk

