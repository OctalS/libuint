#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"




int	main() {


	uint256_t a, b, c;

	uint64_t x1, x2;


	set_uint256(a, "ff");

	uint256_lsh(a, 255);
	printf("A = %s\n", get_uint256(a));

	uint256_rsh(a, 64);
	printf("A = %s\n", get_uint256(a));

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



















