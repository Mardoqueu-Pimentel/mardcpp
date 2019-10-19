//
// Created by mard on 10/19/19.
//

#pragma once

#include <istream>

namespace mardCpp::inStream {

	using IStream = std::istream;

	class InStream {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
		IStream &mStream;
#pragma clang diagnostic pop

	public:
		InStream(IStream &stream)
			: mStream(stream) {}

	};
}