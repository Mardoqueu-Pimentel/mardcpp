//
// Created by mard on 10/5/19.
//

#pragma once

#include <mardcpp/mardcpp.hpp>
#include <mardcpp/utils/util.hpp>
#include <iosfwd>
#include <functional>


namespace mc {

	class Env {
	public:
		enum class Value: u08 { DEVELOPMENT, STAGE, PRODUCTION };
		inline static const Value DEFAULT = Value::DEVELOPMENT;
		inline static const String STR_DEVELOPMENT = "development";
		inline static const String STR_STAGE = "stage";
		inline static const String STR_PRODUCTION = "production";

	private:
		Value mValue;

	public:
		constexpr Env()
			: mValue(DEFAULT) {}
		constexpr Env(const Value& value)
			: mValue(value) {}

		constexpr operator Value() const noexcept {
			return mValue;
		}

		constexpr bool operator==(const Env& env) const noexcept {
			return mValue == env;
		}
		constexpr bool operator!=(const Env& env) const noexcept {
			return mValue != env;
		}

		operator const String&() const noexcept {
			switch (mValue) {
				case Value::DEVELOPMENT:
					return STR_DEVELOPMENT;
				case Value::STAGE:
					return STR_STAGE;
				case Value::PRODUCTION:
					return STR_PRODUCTION;
				default:
					return STR_DEVELOPMENT;
			}
		}

		friend std::istream& operator>>(std::istream &is, Env &env) {
			using KT = const String;
			using K = std::reference_wrapper<KT>;
			using V = Env;
			using H = RefHasher<KT>;
			using C = RefEq<KT>;

			std::unordered_map<K, V, H, C> ENV_TO_STRING = {
				{ Env::STR_DEVELOPMENT, Env(Env::Value::DEVELOPMENT) },
				{ Env::STR_STAGE, Env(Env::Value::STAGE)},
				{ Env::STR_PRODUCTION, Env(Env::Value::PRODUCTION) }
			};

			String word = env; is >> word;

			auto it = ENV_TO_STRING.find(word);
			if (it != ENV_TO_STRING.end()) {
				env.mValue = it->second;
			} else {
				env.mValue = DEFAULT;
			}

			return is;
		}

		friend std::ostream& operator<<(std::ostream &os, const Env &env) {
			const String& string = env;
			os << string;
			return os;
		}
	};

	namespace gb {
		static inline Env env;
	}
}
