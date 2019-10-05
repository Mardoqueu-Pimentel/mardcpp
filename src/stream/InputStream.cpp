//
// Created by mard on 6/15/19.
//

#include <mardcpp/stream/InputStream.hpp>

namespace mc {

	InputStream::InputStream(std::istream &is)
		: is(is) {}

	InputStream &InputStream::operator>>(unsigned char &e) {
		unsigned short dummy;
		is >> dummy;
		e = (unsigned char) dummy;
		return *this;
	}

	InputStream &InputStream::operator>>(signed char &e) {
		signed short dummy;
		is >> dummy;
		e = (signed char) dummy;
		return *this;
	}

}