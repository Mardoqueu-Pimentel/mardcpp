//
// Created by mard on 10/5/19.
//

#include <mardcpp/utils/def.hpp>
#include <mardcpp/utils/Arguments.hpp>
#include <mardcpp/stream/OutputStream.hpp>
#include <mardcpp/utils/Env.hpp>

namespace mardCpp {

	int app(const Arguments& arguments);
}

int main(Int argc, const Char * argv[]) {
	using mardCpp::outputStream::cout;

	cout << "Running in " << mardCpp::global::ENV << " environment" << "\n";
	const mardCpp::Arguments arguments(argc, argv);
	cout << arguments << '\n';
	return mardCpp::app(arguments);
}