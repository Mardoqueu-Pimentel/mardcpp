//
// Created by mard on 10/3/19.
//

#include <mardcpp/utils/application.hpp>
#include <mardcpp/stream/OutputStream.hpp>

int mardcpp::application(const mardcpp::Arguments &arguments) {

	mardcpp::os << arguments << '\n';


	return 0;
}