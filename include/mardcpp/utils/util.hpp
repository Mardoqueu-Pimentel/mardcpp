//
// Created by mard on 5/11/19.
//

#pragma once

#include <sstream>
#include <exception>
#include <cstdarg>
#include <mardcpp/mardcpp.hpp>
#include <mardcpp/std/String.hpp>
#include <array>
#include <mardcpp/mardcpp.hpp>

namespace mc {

	namespace gb {
		template<size_t size = 4_KB>
		std::array<char, size> &getSharedBuffer() {
			static std::array<char, size> buffer;
			return buffer;
		}
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

	template<typename T>
	struct RefHasher {
		using RefType = std::reference_wrapper<T>;
		static constexpr auto hash = std::hash<typename std::remove_const<T>::type>();
		size_t operator()(const RefType &ref) const {
			return hash(ref.get());
		}
	};

	template<typename T>
	struct RefEq {
		using RefType = std::reference_wrapper<T>;
		bool operator()(const RefType &x, const RefType &y) const {
			return x.get() == y.get();
		}
	};

	const char * __attribute__ ((__format__ (__printf__, 1, 2)))
	fmt (const char *__restrict format, ...) noexcept;

	std::string __attribute__ ((__format__ (__printf__, 1, 2)))
	sfmt(const char *__restrict format, ...) noexcept;

	template<typename Error = std::runtime_error>
	Error __attribute__ ((__format__ (__printf__, 1, 2)))
	makeError(const char *__restrict format, ...) noexcept {
		va_list args;
		va_start(args, format);
		vsnprintf(gb::getSharedBuffer().data(), gb::getSharedBuffer().size(), format, args);
		va_end(args);

		return Error(gb::getSharedBuffer().data());
	}

}
