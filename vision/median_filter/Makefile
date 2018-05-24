# Median Filter Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Median Filter Host Application
median_SRCS=./src/medianFilter.cpp $(bitmap_SRCS) $(xcl2_SRCS)
median_HDRS=$(bitmap_HDRS) $(xcl2_HDRS)
median_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(xcl2_CXXFLAGS)
median_LDFLAGS=$(opencl_LDFLAGS)

EXES=median

# Median Filter Kernel
krnl_median_SRCS=./src/krnl_medianFilter.cl

XOS=krnl_median

# Median Filter xclbin
krnl_median_XOS=krnl_median

XCLBINS=krnl_median

# check
check_EXE=median
check_XCLBINS=krnl_median

# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call device2sandsa,$(2))_ARGS = ./xclbin/krnl_median.$(1).$(call device2sandsa,$(2)).xclbin data/inputImage.bmp data/goldenImage.bmp
endef

EXTRA_CLEAN=decoded.bmp

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

