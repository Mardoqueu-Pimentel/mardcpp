//
// Created by mard on 10/24/19.
//

#pragma once

#include <type_traits>

namespace mardCpp {
	template<typename tBase, typename tDerived>
	using IsBaseOf = std::is_base_of<tBase, tDerived>;

	struct Streamable {};

	template<typename tType>
	struct IsStreamable : public IsBaseOf<Streamable, tType> {};
}