#ifndef GUARD_SANDBOXTYPES_H
#define GUARD_SANDBOXTYPES_H

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using float32 = float;
using float64 = double;

using usize = std::size_t;
using isize = std::ptrdiff_t;

using byte = unsigned char;
using uchar = unsigned char;
using ushort = unsigned short;
using uint = unsigned int;
using ulong = unsigned long;
using ullong = unsigned long long;

using wchar = wchar_t;
using char16 = char16_t;
using char32 = char32_t;

using vint8 = volatile int8;
using vint16 = volatile int16;
using vint32 = volatile int32;
using vint64 = volatile int64;

using vuint8 = volatile uint8;
using vuint16 = volatile uint16;
using vuint32 = volatile uint32;
using vuint64 = volatile uint64;

using vfloat32 = volatile float32;
using vfloat64 = volatile float64;

#endif // !GUARD_SANDBOXTYPES_H
