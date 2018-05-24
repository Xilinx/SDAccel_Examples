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
	--sp krnl_idct_1.m_axi_gmem0:bank0 \
	--sp krnl_idct_1.m_axi_gmem1:bank0 \
	--sp krnl_idct_1.m_axi_gmem2:bank1 \
	--kernel_frequency 250

XOS=krnl_idct

# idct xclbin
krnl_idct_XOS=krnl_idct
krnl_idct_NDEVICES= xilinx:vcu1525:dynamic xilinx_vcu1525_dynamic_5_0

XCLBINS=krnl_idct

define mk_args
check_$(1)_$(call sanitize_dsa,$(2))_ARGS = ./xclbin/krnl_idct.$(1).$(call sanitize_dsa,$(2)).xclbin
endef

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))

# check
check_EXE=idct
check_XCLBINS=krnl_idct
check_NDEVICES=$(krnl_idct_NDEVICES)

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

