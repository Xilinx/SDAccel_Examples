# kernel_global Application
COMMON_REPO:=../../..

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# kernel_global Host Application
kernel_global_SRCS=./src/kernel_global_bandwidth.cpp $(xcl_SRCS)
kernel_global_HDRS=$(xcl_HDRS)
kernel_global_CXXFLAGS=$(xcl_CXXFLAGS) $(opencl_CXXFLAGS)
kernel_global_LDFLAGS=$(opencl_LDFLAGS)

EXES=kernel_global

krnl_kernel_global_SRCS=./src/kernel.cl
krnl_kernel_global_CLFLAGS=--max_memory_ports bandwidth
krnl_kernel_global_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xp

SPACE :=
SPACE +=
DASH :=-

# space DSA name for findstring
spaced_dsa = $(strip $(subst $(PERIOD),$(SPACE),$(subst $(COLON),$(SPACE),$(subst $(DASH),$(SPACE),$(1)))))

define ddr_check

ifeq ($(findstring 4ddr,$(call spaced_dsa,$(1))),4ddr)
    krnl_kernel_global_$(call sanitize_dsa,$(1))_CLFLAGS+=-DUSE_4DDR
	kernel_global_CXXFLAGS+=-DUSE_4DDR
    krnl_kernel_global_$(call sanitize_dsa,$(1))_LDCLFLAGS+= \
	--sp bandwidth_1.m_axi_gmem0:bank0 \
	--sp bandwidth_1.m_axi_gmem1:bank1 \
	--sp bandwidth_1.m_axi_gmem2:bank2 \
	--sp bandwidth_1.m_axi_gmem3:bank3
endif
ifeq ($(findstring 2ddr,$(call spaced_dsa,$(1))),2ddr)
	kernel_global_CXXFLAGS+=-DUSE_2DDR
    krnl_kernel_global_$(call sanitize_dsa,$(1))_LDCLFLAGS+= \
	--sp bandwidth_1.m_axi_gmem0:bank0 \
	--sp bandwidth_1.m_axi_gmem1:bank1 
endif


endef

$(foreach device,$(DEVICES),$(eval $(call ddr_check,$(device))))

XOS=krnl_kernel_global

krnl_kernel_global_XOS=krnl_kernel_global
krnl_kernel_global_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr

XCLBINS=krnl_kernel_global

# check
check_EXE=kernel_global
check_XCLBINS=krnl_kernel_global
check_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
