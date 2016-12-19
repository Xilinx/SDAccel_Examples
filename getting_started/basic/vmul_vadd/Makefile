# vaddvmul Application

COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk

# vmulvadd Host Application
vmulvadd_SRCS=./src/main.c $(xcl_SRCS)
vmulvadd_HDRS=$(xcl_HDRS)
vmulvadd_EXE=vmulvadd
vmulvadd_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
vmulvadd_LDFLAGS=$(opencl_LDFLAGS)

# vmul Kernel
krnl_vmul_SRCS=./src/krnl_vmul.cl
krnl_vmul_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl
krnl_vadd_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

EXES=vmulvadd
XCLBINS=krnl_vmul krnl_vadd

# check
check_EXE=vmulvadd
check_XCLBINS=krnl_vmul krnl_vadd
check_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

