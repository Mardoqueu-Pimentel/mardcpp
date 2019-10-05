//
// Created by mard on 6/19/19.
//

#pragma once

#include <map>

#include <mardcpp/stream/OutputStream.hpp>

namespace mc {

	template<typename K, typename V> using Map = std::map<K, V>;

	template<typename K, typename V>
	OutputStream &operator<<(OutputStream &os, const Map<K, V> map) {
		os.output(map, ' ');
		return os;
	}
}