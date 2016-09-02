CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

# Use the Xilinx OpenCL compiler
CLC:=$(XILINX_SDACCEL)/bin/xocc

# Devices per Architecture
X86_DEVICES:= xilinx:adm-pcie-7v3:1ddr:2.1 xilinx:adm-pcie-ku3:2ddr:2.1
X86_CXX:=$(XILINX_SDACCEL)/lnx64/tools/gcc/bin/g++

POWER_DEVICES:= xilinx:adm-pcie-7v3:1ddr-ppc64le:2.1
POWER_CXX:=$(XILINX_SDACCEL)/gnu/ppc64le/4.9.3/lnx64/bin/powerpc64le-linux-gnu-g++

# Kernel Binary Build Types
XMODES:=sw_emu hw_emu hw
ARCHES:=X86 POWER

