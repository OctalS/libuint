#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <stdio.h>
#include "libuint.h"

int	uint_get_bit(CHUNK_TYPE *src, int bit) {


	int b, r;

	if (bit < CHUNK_BITS)
		return bit ? (src[0] >> bit) & 1 : src[0] & 1;

	if (bit == CHUNK_BITS)
		return src[1] & 1;

	b = bit / CHUNK_BITS;
	r = bit % CHUNK_BITS;

	return r ? (src[b] >> r) & 1 : src[b] & 1;

}

void	uint_set_bit(CHUNK_TYPE *dst, int bit) {


	int b, r;

	if (bit == CHUNK_BITS) {
		dst[1] |= 1;
		return;
	}

	if (bit < CHUNK_BITS) {
		b = 0;
		r = bit;
	} else {
		b = bit / CHUNK_BITS;
		r = bit % CHUNK_BITS;
	}

	dst[b] |= (r ? ((CHUNK_TYPE)1 << r) : 1);

}
