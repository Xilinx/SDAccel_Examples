
# affine Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/oclHelper/oclHelper.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# affine Host Application

affine_SRCS=./src/affine.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
affine_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
affine_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
affine_LDFLAGS=$(opencl_LDFLAGS) -Wall -std=c++0x -lrt 

# Median Filter Kernel
krnl_affine_SRCS=./src/krnl_affine.cl

EXES=affine
XCLBINS=krnl_affine

# check
check_EXE=affine
check_XCLBINS=krnl_affine

# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call sanitize_dsa,$(2))_ARGS = ./xclbin/krnl_affine.$(1).$(call sanitize_dsa,$(2)).xclbin
endef

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))


CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

