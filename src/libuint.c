#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#define CHUNK_TYPE	uint64_t

#define CHUNK_SIZE	sizeof(CHUNK_TYPE)

/*                                        n * 32bit entries | n * 64bit entries
                                          -------------------------------------*/
#define CHUNKS_128	(CHUNK_SIZE % 8 ?       4           :        2)
#define CHUNKS_256	(CHUNK_SIZE % 8 ?       8           :        4)
#define CHUNKS_1024	(CHUNK_SIZE % 8 ?       16          :        8)

#define	UINT_MAX_BITLEN	CHUNK_SIZE * CHUNKS_1024 * 2

typedef CHUNK_TYPE	uint128_t[CHUNKS_128];
typedef CHUNK_TYPE	uint256_t[CHUNKS_256];
	

#define	UINT128_MAX	"ffffffffffffffffffffffffffffffff"
#define	UINT256_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
#define	UINT1024_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"

#define	uint128_add(D, A, B)	uintN_add(D, A, B, CHUNKS_128)
#define	uint256_add(D, A, B)	uintN_add(D, A, B, CHUNKS_256)

int	uintN_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N) {

	CHUNK_TYPE i, chunk;
	CHUNK_TYPE x, x1, x2, c, result;

	c = 0;
	x = 0;

	memset(dst, 0, N * CHUNK_SIZE);

	for (chunk = 0; chunk < N; chunk++) { 
		for (i = 0; i < CHUNK_SIZE * 8; i++) {
			x1 = (a[chunk] >> i) & 1;
			x2 = (b[chunk] >> i) & 1;
			switch (x1 + x2 + c) {
				case 0:
					x = 0;
					c = 0;
					break;
				case 1:
					x = 1;
					c = 0;
					break;
				case 2:
					x = 0;
					c = 1;
					break;
				case 3:
					x = 1;
					c = 1;
					break;
			}
	
			dst[chunk] |= x << i;
	
		}

	}

	return 0;
}


#define	set_uint128(D, S)	set_uintN(D, S, CHUNKS_128)
#define	set_uint256(D, S)	set_uintN(D, S, CHUNKS_256)

int	set_uintN(CHUNK_TYPE *dst, const char *str, unsigned int N) {

	int i, b;

	CHUNK_TYPE chunk, temp;
	CHUNK_TYPE *curent;



	if (strlen(str) > CHUNK_SIZE * N * 2)
		return 0;


	memset(dst, 0, N * CHUNK_SIZE);

	b = 0;
	chunk = 0;
	curent = &dst[chunk];

	for (i = strlen(str) - 1; i >= 0; i--, b++) {

		if (b == CHUNK_SIZE * 2) {
			b = 0;
			chunk++;
			curent = &dst[chunk];
		}

		if (str[i] < 0x61)
			temp = str[i] - 0x30;
		else
			temp = (str[i] - 0x60) + 9;

		*curent = *curent | (temp << (4 * b));
	}

}



#define	get_uint128(S)		get_uintN(S, CHUNKS_128)
#define	get_uint256(S)		get_uintN(S, CHUNKS_256)

#define	UINT_MAX_STR		UINT_MAX_BITLEN + 1

char	*get_uintN(const CHUNK_TYPE *src, unsigned int N) {

	long chunk, i, j;
	CHUNK_TYPE val;
	int echo;


	static char str[UINT_MAX_STR];

	memset(str, 0, UINT_MAX_STR);
	j = 0;
	val = 0;
	echo = 0;

	for (chunk = N-1; chunk >= 0; chunk--) {
		for (i = CHUNK_SIZE * 8 - 4 ; i >= 0; i -= 4) {
			val = (src[chunk] >> i) & 0xf;
			if (!val && !echo) {
				continue;
			} else {
				echo = 1;
			}

			sprintf(&str[j++], "%x", val);
		}
	}


	/* print zero */
	if (!echo)
		strcpy(str, "0");

	return str;
}


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



















/*
char* Bin64ToDec(const uint32_t N[2])
{
  static char s[64 / 3 + 1 + 1];
  uint32_t n[2];
  char* p = s;
  int i;

  memset(s, '0', sizeof(s) - 1);
  s[sizeof(s) - 1] = '\0';

  memcpy(n, N, sizeof(n));

  for (i = 0; i < 64; i++)
  {
    int j, carry;

    carry = (n[1] >= 0x80000000);

    n[1] = ((n[1] << 1) & 0xFFFFFFFF) + (n[0] >= 0x80000000);
    n[0] = ((n[0] << 1) & 0xFFFFFFFF);

    for (j = sizeof(s) - 2; j >= 0; j--)
    {
      s[j] += s[j] - '0' + carry;

      carry = (s[j] > '9');

      if (carry)
      {
        s[j] -= 10;
      }
    }
  }

  while ((p[0] == '0') && (p < &s[sizeof(s) - 2]))
  {
    p++;
  }

  return p;
}
*/
