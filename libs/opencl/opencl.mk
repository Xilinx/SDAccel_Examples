# Definition of include file locations
OPENCL12_INCLUDE:= $(XILINX_SDACCEL)/runtime/include/1_2

# Library directories
SDA_LIB:=$(XILINX_SDACCEL)/lib/lnx64.o
OPENCL_X86_LIB:=$(XILINX_SDACCEL)/runtime/lib/x86_64
OPENCL_POWER_LIB:=$(XILINX_SDACCEL)/runtime/lib/ppc64le

opencl_CXXFLAGS=-I$(OPENCL12_INCLUDE)
opencl_X86_LDFLAGS=-L$(OPENCL_X86_LIB) -L$(SDA_LIB) -lOpenCL -pthread
opencl_POWER_LDFLAGS=-L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0

