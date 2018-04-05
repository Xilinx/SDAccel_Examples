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


ifeq ($(findstring kcu1500,$(call spaced_dsa,$(1))),kcu1500)
	high_perf_mat_mult0_LDCLFLAGS+= -I./src \
        --xp vivado_param:bd.ForceAppCoreUpgrade=1 \
	--sp krnl_0.m00_axi:bank3 \
	--sp krnl_0.m01_axi:bank2 \
        --xp vivado_prop:run.pfm_dynamic_krnl_0_0_synth_1.STEPS.SYNTH_DESIGN.TCL.PRE=$(PWD)/src/kcu1500/presynth.tcl \
        --xp param:compiler.userPostSysLinkTcl=$(PWD)/src/kcu1500/syslink-100kernel.tcl \
        --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.POST=$(PWD)/src/kcu1500/postopt.tcl \
        --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.ARGS.DIRECTIVE=Explore \
        --xp vivado_prop:run.impl_1.STEPS.PLACE_DESIGN.ARGS.DIRECTIVE=Explore \
        --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.IS_ENABLED=true \
        --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE=AggressiveExplore \
        --xp vivado_prop:run.impl_1.STEPS.ROUTE_DESIGN.ARGS.DIRECTIVE=Explore \
	--nk kernelSgemm_0:1:krnl_0 \
	--kernel_frequency "0:300|1:400" 
	high_perf_mat_mult_CXXFLAGS=-Wall -I./src/ -I$(XILINX_SDACCEL)/Vivado_HLS/include/  -I$(XILINX_SDACCEL)/include $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
endif

ifeq ($(findstring vu9p,$(call spaced_dsa,$(1))),vu9p) 
	high_perf_mat_mult0_LDCLFLAGS+= -I./src \
        --xp vivado_param:bd.ForceAppCoreUpgrade=1 \
	--sp krnl_0.m00_axi:bank3 \
	--sp krnl_0.m01_axi:bank1 \
        --xp vivado_prop:run.pfm_dynamic_krnl_0_0_synth_1.STEPS.SYNTH_DESIGN.TCL.PRE=$(PWD)/src/vu9p/presynth.tcl \
        --xp param:compiler.userPostSysLinkTcl=$(PWD)/src/vu9p/syslink-100kernel.tcl \
        --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.POST=$(PWD)/src/vu9p/postopt.tcl \
        --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.ARGS.DIRECTIVE=Explore \
        --xp vivado_prop:run.impl_1.STEPS.PLACE_DESIGN.ARGS.DIRECTIVE=Explore \
        --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.IS_ENABLED=true \
        --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE=AggressiveExplore \
        --xp vivado_prop:run.impl_1.STEPS.ROUTE_DESIGN.ARGS.DIRECTIVE=Explore \
	--nk kernelSgemm_0:1:krnl_0 \
	--kernel_frequency "0:300|1:400" 
	high_perf_mat_mult_CXXFLAGS=-Wall -I./src/ -DVU9P -I$(XILINX_SDACCEL)/Vivado_HLS/include/  -I$(XILINX_SDACCEL)/include $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
endif

ifeq ($(findstring vcu1525,$(call spaced_dsa,$(1))),vcu1525) 
	high_perf_mat_mult0_LDCLFLAGS+= -I./src \
        --xp vivado_param:bd.ForceAppCoreUpgrade=1 \
	--sp krnl_0.m00_axi:bank3 \
	--sp krnl_0.m01_axi:bank1 \
        --xp vivado_prop:run.pfm_dynamic_krnl_0_0_synth_1.STEPS.SYNTH_DESIGN.TCL.PRE=$(PWD)/src/vcu1525/presynth.tcl \
        --xp param:compiler.userPostSysLinkTcl=$(PWD)/src/vcu1525/syslink-100kernel.tcl \
        --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.POST=$(PWD)/src/vcu1525/postopt.tcl \
        --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.ARGS.DIRECTIVE=Explore \
        --xp vivado_prop:run.impl_1.STEPS.PLACE_DESIGN.ARGS.DIRECTIVE=Explore \
        --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.IS_ENABLED=true \
        --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE=AggressiveExplore \
        --xp vivado_prop:run.impl_1.STEPS.ROUTE_DESIGN.ARGS.DIRECTIVE=Explore \
	--nk kernelSgemm_0:1:krnl_0 \
	--kernel_frequency "0:300|1:400" 
	high_perf_mat_mult_CXXFLAGS=-Wall -I./src/ -DVCU1525 -I$(XILINX_SDACCEL)/Vivado_HLS/include/  -I$(XILINX_SDACCEL)/include $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
endif

high_perf_mat_mult0_LDCLFLAGS+= -I./src \



endef

$(foreach device,$(DEVICES),$(eval $(call platform_check,$(device))))

high_perf_mat_mult0_XOS=high_perf_mat_mult0
high_perf_mat_mult0_NTARGETS=sw_emu

XCLBINS=high_perf_mat_mult0

# check
check_EXE=high_perf_mat_mult
check_XCLBINS=high_perf_mat_mult0
check_ARGS=64 64 64
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

