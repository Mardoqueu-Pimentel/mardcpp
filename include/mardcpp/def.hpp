//
// Created by mard on 10/15/19.
//

#pragma once

#include <cmath>
#include <cstdint>
#include <string>
#include <string_view>

using i08 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u08 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using f32 = float_t;
using f64 = double_t;
using f80 = long double;

using sc = signed char;
using uc = unsigned char;
using ssi = signed short int;
using usi = unsigned short int;
using si = signed int;
using ui = unsigned int;
using sli = signed long int;
using uli = unsigned long int;
using slli = signed long long int;
using ulli = unsigned long long int;

using Size = size_t;

using Bool = bool;
using Byte = char;
using Char = char;
using Int = i32;
using Long = i64;
using UInt = u32;
using ULong = u64;
using Flt = f32;
using Dbl = f64;

inline constexpr Size operator "" _B (ulli x) {
	return x;
}

inline constexpr Size operator "" _KB (ulli x) {
	return x * 1024;
}

inline constexpr Size operator "" _MB (ulli x) {
	return x * 1024 * 1024;
}

inline constexpr Size operator "" _GB (ulli x) {
	return x * 1024 * 1024 * 1024;
}

using std::string_view_literals::operator ""sv;

using String = std::string;
using StringView = std::string_view;

struct Hash {

	template<typename tType, typename std::enable_if<std::is_invocable<tType, Hash>::value, bool>::type = true>
	Size operator()(const tType &value) const noexcept {
		return value(Hash());
	}

	template<typename tType, typename std::enable_if<not std::is_invocable<tType, Hash>::value, bool>::type = true>
	Size operator()(const tType &value) const noexcept {
		return std::hash<tType>()(value);
	}

};

struct Equal {
	template<typename tType>
	inline bool operator()(const tType &lhe, const tType &rhe) const noexcept {
		return lhe == rhe;
	}
};

struct Less {
	template<typename tType>
	inline bool operator()(const tType &lhe, const tType &rhe) const noexcept {
		return lhe < rhe;
	}
};

struct Zero {};

class Env {
public:
	enum {DEVELOPMENT, STAGE, PRODUCTION};
	constexpr static inline auto STR_DEVELOPMENT = "development"sv;
	constexpr static inline auto STR_STAGE = "stage"sv;
	constexpr static inline auto STR_PRODUCTION = "production"sv;

	using Value = decltype(Env::DEVELOPMENT);
private:
	Value mEnv;

public:
	constexpr Env(const Value& value = Env::DEVELOPMENT)
		: mEnv(value) {}

	constexpr Size operator==(const Env::Value &env) const noexcept {
		return mEnv == env;
	}

	constexpr operator StringView () const noexcept {
		switch (mEnv) {
			case DEVELOPMENT:
				return Env::STR_DEVELOPMENT;
			case STAGE:
				return Env::STR_STAGE;
			case PRODUCTION:
				return Env::STR_PRODUCTION;
		}
		return STR_DEVELOPMENT;
	}

	template<typename tFunctor>
	constexpr void executeIn(const Value &value, const tFunctor &functor) const {
		if (mEnv == value) {
			functor();
		}
	}

};

#ifndef ENVIRONMENT
#define ENVIRONMENT Env::DEVELOPMENT
#endif
static inline constexpr Env env{ENVIRONMENT};
