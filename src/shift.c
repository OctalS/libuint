#include <stdio.h>
#include "libuint.h"

void	__uintN_lsh(CHUNK_TYPE *dst, CHUNK_TYPE *src, unsigned int shift, unsigned int N) {

	unsigned int ch, b;

	ch = shift / (CHUNK_SIZE * 8);
	b = shift % (CHUNK_SIZE * 8);


	printf("ch = %i\n", ch);
	printf("b = %i\n", b);



}

void	__uintN_rsh(CHUNK_TYPE *dst, CHUNK_TYPE *src, unsigned int shift, unsigned int N) {

}
