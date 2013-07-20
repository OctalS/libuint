#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"



#define	offset 	"5f7a76758ecc4d32e56d5a591028b74b29fc4223fdada16c3bf34eda3674da9a21d9000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004c6d7eb6e73802734510a555f256cc005ae556bde8cc9c6a93b21aff4b16c71ee90b3"
#define PRIME	"10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000018d"

void	fnv_test(CHUNK_TYPE *dst, const char *data, size_t size) {

	size_t i;
	uint128_t prime;

	//set_uint128_s(dst, offset);
	//set_uint128_s(prime, PRIME);
	//
	set_uint128_s(dst, UINT128_MAX);
	set_uint128_u(prime, 12345678);

	//printf("offset: %s\n", get_uint1024(dst));
	//printf("prime: %s\n", get_uint1024(prime));

	for (i = 0; i < size; i++) {
		uint128_xor_u(dst, dst, data[i]);	
		uint128_mul(dst, dst, prime);
	}
}


int	main() {


	const char str[] = "Moi mecho mnogo go obi4am";
	char *bla;
	size_t size;

	size = 1000;

	bla = malloc(size);
	memset(bla, 3, size);

	uint128_t a, b, c;
	uint1024_t x1, x2, x3;

	int i;

	//fnv_test(a, bla, size);

	set_uint1024_s(x1, UINT1024_MAX);
	set_uint1024_s(x2, UINT1024_MAX);

	for (i = 0; i < 100; i++)
		uint1024_mul(x3, x1, x2);

	printf("\n   AA = %s\n", get_uint1024(x3));


	free(bla);
	return 0;
}

