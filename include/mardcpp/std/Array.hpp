//
// Created by mard on 10/9/19.
//

#pragma once

#include <array>
#include <mardcpp/mardcpp.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mc {

template<typename T, mc::Size S> using Array = std::array<T, S>;

template<typename T, mc::Size S>
OutputStream &operator<<(OutputStream &os, const Array<T, S> &array) {
	os.output(array, ' ');
	return os;
}

}