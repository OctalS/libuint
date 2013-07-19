#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"



#define	offset 	"dd268dbcaac550362d98c384c4e576ccc8b1536847b6bbb31023b4c8caee0535"
#define PRIME	"1000000000000000000000000000000000000000163"

void	fnv_test(CHUNK_TYPE *dst, const char *data, size_t size) {

	size_t i;
	uint256_t prime;

	set_uint256_s(dst, offset);
	set_uint256_s(prime, PRIME);

	printf("offset: %s\n", get_uint256(dst));
	printf("prime: %s\n", get_uint256(prime));

	for (i = 0; i < size; i++) {
		uint256_xor_u(dst, dst, data[i]);	
		uint256_mul(dst, dst, prime);
	}
}


int	main() {


	uint256_t a, b, c;


	fnv_test(a, "bla", strlen("bla"));

	printf("\n   AA = %s\n", get_uint256(a));
		
	return 0;
}



















