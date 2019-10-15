//
// Created by mard on 10/11/19.
//

#pragma once

#include <mardcpp/utils/def.hpp>

namespace mardCpp {

	class Logger {


	public:
		enum Level {
			FATAL, ERROR, WARN, INFO, DEBUG
		};

		friend Level &operator++(Level &level) {
			int x = (static_cast<int>(level) + 1) % 5;
			return level = static_cast<Level>(x);
		}
		friend Level operator++(Level &level, int) {
			Level copy = level;
			++level;
			return copy;
		}

	private:
		static inline auto sLevel = Level::INFO;

		static inline bool initialized = ([](){
			std::signal(SIGUSR1, [](int){
				Logger::Level tmp = Logger::sLevel;
				std::cout << "SIGUSR1 received. Changing log level from " << tmp << " to " << ++Logger::sLevel << '\n';
			});
			return true;
		})();

	public:
		template<Logger::Level level, typename ... Ts>
		static void write(const Ts &...ts) {
			if (Logger::sLevel < level) {
				return;
			}

			std::cout << "level: " << Logger::sLevel;
			((std::cout << ' ' << ts), ...);
			std::cout << std::endl;
		}

		template<typename ... Ts>
		static void debug(const Ts &...ts) {
			write<Logger::DEBUG>(ts...);
		}

		template<typename ... Ts>
		static void info(const Ts &...ts) {
			write<Logger::INFO>(ts...);
		}

		template<typename ... Ts>
		static void warn(const Ts &...ts) {
			write<Logger::WARN>(ts...);
		}

		template<typename ... Ts>
		static void error(const Ts &...ts) {
			write<Logger::ERROR>(ts...);
		}

		template<typename ... Ts>
		static void fatal(const Ts &...ts) {
			write<Logger::FATAL>(ts...);
		}
	};

}

