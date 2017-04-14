COMMON_REPO := ../../../

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
host_SRCS=./src/host.cpp $(xcl_SRCS)
host_HDRS=${xcl_HDRS}
host_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) 
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall
CXXFLAGS+=-std=c++0x

EXES=host

# Kernel

fir_GOOD_SRCS=./src/fir.cpp
fir_GOOD_CLFLAGS=-k fir_shift_register -I./src/
fir_GOOD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2
	
fir_BAD_SRCS=./src/fir_bad.cpp
fir_BAD_CLFLAGS=-k fir_shift_register -I./src/
fir_BAD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

XOS=fir_GOOD fir_BAD

# xclbin
fir_GOOD_XOS=fir_GOOD
fir_GOOD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

fir_BAD_XOS=fir_BAD
fir_BAD_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0 xilinx:adm-pcie-ku3:2ddr-xpr:3.2

XCLBINS=fir_GOOD fir_BAD

check_EXE=host
check_XCLBINS=fir_GOOD fir_BAD
check_DEVICES=$(fir_GOOD_DEVICES)

CHECKS=check

#Changing Default Device
DEVICES:=xilinx:adm-pcie-ku3:2ddr-xpr:3.2
include $(COMMON_REPO)/utility/rules.mk
