#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#define	LIBUINT_BIT_WARNING

#include <stdio.h>
#include <string.h>

#include "libuint.h"

#define	is_hex(c)	((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))

int	uint_set(CHUNK_TYPE *dst, CHUNK_TYPE *src, unsigned int N) {

	memcpy(dst, src, CHUNK_BYTES);
	return 1;
}

int	uint_set_u(CHUNK_TYPE *dst, CHUNK_TYPE src, unsigned int N) {

	char str[UINT_MAX_STR];

	memset(str, 0, UINT_MAX_STR);
	sprintf(str, CPU_SIZE ? "%x" : "%llx", src);

	return uint_set_s(dst, str, N);
}

int	uint_set_s(CHUNK_TYPE *dst, const char *str, unsigned int N) {

	int i, b;

	CHUNK_TYPE chunk, temp;
	CHUNK_TYPE *curent;



	if (strlen(str) > CHUNK_BYTES * 2)
		return 0;


	memset(dst, 0, CHUNK_BYTES);

	b = 0;
	chunk = 0;
	curent = &dst[chunk];

	for (i = strlen(str) - 1; i >= 0; i--, b++) {

		if (b == CHUNK_SIZE * 2) {
			b = 0;
			chunk++;
			curent = &dst[chunk];
		}

		if (!is_hex(str[i]))
			return 0;

		if (str[i] < 0x61)
			temp = str[i] - 0x30;
		else
			temp = (str[i] - 0x60) + 9;

		*curent = *curent | (temp << (4 * b));
	}

	return 1;
}



char	*uint_get(const CHUNK_TYPE *src, unsigned int N) {

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

			sprintf(&str[j++], CPU_SIZE ? "%x" : "%llx", val);
		}
	}


	/* print zero */
	if (!echo)
		strcpy(str, "0");

	return str;
}



/*
int	uint_cmp(CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	CHUNK_TYPE condA, condB;
	int i;

	condA = (CHUNK_TYPE)(a[0] >= b[0]);
	condB = (CHUNK_TYPE)(a[0] <= b[0]);
	for (i = 1; i < N; i++) {
		condA |= (CHUNK_TYPE)(a[i] >= b[i]) << i;
		condB |= (CHUNK_TYPE)(a[i] <= b[i]) << i;
	}

	return memcmp(&condA, &condB, CHUNK_SIZE);
}
*/

int	uint_cmp(CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	unsigned char condA[N];
	unsigned char condB[N];
	int i;

	for (i = 0; i < N; i++) {
		condA[N-i-1] = (char)(a[i] >= b[i]);
		condB[N-i-1] = (char)(a[i] <= b[i]);
	}

	return memcmp(condA, condB, sizeof(condA));
}


int	uint_cmp_s(CHUNK_TYPE *a, const char *b, unsigned int N) {

	CHUNK_TYPE B[N];

	uint_set_s(B, b, N);
	return uint_cmp(a, B, N);
}


int	uint_cmp_u(CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N) {

	CHUNK_TYPE B[N];

	memset(B, 0, CHUNK_BYTES);
	B[0] = b;
	return uint_cmp(a, B, N);
}


int	uint_is_zero(CHUNK_TYPE *a, unsigned int N) {

	int rc = 0;

	while (N--)
		rc = rc || a[N];

	return !rc;
}
