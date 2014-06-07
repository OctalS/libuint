#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <string.h>
#include "libuint.h"

void	uint_or(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	unsigned int i;
	CHUNK_TYPE A[N], B[N];

	__save(A, a);
	__save(B, b);

	for (i = 0; i < N; i++)
		dst[i] = A[i] | B[i];

}

void	uint_or_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	uint_set_s(B, b, N);
	uint_or(dst, a, B, N);
}

void	uint_or_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];

	__res(B);
	B[0] = b;
	uint_or(dst, a, B, N);

}
