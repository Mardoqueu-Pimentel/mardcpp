//
// Created by mard on 10/12/19.
//

#pragma once

#include <list>
#include <mardcpp/mardcpp.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mc {

	template<typename T>
	using List = std::list<T>;

	template<typename T>
	mc::OutputStream &operator<<(mc::OutputStream &os, const List<T> &list) {
		os.output(list, ' ');
		return os;
	}

	template<typename T>
	mc::OutputStream &operator<<(mc::OutputStream &os, const typename List<T>::iterator &iter) {
		os << *iter;
		return os;
	}
}