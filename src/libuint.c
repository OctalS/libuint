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
	uint128_t prime, dst;

	set_uint128_s(dst, OFFSET128);
	set_uint128_s(prime, PRIME128);

	//printf("offset: %s\n", get_uint1024(dst));
	//printf("prime: %s\n", get_uint1024(prime));

	for (i = 0; i < size; i++) {
		uint128_xor_u(dst, dst, data[i]);	
		uint128_mul(dst, dst, prime);
	}
	printf("\n   AA = %s\n", get_uint128(dst));
}

void	fnv_test1024(const char *data, size_t size) {

	size_t i;
	uint1024_t prime, dst;

	set_uint1024_s(dst, OFFSET1024);
	set_uint1024_s(prime, PRIME1024);

	//printf("offset: %s\n", get_uint1024(dst));
	//printf("prime: %s\n", get_uint1024(prime));

	for (i = 0; i < size; i++) {
		uint1024_xor_u(dst, dst, data[i]);	
		uint1024_mul(dst, dst, prime);
	}

	printf("\n   AA = %s\n", get_uint1024(dst));
}

int	main() {


	const char str[] = "Moi mecho mnogo go obi4am";
	char *bla;
	size_t size;
	int i;

	uint128_t a, b, c;
	uint1024_t x1, x2, x3;
	Uint64_t q, w, e;



	size = 1000000;

	bla = malloc(size);
	memset(bla, 3, size);


	fnv_test1024(bla, size);


	return 0;




	set_uint128_s(a, UINT128_MAX);
	set_uint128_s(b, UINT128_MAX);
	uint128_add(a, a, b);
	printf("\n   AA = %s\n", get_uint128(a));







/*
	set_uint1024_s(x1, "124545433");
	set_uint1024_s(x2, "43454543543435354353222323");


	uint1024_mul(x1, x1, x2);
	printf("\n   AA = %s\n", get_uint1024(x1));
*/




/*
	__set_uintN_s(q, "123", CHUNKS_64);
	__set_uintN_s(w, "123", CHUNKS_64);

	__uintN_mul(q, q, w, CHUNKS_64);



	printf("\n   AA = %s\n", __get_uintN(q, CHUNKS_64));
*/
	return 0;
}

