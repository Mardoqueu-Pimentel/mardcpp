//
// Created by mard on 10/15/19.
//

#pragma once

#include <cmath>
#include <cstdint>
#include <string_view>

using i08 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u08 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using f32 = float_t;
using f64 = double_t;
using f80 = long double;

using sc = signed char;
using uc = unsigned char;
using ssi = signed short int;
using usi = unsigned short int;
using si = signed int;
using ui = unsigned int;
using sli = signed long int;
using uli = unsigned long int;
using slli = signed long long int;
using ulli = unsigned long long int;

using Count = size_t;
using Index = size_t;
using Size = size_t;

using Bool = bool;
using Byte = char;
using Char = char;
using Int = i32;
using Long = i64;
using UInt = u32;
using ULong = u64;
using Flt = f32;
using Dbl = f64;


inline constexpr Size operator "" _B (ulli x) {
	return x;
}

inline constexpr Size operator "" _KB (ulli x) {
	return x * 1024;
}

inline constexpr Size operator "" _MB (ulli x) {
	return x * 1024 * 1024;
}

inline constexpr Size operator "" _GB (ulli x) {
	return x * 1024 * 1024 * 1024;
}

using std::string_view_literals::operator ""sv;

using StringView = std::string_view;
