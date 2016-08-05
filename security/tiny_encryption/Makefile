# Tiny Encription Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk
include ../../libs/bitmap/bitmap.mk
include ../../libs/oclHelper/oclHelper.mk

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

# Tiny Encryption Host Application
tiny_SRCS=./src/tinyEncryption.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
tiny_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
tiny_EXE=tinyEncryption
tiny_CXXFLAGS:=-I./src/ -I./../../libs/bitmap/ -I./../../libs/oclHelper -I$(OPENCL12_INCLUDE)
tiny_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
tiny_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0


# Tiny Encryption Kernel
krnl_tiny_SRCS=./src/krnl_tinyEncryption.cl
krnl_tiny_HDRS=
krnl_tiny_XCLBIN=tinyEncryption
krnl_tiny_XFLAGS=

EXES=tiny
XCLBINS=krnl_tiny

include ../../utility/rules.mk

