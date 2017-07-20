# Definition of include file locations
OPENCL12_INCLUDE:= $(XILINX_SDX)/runtime/include/1_2

# Library directories
SDA_LIB:=$(XILINX_SDX)/lib/lnx64.o

opencl_CXXFLAGS=-I$(OPENCL12_INCLUDE)

ifeq ($(ARCH),POWER)
OPENCL_LIB:=$(XILINX_SDX)/runtime/lib/ppc64le
opencl_LDFLAGS=-L$(OPENCL_LIB) -lxilinxopencl -llmx6.0
else
OPENCL_LIB:=$(XILINX_SDX)/runtime/lib/x86_64
opencl_LDFLAGS=-L$(OPENCL_LIB) -L$(SDA_LIB) -lOpenCL -pthread
endif
