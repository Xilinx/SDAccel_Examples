# vaddvmul Application

COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk

# vmulvadd Host Application
vmulvadd_SRCS=./src/main.c $(xcl2_SRCS)
vmulvadd_HDRS=$(xcl2_HDRS)
vmulvadd_EXE=vmulvadd
vmulvadd_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS)
vmulvadd_LDFLAGS=$(opencl_LDFLAGS)

EXES=vmulvadd

# vmul Kernel
krnl_vmul_SRCS=./src/krnl_vmul.cl
krnl_vmul_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl
krnl_vadd_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr

XOS=krnl_vmul krnl_vadd

# vmul xclbin
krnl_vmul_XOS=krnl_vmul
krnl_vmul_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr

# vadd xclbin
krnl_vadd_XOS=krnl_vadd
krnl_vadd_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr

XCLBINS=krnl_vmul krnl_vadd

# check
check_EXE=vmulvadd
check_XCLBINS=krnl_vmul krnl_vadd
check_NDEVICES=$(krnl_vadd_NDEVICES)

CHECKS=check

# Changing default Device for this example
DEVICES:=xilinx:adm-pcie-7v3:1ddr

include $(COMMON_REPO)/utility/rules.mk

