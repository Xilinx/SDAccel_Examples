# SHA1 Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/logger/logger.mk
include $(COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# hello Host Application
sha1_SRCS=./src/clSha1.cpp ./src/sha1.c ./src/main.cpp $(logger_SRCS) $(cmdparser_SRCS) $(xcl_SRCS)
sha1_HDRS=./src/clSha1.h ./src/oswendian.h ./src/sha1.h $(logger_SRCS) $(cmdparser_HDRS) $(xcl_HDRS)
sha1_CXXFLAGS=-std=gnu++0x -I./src/ $(opencl_CXXFLAGS) $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS) $(xcl_CXXFLAGS)
sha1_LDFLAGS=$(opencl_LDFLAGS) -lrt

EXES=sha1

# SHA1 Kernel
krnl_sha1_SRCS=./src/krnl_clSha1.cl
krnl_sha1_HDRS=./src/clSha1.h
krnl_sha1_CLFLAGS=-I./src/
krnl_sha1_NDEVICES=xilinx:xil-accel-rd-vu9p xilinx:xil-accel-rd-ku115:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr xilinx:adm-pcie-7v3:1ddr

XOS=krnl_sha1

# SHA1 xclbin
krnl_sha1_XOS=krnl_sha1
krnl_sha1_LDCLFLAGS=--nk dev_sha1_update:2
krnl_sha1_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr xilinx:xil-accel-rd-ku115:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr xilinx:adm-pcie-7v3:1ddr

XCLBINS=krnl_sha1

# check
check_EXE=sha1
check_XCLBINS=krnl_sha1
check_NDEVICES=$(krnl_sha1_NDEVICES)

# Pattern to allow cmdline to determine xclbin name
define mk_args
check_$(1)_$(call device2sandsa,$(2))_ARGS = -t 20 -p Xilinx -d $(call device2sandsa,$(2)) -k ./xclbin/krnl_sha1.$(1).$(call device2sandsa,$(2)).xclbin
endef

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_args,$(target),$(device)))))

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

