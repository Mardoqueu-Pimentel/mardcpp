//
// Created by mard on 10/5/19.
//

#pragma once

#include <mardcpp/utils/def.hpp>

namespace mardCpp {

	class Env {
	public:
		enum {
			DEVELOPMENT,
			STAGE,
			PRODUCTION
		};

		using Value = decltype(Env::DEVELOPMENT);

		constexpr static inline auto STR_DEVELOPMENT = "development"sv;
		constexpr static inline auto STR_STAGE = "stage"sv;
		constexpr static inline auto STR_PRODUCTION = "production"sv;

	private:
		Value mEnv;

	public:

		constexpr Env(const Value& value = Env::DEVELOPMENT)
			: mEnv(value) {}

		constexpr Size operator==(const Env::Value &env) const noexcept {
			return mEnv == env;
		}

		constexpr operator const StringView & () const noexcept {
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

		friend std::ostream &operator<<(std::ostream &os, const Env &env) {
			os << static_cast<const StringView &>(env);
			return os;
		}
	};

	namespace global {
#ifndef ENVIRONMENT
#define ENVIRONMENT Env::DEVELOPMENT
#endif
		static inline constexpr Env ENV{ENVIRONMENT};
	}
}
