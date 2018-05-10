# Tiny Encription Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk
include $(COMMON_REPO)/libs/oclHelper/oclHelper.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Tiny Encryption Host Application
tiny_SRCS=./src/tinyEncryption.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
tiny_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
tiny_CXXFLAGS=-I./src/ $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS) $(opencl_CXXFLAGS)
tiny_LDFLAGS=$(opencl_LDFLAGS)

EXES=tiny

# Tiny Encryption Kernel
krnl_tiny_SRCS=./src/krnl_tinyEncryption.cl

XOS=krnl_tiny

# Tiny Encryption xclbin
krnl_tiny_XOS=krnl_tiny
krnl_tiny_NDEVICES=xilinx:vcu1525:dynamic xilinx_vcu1525_dynamic_5_0

XCLBINS=krnl_tiny

# check
check_EXE=tiny
check_XCLBINS=krnl_tiny
check_NDEVICES=$(krnl_tiny_NDEVICES)

# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call device2sandsa,$(2))_ARGS = data/image1.bmp data/image2.bmp ./xclbin/krnl_tiny.$(1).$(call device2sandsa,$(2)).xclbin
endef

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

