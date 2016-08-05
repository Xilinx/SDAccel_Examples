# Huffman Codec Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

CXXFLAGS+= -std=c++0x

# Supported devices
include ../../utility/boards.mk
include ../../libs/logger/logger.mk
include ../../libs/simplebmp/simplebmp.mk
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

# Huffman Codec Host Application
huffman_SRCS=./src/bit_io.cpp ./src/huffmancodec_naive.cpp ./src/huffmancodec_optimized_cpuonly.cpp ./src/huffmancodec_optimized.cpp \
	./src/main.cpp $(simplebmp_SRCS) $(xcl_SRCS) $(logger_SRCS) $(cmdparser_SRCS)
huffman_HDRS=./src/bit_io.h ./src/huffmancodec_naive.h ./src/huffmancodec_optimized_cpuonly.h ./src/huffmancodec_optimized.h \
	$(logger_HDRS) $(simplebmp_HDRS) $(xcl_HDRS) $(cmdparser_HDRS)
huffman_EXE=huffman_codec
huffman_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE) -I$(cmdparser_INCLUDE) -I$(xcl_INCLUDE) -I$(simplebmp_INCLUDE) -I$(logger_INCLUDE)
huffman_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
huffman_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

# Huffman Codec Kernel
krnl_huffman_SRCS=./src/krnl_huffman_singleptr.cl
krnl_huffman_HDRS=
krnl_huffman_XCLBIN=huffman
krnl_huffman_XFLAGS=

EXES=huffman
XCLBINS=krnl_huffman

include ../../utility/rules.mk
