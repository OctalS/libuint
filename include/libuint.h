#ifndef LIBUINT_H
#define LIBUINT

#include <stdint.h>

#define CHUNK_TYPE	uint64_t

#define CHUNK_SIZE	sizeof(CHUNK_TYPE)

#define CHUNK_BITS	(CHUNK_SIZE * 8)

#define TOTAL_BITS	(CHUNK_BITS * N)

/*                                        n * 32bit entries | n * 64bit entries
                                          -------------------------------------*/
#define CHUNKS_128	(CHUNK_SIZE % 8 ?       4           :        2)
#define CHUNKS_256	(CHUNK_SIZE % 8 ?       8           :        4)
#define CHUNKS_1024	(CHUNK_SIZE % 8 ?       16          :        8)

typedef CHUNK_TYPE	uint128_t[CHUNKS_128];
typedef CHUNK_TYPE	uint256_t[CHUNKS_256];
typedef CHUNK_TYPE	uint1024_t[CHUNKS_1024];



#define	UINT_MAX_BITLEN		CHUNK_SIZE * CHUNKS_1024 * 2
#define	UINT_MAX_STR		UINT_MAX_BITLEN + 1
	

#define	UINT128_MAX	"ffffffffffffffffffffffffffffffff"
#define	UINT256_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
#define	UINT1024_MAX	"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"




#define	uint128_or(D, A, B)		__uintN_or(D, A, B, CHUNKS_128)
#define	uint256_or(D, A, B)		__uintN_or(D, A, B, CHUNKS_256)
#define	uint1024_or(D, A, B)		__uintN_or(D, A, B, CHUNKS_1024)

#define	uint128_or_s(D, A, B)		__uintN_or_s(D, A, B, CHUNKS_128)
#define	uint256_or_s(D, A, B)		__uintN_or_s(D, A, B, CHUNKS_256)
#define	uint1024_or_s(D, A, B)		__uintN_or_s(D, A, B, CHUNKS_1024)

#define	uint128_or_u(D, A, B)		__uintN_or_u(D, A, B, CHUNKS_128)
#define	uint256_or_u(D, A, B)		__uintN_or_u(D, A, B, CHUNKS_256)
#define	uint1024_or_u(D, A, B)		__uintN_or_u(D, A, B, CHUNKS_1024)

#define	uint128_xor(D, A, B)		__uintN_xor(D, A, B, CHUNKS_128)
#define	uint256_xor(D, A, B)		__uintN_xor(D, A, B, CHUNKS_256)
#define	uint1024_xor(D, A, B)		__uintN_xor(D, A, B, CHUNKS_1024)

#define	uint128_xor_s(D, A, B)		__uintN_xor_s(D, A, B, CHUNKS_128)
#define	uint256_xor_s(D, A, B)		__uintN_xor_s(D, A, B, CHUNKS_256)
#define	uint1024_xor_s(D, A, B)		__uintN_xor_s(D, A, B, CHUNKS_1024)

#define	uint128_xor_u(D, A, B)		__uintN_xor_u(D, A, B, CHUNKS_128)
#define	uint256_xor_u(D, A, B)		__uintN_xor_u(D, A, B, CHUNKS_256)
#define	uint1024_xor_u(D, A, B)		__uintN_xor_u(D, A, B, CHUNKS_1024)

#define	uint128_and(D, A, B)		__uintN_and(D, A, B, CHUNKS_128)
#define	uint256_and(D, A, B)		__uintN_and(D, A, B, CHUNKS_256)
#define	uint1024_and(D, A, B)		__uintN_and(D, A, B, CHUNKS_1024)

#define	uint128_and_s(D, A, B)		__uintN_and_s(D, A, B, CHUNKS_128)
#define	uint256_and_s(D, A, B)		__uintN_and_s(D, A, B, CHUNKS_256)
#define	uint1024_and_s(D, A, B)		__uintN_and_s(D, A, B, CHUNKS_1024)

#define	uint128_and_u(D, A, B)		__uintN_and_u(D, A, B, CHUNKS_128)
#define	uint256_and_u(D, A, B)		__uintN_and_u(D, A, B, CHUNKS_256)
#define	uint1024_and_u(D, A, B)		__uintN_and_u(D, A, B, CHUNKS_1024)

#define	uint128_lsh(D, A)		__uintN_lsh(D, A, CHUNKS_128)
#define	uint256_lsh(D, A)		__uintN_lsh(D, A, CHUNKS_256)
#define	uint1024_lsh(D, A)		__uintN_lsh(D, A, CHUNKS_1024)

#define	uint128_rsh(D, A)		__uintN_rsh(D, A, CHUNKS_128)
#define	uint256_rsh(D, A)		__uintN_rsh(D, A, CHUNKS_256)
#define	uint1024_rsh(D, A)		__uintN_rsh(D, A, CHUNKS_1024)


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


#define	uint128_mul(D, A, B)		__uintN_mul(D, A, B, CHUNKS_128)
#define	uint256_mul(D, A, B)		__uintN_mul(D, A, B, CHUNKS_256)
#define	uint1024_mul(D, A, B)		__uintN_mul(D, A, B, CHUNKS_1024)

#define	uint128_mul_s(D, A, B)		__uintN_mul_s(D, A, B, CHUNKS_128)
#define	uint256_mul_s(D, A, B)		__uintN_mul_s(D, A, B, CHUNKS_256)
#define	uint1024_mul_s(D, A, B)		__uintN_mul_s(D, A, B, CHUNKS_1024)

#define	uint128_mul_u(D, A, B)		__uintN_mul_u(D, A, B, CHUNKS_128)
#define	uint256_mul_u(D, A, B)		__uintN_mul_u(D, A, B, CHUNKS_256)
#define	uint1024_mul_u(D, A, B)		__uintN_mul_u(D, A, B, CHUNKS_1024)

#define	set_uint128(D, S)	__set_uintN(D, S, CHUNKS_128)
#define	set_uint256(D, S)	__set_uintN(D, S, CHUNKS_256)
#define	set_uint1024(D, S)	__set_uintN(D, S, CHUNKS_1024)

#define	set_uint128_s(D, S)	__set_uintN_s(D, S, CHUNKS_128)
#define	set_uint256_s(D, S)	__set_uintN_s(D, S, CHUNKS_256)
#define	set_uint1024_s(D, S)	__set_uintN_s(D, S, CHUNKS_1024)

#define	set_uint128_u(D, S)	__set_uintN_u(D, S, CHUNKS_128)
#define	set_uint256_u(D, S)	__set_uintN_u(D, S, CHUNKS_256)
#define	set_uint1024_u(D, S)	__set_uintN_u(D, S, CHUNKS_1024)

#define	get_uint128(S)		__get_uintN(S, CHUNKS_128)
#define	get_uint256(S)		__get_uintN(S, CHUNKS_256)
#define	get_uint1024(S)		__get_uintN(S, CHUNKS_1024)







extern	void	__uintN_or(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);
extern	void	__uintN_or_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);
extern	void	__uintN_or_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);

extern	void	__uintN_xor(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);
extern	void	__uintN_xor_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);
extern	void	__uintN_xor_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);

extern	void	__uintN_and(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);
extern	void	__uintN_and_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);
extern	void	__uintN_and_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);

extern	void    __uintN_lsh(CHUNK_TYPE *dst, unsigned int shift, unsigned int N);

extern	void    __uintN_rsh(CHUNK_TYPE *dst, unsigned int shift, unsigned int N);


extern	void	__uintN_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);
extern	void	__uintN_add_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);
extern	void	__uintN_add_ss(CHUNK_TYPE *dst, const char *a, const char *b, unsigned int N);
extern	void	__uintN_add_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);


extern	void	__uintN_mul(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);
extern	void	__uintN_mul_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);
extern	void	__uintN_mul_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);


extern	int	__set_uintN(CHUNK_TYPE *dst, CHUNK_TYPE *src, unsigned int N);
extern	int	__set_uintN_s(CHUNK_TYPE *dst, const char *str, unsigned int N);
extern	int	__set_uintN_u(CHUNK_TYPE *dst, CHUNK_TYPE src, unsigned int N);

extern	char	*__get_uintN(const CHUNK_TYPE *src, unsigned int N);


#endif

