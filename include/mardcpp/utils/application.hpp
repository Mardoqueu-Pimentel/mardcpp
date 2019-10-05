//
// Created by mard on 10/5/19.
//

#include <mardcpp/utils/Arguments.hpp>

namespace mardcpp {

	int application(const Arguments& arguments);
}

int main(int argc, const char * argv[]) {
	return mardcpp::application(mardcpp::Arguments(argc, argv));
}