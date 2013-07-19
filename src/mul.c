#include <stdio.h>
#include <string.h>
#include "libuint.h"

void	__uintN_mul(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	unsigned int i;
	CHUNK_TYPE A[N], B[N], C[N];

	memcpy(A, a, sizeof(A));
	memcpy(B, b, sizeof(B));
	memset(C, 0, sizeof(C));
	memset(dst, 0, sizeof(C));

	for (i = 0; i < TOTAL_BITS; i++) {
		__uintN_and_u(C, B, 1, N);
		if (C[0])
			__uintN_add(dst, dst, A, N);

		__uintN_lsh(A, 1, N);
		__uintN_rsh(B, 1, N);

	}
}

void	__uintN_mul_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	__set_uintN_s(B, b, N);
	__uintN_mul(dst, a, B, N);
}

void	__uintN_mul_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];

	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	__uintN_mul(dst, a, B, N);

}
