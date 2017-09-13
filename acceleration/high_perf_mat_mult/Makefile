# the General Matrix Multiply Application
COMMON_REPO =../..

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# General Matrix Multiply  Host Application
high_perf_mat_mult_SRCS=src/high_perf_mat_mult.cpp $(xcl_SRCS)
high_perf_mat_mult_LDFLAGS=$(opencl_LDFLAGS)

EXES=high_perf_mat_mult

SPACE :=
SPACE +=
DASH :=-

# space DSA name for findstring
spaced_dsa = $(strip $(subst $(PERIOD),$(SPACE),$(subst $(COLON),$(SPACE),$(subst $(DASH),$(SPACE),$(1)))))

define platform_check

ifeq ($(findstring ku115,$(call spaced_dsa,$(1))),ku115)
	high_perf_mat_mult0_LDCLFLAGS+= -I./src/ \
	--xp misc:map_connect=add.kernel.krnl_0.m00_axi.core.OCL_REGION_0.M00_AXI  \
	--xp misc:map_connect=add.kernel.krnl_0.m01_axi.core.OCL_REGION_0.M01_AXI  \
	--xp vivado_prop:run.dr_krnl_0_0_synth_1.STEPS.SYNTH_DESIGN.TCL.PRE=$(PWD)/src/ku115/presynth.tcl \
	--xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.PRE=$(PWD)/src/ku115/ku115-constraints-pblock-1kernel.tcl \
	--xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.ARGS.DIRECTIVE=Explore \
	--xp vivado_prop:run.impl_1.STEPS.PLACE_DESIGN.ARGS.DIRECTIVE=Explore \
	--xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.IS_ENABLED=true \
	--xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE=AggressiveExplore \
	--xp vivado_prop:run.impl_1.STEPS.ROUTE_DESIGN.ARGS.DIRECTIVE=Explore \
	--nk kernelSgemm_0:1:krnl_0 
	high_perf_mat_mult_CXXFLAGS=-Wall -I./src/ -I$(XILINX_SDACCEL)/Vivado_HLS/include/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
endif

ifeq ($(findstring vu9p,$(call spaced_dsa,$(1))),vu9p) 
	high_perf_mat_mult0_LDCLFLAGS+= -I./src \
	--xp param:compiler.enableUtilizationReporting=0 \
	--xp param:compiler.lockFlowCritSlackThreshold=0.0 \
	--xp misc:map_connect=add.kernel.krnl_0.m00_axi.core.OCL_REGION_0.M02_AXI \
	--xp misc:map_connect=add.kernel.krnl_0.m01_axi.core.OCL_REGION_0.M03_AXI \
	--xp vivado_prop:run.dr_krnl_0_0_synth_1.STEPS.SYNTH_DESIGN.TCL.PRE=$(PWD)/src/xilinx_aws-vu9p-f1/presynth.tcl \
	--xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.PRE=$(PWD)/src/xilinx_aws-vu9p-f1/f1-constraints-pblock-1kernel.tcl \
        --xp param:compiler.worstNegativeSlack=-0.10 \
	--xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.POST=$(PWD)/src/xilinx_aws-vu9p-f1/postopt.tcl \
	--xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.ARGS.DIRECTIVE=Explore \
	--xp vivado_prop:run.impl_1.STEPS.PLACE_DESIGN.ARGS.DIRECTIVE=Explore \
	--xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.IS_ENABLED=true \
	--xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE=AggressiveExplore \
	--xp vivado_prop:run.impl_1.STEPS.ROUTE_DESIGN.ARGS.DIRECTIVE=Explore \
	--nk kernelSgemm_0:1:krnl_0 \
	--kernel_frequency "0:300|1:400" 
	high_perf_mat_mult_CXXFLAGS=-Wall -I./src/ -DVU9P -I$(XILINX_SDACCEL)/Vivado_HLS/include/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
endif


endef

$(foreach device,$(DEVICES),$(eval $(call platform_check,$(device))))

high_perf_mat_mult0_XOS=high_perf_mat_mult0
high_perf_mat_mult0_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr xilinx:adm-pcie-7v3:1ddr
high_perf_mat_mult0_NTARGETS=sw_emu

XCLBINS=high_perf_mat_mult0

# check
check_EXE=high_perf_mat_mult
check_XCLBINS=high_perf_mat_mult0
check_ARGS=64 64 64
check_NDEVICES=$(high_perf_mat_mult0_NDEVICES)
check_NTARGETS=sw_emu

CHECKS=check

#Reporting warning if targeting for sw_emu
ifneq (,$(findstring sw_emu,$(TARGETS)))
$(warning WARNING:RTL Kernels do not support sw_emu TARGETS. Please use hw_emu for running RTL kernel Emulation)
endif

define mk_target

xclbin/high_perf_mat_mult0.$(1).$(call device2sandsa, $(2)).xo: src/kernelShigh_perf_mat_mult_0.xo
	mkdir -p xclbin
	cp src/kernelShigh_perf_mat_mult_0.xo xclbin/high_perf_mat_mult0.$(1).$(call device2sandsa,$(2)).xo

endef

$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_target,$(target),$(device)))))

include $(COMMON_REPO)/utility/rules.mk

