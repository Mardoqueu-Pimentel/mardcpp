//
// Created by mard on 6/15/19.
//

#pragma once

#include <unordered_set>
#include <mardcpp/def.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mardCpp {

	using outputStream::OutputStream;

	template<typename tType>
	using UnorderedSet = std::unordered_set<tType>;

	template<typename tType>
	OutputStream& operator<<(OutputStream& os, const UnorderedSet<tType> &set) {
		os.range(set.begin(), set.end());
		return os;
	}
}