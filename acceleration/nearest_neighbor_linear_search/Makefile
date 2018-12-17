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
DEVICE := $(DEVICES)
XCLBIN := ./xclbin
DSA := $(call device2sandsa, $(DEVICE))
BUILD_DIR := ./_x.$(TARGET).$(DSA)

CXX := $(XILINX_SDX)/bin/xcpp
XOCC := $(XILINX_SDX)/bin/xocc

#Include Libraries
include $(ABS_COMMON_REPO)/libs/opencl/opencl.mk
include $(ABS_COMMON_REPO)/libs/xcl2/xcl2.mk
CXXFLAGS += $(xcl2_CXXFLAGS)
LDFLAGS += $(xcl2_LDFLAGS)
HOST_SRCS += $(xcl2_SRCS)
CXXFLAGS += $(opencl_CXXFLAGS) -Wall -O0 -g -std=c++14
LDFLAGS += $(opencl_LDFLAGS)

HOST_SRCS += src/linear_search.cpp

# Host compiler global settings
CXXFLAGS += -fmessage-length=0
LDFLAGS += -lrt -lstdc++ 

# Kernel compiler global settings
CLFLAGS += -t $(TARGET) --platform $(DEVICE) --save-temps --temp_dir $(BUILD_DIR) 


EXECUTABLE = nearest

EMCONFIG_DIR = $(XCLBIN)/$(DSA)

BINARY_CONTAINERS += $(XCLBIN)/krnl_nearest.$(TARGET).$(DSA).xclbin
BINARY_CONTAINER_krnl_nearest_OBJS += $(XCLBIN)/krnl_linear_search.$(TARGET).$(DSA).xo

CP = cp -rf
DATA = ./data

.PHONY: all clean cleanall docs emconfig
all: check-device $(EXECUTABLE) $(BINARY_CONTAINERS) emconfig

.PHONY: exe
exe: $(EXECUTABLE)

# Building kernel
$(XCLBIN)/krnl_linear_search.$(TARGET).$(DSA).xo: src/krnl_linear_search.cpp
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) -c -k krnl_linear_search -I'$(<D)' -o'$@' '$<'
$(XCLBIN)/krnl_nearest.$(TARGET).$(DSA).xclbin: $(BINARY_CONTAINER_krnl_nearest_OBJS)
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) -l $(LDCLFLAGS) --nk krnl_linear_search:2 -o'$@' $(+)

# Building Host
$(EXECUTABLE): $(HOST_SRCS) $(HOST_HDRS)
	mkdir -p $(XCLBIN)
	$(CXX) $(CXXFLAGS) $(HOST_SRCS) $(HOST_HDRS) -o '$@' $(LDFLAGS)

emconfig:$(EMCONFIG_DIR)/emconfig.json
$(EMCONFIG_DIR)/emconfig.json:
	emconfigutil --platform $(DEVICE) --od $(EMCONFIG_DIR)

check: all
ifeq ($(TARGET),$(filter $(TARGET),sw_emu hw_emu))
	$(CP) $(EMCONFIG_DIR)/emconfig.json .
	XCL_EMULATION_MODE=$(TARGET) ./$(EXECUTABLE) ./data/queries.txt ./data/targets.txt
else
	 ./$(EXECUTABLE) ./data/queries.txt ./data/targets.txt
endif
	sdx_analyze profile -i sdaccel_profile_summary.csv -f html

# Cleaning stuff
clean:
	-$(RMDIR) $(EXECUTABLE) $(XCLBIN)/{*sw_emu*,*hw_emu*} 
	-$(RMDIR) sdaccel_* TempConfig system_estimate.xtxt *.rpt
	-$(RMDIR) src/*.ll _xocc_* .Xil emconfig.json dltmp* xmltmp* *.log *.jou *.wcfg *.wdb

cleanall: clean
	-$(RMDIR) $(XCLBIN)
	-$(RMDIR) _x.*

