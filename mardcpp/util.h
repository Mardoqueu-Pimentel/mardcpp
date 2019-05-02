#include <utility>

//
// Created by mard on 4/27/19.
//

#ifndef CODEBENCH_UTIL_H
#define CODEBENCH_UTIL_H

#include <chrono>
#include <iomanip>
#include <iosfwd>
#include <memory>
#include <string>

#include "mardcpp.h"

namespace mardcpp::util {

	class OutputStreamProxy {
		std::ostream &os;
		std::vector<std::function<void(std::ostream&)>> formats;

	public:
		OutputStreamProxy(std::ostream &os)
		: os(os) {}

		void add(std::function<void(std::ostream &)> format) {
			formats.emplace_back(format);
		}

		template<typename T>
		OutputStreamProxy& operator<<(T val) {
			for (const auto &format : formats) { format(os); }
			os << val;
			return *this;
		}
	};

	template<typename ... Args>
	std::string stringFormat(const std::string &format, Args ... args) {
		Size size = (Size) snprintf(nullptr, 0, format.c_str(), args ...) + 1;
		std::unique_ptr<char[]> buffer(new char[size]);
		snprintf(buffer.get(), size, format.c_str(), args ...);
		return std::string(buffer.get(), buffer.get() + size - 1);
	}

	struct Timer {
		struct Time {
			long s, ms, us, ns;

			Time()
			: s(0), ms(0), us(0), ns(0) {}

			friend std::ostream &operator<<(std::ostream &os, const Timer::Time& time) {
				OutputStreamProxy sp(os);
				sp.add([](std::ostream& os) {
					os << std::setfill('0');
					os << std::setw(3);
				});

				sp << "time(";
				sp << time.s << " s, ";
				sp << time.ms << " ms, ";
				sp << time.us << " us, ";
				sp << time.ns << " ns)";

				return os;
			}
		};

		Time &time;
		std::chrono::steady_clock::time_point start;

		Timer(Time& time)
		: time(time), start(std::chrono::steady_clock::now()) {}

		~Timer() {
			auto end = std::chrono::steady_clock::now();
			auto total = end - start;

			time.s = std::chrono::duration_cast<std::chrono::seconds>(total).count();
			time.ms = std::chrono::duration_cast<std::chrono::milliseconds>(total).count();
			time.us = std::chrono::duration_cast<std::chrono::microseconds>(total).count();
			time.ns = std::chrono::duration_cast<std::chrono::nanoseconds>(total).count();

			time.ms -= time.s * (u64) 1e3;

			time.us -= time.ms * (u64) 1e3;
			time.us -= time.s * (u64) 1e6;

			time.ns -= time.us * (u64) 1e3;
			time.ns -= time.ms * (u64) 1e6;
			time.ns -= time.s * (u64) 1e9;
		}
	};
}

#endif //CODEBENCH_UTIL_H
