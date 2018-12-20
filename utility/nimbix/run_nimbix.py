#!/usr/bin/env python
import sys
import os

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
	node = "nx5u"
	name = "xilinx-sdx_2018_2_xdf"
else:
	exit("Error: DEVICE not supported. Please select the DEVICE properly and rerun.")
string = ' '.join(executable)
print(string)
# Function Call for Nimbix
os.system("nimbix_run.py " + string + " --type " + node + " --nae " + name)
