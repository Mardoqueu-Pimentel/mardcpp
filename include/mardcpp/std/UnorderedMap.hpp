//
// Created by mard on 6/15/19.
//

#pragma once

#include <unordered_map>
#include <mardcpp/mardcpp.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mc {

	template<typename K, typename V, typename H = std::hash<K>, typename C = std::equal_to<K>>
	using UnorderedMap = std::unordered_map<K, V, H, C>;

	template<typename K, typename V>
	OutputStream &operator<<(OutputStream &os, const UnorderedMap<K,V> &unorderedMap) {
		os.output(unorderedMap, ' ');
		return os;
	}
}