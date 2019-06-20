//
// Created by mard on 6/15/19.
//

#include <regex>

#include <mardcpp/utils/Kwargs>

namespace mardcpp {

	Arguments::Arguments(int argc, const char **argv) {
		for (int i = 0; i < argc; ++i) {
			String arg(argv[i]);

			std::smatch results;
			if (std::regex_search(arg, results, std::regex("^([^= ]+)=([^= ]+)$"))) {
				mKwargs.emplace(results[1], results[2]);
			} else {
				mArgs.emplace(std::move(arg));
			}
		}
	}

	bool Arguments::has(const Arguments::Arg &arg) const {
		return mKwargs.find(arg) != mKwargs.end();
	}

	OutputStream &operator<<(mardcpp::OutputStream &os, const mardcpp::Arguments &arguments) {
		os << "Args: " << arguments.mArgs << '\n';
		os << "Kwargs: " << arguments.mKwargs << '\n';
		return os;
	}
}
