//
// Created by mard on 10/19/19.
//

#pragma once

#include <memory>
#include <mardcpp/def.hpp>

namespace mardCpp::memory {

	template<typename tType>
	using SharedPtr = std::shared_ptr<tType>;

	template<typename tType>
	using UniquePtr = std::unique_ptr<tType>;

	template<typename tType>
	using WeakPtr = std::weak_ptr<tType>;

}
