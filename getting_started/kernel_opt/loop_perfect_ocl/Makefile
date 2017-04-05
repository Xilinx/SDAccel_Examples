COMMON_REPO := ../../../
#Common Includes
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall

EXES=host

# nearest kernels
nearest_GOOD_SRCS=./src/nearest_good.cl
nearest_GOOD_CLFLAGS=-k nearest
nearest_GOOD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

nearest_BAD_SRCS=./src/nearest_bad.cl
nearest_BAD_CLFLAGS=-k nearest
nearest_BAD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

XOS=nearest_GOOD nearest_BAD

# nearest xclbin
nearest_GOOD_XOS=nearest_GOOD
nearest_GOOD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

nearest_BAD_XOS=nearest_BAD
nearest_BAD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

XCLBINS=nearest_GOOD nearest_BAD

# check
check_EXE=host
check_XCLBINS=nearest_GOOD nearest_BAD
check_DEVICES=$(nearest_GOOD_DEVICES)

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk
