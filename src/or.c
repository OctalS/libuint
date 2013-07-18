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

