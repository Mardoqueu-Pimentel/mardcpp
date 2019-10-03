//
// Created by mard on 6/15/19.
//

#include <mardcpp/utils/strings.hpp>
#include <algorithm>

void mardcpp::toLower(mardcpp::String &string) {
	std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}

void mardcpp::toUpper(mardcpp::String &string) {
	std::transform(string.begin(), string.end(), string.begin(), ::toupper);
}
