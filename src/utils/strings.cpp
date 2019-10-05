//
// Created by mard on 6/15/19.
//

#include <mardcpp/utils/strings.hpp>
#include <algorithm>

void mc::toLower(mc::String &string) {
	std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}

void mc::toUpper(mc::String &string) {
	std::transform(string.begin(), string.end(), string.begin(), ::toupper);
}
