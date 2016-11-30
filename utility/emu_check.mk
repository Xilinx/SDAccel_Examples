# emu_check.mk - defines rules for Running HW/SW Emulation

ECHO:= @echo

#Extended help messages
help::
	$(ECHO) "	make check TARGETS=<sw_emu/hw_emu>"
	$(ECHO)	"		Command to run emulation for specified Target. "
	$(ECHO)	"		Note: It supports single Target."
	$(ECHO) ""

#Default Run Time

RUN_TIME_ARGS:=${XCLBIN_GOALS}

############ CREATE emulation config file ######################################
EM_CONFIG_FILE := emconfig.json
${EM_CONFIG_FILE} :
	$(EMCONFIGUTIL) --xdevice ${DEVICES} --nd 1 --od ./
em_config : ${EM_CONFIG_FILE}

############# Design Emulation #################################################
check: em_config all 
	export XCL_EMULATION_MODE="${TARGETS}"; \
	export LD_LIBRARY_PATH=${XILINX_SDACCEL}/lib/lnx64.o:${XILINX_SDACCEL}/runtime/lib/x86_64:${LD_LIBRARY_PATH};\
	./${EXES} ${RUN_TIME_ARGS} 
