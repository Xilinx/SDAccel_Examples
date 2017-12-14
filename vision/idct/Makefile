# idct Application

COMMON_REPO:=../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# idct Host Application
idct_SRCS=./src/idct.cpp 
idct_CXXFLAGS=-Wall -I./src/ $(opencl_CXXFLAGS)
idct_LDFLAGS=$(opencl_LDFLAGS)

EXES=idct

# idct Kernel
krnl_idct_SRCS=./src/krnl_idct.cpp
krnl_idct_CLFLAGS=-k krnl_idct -I./src
krnl_idct_LDCLFLAGS+= --sp krnl_idct_1.m_axi_gmem0:bank0 --sp krnl_idct_1.m_axi_gmem1:bank1 --sp krnl_idct_1.m_axi_gmem2:bank2 

XOS=krnl_idct

# idct xclbin
krnl_idct_XOS=krnl_idct

XCLBINS=krnl_idct

# check
check_EXE=idct
check_XCLBINS=krnl_idct

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

