//
// Created by mard on 6/15/19.
//

#pragma once

#include <unordered_map>
#include <mardcpp/def.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mardCpp {

	using outputStream::OutputStream;

	template<	typename tKey, typename tValue, typename tHash = std::hash<tKey>,
						typename tComp = std::equal_to<tKey>
	>
	using UnorderedMap = std::unordered_map<tKey, tValue, tHash, tComp>;

	template<typename tKey, typename tValue>
	OutputStream &operator<<(OutputStream &os, const UnorderedMap<tKey,tValue> &unorderedMap) {
		os.range(unorderedMap.begin(), unorderedMap.end());
		return os;
	}
}