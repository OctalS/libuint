#ifndef LIBUINT_H
#define LIBUINT

#include <stdint.h>

#define CHUNK_TYPE	uint64_t

#define CHUNK_SIZE	sizeof(CHUNK_TYPE)

#define CHUNK_BITS	(CHUNK_SIZE * 8)

#define CHUNK_BYTES	(CHUNK_SIZE * N)

#define TOTAL_BITS	(CHUNK_BITS * N)

#define	CPU_SIZE	CHUNK_SIZE == 4


/*				  n * 32bit entries | n * 64bit entries
				  -------------------------------------*/
#define U64		(CPU_SIZE ?	2           :        1)
#define U128		(CPU_SIZE ?	4           :        2)
#define U256		(CPU_SIZE ?	8           :        4)
#define U512		(CPU_SIZE ?	16          :        8)
#define U1024		(CPU_SIZE ?	32          :        16)

typedef CHUNK_TYPE	Uint64_t[U64];
typedef CHUNK_TYPE	Uint128_t[U128];
typedef CHUNK_TYPE	Uint256_t[U256];
typedef CHUNK_TYPE	Uint1024_t[U1024];



#define	UINT_MAX_BITLEN		CHUNK_SIZE * U1024 * 2
#define	UINT_MAX_STR		UINT_MAX_BITLEN + 1
	

#define	UINT128_MAX	"ffffffffffffffffffffffffffffffff"
#define	UINT256_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
#define	UINT512_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
#define UINT1024_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"




extern	void		uint_or(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);




extern	void		uint_or_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);




extern	void		uint_or_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);




extern	void		uint_xor(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);




extern	void		uint_xor_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);




extern	void		uint_xor_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);




extern	void		uint_and(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);




extern	void		uint_and_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);



extern	void		uint_and_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);





extern	void    	uint_shl(CHUNK_TYPE *dst, unsigned int shift, unsigned int N);




extern	void		uint_shr(CHUNK_TYPE *dst, unsigned int shift, unsigned int N);




extern	void		uint_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);



extern	void		uint_add_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);



extern	void		uint_add_ss(CHUNK_TYPE *dst, const char *a, const char *b, unsigned int N);


extern	void		uint_add_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



extern	void		uint_sub(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);


extern	void		uint_sub_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);


extern	void		uint_sub_ss(CHUNK_TYPE *dst, const char *a, const char *b, unsigned int N);


extern	void		uint_sub_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



extern	void		uint_mul(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);



extern	void		uint_mul_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);



extern	void		uint_mul_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



extern	void		uint_div(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);


extern	void		uint_div_s(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, const char *b, unsigned int N);


extern	void		uint_div_u(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



extern	int		uint_set(CHUNK_TYPE *dst, CHUNK_TYPE *src, unsigned int N);



extern	int		uint_set_s(CHUNK_TYPE *dst, const char *str, unsigned int N);



extern	int		uint_set_u(CHUNK_TYPE *dst, CHUNK_TYPE src, unsigned int N);



extern	char		*uint_get(const CHUNK_TYPE *src, unsigned int N);



extern	int		uint_cmp(CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);


extern	int		uint_get_bit(CHUNK_TYPE *src, int bit);


extern	void		uint_set_bit(CHUNK_TYPE *dst, int bit);

#endif

