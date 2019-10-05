//
// Created by mard on 6/15/19.
//

#pragma once

#include <unordered_map>

#include <mardcpp/stream/OutputStream.hpp>

namespace mc {

	template<typename K, typename V> using UnorderedMap = std::unordered_map<K,V>;

	template<typename K, typename V>
	OutputStream &operator<<(OutputStream &os, const UnorderedMap<K,V> &unorderedMap) {
		os.output(unorderedMap, ' ');
		return os;
	}
}