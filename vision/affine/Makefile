# Affine Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Affine Host Application
affine_SRCS=./src/affine.cpp $(bitmap_SRCS) $(xcl2_SRCS)
affine_HDRS=$(bitmap_HDRS) $(xcl2_HDRS)
affine_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) 
affine_LDFLAGS=$(opencl_LDFLAGS) -Wall -std=c++0x -lrt 

EXES=affine

# Affine Kernel
krnl_affine_SRCS=./src/krnl_affine.cl

XOS=krnl_affine

# Affine xclbin
krnl_affine_XOS=krnl_affine
krnl_affine_NDEVICES=xilinx:vcu1525:dynamic xilinx_vcu1525_dynamic_5_0
XCLBINS=krnl_affine

# check
check_EXE=affine
check_XCLBINS=krnl_affine
check_NDEVICES=$(krnl_affine_NDEVICES)
check_ARGS=./data/CT-MONO2-16-brain.raw

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

