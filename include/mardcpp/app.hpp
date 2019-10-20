//
// Created by mard on 10/17/19.
//

#pragma once

#include <mardcpp/Arguments.hpp>
#include <mardcpp/Log.hpp>

namespace mardCpp::app {
	using mardCpp::arguments::Arguments;

	int app(const Arguments &arguments);
}

int main(int argc, const char *argv[]) {
	using mardCpp::arguments::Arguments;
	using mardCpp::Log;

	Log::info("compiled with ", env, " environment");
	const Arguments arguments(argc, argv);
	Log::info(arguments);
	return mardCpp::app::app(arguments);
}