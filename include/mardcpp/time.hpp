//
// Created by mard on 5/11/19.
//

#pragma once

#include <chrono>
#include <mardcpp/def.hpp>
#include <mardcpp/iosfwd.hpp>

namespace mardCpp::time {

	using outStream::OutStream;

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

		friend OutStream &operator<<(OutStream &os, const Time &time);
	};

	class Timer {
		Time &time;
		steady_clock::time_point start;
	public:
		explicit Timer(Time &time);

		~Timer();
	};
}

using std::chrono_literals::operator ""ns;
using std::chrono_literals::operator ""us;
using std::chrono_literals::operator ""ms;
using std::chrono_literals::operator ""s;
using std::chrono_literals::operator ""min;
using std::chrono_literals::operator ""h;