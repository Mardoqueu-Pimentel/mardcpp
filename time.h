//
// Created by mard on 4/28/19.
//

#ifndef MARDCPP_TIME_H
#define MARDCPP_TIME_H

#include <chrono>
#include <iosfwd>
#include <string>

#include "mardcpp.h"

namespace mardcpp::time {
	using std::chrono::steady_clock;
	using std::chrono::duration_cast;
	using std::chrono::seconds;
	using std::chrono::milliseconds;
	using std::chrono::microseconds;
	using std::chrono::nanoseconds;
	using std::chrono::duration;
	using NanoRatio = std::ratio<1, 1000000000>;
	using NanoDuration = duration<long, NanoRatio>;

	struct Time {
		using TimeUnit = i64;
		TimeUnit s, m, u, n;

		Time(): s(0), m(0), u(0), n(0) {}
		void set(const NanoDuration &duration);

		friend std::ostream &operator<<(std::ostream &os, const Time& time);
	};

	class Timer {
		Time& time;
		steady_clock::time_point start;
	public:
		explicit Timer(Time& time);
		~Timer();
	};
}

#endif //MARDCPP_TIME_H
