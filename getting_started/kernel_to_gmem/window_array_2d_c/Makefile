COMMON_REPO := ../../../
#Common Includes
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS) 
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS) -I${XILINX_SDX}/Vivado_HLS/include
host_LDFLAGS=$(opencl_LDFLAGS)

# Kernel
window_array_2d_SRCS=./src/window_array_2d.cpp
window_array_2d_CLFLAGS=-k window_array_2d

EXES=host
XCLBINS=window_array_2d

include ${COMMON_REPO}/utility/rules.mk
include ${COMMON_REPO}/utility/emu_check.mk
