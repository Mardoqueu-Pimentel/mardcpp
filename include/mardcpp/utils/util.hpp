//
// Created by mard on 5/11/19.
//

#pragma once

#include <stdexcept>
#include <sstream>

#include <mardcpp/mardcpp.hpp>
#include <mardcpp/std/String.hpp>
#include <array>
#include <mardcpp/mardcpp.hpp>

namespace mardcpp {

	template<size_t size = 4_KB>
	std::array<char, size> &getSharedBuffer() {
		static std::array<char, size> buffer;
		return buffer;
	}

	template<typename T1, typename T2>
	struct notSame : public std::true_type {};

	template<typename T1>
	struct notSame<T1, T1> : public std::false_type {};

	template<typename T>
	T toType(const String &string) {
		T val;
		std::istringstream is(string);
		if (is >> val) {
			return val;
		}
		throw std::invalid_argument("could not transform string to type");
	}

	template<
		template<typename, typename, typename ...> class C,
		typename K,
		typename V,
		typename ... Args
	>
	const V &getOrDefault(
		C<K, V, Args...> &associativeContainer,
		const typename C<K, V, Args...>::key_type &key,
		const typename C<K, V, Args...>::value_type::second_type &defaultValue
	) {
		auto it = associativeContainer.find(key);
		if (it == associativeContainer.end())
			return defaultValue;
		return it->second;
	}

	const char * __attribute__ ((__format__ (__printf__, 1, 2)))
	fmt (const char *__restrict format, ...) noexcept;

	std::string __attribute__ ((__format__ (__printf__, 1, 2)))
	sfmt(const char *__restrict format, ...) noexcept;
}
