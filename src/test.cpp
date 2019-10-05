//
// Created by mard on 10/3/19.
//

#include <mardcpp/utils/application.hpp>
#include <mardcpp/stream/OutputStream.hpp>

int mardcpp::application(const mardcpp::Arguments &arguments) {

	mardcpp::os << arguments << '\n';

	mardcpp::os << arguments.get(0) << '\n';

	return 0;
}