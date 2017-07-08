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

SPACE :=
SPACE +=
DASH :=-

# space DSA name for findstring
spaced_dsa = $(strip $(subst $(PERIOD),$(SPACE),$(subst $(COLON),$(SPACE),$(subst $(DASH),$(SPACE),$(1)))))

define ddr_check

ifeq ($(findstring 4ddr,$(call spaced_dsa,$(1))),4ddr)
    krnl_kernel_global_$(call sanitize_dsa,$(1))_CLFLAGS+=-DNUM_BANKS_4
    krnl_kernel_global_$(call sanitize_dsa,$(1))_LDCLFLAGS+= \
    --xp misc:map_connect=add.kernel.bandwidth_1.M_AXI_GMEM0.core.OCL_REGION_0.M00_AXI \
    --xp misc:map_connect=add.kernel.bandwidth_1.M_AXI_GMEM1.core.OCL_REGION_0.M01_AXI \
    --xp misc:map_connect=add.kernel.bandwidth_1.M_AXI_GMEM2.core.OCL_REGION_0.M02_AXI \
    --xp misc:map_connect=add.kernel.bandwidth_1.M_AXI_GMEM3.core.OCL_REGION_0.M03_AXI
endif
ifeq ($(findstring 2ddr,$(call spaced_dsa,$(1))),2ddr)
    krnl_kernel_global_$(call sanitize_dsa,$(1))_LDCLFLAGS+= \
    --xp misc:map_connect=add.kernel.bandwidth_1.M_AXI_GMEM0.core.OCL_REGION_0.M00_AXI \
    --xp misc:map_connect=add.kernel.bandwidth_1.M_AXI_GMEM1.core.OCL_REGION_0.M01_AXI
endif


endef

$(foreach device,$(DEVICES),$(eval $(call ddr_check,$(device))))

XOS=krnl_kernel_global

krnl_kernel_global_XOS=krnl_kernel_global

XCLBINS=krnl_kernel_global

# check
check_EXE=kernel_global
check_XCLBINS=krnl_kernel_global

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk
