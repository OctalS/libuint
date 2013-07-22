#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <string.h>
#include "libuint.h"


inline void	uint_and(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	while (N--)
		dst[N] = a[N] & b[N];

}

void	uint_and_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	uint_set_s(B, b, N);
	uint_and(dst, a, B, N);
}

void	uint_and_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];

	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	uint_and(dst, a, B, N);

}
