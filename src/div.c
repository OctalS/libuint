#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libuint.h"

void	uint_div(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	CHUNK_TYPE A[N], B[N];
	int i;

	memcpy(A, a, sizeof(A));
	memcpy(B, b, sizeof(B));
	memset(q, 0, CHUNK_BYTES);
	memset(r, 0, CHUNK_BYTES);

	if (!uint_cmp(B, q, N)) {
		fprintf(stderr, "libuint: division by zero!\n");
		exit(EXIT_FAILURE);
	}

	for (i = TOTAL_BITS - 1; i >= 0; i--) {
		uint_shl(r, 1, N);
		r[0] |= uint_get_bit(A, i);

		if (uint_cmp(r, B, N) >= 0) {
			uint_sub(r, r, B, N);
			uint_set_bit(q, i);
		}
	}
}

void	uint_div_s(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	uint_set_s(B, b, N);
	uint_div(q, r, a, B, N);
}

void	uint_div_u(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];

	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	uint_div(q, r, a, B, N);

}
