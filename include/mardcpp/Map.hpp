//
// Created by mard on 6/19/19.
//

#pragma once

#include <map>
#include <mardcpp/def.hpp>
#include <mardcpp/Pair.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mardCpp {

	using outputStream::OutputStream;

	template<typename tKey, typename tValue>
	using Map = std::map<tKey, tValue>;

	template<typename tKey, typename tValue>
	OutputStream &operator<<(OutputStream &os, const Map<tKey, tValue> &map) {
		os.range(map.begin(), map.end());
		return os;
	}
}