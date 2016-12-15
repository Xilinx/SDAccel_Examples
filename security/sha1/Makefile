# SHA1 Application

include ../../utility/boards.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
sha1_SRCS=./src/clSha1.cpp ./src/sha1.c ./src/main.cpp $(logger_SRCS) $(cmdparser_SRCS) $(xcl_SRCS)
sha1_HDRS=./src/clSha1.h ./src/oswendian.h ./src/sha1.h $(logger_SRCS) $(cmdparser_HDRS) $(xcl_HDRS)
sha1_CXXFLAGS=-std=gnu++0x -I./src/ $(opencl_CXXFLAGS) $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_CXXFLAGS)
sha1_LDFLAGS=$(opencl_LDFLAGS) -lrt

# SHA1 Kernel
krnl_sha1_SRCS=./src/krnl_clSha1.cl
krnl_sha1_HDRS=./src/clSha1.h
krnl_sha1_CLFLAGS=--nk dev_sha1_update:2

EXES=sha1
XCLBINS=krnl_sha1

# check
check_EXE=sha1
check_XCLBINS=krnl_sha1

# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call sanitize_dsa,$(2))_ARGS = -t 20 -p Xilinx -d $(2) -k ./xclbin/krnl_sha1.$(1).$(call sanitize_dsa,$(2)).xclbin
endef

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))

CHECKS=check

include ../../utility/rules.mk

