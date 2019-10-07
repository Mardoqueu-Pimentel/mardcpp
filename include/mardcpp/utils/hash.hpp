//
// Created by mard on 10/7/19.
//

#pragma once

#include <mardcpp/mardcpp.hpp>
#include <mardcpp/utils/util.hpp>

namespace mc {

struct primes {

	static constexpr Size _2p13m001 = 0x1FFF;
	static constexpr Size _2p17m001 = 0x1FFFF;
	static constexpr Size _2p19m001 = 0x7FFFF;
	static constexpr Size _2p31m001 = 0x7FFFFFFF;
	static constexpr Size _2p61m001 = 0x1FFFFFFFFFFFFFFF;

	static constexpr Size _2p32m005 = 0xFFFFFFFB;
	static constexpr Size _2p64m591 = 0xFFFFFFFFFFFFFFC5;

};

bool isPrime(Size n) noexcept;

Size nextPrimeOf(Size n);

inline void hashItImplHelper(Size &seed, const void *mem, Size size) {
	auto * __restrict values = static_cast<const unsigned char *>(mem);
	for (Size i = 0; i < size; ++i) {
		seed = values[i] + (seed * 0x7fffffff);
//			seed = ((seed << 5U) + seed) + values[i];
	}
}

template<typename ... Ts, Size ... N>
inline Size hashItImpl(const Ts &...ts, std::index_sequence<N...>) {
	Size result = 5381;
	((hashItImplHelper(result, (const char *) &ts, sizeof(Ts))), ...);
	return result;
}

template<typename ... Ts, typename Indexes = std::make_index_sequence<sizeof ... (Ts)>>
inline Size hashIt(const Ts& ... ts) {
	return hashItImpl<Ts...>(ts..., Indexes());
}

}