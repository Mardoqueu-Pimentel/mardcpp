//
// Created by mard on 10/19/19.
//

#pragma once

#include <iostream>
#include <mardcpp/def.hpp>
#include <mardcpp/OutStream.hpp>
#include <mardcpp/InStream.hpp>

namespace mardCpp {

	using outStream::OutStream;
	using inStream::InStream;

	static inline OutStream cout(std::cout);
	static inline InStream cin(std::cin);
}