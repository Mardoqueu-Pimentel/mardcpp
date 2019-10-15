//
// Created by mard on 6/15/19.
//

#pragma once

#include <iomanip>
#include <iostream>
#include <mardcpp/stream/def.hpp>

namespace mardCpp::outputStream {

	using std::istream;
	using std::ostream;

	class OutputStream {
		std::ostream &os;

	public:
		Char padding;
		Int paddingNumber;

		explicit OutputStream(ostream &os);

		template<typename tType>
		inline OutputStream &operator<<(const tType &e) {
			if (paddingNumber) {
				os << std::setw(paddingNumber) << std::setfill(padding);
			}
			os << e;
			return *this;
		}

		inline OutputStream &operator<<(const uc &e);

		inline OutputStream &operator<<(const sc &e);

		template<Size tN>
		inline OutputStream &operator<<(const Char (&arr)[tN]) {
			os << arr;
			return *this;
		}

		template<typename tType, Size tN>
		inline OutputStream &operator<<(const tType (&arr)[tN]) {
			for (size_t i = 0; i < tN; ++i) {
				*this << arr[i];
				if (i + 1 < tN) {
					*this << ' ';
				}
			}
			return *this;
		}

		template<typename tType, Size tN, Size tM>
		inline OutputStream &operator<<(const tType (&arr)[tN][tM]) {
			for (int i = 0; i < tN; ++i) {
				*this << arr[i];
				if (i + 1 < tN) {
					os << '\n';
				}
			}
			return *this;
		}

		template<typename tIter>
		inline void range(tIter it, tIter end, Char separator = ' ') {
			if (it != end) {
				auto nextIt = it;
				while (++nextIt != end) {
					*this << *it;
					os << separator;
				}
				*this << *it;
			}
		}
	};

	static inline auto cout = OutputStream(std::cout);
}
