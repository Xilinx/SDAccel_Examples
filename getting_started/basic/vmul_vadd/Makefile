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

EXES=vmulvadd

# vmul Kernel
krnl_vmul_SRCS=./src/krnl_vmul.cl
krnl_vmul_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr:3.3 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl
krnl_vadd_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr:3.3 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XOS=krnl_vmul krnl_vadd

# vmul xclbin
krnl_vmul_XOS=krnl_vmul
krnl_vmul_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr:3.3 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

# vadd xclbin
krnl_vadd_XOS=krnl_vadd
krnl_vadd_NDEVICES=xilinx:xil-accel-rd-ku115:4ddr-xpr:3.3 xilinx:adm-pcie-ku3:2ddr-xpr:3.3

XCLBINS=krnl_vmul krnl_vadd

# check
check_EXE=vmulvadd
check_XCLBINS=krnl_vmul krnl_vadd
check_NDEVICES=$(krnl_vadd_NDEVICES)

CHECKS=check

# Changing default Device for this example
DEVICES:=xilinx:adm-pcie-7v3:1ddr:3.0

include $(COMMON_REPO)/utility/rules.mk

