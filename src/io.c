#include <stdio.h>
#include <string.h>

#include "libuint.h"

int	__set_uintN(CHUNK_TYPE *dst, CHUNK_TYPE *src, unsigned int N) {

	memcpy(dst, src, CHUNK_SIZE * N);
	return 0;
}

int	__set_uintN_u(CHUNK_TYPE *dst, CHUNK_TYPE src, unsigned int N) {

	char str[UINT_MAX_STR];

	memset(str, 0, UINT_MAX_STR);
	sprintf(str, "%lx", src);

	return __set_uintN_s(dst, str, N);
}

int	__set_uintN_s(CHUNK_TYPE *dst, const char *str, unsigned int N) {

	int i, b;

	CHUNK_TYPE chunk, temp;
	CHUNK_TYPE *curent;



	if (strlen(str) > CHUNK_SIZE * N * 2)
		return 0;


	memset(dst, 0, N * CHUNK_SIZE);

	b = 0;
	chunk = 0;
	curent = &dst[chunk];

	for (i = strlen(str) - 1; i >= 0; i--, b++) {

		if (b == CHUNK_SIZE * 2) {
			b = 0;
			chunk++;
			curent = &dst[chunk];
		}

		if (str[i] < 0x61)
			temp = str[i] - 0x30;
		else
			temp = (str[i] - 0x60) + 9;

		*curent = *curent | (temp << (4 * b));
	}

	return 1;
}



char	*__get_uintN(const CHUNK_TYPE *src, unsigned int N) {

	long chunk, i, j;
	CHUNK_TYPE val;
	int echo;


	static char str[UINT_MAX_STR];

	memset(str, 0, UINT_MAX_STR);
	j = 0;
	val = 0;
	echo = 0;

	for (chunk = N-1; chunk >= 0; chunk--) {
		for (i = CHUNK_SIZE * 8 - 4 ; i >= 0; i -= 4) {
			val = (src[chunk] >> i) & 0xf;
			if (!val && !echo) {
				continue;
			} else {
				echo = 1;
			}

			sprintf(&str[j++], "%x", val);
		}
	}


	/* print zero */
	if (!echo)
		strcpy(str, "0");

	return str;
}

