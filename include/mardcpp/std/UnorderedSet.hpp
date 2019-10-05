//
// Created by mard on 6/15/19.
//

#pragma once

#include <unordered_set>

#include <mardcpp/stream/OutputStream.hpp>

namespace mc {

	template<typename T> using UnorderedSet = std::unordered_set<T>;

	template<typename T>
	OutputStream& operator<<(OutputStream& os, const UnorderedSet<T> &set) {
		os.output(set, ' ');
		return os;
	}
}