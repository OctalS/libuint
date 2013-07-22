#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <stdio.h>
#include <string.h>
#include "libuint.h"

void	uint_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

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


void	uint_add_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	uint_set_s(B, b, N);
	uint_add(dst, a, B, N);
}


void	uint_add_ss(CHUNK_TYPE *dst, const char *a, const char *b, unsigned int N) {

	CHUNK_TYPE A[N], B[N];

	uint_set_s(A, a, N);
	uint_set_s(B, b, N);

	uint_add(dst, A, B, N);
}

void	uint_add_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];
	
	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	uint_add(dst, a, B, N);
}
