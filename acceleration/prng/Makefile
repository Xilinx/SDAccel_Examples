# Pseudo Random Number Generator Application
COMMON_REPO =../..

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Pseudo Random Number Generator Host Application
prng_SRCS=src/prng.cpp $(xcl_SRCS)
prng_HDRS=src/prng.h $(xcl_HDRS)
prng_CXXFLAGS=-Wall -I./src/ -I$(XILINX_SDACCEL)/Vivado_HLS/include/ -I$(XILINX_VIVADO)/include $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
prng_LDFLAGS=$(opencl_LDFLAGS)

EXES=prng

# Pseudo Random Number Generator Kernel
dma_SRCS=src/dma.cpp
dma_HDRS=src/dma.h
dma_CLFLAGS=--kernel dma -I./src/

XOS=dma

# Pseudo Random Number Generator xclbin
dma_XOS=dma

XCLBINS=dma

# check
check_EXE=prng
check_XCLBINS=dma

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
