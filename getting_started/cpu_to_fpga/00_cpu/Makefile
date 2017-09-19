COMMON_REPO := ../../../

# Common Includes
include $(COMMON_REPO)/utility/boards.mk

# Host Application
host_SRCS=./src/main.cpp
host_CXXFLAGS=-I./src/

host_NTARGETS=hw_emu hw
EXES=host

# check
check_EXE=host
check_NTARGETS=$(host_NTARGETS)

CHECKS=check

#Reporting warning if not targeting for sw_emu
ifneq (sw_emu,$(findstring sw_emu,$(TARGETS)))
$(warning WARNING:Application supports only sw_emu TARGETS. Please use sw_emu for running the application)
endif

include $(COMMON_REPO)/utility/rules.mk
