#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <stdio.h>
#include <string.h>
#include "libuint.h"

void	__uintN_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	unsigned int chunk;
	CHUNK_TYPE x, c;
	CHUNK_TYPE A[N], B[N];

	c = 0;
	x = 0;

	/* save a and b */
	memcpy(A, a, sizeof(A));
	memcpy(B, b, sizeof(B));

	memset(dst, 0, CHUNK_BYTES);

	for (chunk = 0; chunk < N; chunk++) {
		x = A[chunk] + B[chunk];

		dst[chunk] = x + c;

		c = x < A[chunk] ? 1 : 0;
	}
}


void	__uintN_add_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	__set_uintN_s(B, b, N);
	__uintN_add(dst, a, B, N);
}


void	__uintN_add_ss(CHUNK_TYPE *dst, const char *a, const char *b, unsigned int N) {

	CHUNK_TYPE A[N], B[N];

	__set_uintN_s(A, a, N);
	__set_uintN_s(B, b, N);

	__uintN_add(dst, A, B, N);
}

void	__uintN_add_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];
	
	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	__uintN_add(dst, a, B, N);
}
