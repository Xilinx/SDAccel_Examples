
XCLBIN_DIR=xclbin

define mk_power

$(2): $($(1)_SRCS) $($(1)_HDRS)
	$(CPOWER) $($(1)_CXXFLAGS) -o $$@ $($(1)_SRCS) $($(1)_PLDFLAGS)

POWER_GOALS+=$(2)

endef

define mk_exe

$(2): $($(1)_SRCS) $($(1)_HDRS)
	$(CXX) $($(1)_CXXFLAGS) -o $$@ $($(1)_SRCS) $($(1)_LDFLAGS)

EXE_GOALS+=$(2)

endef

COLON=:
UNDERSCORE=_
X86:= X86
POWER:= POWER

define mk_xclbin

ifeq ($(4),X86)
	XCLBIN_GOALS+= $(XCLBIN_DIR)/$(1).$(2).$(subst $(COLON),$(UNDERSCORE),$(3)).xclbin
else
	SV_XCLBIN_GOALS+= $(XCLBIN_DIR)/$(1).$(2).$(subst $(COLON),$(UNDERSCORE),$(3)).xclbin
endif

$(XCLBIN_DIR)/$(1).$(2).$(subst $(COLON),$(UNDERSCORE),$(3)).xclbin: $($(1)_SRCS) $($(1)_HDRS)
	$(CLC) $($(1)_XFLAGS) -o $$@ -t $(2) --xdevice $(3) $($(1)_SRCS)

endef

.PHONY: all
all: all-x86

$(foreach exe,$(EXES),$(eval $(call mk_exe,$(exe),$(exe).exe)))

$(foreach exe,$(EXES),$(eval $(call mk_power,$(exe),$(exe)_power.exe)))

$(foreach xclbin,$(XCLBINS),$(foreach xmode, $(XMODES),$(foreach xdevice,$(X86_DEVICES),$(eval $(call mk_xclbin,$(xclbin),$(xmode),$(xdevice),$(X86))))))

$(foreach xclbin,$(XCLBINS),$(foreach xmode, $(XMODES),$(foreach xdevice,$(POWER_DEVICES),$(eval $(call mk_xclbin,$(xclbin),$(xmode),$(xdevice),$(POWER))))))

.PHONY: all-x86
all-x86: $(EXE_GOALS) $(XCLBIN_GOALS)

.PHONY: sv_all
sv_all: $(POWER_GOALS) $(EXE_GOALS) $(SV_XCLBIN_GOALS)

.PHONY: clean
clean:
	rm -rf $(EXE_GOALS) $(XCLBIN_GOALS) $(SV_XCLBIN_GOALS) sdaccel* *.ll
