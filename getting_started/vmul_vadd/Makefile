# Vaddvmul Application

include ../../utility/boards.mk
include ../../libs/opencl/opencl.mk

# vmulvadd Host Application
vmulvadd_SRCS=./src/main.c
vmulvadd_HDRS=
vmulvadd_EXE=vmulvadd
vmulvadd_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS)
vmulvadd_X86_LDFLAGS=$(opencl_X86_LDFLAGS)
vmulvadd_POWER_LDFLAGS=$(opencl_POWER_LDFLAGS)

# vmul Kernel
krnl_vmul_SRCS=./src/krnl_vmul.cl

# vadd Kernel
krnl_vadd_SRCS=./src/krnl_vadd.cl

EXES=vmulvadd
XCLBINS=krnl_vmul krnl_vadd

include ../../utility/rules.mk

