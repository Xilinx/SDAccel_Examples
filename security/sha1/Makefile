# SHA1 Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk

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
sha1_SRCS=./src/sha1_app.cpp ./src/sha1.c ./src/main.cpp $(logger_SRCS) $(cmdparser_SRCS) $(xcl_SRCS)
sha1_HDRS=./src/sha1_app.h ./src/oswendian.h ./src/sha1.h $(logger_HDRS) $(cmdparser_HDRS) $(xcl_HDRS)
sha1_EXE=sha1
sha1_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(logger_INCLUDE) -I$(cmdparser_INCLUDE) -I$(xcl_INCLUDE)
sha1_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
sha1_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0


# SHA1 Kernel
krnl_sha1_SRCS=./src/krnl_sha1.cl
krnl_sha1_HDRS=
krnl_sha1_XCLBIN=sha1
krnl_sha1_XFLAGS=

EXES=sha1
XCLBINS=krnl_sha1

include ../../utility/rules.mk

