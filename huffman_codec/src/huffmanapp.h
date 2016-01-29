#ifndef AESAPP_H_
#define AESAPP_H_

#include "benchapp.h"
#include "base.h"

#define COMPUTE_UNITS 1

namespace sda {
namespace cl {

/*!
 *
 */
class HuffmanApp : public BenchApp {
public:
	HuffmanApp();
	HuffmanApp(const string& vendor_name,
		   const string& device_name,
		   int selected_device,
		   const string& strKernelFP,
		   const string& strBitmapFP);
	virtual ~HuffmanApp();

	enum EvBreakDown {evtHostWrite = 0, evtKernelExec = 1, evtHostRead = 2, evtCount = 3};

	bool run(int idevice, int nruns);

	bool invoke_kernel(bool encode, const vector<u8>& vec_input, vector<u8>& vec_output, cl_event events[evtCount]);

	static bool unit_test_kernel_cpu();
	static bool unit_test_naive();

protected:
	bool releaseMemObject(cl_mem &obj);

private:
	string m_strBitmapFP;

	cl_kernel m_clKernelHuffmanEncoder;
	cl_kernel m_clKernelHuffmanDecoder;
};

}
}

#endif /* AESAPP_H_ */
