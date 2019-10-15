//
// Created by mard on 6/15/19.
//

#pragma once

#include <utility>
#include <mardcpp/def.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mardCpp {

	using outputStream::OutputStream;

	template<typename tFirst, typename tSecond>
	using Pair = std::pair<tFirst,tSecond>;

	template<typename tFirst, typename tSecond>
	OutputStream &operator<<(OutputStream &os, const Pair<tFirst,tSecond> &pair) {
		os << pair.first << ':' << pair.second;
		return os;
	}
}
