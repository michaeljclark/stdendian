#undef NDEBUG
#include <assert.h>
#include <stdio.h>

#include "stdendian.h"

void test_u16()
{
	assert(bswap16(0x0102ull) == 0x0201ull);
#if BYTE_ORDER == BIG_ENDIAN
	assert(le16(0x0102ull) == 0x0201ull);
	assert(be16(0x0102ull) == 0x0102ull);
#elif BYTE_ORDER == LITTLE_ENDIAN
	assert(le16(0x0102ull) == 0x0102ull);
	assert(be16(0x0102ull) == 0x0201ull);
#endif
}

void test_u32()
{
	assert(bswap32(0x01020304ull) == 0x04030201ull);
#if BYTE_ORDER == BIG_ENDIAN
	assert(le32(0x01020304ull) == 0x04030201ull);
	assert(be32(0x01020304ull) == 0x01020304ull);
#elif BYTE_ORDER == LITTLE_ENDIAN
	assert(le32(0x01020304ull) == 0x01020304ull);
	assert(be32(0x01020304ull) == 0x04030201ull);
#endif
}

void test_u64()
{
	assert(bswap64(0x0102030405060708ull) == 0x0807060504030201ull);
#if BYTE_ORDER == BIG_ENDIAN
	assert(le64(0x0102030405060708ull) == 0x0807060504030201ull);
	assert(be64(0x0102030405060708ull) == 0x0102030405060708ull);
#elif BYTE_ORDER == LITTLE_ENDIAN
	assert(le64(0x0102030405060708ull) == 0x0102030405060708ull);
	assert(be64(0x0102030405060708ull) == 0x0807060504030201ull);
#endif
}

int main()
{
	test_u16();
	test_u32();
	test_u64();
}