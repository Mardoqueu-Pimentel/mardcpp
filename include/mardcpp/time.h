//
// Created by mard on 5/11/19.
//

#ifndef MARDCPP_TIME_H
#define MARDCPP_TIME_H

#include <chrono>
#include <iosfwd>
#include <string>

#include <mardcpp/mardcpp.h>

namespace mardcpp::time {

	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::microseconds;
	using std::chrono::milliseconds;
	using std::chrono::nanoseconds;
	using std::chrono::seconds;
	using std::chrono::steady_clock;

	using NanoRatio = std::ratio<1, 1000000000>;
	using NanoDuration = duration<long, NanoRatio>;

	struct Time {
		using TimeUnit = i64;
		TimeUnit s, m, u, n, raw;

		Time() : s(0), m(0), u(0), n(0), raw(0) {}

		void set(const NanoDuration &duration);

		friend std::ostream &operator<<(std::ostream &os, const Time &time);
	};

	class Timer {
		Time &time;
		steady_clock::time_point start;
	public:
		explicit Timer(Time &time);

		~Timer();
	};
}

#endif //MARDCPP_TIME_H
