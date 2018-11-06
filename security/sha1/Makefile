.PHONY: help

help::
	$(ECHO) "Makefile Usage:"
	$(ECHO) "  make all TARGET=<sw_emu/hw_emu/hw> DEVICE=<FPGA platform>"
	$(ECHO) "      Command to generate the design for specified Target and Device."
	$(ECHO) ""
	$(ECHO) "  make clean "
	$(ECHO) "      Command to remove the generated non-hardware files."
	$(ECHO) ""
	$(ECHO) "  make cleanall"
	$(ECHO) "      Command to remove all the generated files."
	$(ECHO) ""
	$(ECHO) "  make check TARGET=<sw_emu/hw_emu/hw> DEVICE=<FPGA platform>"
	$(ECHO) "      Command to run application in emulation."
	$(ECHO) ""

# Points to Utility Directory
COMMON_REPO = ../../
ABS_COMMON_REPO = $(shell readlink -f $(COMMON_REPO))

include ./utils.mk

TARGETS := hw
TARGET := $(TARGETS)
DEVICES := xilinx_vcu1525_dynamic
DEVICE := $(DEVICES)
XCLBIN := ./xclbin
DSA := $(call device2sandsa, $(DEVICE))

CXX := $(XILINX_SDX)/bin/xcpp
XOCC := $(XILINX_SDX)/bin/xocc

CXXFLAGS := $(opencl_CXXFLAGS) -Wall -O0 -g -std=c++14
LDFLAGS := $(opencl_LDFLAGS)

HOST_SRCS = ./src/clSha1.cpp ./src/sha1.c src/main.cpp
HOST_HDRS = ./src/clShal1.h ./src/oswendian.h ./src/sha1.h

# Host compiler global settings
CXXFLAGS = -I $(XILINX_XRT)/include/ -I/$(XILINX_SDX)/Vivado_HLS/include/ -O0 -g -Wall -fmessage-length=0 -std=c++14
LDFLAGS = -lOpenCL -lpthread -lrt -lstdc++ -L$(XILINX_XRT)/lib/

# Kernel compiler global settings
CLFLAGS = -t $(TARGET) --platform $(DEVICE) --save-temps 

EXECUTABLE = sha1

EMCONFIG_DIR = $(XCLBIN)/$(DSA)

BINARY_CONTAINERS += $(XCLBIN)/krnl_sha1.$(TARGET).$(DSA).xclbin
BINARY_CONTAINER_1_OBJS += $(XCLBIN)/krnl_sha1.$(TARGET).$(DSA).xo

#Include Libraries
include $(ABS_COMMON_REPO)/libs/opencl/opencl.mk
include $(ABS_COMMON_REPO)/libs/logger/logger.mk
include $(ABS_COMMON_REPO)/libs/cmdparser/cmdparser.mk
CXXFLAGS += $(logger_CXXFLAGS) $(cmdparser_CXXFLAGS)
LDFLAGS += $(logger_LDFLAGS) $(cmdparser_LDFLAGS)
HOST_SRCS += $(logger_SRCS) $(cmdparser_SRCS)
HOST_HDRS += $(logger_HRDS) $(cmdparser_HRDS)

CP = cp -rf

.PHONY: all clean cleanall docs emconfig
all: $(EXECUTABLE) $(BINARY_CONTAINERS) emconfig

.PHONY: exe
exe: $(EXECUTABLE)

# Building kernel
$(XCLBIN)/krnl_sha1.$(TARGET).$(DSA).xo: ./src/krnl_clSha1.cl
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) -c -k dev_sha1_update -I'$(<D)' -o'$@' '$<'

$(XCLBIN)/krnl_sha1.$(TARGET).$(DSA).xclbin: $(BINARY_CONTAINER_1_OBJS)
	$(XOCC) $(CLFLAGS) -l $(LDCLFLAGS) --nk dev_sha1_update:2 -o'$@' $(+)

# Building Host
$(EXECUTABLE): $(HOST_SRCS) $(HOST_HRDS)
	mkdir -p $(XCLBIN)
	$(CXX) $(CXXFLAGS) $(HOST_SRCS) $(HOST_HRDS) -o '$@' $(LDFLAGS)

emconfig:$(EMCONFIG_DIR)/emconfig.json
$(EMCONFIG_DIR)/emconfig.json:
	emconfigutil --platform $(DEVICE) --od $(EMCONFIG_DIR)

check: all

ifeq ($(TARGET),$(filter $(TARGET),sw_emu hw_emu))
	$(CP) $(EMCONFIG_DIR)/emconfig.json .
	XCL_EMULATION_MODE=$(TARGET) ./$(EXECUTABLE) -t 20 -p Xilinx -k ./xclbin/krnl_sha1.$(TARGET).$(DSA).xclbin
else
	 ./$(EXECUTABLE) -t 20 -p Xilinx -k ./xclbin/krnl_sha1.$(TARGET).$(DSA).xclbin
endif
ifneq ($(TARGET),$(findstring $(TARGET), sw_emu hw))
$(warning WARNING:Application supports only sw_emu hw TARGET. Please use the target for running the application)
endif

	sdx_analyze profile -i sdaccel_profile_summary.csv -f html

# Cleaning stuff
clean:
	-$(RMDIR) $(EXECUTABLE) $(XCLBIN)/{*sw_emu*,*hw_emu*} 
	-$(RMDIR) sdaccel_* TempConfig system_estimate.xtxt *.rpt
	-$(RMDIR) src/*.ll _xocc_* .Xil emconfig.json dltmp* xmltmp* *.log *.jou *.wcfg *.wdb

cleanall: clean
	-$(RMDIR) $(XCLBIN)
	-$(RMDIR) ./_x


