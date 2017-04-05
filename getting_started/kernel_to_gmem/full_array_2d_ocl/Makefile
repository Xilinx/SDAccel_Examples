COMMON_REPO := ../../../
#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=$(xcl_HDRS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)

EXES=host

# Kernel
mmult_SRCS=./src/mmult.cl
mmult_CLFLAGS=-k mmult
mmult_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XOS=mmult

# xclbin
mmult_XOS=mmult
mmult_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

XCLBINS=mmult

# check
check_EXE=host
check_XCLBINS=mmult
check_DEVICES=$(mmult_DEVICES)

CHECKS=check

DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.3

include $(COMMON_REPO)/utility/rules.mk

