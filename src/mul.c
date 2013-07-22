#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <stdio.h>
#include <string.h>
#include "libuint.h"

void	uint_mul(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	int i, local_bit, global_bit;
	CHUNK_TYPE A[N], B[N], C[N], x;


	memcpy(A, a, sizeof(A));
	memcpy(B, b, sizeof(B));
	memset(C, 0, sizeof(C));
	memset(dst, 0, sizeof(C));


	global_bit = 0;
	for (i = 0; i < N; i++) {
		x = B[i];
		for (local_bit = 0; local_bit < CHUNK_BITS; local_bit++, global_bit++, x >>= 1) {
			if (x & 1) {
				memcpy(C, A, sizeof(C));
				uint_shl(C, global_bit, N);
				uint_add(dst, dst, C, N);
			}
		}
	}
}

void	uint_mul_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	uint_set_s(B, b, N);
	uint_mul(dst, a, B, N);
}

void	uint_mul_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];

	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	uint_mul(dst, a, B, N);

}
