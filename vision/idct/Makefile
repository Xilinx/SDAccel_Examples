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
krnl_idct_LDCLFLAGS+= \
      --xp misc:map_connect=add.kernel.krnl_idct_1.M_AXI_GMEM.core.OCL_REGION_0.M00_AXI \
      --xp misc:map_connect=add.kernel.krnl_idct_1.M_AXI_GMEM1.core.OCL_REGION_0.M00_AXI \
      --xp misc:map_connect=add.kernel.krnl_idct_1.M_AXI_GMEM2.core.OCL_REGION_0.M01_AXI 

XOS=krnl_idct

# idct xclbin
krnl_idct_XOS=krnl_idct
krnl_idct_NDEVICES=xilinx:adm-pcie-7v3:1ddr

XCLBINS=krnl_idct

# check
check_EXE=idct
check_XCLBINS=krnl_idct
check_NDEVICES=xilinx:adm-pcie-7v3:1ddr

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

