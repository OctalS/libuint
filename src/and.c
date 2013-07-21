#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <string.h>
#include "libuint.h"


inline void	__uintN_and(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	while (N--)
		dst[N] = a[N] & b[N];

}

void	__uintN_and_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	__set_uintN_s(B, b, N);
	__uintN_and(dst, a, B, N);
}

void	__uintN_and_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];

	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	__uintN_and(dst, a, B, N);

}
