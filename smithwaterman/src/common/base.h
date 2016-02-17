/*******************************************************************************
Copyright (C) 2016 XILINX, Inc.

This file contains confidential and proprietary information of Xilinx, Inc. and 
is protected under U.S. and international copyright and other intellectual 
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials 
distributed herewith. Except as otherwise provided in a valid license issued to 
you by Xilinx, and to the maximum extent permitted by applicable law: 
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX 
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, 
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR 
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether 
in contract or tort, including negligence, or under any other theory of 
liability) for any loss or damage of any kind or nature related to, arising under 
or in connection with these materials, including for any direct, or any indirect, 
special, incidental, or consequential loss or damage (including loss of data, 
profits, goodwill, or any type of loss or damage suffered as a result of any 
action brought by a third party) even if such damage or loss was reasonably 
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any 
application requiring fail-safe performance, such as life-support or safety 
devices or systems, Class III medical devices, nuclear facilities, applications 
related to the deployment of airbags, or any other applications that could lead 
to death, personal injury, or severe property or environmental damage 
(individually and collectively, "Critical Applications"). Customer assumes the 
sole risk and liability of any use of Xilinx products in Critical Applications, 
subject only to applicable laws and regulations governing limitations on product 
liability. 

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT 
ALL TIMES.

*******************************************************************************/
#include <iostream>
#ifndef BASE_H_
#define BASE_H_

#ifdef WIN32
#define PS_OS_WINDOWS 1
#elif defined(__linux__) || defined(linux)
#define PS_OS_LINUX 2
#elif defined(__APPLE__)
#define PS_OS_MAC 3
#elif defined(__QNX__)
#define PS_OS_QNX 4
#endif

#ifdef _MSC_VER
#define PS_COMPILER_MS
#elif defined(__GNUC__)
#define PS_COMPILER_GNU
#endif

#if defined(_M_X64) || defined(__amd64__) || defined(_LP64)
#define PS_POINTER_SIZE 8
#else
#define PS_POINTER_SIZE 4
#endif

#ifdef PS_OS_LINUX
#include <cmath>
#include <cfloat>
#elif defined(PS_OS_MAC)
#include <cfloat>
#endif

//Min and Max
#define MATHMIN(_A_, _B_) ((_A_) < (_B_)) ? (_A_) : (_B_)
#define MATHMAX(_A_, _B_) ((_A_) > (_B_)) ? (_A_) : (_B_)

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)  \
    {                   \
        if (p) {        \
            delete (p); \
            (p) = NULL; \
        }               \
    }
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) \
    {                        \
        if ((p)) {           \
            delete[](p);     \
            (p) = NULL;      \
        }                    \
    }
#endif

#define PS_UNUSED(arg) (void) arg;

#ifndef EASY_TYPES
#define EASY_TYPES

typedef unsigned char u8;
typedef unsigned char uchar;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned int uint;
typedef char i8;
typedef short i16;
typedef int i32;

#if defined(_MSC_VER)
typedef unsigned __int64 u64;
typedef __int64 i64;
#else
typedef unsigned long long u64;
typedef long long i64;
#endif

#endif //easy types

//PI
const float Pi = 3.14159265358979323846f;

//PI over 2
const float PiOver2 = Pi / 2.0f;

//2PI
const float TwoPi = Pi * 2.0f;

// error tolerance for check
const float EPSILON = 1e-4f;

#define PS_PLUS_INFINITY FLT_MAX
#define PS_MINUS_INFINITY -1.0f * FLT_MAX

///////////////////////////////////////////////////////////////////
//Vec2
template <typename T>
class Vec2 {
public:
    Vec2()
        : x(0)
        , y(0)
    {
    }
    Vec2(T a_)
        : x(a_)
        , y(a_)
    {
    }
    Vec2(T x_, T y_)
        : x(x_)
        , y(y_)
    {
    }
    Vec2(const Vec2& rhs)
        : x(rhs.x)
        , y(rhs.y)
    {
    }

    inline Vec2<T>& operator=(const Vec2<T>& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
        return (*this);
    }

public:
    union {
        struct {
            T x;
            T y;
        };
        T e[2];
    };
};

//Vec3
template <typename T>
class Vec3 {
public:
    Vec3()
        : x(0)
        , y(0)
        , z(0)
    {
    }
    Vec3(T a_)
        : x(a_)
        , y(a_)
        , z(a_)
    {
    }
    Vec3(T x_, T y_, T z_)
        : x(x_)
        , y(y_)
        , z(z_)
    {
    }
    Vec3(const Vec3& rhs)
        : x(rhs.x)
        , y(rhs.y)
        , z(rhs.z)
    {
    }

    inline Vec3<T>& operator=(const Vec3<T>& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        return (*this);
    }

public:
    union {
        struct {
            T x;
            T y;
            T z;
        };
        T e[3];
    };
};

//Vec4
template <typename T>
class Vec4 {
public:
    Vec4()
        : x(0)
        , y(0)
        , z(0)
        , w(0)
    {
    }
    Vec4(T a_)
        : x(a_)
        , y(a_)
        , z(a_)
        , w(a_)
    {
    }
    Vec4(T x_, T y_, T z_, T w_)
        : x(x_)
        , y(y_)
        , z(z_)
        , w(w_)
    {
    }
    Vec4(const Vec4& rhs)
        : x(rhs.x)
        , y(rhs.y)
        , z(rhs.z)
        , w(rhs.w)
    {
    }

    inline Vec4<T>& operator=(const Vec4<T>& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->w = rhs.w;
        return (*this);
    }

public:
    union {
        struct {
            T x;
            T y;
            T z;
            T w;
        };
        T e[4];
    };
};

typedef Vec2<int> vec2i;
typedef Vec3<int> vec3i;
typedef Vec4<int> vec4i;

typedef Vec2<u32> vec2u;
typedef Vec3<u32> vec3u;
typedef Vec4<u32> vec4u;

typedef Vec2<float> vec2f;
typedef Vec3<float> vec3f;
typedef Vec4<float> vec4f;
///////////////////////////////////////////////////////////////////

#endif /* BASE_H_ */
