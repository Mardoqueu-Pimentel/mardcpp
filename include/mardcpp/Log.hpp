//
// Created by mard on 10/19/19.
//

#pragma once

#include <chrono>
#include <csignal>
#include <iostream>
#include <mardcpp/def.hpp>
#include <mardcpp/OutStream.hpp>

namespace mardCpp {
	using outStream::OutStream;

	static inline OutStream cerr(std::cerr), clog(std::clog), cout(std::cout);

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
		static void write(OutStream &stream, const Ts &...ts) {
			if (Log::sLevel < level) {
				return;
			}

			auto timeStamp = std::chrono::system_clock::to_time_t(
				std::chrono::system_clock::now()
			);

			stream << "[" << Log::toString(level) << "] " << std::ctime(&timeStamp);
			((stream << ts), ...);
			stream << "\n\n";
			stream.flush();
		}

	public:
		template<typename ... Ts>
		static void debug(const Ts &...ts) {
			write<Log::Level::kDebug>(cout, ts...);
		}

		template<typename ... Ts>
		static void info(const Ts &...ts) {
			write<Log::Level::kInfo>(cout, ts...);
		}

		template<typename ... Ts>
		static void warn(const Ts &...ts) {
			write<Log::Level::kWarn>(cerr, ts...);
		}

		template<typename ... Ts>
		static void error(const Ts &...ts) {
			write<Log::Level::kError>(cerr, ts...);
		}

		template<typename ... Ts>
		static void fatal(const Ts &...ts) {
			write<Log::Level::kFatal>(cerr, ts...);
		}

		template<typename ... Ts>
		static void super(const Ts &...ts) {
			write<Log::Level::kSuper>(cerr, ts...);
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

