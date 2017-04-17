COMMON_REPO := ../../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS) -I$(XILINX_SDACCEL)/Vivado_HLS/include
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
row_array_2d_SRCS=./src/row_array_2d.cpp
row_array_2d_CLFLAGS=-k row_array_2d -I./src/

XOS=row_array_2d

# xclbin
row_array_2d_XOS=row_array_2d

XCLBINS=row_array_2d

# check
check_EXE=host
check_XCLBINS=row_array_2d

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

