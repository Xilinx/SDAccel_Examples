#!/usr/bin/env groovy

properties([buildDiscarder(logRotator(artifactDaysToKeepStr: '',
artifactNumToKeepStr: '', daysToKeepStr: '30', numToKeepStr: '5')), [$class:
'GithubProjectProperty', displayName: '', projectUrlStr:
'https://gitenterprise.xilinx.com/SDx-Hub/apps/'], pipelineTriggers([[$class:
'GitHubPushTrigger']])])

// Days between clean builds
days = 10

devices = ''
devices += ' xilinx:adm-pcie-7v3:1ddr:3.0'
devices += ' xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2'
devices += ' xilinx:adm-pcie-ku3:2ddr-xpr:3.2'

version = '2016.3'

def buildExample(target, dir, devices, workdir) {
	return { ->
		if ( target == "sw_emu" ) {
			cores = 1
			queue = "medium"
		} else {
			cores = 8
			queue = "long"
		}

		sh """#!/bin/bash -e

cd ${workdir}

. /tools/local/bin/modinit.sh > /dev/null 2>&1
module use.own /proj/picasso/modulefiles

module add vivado/${version}_daily
module add vivado_hls/${version}_daily
module add sdaccel/${version}_daily
module add opencv/vivado_hls
module add lsf

cd ${dir}

echo
echo "-----------------------------------------------"
echo "PWD: \$(pwd)"
echo "-----------------------------------------------"
echo

rsync -rL \$XILINX_SDX/Vivado_HLS/lnx64/tools/opencv/ lib/

bsub -I -q ${queue} -R "osdistro=rhel && osver==ws6" -n ${cores} -R "span[ptile=${cores}]" -J "\$(basename ${dir})-${target}" <<EOF
make -k TARGETS=${target} DEVICES=\"${devices}\" all
EOF

"""
		retry(3) {
			/* Node is here to prevent too much strain on Nimbix by rate limiting
			 * to the number of job slots */
			node("rhel6 && xsjrdevl") {
				sh """#!/bin/bash -e

cd ${workdir}

. /tools/local/bin/modinit.sh > /dev/null 2>&1
module use.own /proj/picasso/modulefiles

module add vivado/${version}_daily
module add vivado_hls/${version}_daily
module add sdaccel/${version}_daily
module add opencv/vivado_hls

module add proxy

cd ${dir}

echo
echo "-----------------------------------------------"
echo "PWD: \$(pwd)"
echo "-----------------------------------------------"
echo

export PYTHONUNBUFFERED=true

make -k TARGETS=${target} DEVICES=\"${devices}\" check

"""
			}
		}
	}
}

timestamps {
// Always build on the same host so that the workspace is reused
node('rhel6 && xsjrdevl && xsjrdevl110') {
try {

	stage("checkout") {
		checkout scm
	}

	try {
		lastclean = readFile('lastclean.dat')
	} catch (e) {
		lastclean = "01/01/1970"
	} finally {
		lastcleanDate = new Date(lastclean)
		echo "Last Clean Build on ${lastcleanDate}"
	}
        
	def date = new Date()
	echo "Current Build Date is ${date}"

	if(date > lastcleanDate + days) {
		echo "Build too old reseting build area"
		stage("clean") {
			sh 'git clean -xfd'
			// After clean write new lastclean Date to lastclean.dat
			writeFile(file: 'lastclean.dat', text: "${date}")
		}
	}

	stage('pre-check') {
		sh """
. /tools/local/bin/modinit.sh > /dev/null 2>&1
module use.own /proj/picasso/modulefiles

module add vivado/${version}_daily
module add vivado_hls/${version}_daily
module add sdaccel/${version}_daily
module add opencv/vivado_hls

module add proxy

./utility/check_license.sh LICENSE.txt
./utility/check_readme.sh
"""
	}

	stage('configure') {
		sh 'git ls-files | grep description.json | sed -e \'s/\\.\\///\' -e \'s/\\/description.json//\' > examples.dat'
		examplesFile = readFile 'examples.dat'
		examples = examplesFile.split('\\n')

	}

	workdir = pwd()

	stage('sw_emu') {
		def swEmuSteps = [:]

		for(int i = 0; i < examples.size(); i++) {
			name = "${examples[i]}-sw_emu"
			swEmuSteps[name] = buildExample('sw_emu', examples[i], devices, workdir)
		}

		parallel swEmuSteps
	}

	stage('hw') {
		lock("only_one_hw_stage_at_a_time") {
			def hwSteps = [:]

			for(int i = 0; i < examples.size(); i++) {
				name = "${examples[i]}-hw"
				hwSteps[name] = buildExample('hw', examples[i], devices, workdir)
			}

			parallel hwSteps
		}
	}

} catch (e) {
	currentBuild.result = "FAILED"
	throw e
} finally {
	stage('post-check') {
		step([$class: 'GitHubCommitStatusSetter'])
		step([$class: 'Mailer', notifyEveryUnstableBuild: true, recipients: 'spenserg@xilinx.com', sendToIndividuals: false])
	}
	stage('cleanup') {
		// Cleanup .Xil Files after run
		sh 'find . -name .Xil | xargs rm -rf'
	}
} // try
} // node
} // timestamps


