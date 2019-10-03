//
// Created by mard on 5/11/19.
//

#pragma once

#include <cstdint>
#include <cmath>

namespace mardcpp {

	inline constexpr size_t operator "" _B (unsigned long long x) {
		return x;
	}

	inline constexpr size_t operator "" _KB (unsigned long long x) {
		return x * 1024;
	}

	inline constexpr size_t operator "" _MB (unsigned long long x) {
		return x * 1024 * 1024;
	}

	inline constexpr size_t operator "" _GB (unsigned long long x) {
		return x * 1024 * 1024 * 1024;
	}

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

	using Index = size_t;
}

