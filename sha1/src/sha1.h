#ifndef _SHA1_H_
#define _SHA1_H_

/*
SHA-1 in C
By Steve Reid <steve@edmweb.com>
100% Public Domain
*/

#ifdef HAVE_LIBNSS
# include <nss.h>
# include <pk11pub.h>
#endif

#ifndef __linux__
typedef unsigned u_int32_t;
#endif

typedef struct {
#ifdef HAVE_LIBNSS
    PK11Context* ctx_nss;
#else
    u_int32_t state[5];
    u_int32_t count[2];
    unsigned char buffer[64];
#endif
} SHA1_CTX;

#ifdef __linux__
void SHA1Init(SHA1_CTX* context);
void SHA1Update(SHA1_CTX* context, const unsigned char* data, u_int32_t len);
void SHA1Final(unsigned char digest[20], SHA1_CTX* context);
unsigned char *SHA1(const unsigned char *data, size_t len, unsigned char *digest);
#endif

#endif /* _SHA1_H_ */
