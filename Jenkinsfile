#!/usr/bin/env groovy

properties([buildDiscarder(logRotator(artifactDaysToKeepStr: '',
artifactNumToKeepStr: '', daysToKeepStr: '30', numToKeepStr: '5')), [$class:
'GithubProjectProperty', displayName: '', projectUrlStr:
'https://gitenterprise.xilinx.com/SDx-Hub/apps/'], pipelineTriggers([[$class:
'GitHubPushTrigger']])])

devices  = 'xilinx:adm-pcie-7v3:1ddr:3.0'
devices += ' xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2'

def examples = [
	"acceleration/smithwaterman",
	"acceleration/nearest_neighbor_linear_search",
	"vision/huffman_codec",
	"vision/convolve",
	"vision/median_filter",
	"vision/histogram_eq",
	"vision/edge_detection",
	"vision/affine",
	"vision/watermarking",
	"getting_started/kernel_opt/lmem_2rw_c",
	"getting_started/kernel_opt/lmem_2rw_ocl",
	"getting_started/kernel_opt/dependence_inter_c",
	"getting_started/kernel_to_gmem/burst_rw_c",
	"getting_started/kernel_to_gmem/custom_datatype_c",
	"getting_started/kernel_to_gmem/full_array_2d_c",
	"getting_started/kernel_to_gmem/gmem_2banks_ocl",
	"getting_started/kernel_to_gmem/window_array_2d_c",
	"getting_started/kernel_to_gmem/wide_mem_rw_c",
	"getting_started/kernel_to_gmem/full_array_2d_ocl",
	"getting_started/kernel_to_gmem/custom_datatype_ocl",
	"getting_started/kernel_to_gmem/row_array_2d_c",
	"getting_started/kernel_to_gmem/window_array_2d_ocl",
	"getting_started/kernel_to_gmem/burst_rw_ocl",
	"getting_started/kernel_to_gmem/gmem_2banks_c",
	"getting_started/kernel_to_gmem/row_array_2d_ocl",
	"getting_started/kernel_to_gmem/wide_mem_rw_ocl",
	"getting_started/basic/sum_scan",
	"getting_started/basic/vmul_vadd",
	"getting_started/basic/vadd",
	"getting_started/basic/vdotprod",
	"getting_started/basic/hello",
	"getting_started/basic/host_global_bandwidth",
	"getting_started/basic/kernel_global_bandwidth",
	"getting_started/host/device_query_ocl",
	"getting_started/host/helloworld_ocl",
	"getting_started/dataflow/dataflow_stream_array_c",
	"getting_started/dataflow/dataflow_stream_c",
	"getting_started/dataflow/dataflow_pipes_ocl",
	"getting_started/dataflow/dataflow_loop_c",
	"getting_started/debug/debug_printf_ocl",
	"getting_started/debug/debug_profile_ocl",
	"security/sha1",
	"security/rsa",
	"security/aes_decrypt",
	"security/tiny_encryption",
]

def buildExample(target, dir, devices, workdir) {
	return { ->
		stage("${dir}-${target}") {
			node('rhel6 && xsjrdevl') {
				/* Retry up to 3 times to get this to work */
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

rsync -rL \$XILINX_SDX/Vivado_HLS/lnx64/tools/opencv/ lib/

make TARGETS=${target} DEVICES=\"${devices}\" check

"""
				}
			}
		}
	}
}

timestamps {
node('rhel6 && xsjrdevl') {

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

		step([$class: 'GitHubSetCommitStatusBuilder'])
	}

	Calendar now = Calendar.getInstance();

	if (now.get(Calendar.DAY_OF_WEEK) == Calendar.TUESDAY || 
	    ! fileExists('configure.mk') || ! fileExists('xilinx.lic') ) {
		stage('clean') {
			sh 'echo "FIXME: Clean not implemented"'
		}
	}

	stage('Build') {

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
