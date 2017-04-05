COMMON_REPO := ../../..

#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# Host Application
errors_SRCS=./src/host.cpp $(oclHelper_SRCS) 
errors_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(oclHelper_CXXFLAGS) -std=c++0x
errors_LDFLAGS=$(opencl_LDFLAGS)

EXES=errors

# Kernel
vector_addition_SRCS=./src/vector_addition.cl

XOS=vector_addition

# xclbin
vector_addition_XOS=vector_addition

XCLBINS=vector_addition

# check
check_EXE=errors
check_XCLBINS=vector_addition

# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call sanitize_dsa,$(2))_ARGS = ./xclbin/vector_addition.$(1).$(call sanitize_dsa,$(2)).xclbin
endef

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))

CHECKS=check


include $(COMMON_REPO)/utility/rules.mk
