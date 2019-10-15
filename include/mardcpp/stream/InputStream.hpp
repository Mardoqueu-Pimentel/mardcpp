//
// Created by mard on 6/15/19.
//

#pragma once

#include <iostream>
#include <mardcpp/stream/def.hpp>

namespace mardCpp::inputStream {

	using std::istream;

	class InputStream {
		std::istream &is;
	public:
		explicit InputStream(std::istream &is);

		template<typename tType>
		inline InputStream &operator>>(tType &e) {
			is >> e;
			return *this;
		}

		inline InputStream &operator>>(unsigned char &e);

		inline InputStream &operator>>(signed char &e);

		template<typename tType, Size tN>
		inline InputStream &operator>>(tType (&arr)[tN]) {
			for (auto &e : arr) { *this >> e; }
			return *this;
		}
	};

	static inline auto is = InputStream(std::cin);
}