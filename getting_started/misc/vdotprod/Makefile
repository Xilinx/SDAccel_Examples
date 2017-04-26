# vdotprod Application

COMMON_REPO:=../../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# vdotprod Host Application
vdotprod_SRCS=./src/host.cpp $(xcl_SRCS)
vdotprod_HDRS=./src/vdotprod.h $(xcl_HDRS)
vdotprod_EXE=vdotprod
vdotprod_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
vdotprod_LDFLAGS=$(opencl_LDFLAGS)

EXES=vdotprod

# hello Kernel
krnl_vdotprod_SRCS=./src/krnl_vdotprod.cl

XOS=krnl_vdotprod

# hello xclbin
krnl_vdotprod_XOS=krnl_vdotprod

XCLBINS=krnl_vdotprod

# check
check_EXE=vdotprod
check_XCLBINS=krnl_vdotprod

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

