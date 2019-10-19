//
// Created by mard on 10/19/19.
//

#pragma once

#include <map>

namespace mardCpp::map {

	template<typename ... tTs>
	using Map = std::map<tTs...>;

}