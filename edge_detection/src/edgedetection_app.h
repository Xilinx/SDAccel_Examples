/*
 * EdgeDetectionApp.h
 *
 *  Created on: Feb 3, 2016
 *      Author: pouryas
 */

#ifndef EDGEDETECTIONAPP_H_
#define EDGEDETECTIONAPP_H_

#include <string>
#include "xcl.h"

using namespace std;

class EdgeDetectFilter {
public:
	EdgeDetectFilter(const string& vendor_name,
			   const string& device_name,
			   int selected_device,
			   const string& strKernelFP);

	virtual ~EdgeDetectFilter();


	bool run(const string& strInput, string& strOutput);

protected:
	xcl_world m_world;

	cl_kernel m_clKrnlSobel;
};

#endif /* EDGEDETECTIONAPP_H_ */
