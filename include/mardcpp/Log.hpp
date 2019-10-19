//
// Created by mard on 10/19/19.
//

#pragma once

//
// Created by mard on 10/11/19.
//

#pragma once

#include <chrono>
#include <csignal>
#include <iostream>
#include <mardcpp/def.hpp>

namespace mardCpp {

	class Log {

	public:
		enum class Level {
			kSuper, kFatal, kError, kWarn, kInfo, kDebug
		};

		inline friend Level &operator++(Level &level) {
			int x = (static_cast<int>(level) + 1) % 5;
			return level = static_cast<Level>(x);
		}

		inline friend Level operator++(Level &level, int) {
			Level copy = level;
			++level;
			return copy;
		}

		constexpr static StringView toString(const Level level) {
			switch (level) {
				case Level::kSuper: return "super"sv;
				case Level::kFatal:	return "fatal"sv;
				case Level::kError:	return "error"sv;
				case Level::kWarn:	return "warn"sv;
				case Level::kInfo:	return "info"sv;
				default:						return "debug"sv;
			}
		}

	private:
		static inline auto sLevel = env == Env::PRODUCTION ? Level::kInfo : Level::kDebug;

		template<Log::Level level, typename ... Ts>
		static void write(std::ostream &os, const Ts &...ts) {
			if (Log::sLevel < level) {
				return;
			}

			auto timeStamp = std::chrono::system_clock::to_time_t(
				std::chrono::system_clock::now()
			);

			os << "[" << Log::toString(level) << "] " << std::ctime(&timeStamp);
			((os << ts), ...);
			os << '\n' << std::endl;
		}

	public:
		template<typename ... Ts>
		static void debug(const Ts &...ts) {
			write<Log::Level::kDebug>(std::clog, ts...);
		}

		template<typename ... Ts>
		static void info(const Ts &...ts) {
			write<Log::Level::kInfo>(std::clog, ts...);
		}

		template<typename ... Ts>
		static void warn(const Ts &...ts) {
			write<Log::Level::kWarn>(std::clog, ts...);
		}

		template<typename ... Ts>
		static void error(const Ts &...ts) {
			write<Log::Level::kError>(std::clog, ts...);
		}

		template<typename ... Ts>
		static void fatal(const Ts &...ts) {
			write<Log::Level::kFatal>(std::clog, ts...);
		}

		template<typename ... Ts>
		static void super(const Ts &...ts) {
			write<Log::Level::kSuper>(std::clog, ts...);
		}

		template<typename ... Ts>
		static void dev(const Ts &...ts) {
			if constexpr (env == Env::DEVELOPMENT) {
				write<Log::Level::kDebug>(std::clog, ts...);
			}
		}

		static inline bool initialized = ([](){
			std::signal(SIGUSR1, [](int){
				auto strFrom 	= toString(Log::sLevel);
				auto strTo		= toString(++Log::sLevel);
				Log::super("SIGUSR1: ", strFrom, " -> ", strTo);
			});
			return true;
		})();
	};

}

