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

	uint_set_s(dst, OFFSET128, U128);
	uint_set_s(prime, PRIME128, U128);

	//printf("offset: %s\n", get_uint1024(dst));
	//printf("prime: %s\n", get_uint1024(prime));

	for (i = 0; i < size; i++) {
		uint_xor_u(dst, dst, data[i], U128);	
		uint_mul(dst, dst, prime, U128);
	}
	printf("\n   AA = %s\n", uint_get(dst, U128));
}

void	fnv_test1024(const char *data, size_t size) {

	size_t i;
	Uint1024_t prime, dst;

	uint_set_s(dst, OFFSET1024, U1024);
	uint_set_s(prime, PRIME1024, U1024);

	//printf("offset: %s\n", get_uint1024(dst));
	//printf("prime: %s\n", get_uint1024(prime));

	for (i = 0; i < size; i++) {
		uint_xor_u(dst, dst, data[i], U1024);	
		uint_mul(dst, dst, prime, U1024);
	}

	printf("\n   AA = %s\n", uint_get(dst, U1024));
}

int	main() {


	const char str[] = "Moi mecho mnogo go obi4am";
	char *bla;
	size_t size;
	int i;

	Uint128_t a, b, c;
	Uint1024_t x1, x2, x3;
	Uint64_t q, w, e;



	size = 1000000;


	bla = malloc(size);
	memset(bla, 3, size);


	fnv_test1024(bla, size);


	return 0;


}

