//
// Created by mard on 10/12/19.
//

#pragma once

#include <list>
#include <mardcpp/def.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mardCpp {

	using outputStream::OutputStream;

	template<typename tType>
	using List = std::list<tType>;

	template<typename tType>
	OutputStream &operator<<(OutputStream &os, const List<tType> &list) {
		os.range(list.begin(), list.end());
		return os;
	}
}