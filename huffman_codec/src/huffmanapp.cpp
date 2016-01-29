#include <assert.h>
#include <string.h>
#include "huffmanapp.h"
#include "simplebmp.h"
#include "huffmancodec.h"
#include "logger.h"
#include "huffmancodec_opencl_cpu.h"

#define ROUNDS 10
//ROUNDS <= 10 valid

using namespace sda;
using namespace sda::cl;

/////////////////////////////////////////////////////////////////////////////////
//load_file_to_memory
//Allocated memory for and load file from disk memory
//Return value
// 0   Success
//-1   Failure to open file
//-2   Failure to allocate memory
int load_file_to_memory(const char *filename, char **result, size_t *inputsize) {
	int size = 0;
	FILE *f = fopen(filename, "rb");
	if (f == NULL) {
		*result = NULL;
		return -1; // -1 means file opening fail
	}
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fseek(f, 0, SEEK_SET);
	*result = (char *) malloc(size + 1);
	if (size != (int)fread(*result, sizeof(char), size, f)) {
		free(*result);
		return -2; // -2 means file reading fail
	}
	fclose(f);
	(*result)[size] = 0;
	if (inputsize != NULL)
		(*inputsize) = size;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
HuffmanApp::HuffmanApp() :
	BenchApp() {
	// TODO Auto-generated constructor stub

}

HuffmanApp::HuffmanApp(const string& vendor_name,
			   const string& device_name,
			   int selected_device,
			   const string& strKernelFP,
			   const string& strBitmapFP) :
			   	   BenchApp(vendor_name, device_name, selected_device, strKernelFP)
{
	//store path to input bitmap
	m_strBitmapFP = strBitmapFP;


	//create the kernels
	if (!CreateKernelByName(m_clprogram, "encode", m_clKernelHuffmanEncoder)) {
		LogError("Unable to create the encode kernel");
		abort();
	}

	if (!CreateKernelByName(m_clprogram, "decode", m_clKernelHuffmanDecoder)) {
		LogError("Unable to create the decode kernel");
		abort();
	}
}

HuffmanApp::~HuffmanApp() {
	// TODO Auto-generated destructor stub
	cleanup();
}

bool HuffmanApp::unit_test_kernel_cpu() {
	string msgs[] = {"AABBCCCC",
					 "Xilinx SDAccel Benchmarking",
					 "Hello Pourya Shirazian",
					 "The quick brown fox jumps over the lazy dog."};

	LogInfo("Start unit tests for kernels on the CPU");

	HuffmanCodec codec;
	u32 total = sizeof(msgs) / sizeof(msgs[0]);
	u32 ctPassed = 0;
	for(u32 i = 0; i < total; i++) {
		vector<u8> encoded_data;
		string out_str;
		codec.kernel_encode_string(msgs[i], encoded_data);

		codec.kernel_decode_string(encoded_data, out_str);

		if(msgs[i] == out_str) {
			LogInfo("Test [%u of %u] PASS", i+1, total);
			ctPassed++;
		}
		else
		{
			LogError("Test [%u of %u] Failed! (input: %s, output: %s)", msgs[i].c_str(), out_str.c_str());
		}
	}

	LogInfo("End unit tests for kernels on the CPU");

	return(ctPassed == total);
}

/*!
 * Unit test for the huffman cpu version
 */
bool HuffmanApp::unit_test_naive() {
	string msgs[] = {"aabbcccc",
					 "Xilinx SDAccel Benchmarking",
					 "Hello Pourya Shirazian",
					 "The quick brown fox jumps over the lazy dog."};


	HuffmanCodec codec;
	u32 ctPassed = 0;
	u32 total = sizeof(msgs) / sizeof(msgs[0]);
	for(u32 i = 0; i < total; i++) {
		vector<u8> data_out;
		string out_str;

		int res = codec.encode_naive(msgs[i], data_out);
		res &= codec.decode_naive(data_out, out_str);

		if(msgs[i] == out_str) {
			LogInfo("Test [%u of %u] PASS", i+1, total);
			ctPassed++;
		}
		else
		{
			LogError("Test [%u of %u] Failed! (input: %s, output: %s)", msgs[i].c_str(), out_str.c_str());
		}
	}

	return (ctPassed == total);
}

bool HuffmanApp::releaseMemObject(cl_mem &obj)
{
  cl_int   err = 0;
  bool     returnStatus = true;    // true if successful

  if (obj != NULL)  // This means it has been initialized
  {
    err = clReleaseMemObject(obj);
    if (err != CL_SUCCESS)
    {
      cout << "Error releasing variable\n";
      returnStatus |= false;
    }
    else
      obj = NULL; /* memory was released, re-initialize pointer to NULL */
  }

  return returnStatus;
}

bool HuffmanApp::invoke_kernel(bool encode,
							   const vector<u8>& vec_input,
							   vector<u8>& vec_output,
							   cl_event events[evtCount]) {
	if(vec_input.size() == 0)
		return false;

	cl_kernel kernel = encode ? m_clKernelHuffmanEncoder : m_clKernelHuffmanDecoder;

	u32 sz_input = vec_input.size();
	u32 sz_output = 0;

//	__kernel
//	__attribute__ ((reqd_work_group_size(1,1,1)))
//	void encode(__global uchar* in_data, uint size_in_data, __global uchar* out_data, __global uint* size_out_data, uchar fetch_size_only)
//	void decode(__global uchar* in_data, uint size_in_data, __global uchar* out_data, __global uint* size_out_data, uchar fetch_size_only) {
	//create input and output buffers size for 24 bpp image
	cl_int err;
	cl_mem mem_input;
	mem_input = clCreateBuffer(m_clcontext, CL_MEM_READ_WRITE, sz_input, NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Error: Failed to allocate OpenCL source buffer of size %lu", sz_input);
		return false;
	}

	cl_mem mem_output;
	mem_output = clCreateBuffer(m_clcontext, CL_MEM_READ_WRITE, sz_input, NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Failed to allocate worst case OpenCL output buffer of size %lu",
				sz_input);
		return false;
	}

	cl_mem mem_sz_output;
	mem_sz_output = clCreateBuffer(m_clcontext, CL_MEM_READ_WRITE, sizeof(u32), NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Failed to allocate worst case OpenCL output buffer of size %lu",
				sizeof(u32));
		return false;
	}


	//copy input dataset to OpenCL buffer
	err = clEnqueueWriteBuffer(m_clcommandqs[0], mem_input, CL_TRUE, 0,
							   sz_input, vec_input.data(), 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		LogError("Failed to copy input dataset to OpenCL buffer");
		return false;
	}

	//finish all memory writes
	clFinish(m_clcommandqs[0]);

	//execute kernel
	/*!
	 * void encode(__global uchar* in_data, uint size_in_data,
	 * 			   __global uchar* out_data, __global uint* size_out_data,
	 * 			   uchar fetch_size_only)
	 *
	 * void decode(__global uchar* in_data, uint size_in_data,
	 * 			   __global uchar* out_data, __global uint* size_out_data,
	 * 			   uchar fetch_size_only)
	 */
	err = 0;
	err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &mem_input);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [0] input_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 1, sizeof(u32), &sz_input);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [1] sz_input! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &mem_output);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [2] output_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	err |= clSetKernelArg(kernel, 3, sizeof(cl_mem), &mem_sz_output);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [3] sz_output! %d", err);
		LogError("Test failed");
		return false;
	}

	//enable fetch size
	u8 fetch_size_only = 1;
	err |= clSetKernelArg(kernel, 4, sizeof(u8), &fetch_size_only);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [4] fetch_size_only! %d", err);
		LogError("Test failed");
		return false;
	}

	size_t global[1];
	size_t local[1];
	global[0] = 1;
	local[0] = 1;

	//call once to guarentee that all buffers are migrated to device memory
	err = clEnqueueNDRangeKernel(m_clcommandqs[0], kernel, 1, NULL, global,
			local, 0, NULL, &events[evtHostWrite]);
	if (err != CL_SUCCESS) {
		LogError("[EX1] Failed to execute kernel %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_clcommandqs[0]);

	//read output size
	err = clEnqueueReadBuffer(m_clcommandqs[0], mem_sz_output, CL_TRUE, 0,
			sizeof(u32), (void *) &sz_output, 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		LogError("Failed to read output size buffer %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_clcommandqs[0]);

	//resize output-buffer
	releaseMemObject(mem_output);

	vec_output.resize(sz_output);
	mem_output = clCreateBuffer(m_clcontext, CL_MEM_READ_WRITE, sz_output, NULL, &err);
	if (err != CL_SUCCESS) {
		LogError("Failed to allocate worst case OpenCL output buffer of size %lu", sz_output);
		return false;
	}

	//set output again
	err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &mem_output);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [2] output_buffer! %d", err);
		LogError("Test failed");
		return false;
	}

	//set output size again
	err |= clSetKernelArg(kernel, 3, sizeof(cl_mem), &mem_sz_output);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [3] sz_output! %d", err);
		LogError("Test failed");
		return false;
	}

	//disable fetch size
	fetch_size_only = 0;
	err |= clSetKernelArg(kernel, 4, sizeof(u8), &fetch_size_only);
	if (err != CL_SUCCESS) {
		LogError("Failed to set kernel argument [4] fetch_size_only! %d", err);
		LogError("Test failed");
		return false;
	}

	//call a second time to measure on-chip throughput
	err = clEnqueueNDRangeKernel(m_clcommandqs[0], kernel, 1, NULL, global,
			local, 0, NULL, &events[evtKernelExec]);
	if (err != CL_SUCCESS) {
		LogError("[EX2] Failed to execute kernel %d", err);
		LogError("Test failed");
		return false;
	}

	clFinish(m_clcommandqs[0]);

	//copy results back from OpenCL buffer
	err = clEnqueueReadBuffer(m_clcommandqs[0], mem_output, CL_TRUE, 0,
			sz_output, (void *) vec_output.data(), 0, NULL, &events[evtHostRead]);
	if (err != CL_SUCCESS) {
		LogError("Failed to read output size buffer %d", err);
		LogError("Test failed");
		return false;
	}
	clFinish(m_clcommandqs[0]);


	//cleanup
	releaseMemObject(mem_input);
	releaseMemObject(mem_output);
	releaseMemObject(mem_sz_output);

	return true;
}




bool HuffmanApp::run(int idevice, int nruns) {
	if (idevice < 0 || idevice >= (int) m_numdevices)
		return false;

	if (nruns <= 0)
		return false;

	assert(unit_test_kernel_cpu());


	int err;
	struct bmp_t inputbmp;
	err = readbmp((char*)m_strBitmapFP.c_str(), &inputbmp);
	if (err != 0) {
		LogError("Unable to read bitmap file: [%s]", m_strBitmapFP.c_str());
		return false;
	}

	//input buffer size
	u32 szInputBuffer = inputbmp.height * inputbmp.width * 3;
	u8* buffer = reinterpret_cast<u8*>(inputbmp.pixels);

	//timings
	cl_event events[evtCount];
	double durations[evtCount];
	for(int i=0; i < evtCount; i++)
		durations[i] = 0.0;

	//start time stamps
	double startMS = ProfileController::timestamp();

	vector<u8> vec_in(buffer, buffer + szInputBuffer);
	vector<u8> vec_encoded_data;
	vector<u8> vec_decoded_data;

	//encode image
	bool res = invoke_kernel(true, vec_in, vec_encoded_data, &events[0]);
	if(!res) {
		LogError("Failed to encode the input. Test Failed");
		return false;
	}

	//collect times
	for(int i=0; i < evtCount; i++) {
		durations[i] += ProfileController::GetEventDurationInMS(events[i]);
	}


	//decode image
	res |= invoke_kernel(false, vec_encoded_data, vec_decoded_data, &events[0]);
	if(!res) {
		LogError("Failed to decode the output. Test Failed");
		return false;
	}

	//collect times
	for(int i=0; i < evtCount; i++) {
		durations[i] += ProfileController::GetEventDurationInMS(events[i]);
	}


	//using the standard impl
	/*
	HuffmanCodec codec;
	u32 szEncoded = 0;
	u32 szDecoded = 0;

	//encode
	encode(vec_in.data(), vec_in.size(), vec_encoded_data.data(), &szEncoded, true);
	vec_encoded_data.resize(szEncoded);
	encode(vec_in.data(), vec_in.size(), vec_encoded_data.data(), &szEncoded, false);
	LogInfo("Encoded image. Org Size %u, Compact Size %u", vec_in.size(), vec_encoded_data.size());

	decode(vec_encoded_data.data(), vec_encoded_data.size(), vec_decoded_data.data(), &szDecoded, true);
	vec_decoded_data.resize(szDecoded);
	decode(vec_encoded_data.data(), vec_encoded_data.size(), vec_decoded_data.data(), &szDecoded, false);
	*/



	//set stats to valid data
	if (m_full_device_names.size() > 0)
		m_sp_prof->data().m_full_device_name = m_full_device_names[0];
	m_sp_prof->data().m_full_vendor_name = m_full_vendor_name;
	m_sp_prof->data().m_number_of_runs = nruns;
	m_sp_prof->data().m_totalMS = ProfileController::timestamp() - startMS;
	m_sp_prof->data().m_tHostWriteMS = durations[evtHostWrite];
	m_sp_prof->data().m_tKernelExecMS = durations[evtKernelExec];
	m_sp_prof->data().m_tHostReadMS = durations[evtHostRead];
	m_sp_prof->data().m_avg_temp_deg = 0;
	m_sp_prof->data().m_power_watts = 0;
	m_sp_prof->data().m_h2d_tx_rate_mbits_psec = 0;
	m_sp_prof->data().m_d2h_tx_rate_mbits_psec = 0;

	//compute transfer rate for host write
	if(durations[evtHostWrite] > 0) {
		u32 sz_bytes = vec_in.size() + vec_encoded_data.size();

		//bits per second
		double tmp = (sz_bytes * 8.0) / (durations[evtHostWrite] / 1000.0);

		//mega-bits per second
		tmp = tmp / (1024.0 * 1024.0);
		m_sp_prof->data().m_h2d_tx_rate_mbits_psec = tmp;
	}

	//compute transfer rate for host read
	if(durations[evtHostRead] > 0) {
		u32 sz_bytes = vec_encoded_data.size() + vec_decoded_data.size();

		//bits per second
		double tmp = (sz_bytes * 8.0) / (durations[evtHostRead] / 1000.0);

		//mega-bits per second
		tmp = tmp / (1024.0 * 1024.0);
		m_sp_prof->data().m_d2h_tx_rate_mbits_psec = tmp;
	}

	m_sp_prof->data().setValid(true);

	//write decoded bmp
	string strOutputFP = "decoded.bmp";
	LogInfo("Image decoded OK. Check the output image file: %s", strOutputFP.c_str());
	inputbmp.pixels = reinterpret_cast<uint32_t*>(&vec_decoded_data[0]);
	writebmp((char*)strOutputFP.c_str(), &inputbmp);


	return true;
}

