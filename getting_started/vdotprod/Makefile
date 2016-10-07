# vdotprod Application

include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencl/opencl.mk

# vdotprod Host Application
vdotprod_SRCS=./src/vdotprod.cpp $(xcl_SRCS)
vdotprod_HDRS=./src/vdotprod.h $(xcl_HDRS)
vdotprod_EXE=vdotprod
vdotprod_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
vdotprod_LDFLAGS=$(opencl_LDFLAGS)

# hello Kernel
krnl_vdotprod_SRCS=./src/krnl_vdotprod.cl

EXES=vdotprod
XCLBINS=krnl_vdotprod

include ../../utility/rules.mk

