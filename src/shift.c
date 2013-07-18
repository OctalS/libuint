#include "libuint.h"

static void	shift_chunks_left(CHUNK_TYPE *dst, CHUNK_TYPE bits, unsigned int N) {

	unsigned int a, b, n;
	CHUNK_TYPE A, B, C;

	n = CHUNK_BITS - bits;
	
	for (a = N-1, b = N-2; a > 0; a--, b--) {

		dst[a] = n ? dst[a] << bits : 0;
		dst[a] |= dst[b] >> n;
	}

	dst[0] = n ? dst[0] << bits : 0;
}


static void	shift_chunks_right(CHUNK_TYPE *dst, CHUNK_TYPE bits, unsigned int N) {

	unsigned int a, b, n;
	CHUNK_TYPE A, B, C;

	n = CHUNK_BITS - bits;
	
	for (a = 0, b = 1; b < N; a++, b++) {

		dst[a] = n ? dst[a] >> bits : 0;
		dst[a] |= dst[b] << n;
	}

	dst[N-1] = n ? dst[N-1] >> bits : 0;
}


void	__uintN_lsh(CHUNK_TYPE *dst, unsigned int shift, unsigned int N) {

	CHUNK_TYPE s, bits;

	if (shift >= TOTAL_BITS)
		return;

	if (shift <= CHUNK_BITS) {
		shift_chunks_left(dst, shift, N);
		return;
	}

	s = shift / CHUNK_BITS;
	bits = shift % CHUNK_BITS;

	if (s) {
		while (s--)
			shift_chunks_left(dst, CHUNK_BITS, N);
	}

	if (bits)
		shift_chunks_left(dst, bits, N);

}

void	__uintN_rsh(CHUNK_TYPE *dst, unsigned int shift, unsigned int N) {

	CHUNK_TYPE s, bits;

	if (shift >= TOTAL_BITS)
		return;

	if (shift <= CHUNK_BITS) {
		shift_chunks_right(dst, shift, N);
		return;
	}

	s = shift / CHUNK_BITS;
	bits = shift % CHUNK_BITS;

	if (s) {
		while (s--)
			shift_chunks_right(dst, CHUNK_BITS, N);
	}

	if (bits)
		shift_chunks_right(dst, bits, N);
}
