//
// Created by mard on 5/11/19.
//

#ifndef MARDCPP_IOS_H
#define MARDCPP_IOS_H

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <deque>
#include "util.h"

namespace mardcpp {

	class OutputStream {
		std::ostream &os;

	public:
		char padding;
		unsigned paddingNumber;

		OutputStream(std::ostream &os)
			: os(os), padding(' '), paddingNumber(0) {}

		template<typename T>
		inline OutputStream &operator<<(const T &e) {
			if (paddingNumber) {
				os << std::setw(paddingNumber) << std::setfill(padding);
			}
			os << e;
			return *this;
		}

		inline OutputStream &operator<<(const unsigned char &e) {
			os << (unsigned short) e;
			return *this;
		}

		inline OutputStream &operator<<(const signed char &e) {
			os << (signed short) e;
			return *this;
		}

		template<typename T1, typename T2>
		inline OutputStream &operator<<(const std::unordered_map<T1, T2> &map) {
			auto it = map.begin();
			if (it != map.end()) {
				auto prevIt = it;
				while (++it != map.end()) {
					const auto&[key, val] = *prevIt;

					*this << key;
					os << ':';
					*this << val;
					os << ' ';

					prevIt = it;
				}

				const auto&[key, val] = *prevIt;
				*this << key;
				os << ':';
				*this << val;
			}

			return *this;
		}

		template<typename T, size_t N>
		inline OutputStream &operator<<(const T (&arr)[N]) {
			for (size_t i = 0; i < N; ++i) {
				*this << arr[i];
				if (i + 1 < N) {
					*this << ' ';
				}
			}
			return *this;
		}

		template<typename T, template<typename, typename> class Cont>
		inline OutputStream &operator<<(const Cont<T, std::allocator<T>> &cont) {
			auto it = cont.begin();
			if (it != cont.end()) {
				auto nextIt = it;
				++nextIt;
				while (nextIt != cont.end()) {
					*this << *it;
					os << ' ';
					it = nextIt;
					++nextIt;
				}
				*this << *it;
			}
			return *this;
		}

		template<
			typename T,
			template<typename, typename> class ContA,
			template<typename, typename> class ContB
		>
		inline OutputStream &operator<<(
			const ContA<ContB<T, std::allocator<T>>, std::allocator<ContB<T, std::allocator<T>>>> &cont
		) {
			auto it = cont.begin();
			if (it != cont.end()) {
				auto nextIt = it;
				++nextIt;
				while (nextIt != cont.end()) {
					*this << *it;
					os << '\n';
					it = nextIt;
					++nextIt;
				}
				*this << *it;
			}
			return *this;
		}

		template<size_t N>
		inline OutputStream &operator<<(const char (&arr)[N]) {
			os << arr;
			return *this;
		}

		template<typename T, size_t N, size_t M>
		inline OutputStream &operator<<(const T (&arr)[N][M]) {
			for (int i = 0; i < N; ++i) {
				*this << arr[i];
				if (i + 1 < N) {
					os << '\n';
				}
			}
			return *this;
		}
	};

	class InputStream {
		std::istream &is;
	public:
		InputStream(std::istream &is)
			: is(is) {}

		template<typename T>
		inline InputStream &operator>>(T &e) {
			is >> e;
			return *this;
		}

		inline InputStream &operator>>(unsigned char &e) {
			unsigned short dummy;
			is >> dummy;
			e = (unsigned char) dummy;
			return *this;
		}

		inline InputStream &operator>>(signed char &e) {
			signed short dummy;
			is >> dummy;
			e = (signed char) dummy;
			return *this;
		}

		template<typename T, size_t N>
		inline InputStream &operator>>(T (&arr)[N]) {
			for (auto &e : arr) { *this >> e; }
			return *this;
		}
	};

};


#endif //MARDCPP_IOS_H
