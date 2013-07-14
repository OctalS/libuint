#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"




int	main() {


	uint256_t a, b, c;

	uint64_t x1, x2;

	set_uint256(a, "3543543543534454353453453452352142142");
	set_uint256(b, "30888534049580349580439580943503485034534052354353958340");

	printf("a = %s\n", get_uint256(a));
	printf("b = %s\n", get_uint256(b));
	uint256_add(c, a, b);

	printf("c = %s\n", get_uint256(c));

	x1 = 0x123456789abcd;
	x2 = 0xffff;

	printf("\nt = %lx\n", x1 + x2); 



		
	return 0;
}



















