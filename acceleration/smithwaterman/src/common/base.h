/**********
Copyright (c) 2016, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/
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
