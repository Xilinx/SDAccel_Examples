XCLBIN_DIR=xclbin

define mk_exe

$(2): $($(1)_SRCS) $($(1)_HDRS)
	$($(3)_CXX) $(CXXFLAGS) $($(1)_CXXFLAGS) $($(1)_$(3)_CXXFLAGS) -o $$@ $($(1)_SRCS) $($(1)_LDFLAGS) $($(1)_$(3)_LDFLAGS)

$(3)_EXE_GOALS+= $(2)

endef

COLON=:
UNDERSCORE=_

define mk_xclbin

$(XCLBIN_DIR)/$(1).$(2).$(subst $(COLON),$(UNDERSCORE),$(3)).xclbin: $($(1)_SRCS) $($(1)_HDRS)
	$(CLC) $(XOCCFLAGS) $($(1)_XFLAGS) -o $$@ -t $(2) --xdevice $(3) $($(1)_SRCS)

$(4)_XCLBIN_GOALS+= $(XCLBIN_DIR)/$(1).$(2).$(subst $(COLON),$(UNDERSCORE),$(3)).xclbin

endef

define mk_all

.PHONY: all-$(1)
all-$(1): $($(1)_EXE_GOALS) $($(1)_XCLBIN_GOALS)

endef

.PHONY: all
all: all-X86

$(foreach exe,$(EXES),$(foreach arch,$(ARCHES),$(eval $(call mk_exe,$(exe),$(exe)_$(arch).exe,$(arch)))))

$(foreach xclbin,$(XCLBINS),$(foreach xmode,$(XMODES),$(foreach arch,$(ARCHES),$(foreach xdevice,$($(arch)_DEVICES),$(eval $(call mk_xclbin,$(xclbin),$(xmode),$(xdevice),$(arch)))))))

$(foreach arch, $(ARCHES),$(eval $(call mk_all,$(arch))))

.PHONY: clean
clean:
	rm -rf $(foreach arch,$(ARCHES),$($(arch)_EXE_GOALS) $($(arch)_XCLBIN_GOALS)) sdaccel* *.ll _xocc_*
