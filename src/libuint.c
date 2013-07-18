#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"




int	main() {


	uint256_t a, b, c;

	uint64_t x1, x2;

	set_uint256(a, "5");
	set_uint256(b, "5");

	//printf("a = %s\n", get_uint256(a));
	//printf("b = %s\n", get_uint256(b));
	uint256_add_u(c, a, 5);

	printf("c = %s\n", get_uint256(c));

	x1 = 0x20;
	x2 = 0x324f;

	printf("\nt = %lx\n", x1 * x2); 


	set_uint256(a, "f");
	uint256_lsh(a, 199);
	printf("A = %s\n", get_uint256(a));
/*
	for (x1 = 1; x1 < 256; x1++) {
		uint256_lsh(a, 2);
		printf("A = %s\n", get_uint256(a));
	}
*/

	x1 = 1ULL << 63;
	printf("%lx\n", x1);
	x1 <<= 2;
	printf("%lx\n", x1);

		
	return 0;
}



















