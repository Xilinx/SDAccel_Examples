#ifdef __ECLIPSE__
#define kernel
#define global
#define __constant
#endif

typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef			 char		i8;
typedef			 short		i16;
typedef			 int		i32;

/*!
 * Input is an RGBA image with 24 or 32 bits per pixel format
 * Output is the greyscale image with 8 bits per pixel
 */
__kernel
__attribute__ ((reqd_work_group_size(1,1,1)))
void krnl_greyscale(global unsigned char* in_pixels, int nchannels, int width, int height, global unsigned char* out_pixels)
{
	#ifdef __xilinx__
		__attribute__((xcl_pipeline_loop))
	#endif
	for(int y=0; y < height; y++) {
		for(int x=0; x < width; x++) {
			int current = (x + y * width) * nchannels;
			
			u32 intensity = 0; 			
			for(int k=0; k < nchannels; k++)
				intensity += (in_pixels[current + k] * in_pixels[current + k]);

			out_pixels[current] = (u8)sqrt((float)intensity / (float)nchannels);
        }
    }   

}
