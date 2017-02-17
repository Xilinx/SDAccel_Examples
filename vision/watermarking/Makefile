# Watermarking Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/oclHelper/oclHelper.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Watermarking Host Application
watermark_SRCS=./src/watermarking.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
watermark_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
watermark_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
watermark_LDFLAGS=$(opencl_LDFLAGS)

# Watermark Kernel
krnl_watermark_SRCS=./src/krnl_watermarking.cl

EXES=watermark
XCLBINS=krnl_watermark

# check
check_EXE=watermark
check_XCLBINS=krnl_watermark

# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call sanitize_dsa,$(2))_ARGS = data/inputImage.bmp ./xclbin/krnl_watermark.$(1).$(call sanitize_dsa,$(2)).xclbin
endef

EXTRA_CLEAN=output.bmp

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

