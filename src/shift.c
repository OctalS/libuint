#include <stdio.h>
#include "libuint.h"

static void	shift_chunks_left(CHUNK_TYPE *dst, CHUNK_TYPE bits, unsigned int N) {

	unsigned int a, b, n;
	CHUNK_TYPE A, B, C;

	n = CHUNK_SIZE * 8 - bits;
	
	for (a = N-1, b = N-2; a > 0; a--, b--) {
		if (n)
			dst[a] <<= bits;
		else
			dst[a] = 0;

		dst[a] |= dst[b] >> n;
	}

	if (n)
		dst[0] <<= bits;
	else
		dst[0] = 0;
}


void	__uintN_lsh(CHUNK_TYPE *dst, unsigned int shift, unsigned int N) {

	CHUNK_TYPE s, bits;

	if (shift == CHUNK_SIZE * N * 8)
		return;

	if (shift <= CHUNK_SIZE * 8) {
		shift_chunks_left(dst, shift, N);
		return;
	}

	s = shift / (CHUNK_SIZE * 8);
	bits = shift % (CHUNK_SIZE * 8);

	if (s) {
		while (s--)
			shift_chunks_left(dst, CHUNK_SIZE * 8, N);
	}

	if (bits)
		shift_chunks_left(dst, bits, N);

}

void	__uintN_rsh(CHUNK_TYPE *dst, unsigned int shift, unsigned int N) {

}
