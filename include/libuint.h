#ifndef LIBUINT_H
#define LIBUINT

#include <stdint.h>

#define CHUNK_TYPE	uint64_t

#define CHUNK_SIZE	sizeof(CHUNK_TYPE)

/*                                        n * 32bit entries | n * 64bit entries
                                          -------------------------------------*/
#define CHUNKS_128	(CHUNK_SIZE % 8 ?       4           :        2)
#define CHUNKS_256	(CHUNK_SIZE % 8 ?       8           :        4)
#define CHUNKS_1024	(CHUNK_SIZE % 8 ?       16          :        8)

typedef CHUNK_TYPE	uint128_t[CHUNKS_128];
typedef CHUNK_TYPE	uint256_t[CHUNKS_256];
typedef CHUNK_TYPE	uint1024_t[CHUNKS_1024];



#define	UINT_MAX_STR		UINT_MAX_BITLEN + 1
#define	UINT_MAX_BITLEN		CHUNK_SIZE * CHUNKS_1024 * 2
	

#define	UINT128_MAX	"ffffffffffffffffffffffffffffffff"
#define	UINT256_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
#define	UINT1024_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"




#define	uint128_add(D, A, B)		__uintN_add(D, A, B, CHUNKS_128)
#define	uint256_add(D, A, B)		__uintN_add(D, A, B, CHUNKS_256)
#define	uint1024_add(D, A, B)		__uintN_add(D, A, B, CHUNKS_1024)

#define	uint128_add_s(D, A, B)		__uintN_add_s(D, A, B, CHUNKS_128)
#define	uint256_add_s(D, A, B)		__uintN_add_s(D, A, B, CHUNKS_256)
#define	uint1024_add_s(D, A, B)		__uintN_add_s(D, A, B, CHUNKS_1024)

#define	uint128_add_ss(D, A, B)		__uintN_add_ss(D, A, B, CHUNKS_128)
#define	uint256_add_ss(D, A, B)		__uintN_add_ss(D, A, B, CHUNKS_256)
#define	uint1024_add_ss(D, A, B)	__uintN_add_ss(D, A, B, CHUNKS_1024)

#define	uint128_add_u(D, A, B)		__uintN_add_u(D, A, B, CHUNKS_128)
#define	uint256_add_u(D, A, B)		__uintN_add_u(D, A, B, CHUNKS_256)
#define	uint1024_add_u(D, A, B)		__uintN_add_u(D, A, B, CHUNKS_1024)

#define	uint128_lsh(D, A, B)		__uintN_lsh(D, A, B, CHUNKS_128)
#define	uint256_lsh(D, A, B)		__uintN_lsh(D, A, B, CHUNKS_256)
#define	uint1024_lsh(D, A, B)		__uintN_lsh(D, A, B, CHUNKS_1024)

#define	uint128_mul(D, A, B)		__uintN_mul(D, A, B, CHUNKS_128)
#define	uint256_mul(D, A, B)		__uintN_mul(D, A, B, CHUNKS_256)
#define	uint1024_mul(D, A, B)		__uintN_mul(D, A, B, CHUNKS_1024)



#define	set_uint128(D, S)	__set_uintN(D, S, CHUNKS_128)
#define	set_uint256(D, S)	__set_uintN(D, S, CHUNKS_256)
#define	set_uint1024(D, S)	__set_uintN(D, S, CHUNKS_1024)

#define	get_uint128(S)		__get_uintN(S, CHUNKS_128)
#define	get_uint256(S)		__get_uintN(S, CHUNKS_256)
#define	get_uint1024(S)		__get_uintN(S, CHUNKS_1024)


extern	void	__uintN_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);

extern	void	__uintN_add_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);

extern	void	__uintN_add_ss(CHUNK_TYPE *dst, const char *a, const char *b, unsigned int N);

extern	void	__uintN_add_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);

extern	void	__uintN_mul(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);

extern	int	__set_uintN(CHUNK_TYPE *dst, const char *str, unsigned int N);

extern	char	*__get_uintN(const CHUNK_TYPE *src, unsigned int N);

extern	void    __uintN_lsh(CHUNK_TYPE *dst, CHUNK_TYPE *src, unsigned int shift, unsigned int N);

#endif

