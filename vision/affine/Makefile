# Affine Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/oclHelper/oclHelper.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Affine Host Application
affine_SRCS=./src/affine.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
affine_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
affine_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
affine_LDFLAGS=$(opencl_LDFLAGS) -Wall -std=c++0x -lrt 

EXES=affine

# Affine Kernel
krnl_affine_SRCS=./src/krnl_affine.cl

XOS=krnl_affine

# Affine xclbin
krnl_affine_XOS=krnl_affine

XCLBINS=krnl_affine

# check
check_EXE=affine
check_XCLBINS=krnl_affine

# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call sanitize_dsa,$(2))_ARGS = ./data/CT-MONO2-16-brain.raw ./xclbin/krnl_affine.$(1).$(call sanitize_dsa,$(2)).xclbin
endef

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))


CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

