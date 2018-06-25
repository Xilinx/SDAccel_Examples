# kernel_global Application
COMMON_REPO:=../../..

ddr_banks=4
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# kernel_global Host Application
kernel_global_SRCS=./src/kernel_global_bandwidth.cpp $(xcl2_SRCS)
kernel_global_HDRS=$(xcl2_HDRS)
kernel_global_CXXFLAGS=$(xcl2_CXXFLAGS) $(opencl_CXXFLAGS) -DNDDR_BANKS=$(ddr_banks)
kernel_global_LDFLAGS=$(opencl_LDFLAGS)

EXES=kernel_global

krnl_kernel_global_SRCS=./src/kernel.cl
krnl_kernel_global_CLFLAGS=--max_memory_ports bandwidth -DNDDR_BANKS=$(ddr_banks)

krnl_kernel_global_LDCLFLAGS+= --sp bandwidth_1.m_axi_gmem0:bank0 
ifneq ($(strip $(ddr_banks)),1)
krnl_kernel_global_LDCLFLAGS+= --sp bandwidth_1.m_axi_gmem1:bank1
ifneq ($(strip $(ddr_banks)),2)
krnl_kernel_global_LDCLFLAGS+= --sp bandwidth_1.m_axi_gmem2:bank2
ifneq ($(strip $(ddr_banks)),3)
krnl_kernel_global_LDCLFLAGS+= --sp bandwidth_1.m_axi_gmem3:bank3
endif
endif
endif

XOS=krnl_kernel_global

krnl_kernel_global_XOS=krnl_kernel_global

XCLBINS=krnl_kernel_global

# check
check_EXE=kernel_global
check_XCLBINS=krnl_kernel_global

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
