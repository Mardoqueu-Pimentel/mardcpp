//
// Created by mard on 6/15/19.
//

#include <mardcpp/stream/OutputStream.hpp>

namespace mardCpp::outputStream {

	OutputStream::OutputStream(ostream &os)
		: os(os), padding(' '), paddingNumber(0) {}

	OutputStream &OutputStream::operator<<(const unsigned char &e) {
		os << (unsigned short) e;
		return *this;
	}

	OutputStream &OutputStream::operator<<(const signed char &e) {
		os << (signed short) e;
		return *this;
	}

}