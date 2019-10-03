//
// Created by mard on 5/11/19.
//

#include <mardcpp/utils/util.hpp>

#include <cstdarg>
#include <iostream>

namespace mardcpp {

	template<size_t size>
	const char * format(const char *__restrict format, ...) noexcept {
		va_list args;
		va_start(args, format);
		vsnprintf(getSharedBuffer().data(), getSharedBuffer().size(), format, args);
		va_end(args);
		return getSharedBuffer().data();
	}

	std::string format(const char *__restrict format, ...) noexcept {
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

