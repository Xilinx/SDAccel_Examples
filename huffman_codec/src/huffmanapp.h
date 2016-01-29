#ifndef AESAPP_H_
#define AESAPP_H_

#include <string>
#include <vector>
#include "bit_io.h"
#include "xcl.h"

#define COMPUTE_UNITS 1

using namespace std;

namespace sda {
namespace cl {

/*!
 *
 */
class HuffmanApp {
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


	static double timestamp();
	static double computeEventDurationInMS(const cl_event& event);
	static bool unit_test_kernel_cpu();
	static bool unit_test_naive();


protected:
	void cleanup();
	bool releaseMemObject(cl_mem &obj);

private:
	string m_strBitmapFP;

	xcl_world m_world;
	cl_kernel m_clKernelHuffmanEncoder;
	cl_kernel m_clKernelHuffmanDecoder;
};

}
}

#endif /* AESAPP_H_ */
