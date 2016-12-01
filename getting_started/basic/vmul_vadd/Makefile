# vaddvmul Application

COMMON_REPO:=../../../
include ${COMMON_REPO}/utility/boards.mk
include ${COMMON_REPO}/libs/opencl/opencl.mk
include ${COMMON_REPO}/libs/xcl/xcl.mk

# vmulvadd Host Application
vmulvadd_SRCS=./src/main.c $(xcl_SRCS)
vmulvadd_HDRS=$(xcl_HDRS)
vmulvadd_EXE=vmulvadd
vmulvadd_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
vmulvadd_LDFLAGS=$(opencl_LDFLAGS)

# vmul Kernel
krnl_vmul_SRCS=./src/krnl_vmul.cl

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl

EXES=vmulvadd
XCLBINS=krnl_vmul krnl_vadd

# check
check_EXE=vmulvadd
check_XCLBINS=krnl_vmul krnl_vadd

CHECKS=check

include ${COMMON_REPO}/utility/rules.mk

