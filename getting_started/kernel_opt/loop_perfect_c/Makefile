COMMON_REPO := ../../../
#Common Includes
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl2/xcl2.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl2_SRCS)
host_HDRS=$(xcl2_HDRS)
host_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall
# Switch between GOOD/BAD Examples
KFLOW:=GOOD

EXES=host

# nearest kernels
nearest_GOOD_SRCS=./src/nearest_good.cpp
nearest_GOOD_CLFLAGS=-k nearest

nearest_BAD_SRCS=./src/nearest_bad.cpp
nearest_BAD_CLFLAGS=-k nearest

XOS=nearest_GOOD nearest_BAD

nearest_CLFLAGS=-k nearest
nearest_DEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:adm-pcie-ku3:2ddr-xpr

# nearest xclbin
nearest_GOOD_XOS=nearest_GOOD

nearest_BAD_XOS=nearest_BAD

XCLBINS=nearest_GOOD nearest_BAD

# check
check_EXE=host
check_XCLBINS=nearest_GOOD nearest_BAD

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk
