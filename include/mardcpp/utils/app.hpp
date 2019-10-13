//
// Created by mard on 10/5/19.
//

#include <mardcpp/utils/Arguments.hpp>
#include <mardcpp/utils/Env.hpp>
#include <mardcpp/stream/OutputStream.hpp>

namespace mc {

	int app(const Arguments& arguments);
}

int main(int argc, const char * argv[]) {
	mc::cout << "Running in " << mc::global::ENV << " environment" << "\n";
	const mc::Arguments arguments(argc, argv);
	mc::cout << arguments << '\n';
	return mc::app(arguments);
}