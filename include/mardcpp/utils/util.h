//
// Created by mard on 5/11/19.
//

#ifndef MARDCPP_UTIL_H
#define MARDCPP_UTIL_H

#include <iosfwd>
#include <string>
#include <unordered_map>
#include <vector>

#include <mardcpp/mardcpp.h>


namespace mardcpp {

	template<typename T1, typename T2>
	struct notSame : public std::true_type {};

	template<typename T1>
	struct notSame<T1, T1> : public std::false_type {};

	using std::pair;
	using std::string;
	using std::unordered_map;
	using std::vector;

	using Arg = string;
	using Args = vector<Arg>;
	using Kwarg = pair<Arg, string>;
	using Kwargs = unordered_map<Kwarg::first_type, Kwarg::second_type>;

	const pair<Args, Kwargs> parseArgv(int argc, const char *argv[]);
}


#endif //MARDCPP_UTIL_H
