#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"




int	main() {


	uint128_t a, b, c;

	uint64_t x1, x2;


	set_uint128(a, "ab");

	uint128_lsh(a, 113);
	printf("A = %s\n", get_uint128(a));

	uint128_rsh(a, 64);
	printf("A = %s\n", get_uint128(a));

/*
	for (x1 = 0; x1 < 256; x1++) {
		uint256_rsh(a, 19);
		printf("A = %s\n", get_uint256(a));
	}
*/


//	x1 = ULONG_MAX >> 63;
//	printf("%lx\n", x1);

		
	return 0;
}



















