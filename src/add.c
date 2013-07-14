#include <string.h>
#include "libuint.h"

int	__uintN_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	CHUNK_TYPE i, chunk;
	CHUNK_TYPE x, x1, x2, c;

	c = 0;
	x = 0;

	memset(dst, 0, N * CHUNK_SIZE);

	for (chunk = 0; chunk < N; chunk++) { 
		for (i = 0; i < CHUNK_SIZE * 8; i++) {
			x1 = (a[chunk] >> i) & 1;
			x2 = (b[chunk] >> i) & 1;
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

	return 0;
}
