/*
 * Sobel_CpuOnly.h
 *
 *  Created on: Feb 3, 2016
 *      Author: pouryas
 */

#ifndef SOBEL_CPUONLY_H_
#define SOBEL_CPUONLY_H_

#include <string>
#include <stdint.h>

using namespace std;

typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef			 char		i8;
typedef			 short		i16;
typedef			 int		i32;


class Sobel {
public:
	Sobel();
	virtual ~Sobel();

	static bool apply(const string& input, const string& output);
	static bool apply(const u8* in_pixels, u8 nchannels, int width, int height, u8* out_pixels);

	static u32 pack_from_bgr_to_rgba(const u8* in_pixels);

	static void unpack_from_rgba_to_bgr(u32 rgba, u8* out_pixels);
};

#endif /* SOBEL_CPUONLY_H_ */
