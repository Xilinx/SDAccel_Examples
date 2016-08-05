# Watermarking Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk
include ../../libs/oclHelper/oclHelper.mk
include ../../libs/bitmap/bitmap.mk

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

# Watermarking Host Application
watermark_SRCS=./src/watermarking.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
watermark_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
watermark_EXE=watermark
watermark_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(bitmap_INCLUDE) -I$(oclHelper_INCLUDE)
watermark_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
watermark_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# Watermark Kernel
krnl_watermark_SRCS=./src/krnl_watermarking.cl
krnl_watermark_HDRS=
krnl_watermark_XCLBIN=watermark
krnl_watermark_XFLAGS=

EXES=watermark
XCLBINS=krnl_watermark

include ../../utility/rules.mk
