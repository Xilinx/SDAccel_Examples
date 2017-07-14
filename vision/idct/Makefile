# idct Application

COMMON_REPO:=../../
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# idct Host Application
idct_SRCS=./src/idct.cpp $(xcl2_SRCS)
idct_HDRS=$(xcl2_HDRS)
idct_CXXFLAGS=-I./src/ $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
idct_LDFLAGS=$(opencl_LDFLAGS)

EXES=idct

# idct Kernel
krnl_idct_SRCS=./src/krnl_idct.cpp
krnl_idct_CLFLAGS=-k krnl_idct -I./src/

XOS=krnl_idct

# idct xclbin
krnl_idct_XOS=krnl_idct

XCLBINS=krnl_idct

# check
check_EXE=idct
check_XCLBINS=krnl_idct

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

