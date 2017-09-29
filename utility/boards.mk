# By Default report is set to none, so report will be generated
# 'estimate' for estimate report generation
# 'system' for system report generation
REPORT:=none

# Default C++ Compiler Flags and xocc compiler flags
CXXFLAGS:=-Wall -O0 -g
CLFLAGS:= --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

ifneq ($(REPORT),none)
CLFLAGS += --report $(REPORT)
endif 

LDCLFLAGS:=$(CLFLAGS)

ifdef XILINX_SDX
XILINX_SDACCEL=${XILINX_SDX}
endif

ifndef XILINX_SDACCEL
$(error XILINX_SDX or XILINX_SDACCEL is not set. Please source the SDx settings64.{csh,sh} script before attempting to run examples)
endif

VIVADO=$(XILINX_VIVADO)/bin/vivado

# Use the Xilinx OpenCL compiler
CLC:=$(XILINX_SDACCEL)/bin/xocc
LDCLC:=$(CLC)
EMCONFIGUTIL := $(XILINX_SDACCEL)/bin/emconfigutil

# By default build for X86, this could also be set to POWER to build for power
ARCH:=X86

ifeq ($(ARCH),POWER)
DEVICES:= xilinx:adm-pcie-7v3:1ddr-ppc64le
CXX:=$(XILINX_SDACCEL)/gnu/ppc64le/4.9.3/lnx64/bin/powerpc64le-linux-gnu-g++
else
DEVICES:= xilinx:xil-accel-rd-ku115:4ddr-xpr
CXX:=$(XILINX_SDACCEL)/bin/xcpp
endif

#if COMMON_REPO is not defined use the default value support existing Designs
COMMON_REPO ?= ../../

# By default build for hardware can be set to
#   hw_emu for hardware emulation
#   sw_emu for software emulation
#   or a collection of all or none of these
TARGETS:=hw

# By default only have one device in the system
NUM_DEVICES:=1

# sanitize_dsa - create a filesystem friendly name from dsa name
#   $(1) - name of dsa
COLON=:
PERIOD=.
UNDERSCORE=_
sanitize_dsa = $(strip $(subst $(PERIOD),$(UNDERSCORE),$(subst $(COLON),$(UNDERSCORE),$(1))))

device2dsa = $(if $(filter $(suffix $(1)),.xpfm),$(shell $(COMMON_REPO)/utility/parsexpmf.py $(1) dsa 2>/dev/null),$(1))
device2sandsa = $(call sanitize_dsa,$(call device2dsa,$(1)))
device2dep = $(if $(filter $(suffix $(1)),.xpfm),$(dir $(1))/$(shell $(COMMON_REPO)/utility/parsexpmf.py $(1) hw 2>/dev/null) $(1),)


