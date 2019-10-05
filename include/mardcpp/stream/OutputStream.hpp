//
// Created by mard on 6/15/19.
//

#pragma once

#include <iostream>
#include <iomanip>

namespace mardcpp {

	using std::istream;
	using std::ostream;

	class OutputStream {
		std::ostream &os;

	public:
		char padding;
		int paddingNumber;

		explicit OutputStream(std::ostream &os);

		template<typename T>
		inline OutputStream &operator<<(const T &e) {
			if (paddingNumber) {
				os << std::setw(paddingNumber) << std::setfill(padding);
			}
			os << e;
			return *this;
		}

		inline OutputStream &operator<<(const unsigned char &e);

		inline OutputStream &operator<<(const signed char &e);

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

		template<template<typename ...> class Container, typename ... Ts>
		void output(const Container<Ts...> &cont, char sep) {
			auto it = cont.begin(), end = cont.end();
			if (it != end) {
				auto nextIt = it;
				while (++nextIt != end) {
					*this << *it;
					os << sep;
					it = nextIt;
				}
				*this << *it;
			}
		}
	};

	static inline auto os = OutputStream(std::cout);
}
