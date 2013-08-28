#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"


#define	OFFSET1024 	"5f7a76758ecc4d32e56d5a591028b74b29fc4223fdada16c3bf34eda3674da9a21d9000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004c6d7eb6e73802734510a555f256cc005ae556bde8cc9c6a93b21aff4b16c71ee90b3"

#define PRIME1024	"10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000018d"

#define PRIME128	"1000000000000000000013b"
#define OFFSET128	"6c62272e07bb014262b821756295c58d"

void	fnv_test128(const char *data, size_t size) {

	size_t i;
	Uint128_t prime, dst;

	u_set_s(dst, OFFSET128);
	u_set_s(prime, PRIME128);

	for (i = 0; i < size; i++) {
		u_xor_u(dst, dst, data[i]);	
		u_mul(dst, dst, prime);
	}
	printf("\nFNV 128 = %s\n", u_get(dst));
}

void	fnv_test1024(const char *data, size_t size) {

	size_t i;
	Uint1024_t prime, dst;

	u_set_s(dst, OFFSET1024);
	u_set_s(prime, PRIME1024);

	for (i = 0; i < size; i++) {
		u_xor_u(dst, dst, data[i]);	
		u_mul(dst, dst, prime);
	}
	printf("\nFNV 1024 = %s\n", u_get(dst));
}



int	main() {


	Uint256_t test;

	u_set_s(test, UINT256_MAX);
	u_add_u(test, test, 1);
	printf("%s\n", u_get(test));


	printf("Running with libuint version: %s\n", u_version(0));

	int size = 1000000;
	char *buf = malloc(size);

	memset(buf, 3, size);

	printf("\nComputing 128 bit fnv hash from buffer with size %i\n", size);
	fnv_test128(buf, size);

	printf("\nComputing 1024 bit fnv hash from buffer with size %i\n", size);
	fnv_test1024(buf, size);
	
	free(buf);
	return 0;


}

