# stdendian

stdendian.h header providing cross-platform endian macros and endian
conversion functions.

### Preprocessor macro

 This header defines endian macros referenced here:
 [http://austingroupbugs.net/view.php?id=162](http://austingroupbugs.net/view.php?id=162)

 - `BYTE_ORDER`
   - macro shall have a value equal to one of the_ENDIAN macros in this header.
 - `LITTLE_ENDIAN`
   - the host byte order is from least significant to most significant.
 - `BIG_ENDIAN`
   - the host byte order is from most significant to least significant.

### Byte-swapping functions

This header also defines several byte-swap interfaces, some that
map directly to the host byte swap intrinsics and some sensitive
to the host endian representation, performing a swap only if the
host representation differs from the chosen representation.

### Direct byte swapping interfaces

These interfaces swap the byte order of words and map to host byte
swap intrinsics.

- `uint16_t bswap16(uint16_t x);`
- `uint32_t bswap32(uint32_t x);`
- `uint64_t bswap64(uint32_t x);`

### Simplified host endian interfaces

Simplified endian sensitive interfaces designed to remove duplication.
These interfaces requires wrapping loads or stores with indication of the representation. This style has been adopted by cryptographers because it
makes code and algorithms easier to read and understand.

#### big-endian

- `uint16_t be16(uint16_t x);`
- `uint32_t be32(uint32_t x);`
- `uint64_t be64(uint32_t x);`

#### litte-endian

- `uint16_t le16(uint16_t x);`
- `uint32_t le32(uint32_t x);`
- `uint64_t le64(uint32_t x);`

### BSD host endian interfaces

Traditional BSD interface with duplication. This is the traditional
interface that has redundant directioality. It makes it more complex
to read and understand code versus simply indicating representation.
These interfaces are retained for compatibility.

#### 16-bit word

- `uint16_t htobe16(uint16_t x) { return be16(x); }`
- `uint16_t htole16(uint16_t x) { return le16(x); }`
- `uint16_t be16toh(uint16_t x) { return be16(x); }`
- `uint16_t le16toh(uint16_t x) { return le16(x); }`

#### 32-bit word

- `uint32_t htobe32(uint32_t x) { return be32(x); }`
- `uint32_t htole32(uint32_t x) { return le32(x); }`
- `uint32_t be32toh(uint32_t x) { return be32(x); }`
- `uint32_t le32toh(uint32_t x) { return le32(x); }`

#### 64-bit word

- `uint64_t htobe64(uint32_t x) { return be64(x); }`
- `uint64_t htole64(uint32_t x) { return le64(x); }`
- `uint64_t be64toh(uint32_t x) { return be64(x); }`
- `uint64_t le64toh(uint32_t x) { return le64(x); }`
