//
// Created by mard on 6/15/19.
//

#pragma once

#include <vector>
#include <mardcpp/def.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mardCpp {

	using outputStream::OutputStream;

	template<typename tType>
	using Vector = std::vector<tType>;

	template<typename tType>
	OutputStream& operator<<(OutputStream &os, const Vector<tType> &vector) {
		os.range(vector.begin(), vector.end());
		return os;
	}

	template<typename tType>
	OutputStream& operator<<(OutputStream &os, const Vector<Vector<tType>> &vector) {
		os.range(vector.begin(), vector.end(), '\n');
		return os;
	}
}