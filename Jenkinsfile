#!/usr/bin/env groovy

properties([buildDiscarder(logRotator(artifactDaysToKeepStr: '',
artifactNumToKeepStr: '', daysToKeepStr: '30', numToKeepStr: '5')), [$class:
'GithubProjectProperty', displayName: '', projectUrlStr:
'https://gitenterprise.xilinx.com/SDx-Hub/apps/'], pipelineTriggers([[$class:
'GitHubPushTrigger']])])

devices = ''
//devices += ' xilinx:adm-pcie-7v3:1ddr:3.0'
devices += ' xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2'
devices += ' xilinx:adm-pcie-ku3:2ddr-xpr:3.2'

def buildExample(target, dir, devices, workdir) {
	return { ->
		stage("${dir}-${target}") {
			node('rhel6 && xsjrdevl') {
				/* Retry up to 3 times to get this to work */

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

module add vivado/2016.3_daily
module add vivado_hls/2016.3_daily
module add sdaccel/2016.3_daily
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
			}
			retry(3) {
				sh """#!/bin/bash -e

cd ${workdir}

. /tools/local/bin/modinit.sh > /dev/null 2>&1
module use.own /proj/picasso/modulefiles

module add vivado/2016.3_daily
module add vivado_hls/2016.3_daily
module add sdaccel/2016.3_daily
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
	Calendar now = Calendar.getInstance();

	if (now.get(Calendar.DAY_OF_WEEK) == Calendar.TUESDAY) {
		stage('clean') {
			sh 'echo "FIXME: Clean not implemented"'
		}
	}

	stage("Checkout") {
		checkout scm

		// The following can be used when testing changes in the script console
		/* 
		checkout poll: false, scm: [
			$class: 'GitSCM', 
		*/ //	branches: [[name: '*/master']], 
		/*	userRemoteConfigs: [[
				credentialsId: '99feb95b-e9a4-4532-b6a0-ecce75d3dfad', 
				url: 'git@gitenterprise.xilinx.com:SDx-Hub/apps.git'
			]]
		]
	*/

		step([$class: 'GitHubCommitStatusSetter'])
	}

	stage('Build') {
		sh 'git ls-files | grep description.json | sed -e \'s/\\.\\///\' -e \'s/\\/description.json//\' > examples.dat'
		examplesFile = readFile 'examples.dat'
		examples = examplesFile.split('\\n')

		workdir = pwd()

		def swEmuSteps = [:]

		for(int i = 0; i < examples.size(); i++) {
			name = "${examples[i]}-sw_emu"
			swEmuSteps[name] = buildExample('sw_emu', examples[i], devices, workdir)
		}

		parallel swEmuSteps

		def hwSteps = [:]

		for(int i = 0; i < examples.size(); i++) {
			name = "${examples[i]}-hw"
			hwSteps[name] = buildExample('hw', examples[i], devices, workdir)
		}

		parallel hwSteps

	}

	step([$class: 'GitHubCommitStatusSetter'])
	step([$class: 'Mailer', notifyEveryUnstableBuild: true, recipients: 'spenserg@xilinx.com', sendToIndividuals: false])
}
} // timestamps
