# RSA Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
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

# hello Host Application
rsa_SRCS=./src/rsa_app.cpp ./src/common.cpp ./src/main.cpp $(cmdparser_SRCS) $(xcl_SRCS) $(logger_SRCS)
rsa_HDRS=./src/rsa_app.h ./src/common.h $(cmdparser_HDRS) $(logger_HDRS) $(xcl_HDRS)
rsa_EXE=rsa
rsa_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(cmdparser_INCLUDE) -I$(logger_INCLUDE) -I$(xcl_INCLUDE)
rsa_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
rsa_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# RSA Kernel
krnl_rsa_SRCS=./src/krnl_rsa.cl
krnl_rsa_HDRS=
krnl_rsa_XCLBIN=rsa
krnl_rsa_XFLAGS=

EXES=rsa
XCLBINS=krnl_rsa

include ../../utility/rules.mk

