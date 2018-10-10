# Definition of include file locations
OPENCL_INCLUDE:= $(XILINX_XRT)/include/

opencl_CXXFLAGS=-I$(OPENCL_INCLUDE)

OPENCL_LIB:=$(XILINX_XRT)/lib/
opencl_LDFLAGS=-L$(OPENCL_LIB) -lOpenCL -lpthread
