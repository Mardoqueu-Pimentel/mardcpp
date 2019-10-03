//
// Created by mard on 10/3/19.
//

#include <mardcpp/test.hpp>
#include <mardcpp/utils/Arguments.hpp>

int app(const mardcpp::Arguments &args) {


	return 0;
}

int main(int argc, const char **argv) {
	return app(mardcpp::Arguments(argc, argv));
}
