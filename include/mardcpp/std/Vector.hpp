//
// Created by mard on 6/15/19.
//

#pragma once

#include <vector>

#include <mardcpp/stream/OutputStream.hpp>

namespace mardcpp {

	template<typename T> using Vector = std::vector<T>;

	template<typename T>
	OutputStream& operator<<(OutputStream &os, const Vector<T> &vector) {
		os.output(vector, ' ');
		return os;
	}

	template<typename T>
	OutputStream& operator<<(OutputStream &os, const Vector<Vector<T>> &vector) {
		os.output(vector, '\n');
		return os;
	}
}