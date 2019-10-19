//
// Created by mard on 10/19/19.
//

#include <mardcpp/utility.hpp>

namespace mardCpp::utility {

	const char * fmt(const char *__restrict format, ...) noexcept {
		va_list args;
		va_start(args, format);
		vsnprintf(global::errorBuffer.data(), global::errorBuffer.size(), format, args);
		va_end(args);
		return global::errorBuffer.data();
	}

	String sfmt(const char *__restrict format, ...) noexcept {
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