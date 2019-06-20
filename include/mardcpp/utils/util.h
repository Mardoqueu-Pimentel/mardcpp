//
// Created by mard on 5/11/19.
//

#ifndef MARDCPP_UTIL_H
#define MARDCPP_UTIL_H

#include <stdexcept>
#include <sstream>

#include <mardcpp/mardcpp>
#include <mardcpp/std/String>

namespace mardcpp {

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

}

#endif //MARDCPP_UTIL_H
