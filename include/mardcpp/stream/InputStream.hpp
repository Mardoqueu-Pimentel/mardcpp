//
// Created by mard on 6/15/19.
//

#pragma once

#include <iostream>

namespace mardcpp {

	class InputStream {
		std::istream &is;
	public:
		explicit InputStream(std::istream &is);

		template<typename T>
		inline InputStream &operator>>(T &e) {
			is >> e;
			return *this;
		}

		inline InputStream &operator>>(unsigned char &e);

		inline InputStream &operator>>(signed char &e);

		template<typename T, size_t N>
		inline InputStream &operator>>(T (&arr)[N]) {
			for (auto &e : arr) { *this >> e; }
			return *this;
		}
	};

	static inline auto is = InputStream(std::cin);
}