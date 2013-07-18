#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "libuint.h"




int	main() {


	uint1024_t a, b, c;

	uint64_t x1, x2;


	set_uint1024_s(a, "2");

	uint1024_mul_s(c, a, "5");
	printf("\n      AA = %s\n", get_uint1024(c));


		
	return 0;
}



















