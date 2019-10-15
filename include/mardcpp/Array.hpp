//
// Created by mard on 10/9/19.
//

#pragma once

#include <array>
#include <mardcpp/def.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mardCpp {

	using outputStream::OutputStream;

	template<typename tType, Size tSize>
	using Array = std::array<tType, tSize>;

	template<typename tType, Size tSize>
	OutputStream &operator<<(OutputStream &os, const Array<tType, tSize> &array) {
		os.range(array.begin(), array.end());
		return os;
	}
}