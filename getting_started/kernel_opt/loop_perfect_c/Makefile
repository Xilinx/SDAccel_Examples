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
# Switch between GOOD/BAD Examples
KFLOW:=GOOD

# Kernel
ifeq ($(KFLOW),GOOD)
    nearest_SRCS=./src/nearest_good.cpp
else
    nearest_SRCS=./src/nearest_bad.cpp
endif

nearest_CLFLAGS=-k nearest
nearest_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

EXES=host
XCLBINS=nearest

# check
check_EXE=host
check_XCLBINS=nearest
check_DEVICES=$(nearest_DEVICES)

CHECKS=check

DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.2

include ${COMMON_REPO}/utility/rules.mk
