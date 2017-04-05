# Median Filter Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/oclHelper/oclHelper.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Median Filter Host Application
median_SRCS=./src/medianFilter.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
median_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
median_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
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
check_$(1)_$(call sanitize_dsa,$(2))_ARGS = data/inputImage.bmp ./xclbin/krnl_median.$(1).$(call sanitize_dsa,$(2)).xclbin
endef

EXTRA_CLEAN=decoded.bmp

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

