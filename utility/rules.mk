# rules.mk - defines basic rules for building executables and xclbins

# Defines the prefix for each kernel.
XCLBIN_DIR=xclbin

ECHO:= @echo

.PHONY: help
help::
	$(ECHO) "Makefile Usage:"
	$(ECHO) "	make all TARGETS=<sw_emu/hw_emu/hw>"
	$(ECHO) "		Command to generate the design for specified Target."
	$(ECHO) ""
	$(ECHO) "	make clean"
	$(ECHO) "		Command to remove the generated files."
	$(ECHO) ""

# mk_exe - build an exe from host code
#   CXX - compiler to use
#   CXXFLAGS - base compiler flags to use
#   LDFLAGS - base linker flags to use
#   $(1) - name of exe
#   $(1)_SRCS - the source files to compile
#   $(1)_HDRS - the header files used by sources
#   $(1)_CXXFLAGS - extra flags specific to this exe
#   $(1)_LDFLAGS - extra linkder flags
define mk_exe

$(1): $($(1)_SRCS) $($(1)_HDRS)
	$(CXX) $(CXXFLAGS) $($(1)_CXXFLAGS) -o $$@ $($(1)_SRCS) $($(1)_LDFLAGS) $(LDFLAGS)

EXE_GOALS+= $(1)

endef

# sanitize_dsa - create a filesystem friendly name from dsa name
#   $(1) - name of dsa
COLON=:
PERIOD=.
UNDERSCORE=_
sanitize_dsa = $(strip $(subst $(PERIOD),$(UNDERSCORE),$(subst $(COLON),$(UNDERSCORE),$(1))))

# mk_xclbin - create an xclbin from a set of krnl sources
#  CLC - kernel compiler to use
#  CLFLAGS - flags to pass to the compiler
#  $(1) - base name for this xclbin
#  $(1)_SRCS - set of source files
#  $(1)_HDRS - set of header files
#  $(1)_CLFLAGS - set clflags per xclbin
#  $(2) - compilation target (i.e. hw, hw_emu, sw_emu)
#  $(3) - device name (i.e. xilinx:adm-pcie-ku3:1ddr:3.0)
define mk_xclbin

$(XCLBIN_DIR)/$(1).$(2).$(call sanitize_dsa,$(3)).xclbin: $($(1)_SRCS) $($(1)_HDRS)
	mkdir -p ${XCLBIN_DIR}
	$(CLC) $(CLFLAGS) $($(1)_CLFLAGS) -o $$@ -t $(2) --xdevice $(3) $($(1)_SRCS)

XCLBIN_GOALS+= $(XCLBIN_DIR)/$(1).$(2).$(call sanitize_dsa,$(3)).xclbin

endef

$(foreach exe,$(EXES),$(eval $(call mk_exe,$(exe))))

$(foreach xclbin,$(XCLBINS),$(foreach target,$(TARGETS),$(foreach device,$(DEVICES),$(eval $(call mk_xclbin,$(xclbin),$(target),$(device))))))

$(info $(XCLBIN_GOALS))

.PHONY: all
all: $(EXE_GOALS) $(XCLBIN_GOALS)

.PHONY: docs
docs: README.md

.PHONY: clean
clean:
	rm -rf $(EXE_GOALS) $(XCLBIN_GOALS) sdaccel* TempConfig
	rm -rf src/*.ll _xocc_* .Xil emconfig.json $(EXTRA_CLEAN) dltmp* xmltmp* *.log

README.md: description.json
	$(COMMON_REPO)/utility/readme_gen/readme_gen.py description.json

include $(COMMON_REPO)/utility/check.mk
