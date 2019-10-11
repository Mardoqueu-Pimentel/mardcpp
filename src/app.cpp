//
// Created by mard on 10/10/19.
//


#include <csignal>
#include <thread>

#include <mardcpp/utils/app.hpp>
#include <mardcpp/utils/Logger.hpp>


int mc::app(const mc::Arguments &arguments) {


	using std::chrono::operator ""s;

	while (true) {
		Logger::debug("testing", "the", "debugger", "with", "logging", "=", "debug");
		Logger::info("testing", "the", "debugger", "with", "logging", "=", "info");
		Logger::warn("testing", "the", "debugger", "with", "logging", "=", "warn");
		Logger::error("testing", "the", "debugger", "with", "logging", "=", "error");
		Logger::fatal("testing", "the", "debugger", "with", "logging", "=", "fatal");

		std::this_thread::sleep_for(1s);
	}


	return 0;
}