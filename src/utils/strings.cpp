//
// Created by mard on 6/15/19.
//

#include <mardcpp/utils/strings.hpp>
#include <algorithm>

void mardCpp::toLower(mardCpp::String &string) {
	std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}

void mardCpp::toUpper(mardCpp::String &string) {
	std::transform(string.begin(), string.end(), string.begin(), ::toupper);
}
