#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"




int	main() {


	uint256_t a, b, c;

	uint64_t x1, x2;


	set_uint256_u(b, 0xff);
	set_uint256(a, b);
	printf("A = %s\n", get_uint256(a));

	set_uint256_s(a, UINT256_MAX);
	set_uint256_s(b, UINT256_MAX);
	uint256_add(a, a, b);
	printf("A = %s\n", get_uint256(a));

	uint256_lsh(a, 113);
	printf("LA = %s\n", get_uint256(a));

	uint256_rsh(a, 64);
	printf("RA = %s\n", get_uint256(a));

	uint256_and(a, a, b);
	printf("AA = %s\n", get_uint256(a));


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



















