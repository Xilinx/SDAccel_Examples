#!/usr/bin/env python
import sys
import os
import nimbix_run

sys.dont_write_bytecode = True

# Arguments
executable = sys.argv[1:-1]
# Device
device = sys.argv[-1]
if "kcu1500" in device:
	node = "nx4b"
	name = "xilinx-sdx_2018_2"
elif "vcu1525" in device:
	node = "nx5b"
	name = "xilinx-sdx_2018_2"
elif "u200" in device:
	node = "nx5u"
	name = "xilinx-sdx_2018_2_xdf"
elif "u250" in device:
	node = "nx6u"
	name = "xilinx-sdx_2018_2_xdf"
else:
	exit("Error: DEVICE not supported. Please select the DEVICE properly and rerun.")
# Join Command Line Arguments
string = ' '.join(executable)
# Get the Present Script directory
pwd = sys.path[0]
# Function Call for Nimbix Cloud Execution
os.system(pwd + "/nimbix_run.py " + string + " --type " + node + " --nae " + name)
