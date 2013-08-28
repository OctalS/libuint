#ifndef LIBUINT_H
#define LIBUINT

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

//		Version

#define LIBUINT_VERSION_MAJOR     1   
#define LIBUINT_VERSION_MINOR     0   

/* version control macros */
#define LIBUINT_TO_STRING(s)      #s  
#define LIBUINT_VERSION_NUM       LIBUINT_VERSION(LIBUINT_VERSION_MAJOR, LIBUINT_VERSION_MINOR)
#define LIBUINT_VERSION_DOT(a, b) a.b 

#define LIBUINT_VERSION(a, b)     (a << 8 | b)    
#define LIBUINT_VERSION_STR       LIBUINT_VERSION_DOT(LIBUINT_VERSION_MAJOR, LIBUINT_VERSION_MINOR)
#define LIBUINT_VERSION_STRING(a) LIBUINT_TO_STRING(a)



//		CPU size check

#if ULONG_MAX == 4294967295UL || defined (LIBUINT_BIT32)

  #define CHUNK_TYPE    uint32_t
  #ifdef LIBUINT_BIT_WARNING
    #warning      Compiling libuint for 32bit
  #endif

#elif ULONG_MAX == 18446744073709551615UL || defined (LIBUINT_BIT64)

  #define CHUNK_TYPE    uint64_t
  #ifdef LIBUINT_BIT_WARNING
    #warning      Compiling libuint for 64bit
  #endif

#else

  #ifdef LIBUINT_BIT_WARNING
    #warning      Cannot determine CPU size. Please define LIBUINT_BIT32 or LIBUINT_BIT64
    #warning      Compiling libuint for 32bit
  #endif

  #define CHUNK_TYPE    uint32_t

#endif


//		Types and Sizes

#define CHUNK_SIZE	sizeof(CHUNK_TYPE)
#define CHUNK_BITS	(CHUNK_SIZE * 8)
#define CHUNK_BYTES	(CHUNK_SIZE * N)
#define TOTAL_BITS	(CHUNK_BITS * N)
#define	CPU_SIZE	CHUNK_SIZE == sizeof(uint32_t)

#define uint_val(bits)			((bits / 8) / CHUNK_SIZE)
#define	uint_create(type_name, size)	typedef	CHUNK_TYPE	type_name[size]
#define uint_var_size(var)		(sizeof(var) / CHUNK_SIZE)

#define U64		uint_val(64)
#define U128		uint_val(128)
#define U256		uint_val(256)
#define U512		uint_val(512)
#define U1024		uint_val(1024)
#define U2048		uint_val(2048)
#define UMAX		U2048

uint_create(Uint64_t, U64);
uint_create(Uint128_t, U128);
uint_create(Uint256_t, U256);
uint_create(Uint512_t, U512);
uint_create(Uint1024_t, U1024);
uint_create(Uint2048_t, U2048);




//		Limits

#define U64_MAX		"ffffffffffffffff"
#define	U128_MAX	U64_MAX U64_MAX
#define	U256_MAX	U128_MAX U128_MAX
#define	U512_MAX	U256_MAX U256_MAX
#define U1024_MAX	U512_MAX U512_MAX
#define U2048_MAX	U1024_MAX U1024_MAX

#define	UINT_MAX_BITLEN		CHUNK_SIZE * UMAX * 2
#define	UINT_MAX_STR		UINT_MAX_BITLEN + 1


//		Function Prototypes

/* Checks for libuint version.
*
*  req_version - requiered version to check. Use macro LIBUINT_VERSION(major,minor)
*                passing 0 will make it return the current verion
*
* Return:
*       version string or NULL if req_version > current versio */

#define	u_version(req_ver)	uint_version(req_ver)
const static inline char	*uint_version(int req_ver) {

        if (!req_ver || req_ver <= LIBUINT_VERSION_NUM)
                return LIBUINT_VERSION_STRING(LIBUINT_VERSION_STR);

        return NULL;
}



#define u_or(dst, a, b)		uint_or(dst, a, b, uint_var_size(dst))
extern	void			uint_or(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);



#define u_or_s(dst, a, b)	uint_or_s(dst, a, b, uint_var_size(dst))
extern	void			uint_or_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);



#define u_or_u(dst, a, b)	uint_or_u(dst, a, b, uint_var_size(dst))
extern	void			uint_or_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



#define	u_xor(dst, a, b)	uint_xor(dst, a, b, uint_var_size(dst))
extern	void			uint_xor(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);



#define	u_xor_s(dst, a, b)	uint_xor_s(dst, a, b, uint_var_size(dst))
extern	void			uint_xor_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);



#define u_xor_u(dst, a, b)	uint_xor_u(dst, a, b, uint_var_size(dst))
extern	void			uint_xor_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



#define	u_and(dst, a, b)	uint_and(dst, a, b, uint_var_size(dst))
extern	void			uint_and(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);



#define	u_and_s(dst, a, b)	uint_and_s(dst, a, b, uint_var_size(dst))
extern	void			uint_and_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);



#define	u_and_u(dst, a, b)	uint_and_u(dst, a, b, uint_var_size(dst))
extern	void			uint_and_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



#define	u_shl(dst, a)		uint_shl(dst, a, uint_var_size(dst))
extern	void			uint_shl(CHUNK_TYPE *dst, unsigned int shift, unsigned int N);



#define	u_shr(dst, a)		uint_shr(dst, a, uint_var_size(dst))
extern	void			uint_shr(CHUNK_TYPE *dst, unsigned int shift, unsigned int N);



#define	u_add(dst, a, b)	uint_add(dst, a, b, uint_var_size(dst))
extern	void			uint_add(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);



#define	u_add_s(dst, a, b)	uint_add_s(dst, a, b, uint_var_size(dst))
extern	void			uint_add_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);



#define	u_add_ss(dst, a, b)	uint_add_ss(dst, a, b, uint_var_size(dst))
extern	void			uint_add_ss(CHUNK_TYPE *dst, const char *a, const char *b, unsigned int N);



#define	u_add_u(dst, a, b)	uint_add_u(dst, a, b, uint_var_size(dst))
extern	void			uint_add_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



#define	u_sub(dst, a, b)	uint_sub(dst, a, b, uint_var_size(dst))
extern	void			uint_sub(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);


#define	u_sub_s(dst, a, b)	uint_sub_s(dst, a, b, uint_var_size(dst))
extern	void			uint_sub_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);


#define	u_sub_ss(dst, a, b)	uint_sub_ss(dst, a, b, uint_var_size(dst))
extern	void			uint_sub_ss(CHUNK_TYPE *dst, const char *a, const char *b, unsigned int N);


#define	u_sub_u(dst, a, b)	uint_sub_u(dst, a, b, uint_var_size(dst))
extern	void			uint_sub_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



#define	u_mul(dst, a, b)	uint_mul(dst, a, b, uint_var_size(dst))
extern	void			uint_mul(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);



#define	u_mul_s(dst, a, b)	uint_mul_s(dst, a, b, uint_var_size(dst))
extern	void			uint_mul_s(CHUNK_TYPE *dst, CHUNK_TYPE *a, const char *b, unsigned int N);



#define	u_mul_u(dst, a, b)	uint_mul_u(dst, a, b, uint_var_size(dst))
extern	void			uint_mul_u(CHUNK_TYPE *dst, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



#define	u_div(q, r, a, b)	uint_div(q, r, a, b, uint_var_size(q))
extern	void			uint_div(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);


#define	u_div_s(q, r, a, b)	uint_div_s(q, r, a, b, uint_var_size(q))
extern	void			uint_div_s(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, const char *b, unsigned int N);


#define	u_div_u(q, r, a, b)	uint_div_u(q, r, a, b, uint_var_size(q))
extern	void			uint_div_u(CHUNK_TYPE *q, CHUNK_TYPE *r, CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);



#define u_set(dst, src)		uint_set(dst, src, uint_var_size(dst))
extern	int			uint_set(CHUNK_TYPE *dst, CHUNK_TYPE *src, unsigned int N);



#define u_set_s(dst, str)	uint_set_s(dst, str, uint_var_size(dst))
extern	int			uint_set_s(CHUNK_TYPE *dst, const char *str, unsigned int N);



#define u_set_u(dst, str)	uint_set_u(dst, str, uint_var_size(dst))
extern	int			uint_set_u(CHUNK_TYPE *dst, CHUNK_TYPE src, unsigned int N);



#define u_get(src)		uint_get(src, uint_var_size(src))
extern	char			*uint_get(const CHUNK_TYPE *src, unsigned int N);


#define	u_cmp(a, b)		u_cmp(a, b, uint_var_size(a)))
extern	int			uint_cmp(CHUNK_TYPE *a, CHUNK_TYPE *b, unsigned int N);


#define	u_cmp_s(a, b)		u_cmp_s(a, b, uint_var_size(a)))
extern	int			uint_cmp_s(CHUNK_TYPE *a, const char *b, unsigned int N);


#define	u_cmp_u(a, b)		u_cmp_u(a, b, uint_var_size(a)))
extern	int			uint_cmp_u(CHUNK_TYPE *a, CHUNK_TYPE b, unsigned int N);


#define	u_getbit(src, bit)	uint_get_bit(src, bit)
extern	int			uint_get_bit(CHUNK_TYPE *src, int bit);


#define	u_setbit(dst, bit)	uint_set_bit(dst, bit)
extern	void			uint_set_bit(CHUNK_TYPE *dst, int bit);


#define	u_is_zero(a)		uint_is_zero(a, uint_var_size(a))
extern	int			uint_is_zero(CHUNK_TYPE *a, unsigned int N);

#endif

