//
// Created by mard on 10/19/19.
//

#pragma once

#include <unordered_map>
#include <mardcpp/def.hpp>

namespace mardCpp::unorderedMap {

	template<typename tKey, typename tValue>
	using UnorderedMap = std::unordered_map<tKey, tValue, Hash, Equal>;

}