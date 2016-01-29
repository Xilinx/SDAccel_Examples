
#ifndef BITMAP_DOT_H
#define BITMAP_DOT_H

#include <stdlib.h>

class BitmapInterface
{
 private:
  char* core ;
  char* dib ;
  const char* filename ;
  int* image ;

  // Core header information
  unsigned short magicNumber ;
  unsigned int fileSize ;
  unsigned int offsetOfImage ;

  // DIB information
  int sizeOfDIB ;
  int sizeOfImage ;
  int height ;
  int width ;

 public:
  BitmapInterface(const char* f) ;
  ~BitmapInterface() ;

  bool readBitmapFile() ;
  bool writeBitmapFile(int* otherImage = NULL); 

  inline int* bitmap() { return image ; } 
  unsigned int numPixels() { return sizeOfImage/3 ; }

  inline int getHeight() { return height ; }
  inline int getWidth() { return width ; }

} ;

#endif
