#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <string.h>
#include "libuint.h"

void	__uintN_or(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	unsigned int i;
	CHUNK_TYPE A[N], B[N];

	memcpy(A, a, sizeof(A));
	memcpy(B, b, sizeof(B));

	for (i = 0; i < N; i++)
		dst[i] = A[i] | B[i];

}

void	__uintN_or_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	__set_uintN_s(B, b, N);
	__uintN_or(dst, a, B, N);
}

void	__uintN_or_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];

	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	__uintN_or(dst, a, B, N);

}
