//
// Created by mard on 5/11/19.
//

#include <mardcpp/time.h>

#include <iostream>

namespace mardcpp::time {

	Timer::~Timer() {
		auto total = steady_clock::now() - start;
		time.set(total);
	}

	Timer::Timer(Time &time)
			:	time(time), start(steady_clock::now()) {}

	void Time::set(const mardcpp::time::NanoDuration &duration) {
		s = duration_cast<seconds>(duration).count();

		m = duration_cast<milliseconds>(duration).count();
		m -= s * 1000;

		u = duration_cast<microseconds>(duration).count();
		u -= s * 1000000;
		u -= m * 1000;

		n = duration_cast<nanoseconds>(duration).count();
		n -= s * 1000000000;
		n -= m * 1000000;
		n -= u * 1000;

		raw = duration_cast<nanoseconds>(duration).count();
	}

	std::ostream &operator<<(std::ostream &os, const Time &time) {
		Time::TimeUnit m = time.s / 60;
		Time::TimeUnit h = m / 60;
		Time::TimeUnit d = h / 24;

		os << "time(";
		if (d > 0) {
			os << d << "d, ";
			os << h << "h, ";
			os << m << 'm';
		} else if(h > 0) {
			os << h << "h, ";
			os << m << "m, ";
			os << time.s << 's';
		} else if(m > 0) {
			os << m << "m, ";
			os << time.s << "s, ";
			os << time.m << "ms";
		} else if(time.s > 0) {
			os << time.s << "s, ";
			os << time.m << "ms, ";
			os << time.u << "us";
		} else {
			os << time.m << "ms, ";
			os << time.u << "us, ";
			os << time.n << "ns";
		}
		os << ')';

		return os;
	}
}