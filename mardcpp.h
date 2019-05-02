#ifndef MARDCPP_LIBRARY_H
#define MARDCPP_LIBRARY_H

#include <cstdint>
#include <cmath>

namespace mardcpp {

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

	using Size = size_t;

	void hello();
}

#endif