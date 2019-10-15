//
// Created by mard on 5/11/19.
//

#include <mardcpp/utils/util.hpp>

#include <cstdarg>
#include <iostream>

namespace mardCpp {

	const char * fmt(const char *__restrict format, ...) noexcept {
		va_list args;
		va_start(args, format);
		vsnprintf(global::getSharedBuffer().data(), global::getSharedBuffer().size(), format, args);
		va_end(args);
		return global::getSharedBuffer().data();
	}

	std::string sfmt(const char *__restrict format, ...) noexcept {
		va_list args;
		va_start(args, format);
		std::string result;

		char *cp = result.data();

		result.resize(vsnprintf(nullptr, 0, format, args));
		vsnprintf(cp, result.size(), format, args);
		va_end(args);
		return result;
	}
}

