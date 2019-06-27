//
// Created by mard on 6/15/19.
//

#include <regex>

#include <mardcpp/utils/Arguments>

namespace mardcpp {

	Arguments::Arguments(int argc, const char **argv) noexcept {
		for (int i = 0; i < argc; ++i) {
			parse(argv[i]);
		}
	}

	Arguments::Arguments(std::istream &input) noexcept {
		String line;
		while (std::getline(input, line)) {
			parse(line);
		}
	}

	bool Arguments::has(const Arguments::Arg &arg) const noexcept {
		return mKwargs.find(arg) != mKwargs.end();
	}

	OutputStream &operator<<(mardcpp::OutputStream &os, const mardcpp::Arguments &arguments) {
		os << "Args: " << arguments.mArgs << '\n';
		os << "Kwargs: " << arguments.mKwargs << '\n';
		return os;
	}

	void Arguments::parse(const String &string) {
		std::smatch results;
		if (std::regex_search(string, results, std::regex("^([^= ]+)=([^= ]+)$"))) {
			mKwargs.emplace(results[1], results[2]);
		} else {
			mArgs.emplace(std::move(string));
		}
	}

	const Arguments::Args &Arguments::getArgs() const noexcept {
		return mArgs;
	}

	const Arguments::Kwargs &Arguments::getKwargs() const noexcept {
		return mKwargs;
	}
}
