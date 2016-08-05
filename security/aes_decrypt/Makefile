# AES Decrypt Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/simplebmp/simplebmp.mk

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
aes_SRCS=./src/aes_ecb.cpp ./src/aes_app.cpp ./src/main.cpp $(xcl_SRCS) $(cmdparser_SRCS) $(logger_SRCS) $(simplebmp_SRCS)
aes_HDRS=./src/aes_app.h $(xcl_HDRS) $(cmdparser_HDRS) $(logger_HDRS) $(simplebmp_HDRS)
aes_EXE=aesdecrypt
aes_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(xcl_INCLUDE) -I$(cmdparser_INCLUDE) -I$(logger_INCLUDE) -I$(simplebmp_INCLUDE)
aes_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
aes_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0


# AES Kernel
krnl_aes_SRCS=./src/krnl_aes.cl
krnl_aes_HDRS=
krnl_aes_XCLBIN=aes
krnl_aes_XFLAGS=

EXES=aes
XCLBINS=krnl_aes

include ../../utility/rules.mk

