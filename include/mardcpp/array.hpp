//
// Created by mard on 10/17/19.
//

#pragma once

#include <array>
#include <mardcpp/def.hpp>

namespace mardCpp::array {

	template<typename tType, Size tSize>
	using Array = std::array<tType, tSize>;

}