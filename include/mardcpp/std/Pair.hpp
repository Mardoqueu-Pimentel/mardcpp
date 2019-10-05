//
// Created by mard on 6/15/19.
//

#pragma once

#include <utility>

#include <mardcpp/stream/OutputStream.hpp>

namespace mc {

	template<typename F, typename S> using Pair = std::pair<F,S>;

	template<typename F, typename S>
	OutputStream &operator<<(OutputStream &os, const Pair<F,S> &pair) {
		os << pair.first << '=' << pair.second;
		return os;
	}
}
