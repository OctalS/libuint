#include <string.h>
#include "libuint.h"

void	__uintN_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	CHUNK_TYPE i, chunk;
	CHUNK_TYPE x, x1, x2, c;
	CHUNK_TYPE A[N], B[N];

	c = 0;
	x = 0;

	/* save a and b */
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));

	memcpy(A, a, sizeof(A));
	memcpy(B, a, sizeof(B));

	memset(dst, 0, N * CHUNK_SIZE);

	for (chunk = 0; chunk < N; chunk++) { 
		for (i = 0; i < CHUNK_SIZE * 8; i++) {
			x1 = (A[chunk] >> i) & 1;
			x2 = (B[chunk] >> i) & 1;
			switch (x1 + x2 + c) {
				case 0:
					x = 0;
					c = 0;
					break;
				case 1:
					x = 1;
					c = 0;
					break;
				case 2:
					x = 0;
					c = 1;
					break;
				case 3:
					x = 1;
					c = 1;
					break;
			}
	
			dst[chunk] |= x << i;
	
		}

	}
}
