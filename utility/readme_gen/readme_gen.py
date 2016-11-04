#!/usr/bin/env python
from sys import argv
import json

def header(target,data):
    target.write(data["example"])
    target.write(" Example \n")
    target.write("======================\n\n")
    target.write("This README file contains the following sections:\n\n")
    target.write("1. OVERVIEW\n")
    target.write("2. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS\n")
    target.write("3. DESIGN FILE HIERARCHY\n")
    target.write("4. INSTALLATION AND OPERATING INSTRUCTIONS\n")
    target.write("5. SUPPORT\n")
    target.write("6. LICENSE\n")
    target.write("7. ACKNOWLEDGEMENTS\n")
    target.write("8. REVISION HISTORY\n\n\n")
    return

def overview(target,data):
    target.write("## 1. OVERVIEW\n")
    target.write(data["overview"])
    target.write("\n\n")
    if 'perf_fields' in data:
        target.write("### PERFORMANCE\n")
        target.write(data["perf_fields"][0])
        target.write("|")
        target.write(data["perf_fields"][1])
        target.write("|")
        target.write(data["perf_fields"][2])
        target.write("\n")
        target.write("----|-----|-----\n")
        for result in data["performance"]:
            target.write(result["system"])
            target.write("|")
            target.write(result["constraint"])
            target.write("|")
            target.write(result["metric"])
            target.write("\n")
    return

def requirements(target,data):
    target.write("## 2. SOFTWARE AND SYSTEM REQUIREMENTS\n")
    target.write("Board | Software Version\n")
    target.write("------|---------\n")
    for board in data["board"]:
        target.write(board)
        target.write("|")
        for version in data["version"]:
            target.write(version)
        target.write("\n")
    target.write("\n\n")
    return

def hierarchy(target):
    target.write("## 3. DESIGN FILE HIERARCHY\n")
    target.write("Application code is located in the src directory. ")
    target.write("Accelerator binary files will be compiled to the xclbin directory. ")
    target.write("The xclbin directory is required by the Makefile and its contents will be filled during compilation.\n\n")
    return

def compilation(target,data):
    target.write("## 4. INSTALLATION AND OPERATING INSTRUCTIONS\n")
    target.write("### Compilation for x86 based servers\n")
    target.write("1. make all\n")
    target.write("\n\tLaunches compilation both emulation and board execution modes of the application for all supported boards.")
    target.write("To limit or change the boards for compilation, edit the utility/boards.mk file located at the top level of this repository.\n\n")
    target.write("2. Executing emulation flows\n")
    target.write("Set the following environment variable to create a emconfig.json file\n")
    target.write("```\n")
    target.write("export LD_LIBRARY_PATH=$XILINX_SDACCEL/runtime/lib/x86_64/:$LD_LIBRARY_PATH\n")
    target.write("export XCL_EMULATION_MODE=")
    try:
      if not data['xcl']:
        target.write('true')
      else:
        target.write('<sw_emu|hw_emu>')
    except:
      target.write('<sw_emu|hw_emu>')
    target.write('\n')
    target.write("emconfigutil --xdevice '")
    target.write(data["dsa"])
    target.write("' --nd 1\n")
    target.write("```\n")
    target.write("Run the application as\n")
    target.write("```\n")
    target.write(data["em_cmd"])
    target.write("\n```\n")
    target.write("The choices for emulation flow are\n")
    target.write("\t\t- sw_emu = software emulation\n")
    target.write("\t\t- hw_emu = hardware emulation\n")
    target.write("*NOTE:* The software emulation flow is a functional correctness check only. It does not estimate the performance of the application in hardware.\n")
    target.write("The hardware emulation flow is a cycle accurate simulation of the hardware generated for the application. As such, it is expected for this simulation to take a long time.\n")
    target.write("It is recommended that for this example the user skips running hardware emulation or modifies the example to work on a reduced data set.\n")
    target.write("3. Running the application on a board hosted by Nimbix from a remote system\n")
    target.write("\n\tInstall the Xilinx Runtime for board in Nimbix using the xbinst utility in SDAccel\n")
    target.write("```\n")
    target.write("xbinst -x '")
    target.write(data["dsa"])
    target.write("' -d .\n")
    target.write("mv xbinst/pkg/pcie/runtime . \n")
    target.write("rm -rf xbinst\n")
    target.write("```\n")
    target.write("Run the nimbix-run.py script provided in the utility/nimbix directory at the top level of this repository\n")
    target.write("```\n")
    target.write(data["hw_cmd"])
    target.write("\n")
    target.write("```\n\n")
    target.write("\tOnly the Alpha Data ADM-PCIE-KU3 card is supported by this method.\n")
    target.write("4. Running the application from within Nimbix\n")
    target.write("\n\tFollow the instructions in the [Nimbix Getting Started Guide][]\n")
    target.write("\r\n### Compilation for IBM POWER servers\n")
    target.write("1. View the SuperVessel [Walkthrough Video][]\n\n")
    target.write("2. make all-POWER\n")
    target.write("\tLaunches compilation both emulation and board execution modes of the application for all supported boards.\n")
    return

def support(target):
    target.write("\r\n## 5. SUPPORT\n")
    target.write("For more information about SDAccel check the [SDAccel User Guides][]\n\n")
    target.write("For questions and to get help on this project or your own projects, visit the [SDAccel Forums][].\n")
    return

def license(target):
    target.write("\r\n## 6. LICENSE\n")
    target.write("The source for this project is licensed under the [3-Clause BSD License][]\n")
    return

def ack(target,data):
    target.write("\r\n## 7. ACKNOWLEDGEMENTS\n")
    target.write("This example is written by developers at\n")
    for contributor in data["contributors"]:
        target.write("- [")
        target.write(contributor["group"])
        target.write("](")
        target.write(contributor["url"])
        target.write(")\n")
    return

def revision(target,data):
    target.write("\r\n## 8. REVISION HISTORY\n")
    target.write("Date | README Version | Description\n")
    target.write("-----|----------------|------------\n")
    for rev in data["revision"]:
        target.write(rev["date"])
        target.write("|")
        target.write(rev["version"])
        target.write("|")
        target.write(rev["description"])
        target.write("\n")
    return

def footer(target):
    target.write("[3-Clause BSD License]: LICENSE.md\n")
    target.write("[SDAccel Forums]: https://forums.xilinx.com/t5/SDAccel/bd-p/SDx\n")
    target.write("[SDAccel User Guides]: http://www.xilinx.com/support/documentation-navigation/development-tools/software-development/sdaccel.html?resultsTablePreSelect=documenttype:SeeAll#documentation\n")
    target.write("[Nimbix Getting Started Guide]: http://www.xilinx.com/member/sdaccel_ea_40hr/Getting_Started_with_SDAccel_on_Nimbix_cloud.pdf\n")
    target.write("[Walkthrough Video]: http://bcove.me/6pp0o482")
    return

# Get the argument from the description
script, desc_file = argv

# load the description file
print "SDAccel README File Genarator"
print "Opening the description file %r" % desc_file
desc = open(desc_file,'r')

# load the json data from the file
print "Parsing the description file"
data = json.load(desc)
desc.close()

print "Generating the README for %r" % data["example"]
target = open("README.md","w")
header(target,data)
overview(target,data)
requirements(target,data)
hierarchy(target)
compilation(target,data)
support(target)
license(target)
ack(target,data)
revision(target,data)
footer(target)
target.close
