//
// Created by mard on 10/5/19.
//

#include <mardcpp/utils/Arguments.hpp>
#include <mardcpp/utils/Env.hpp>
#include <mardcpp/stream/OutputStream.hpp>
#include <mardcpp/std/String.hpp>

namespace mc {

	int app(const Arguments& arguments);
}

int main(int argc, const char * argv[]) {
	const mc::Arguments arguments(argc, argv);
	mc::os << arguments << '\n';
	mc::gb::env = arguments.getOrDefault("env", mc::Env());
	mc::os << "Running in " << mc::gb::env << " environment" << "\n\n";

	return mc::app(arguments);
}