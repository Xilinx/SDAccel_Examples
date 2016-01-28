# Linear Search Application
XDEVICE:=xilinx:adm-pcie-7v3:1ddr:2.0
XMODE:=sw_emu
CXXFLAGS:=-g -O0 -std=c++0x

# Tool locations
CXX:=$(XILINX_SDACCEL)/Vivado_HLS/lnx64/tools/gcc/bin/g++
CLC:=$(XILINX_SDACCEL)/bin/xocc

# Definition of include file locations
SDA_INCLUDE:=$(XILINX_SDACCEL)/include/
OPENCL12_INCLUDE:= $(XILINX_SDACCEL)/runtime/include/1_2

# Library directories
SDA_LIB:=$(XILINX_SDACCEL)/lib/lnx64.o
OPENCL_LIB:=$(XILINX_SDACCEL)/runtime/lib/x86_64

# Host Application
LINEAR_SEARCH_SRC=linear_search.c xcl.c
LINEAR_SEARCH_EXE=linear_search

# Host compile flags
LINEAR_SEARCH_INC:=-I. -I$(OPENCL12_INCLUDE) -I$(SDA_INCLUDE)
LINEAR_SEARCH_LIB:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -lpthread -lrt

# Equalizer Kernel
LINEAR_SEARCH_KRNLSRC=krnl_linear_search.cpp
LINEAR_SEARCH_XCLBIN=linear_search.$(XMODE).xclbin
LINEAR_SEARCH_KRNLFUNC=krnl_linear_search

all: $(LINEAR_SEARCH_EXE) $(LINEAR_SEARCH_XCLBIN)

$(LINEAR_SEARCH_EXE): $(LINEAR_SEARCH_SRC) linear_search.h
	$(CXX) $(CXXFLAGS) -o $@ $(LINEAR_SEARCH_SRC) $(LINEAR_SEARCH_INC) $(LINEAR_SEARCH_LIB)

$(LINEAR_SEARCH_XCLBIN): $(LINEAR_SEARCH_KRNLSRC) linear_search.h
	$(CLC) -g -o $@ -t $(XMODE) -k $(LINEAR_SEARCH_KRNLFUNC) --xdevice $(XDEVICE) $(LINEAR_SEARCH_KRNLSRC)

clean:
	rm -rf $(LINEAR_SEARCH_EXE) $(LINEAR_SEARCH_XCLBIN)

check: check-linear_search

check-linear_search: $(LINEAR_SEARCH_EXE) $(LINEAR_SEARCH_XCLBIN)
	./$(LINEAR_SEARCH_EXE) $(LINEAR_SEARCH_XCLBIN)

