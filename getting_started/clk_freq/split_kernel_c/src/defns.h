#ifndef __DEFNS_H__
#define __DEFNS_H__

#define CHANNELS 3
#define MAX_WIDTH 640
#define MAX_HEIGHT 480

#define WINDOW 3
#define SIZE (WINDOW * WINDOW)
#define BOOST_WINDOW WINDOW
#define MEDIAN_WINDOW WINDOW

#define imin(X, Y) (((X) < (Y)) ? (X) : (Y))
#define imax(X, Y) (((X) > (Y)) ? (X) : (Y))
#define abs(x) ((x)<0 ? -(x) : (x))

typedef unsigned int uint;

#include "boost_helper.h"
#include "median_helper.h"
#include "sketch_helper.h"

#endif







