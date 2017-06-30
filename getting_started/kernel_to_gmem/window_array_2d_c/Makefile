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
window_array_2d_SRCS=./src/window_array_2d.cpp
window_array_2d_CLFLAGS=-k window_array_2d -I./src/

XOS=window_array_2d

# xclbin
window_array_2d_XOS=window_array_2d
window_array_2d_NDEVICES=xilinx:adm-pcie-ku3:2ddr-xpr

XCLBINS=window_array_2d

# check
check_EXE=host
check_XCLBINS=window_array_2d
check_NDEVICES=xilinx:adm-pcie-ku3:2ddr-xpr

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

