# vaddvmul Application

COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk

# vmulvadd Host Application
vmulvadd_SRCS=./src/host.cpp $(xcl2_SRCS)
vmulvadd_HDRS=$(xcl2_HDRS)
vmulvadd_EXE=vmulvadd
vmulvadd_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS)
vmulvadd_LDFLAGS=$(opencl_LDFLAGS)

EXES=vmulvadd

# vmul Kernel
krnl_vmul_SRCS=./src/krnl_vmul.cl

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl

XOS=krnl_vmul krnl_vadd

# vmul Kernel
krnl_vmul_XOS=krnl_vmul

# vadd Kernel
krnl_vadd_XOS=krnl_vadd

XCLBINS=krnl_vmul krnl_vadd


# check
check_EXE=vmulvadd
check_XCLBINS=krnl_vmul krnl_vadd

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

