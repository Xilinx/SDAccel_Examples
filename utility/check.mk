# check.mk - defines rules for testing

# TODO: the filter on xcl_SRCS is not required in 2016.3+
loader = $(if $(filter $(1),hw),$(COMMON_REPO)/utility/nimbix/nimbix-run.py,$(if $(filter %.c,$(xcl_SRCS)),XCL_EMULATION_MODE=$(1),XCL_EMULATION_MODE=true))

# mk_check - run a check against the application
#  $(1) - base name for the check
#  $(1)_EXE - executable to run
#  $(1)_ARGS - arguments to use by default for the check
#  $(2) - compilation target (i.e. hw, hw_emu, sw_emu)
#  $(1)_$(2)_ARGS - specialization of arguments for specific targets
#  $(3) - device name (i.e. xilinx:adm-pcie-ku3:1ddr:3.0)
#  $(1)_$(3)_ARGS - specialization of arguments for specific devices (has
#                   priority over targets)
#  $(1)_$(2)_$(3)_ARGS - specialization of arguments for specific targets and
#                        devices
define mk_check

.PHONY: $(1)_$(2)_$(call sanitize_dsa,$(3))_check
$(1)_$(2)_$(call sanitize_dsa,$(3))_check: $($(1)_DEPS) $($(1)_EXE) $(foreach xclbin,$($(1)_XCLBINS),$(XCLBIN_DIR)/$(xclbin).$(2).$(call sanitize_dsa,$(3)).xclbin)
ifneq ($(2),hw)
	$(EMCONFIGUTIL) --xdevice $(3) --nd 1
endif
ifdef $(1)_$(2)_$(call sanitize_dsa,$(3))_ARGS
	$(call loader,$(2)) ./$($(1)_EXE) $($(1)_$(2)_$(3)_ARGS)
else
ifdef $(1)_$(call sanitize_dsa,$(3))_ARGS
	$(call loader,$(2)) ./$($(1)_EXE) $($(1)_$(3)_ARGS)
else
ifdef $(1)_$(2)_ARGS
	$(call loader,$(2)) ./$($(1)_EXE) $($(1)_$(2)_ARGS)
else
	$(call loader,$(2)) ./$($(1)_EXE) $($(1)_ARGS)
endif
endif
endif

CHECK_GOALS += $(1)_$(2)_$(call sanitize_dsa,$(3))_check

endef

$(foreach check,$(CHECKS),$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_check,$(check),$(target),$(device))))))

ifdef (CHECK_GOALS)
ECHO:= @echo

#Extended help messages
help::
	$(ECHO) "	make check TARGETS=<sw_emu/hw_emu/hw>"
	$(ECHO) "		Command to run emulation for specified Target. "
	$(ECHO) ""
endif

.PHONY: check
check: $(CHECK_GOALS)

