//
// Created by mard on 10/17/19.
//
#include <mardcpp/outStream.hpp>
#include <mardcpp/typeTraits.hpp>

using mardCpp::outStream::OutStream;
using mardCpp::outStream::OStream ;

struct Tuple : mardCpp::Streamable {

	int a, b;

	Tuple(int a, int b)
	: a(a), b(b) {}

	friend OStream &operator<<(OStream &stream, const Tuple& tuple) {
		stream << "a:" << tuple.a << "|b:" << tuple.b;
		return stream;
	}
};

int main() {

	return 0;
}