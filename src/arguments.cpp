//
// Created by mard on 6/15/19.
//

#include <regex>
#include <mardcpp/arguments.hpp>
#include <mardcpp/outStream.hpp>

namespace mardCpp::arguments {

	Arguments::Arguments(int argc, const char **argv) noexcept
		: mNextIsValue(false) {
		for (size_t i = 0; i < static_cast<size_t>(argc); ++i) {
			parseCommand(argv[i]);
		}
		if (mNextIsValue) {
			mArgs.emplace_back(mNextKey);
		}
		for (const auto &arg : mArgs) {
			mExistingArgs.insert(arg);
		}
	}

	Arguments::Arguments(std::istream &input) noexcept
		: mNextIsValue(false) {
		std::string line;
		for (size_t i = 0; std::getline(input, line); ++i) {
			parse(line);
		}
	}

	bool Arguments::has(const Arguments::Arg &arg) const noexcept {
		return mExistingArgs.find(arg) != mExistingArgs.end();
	}

	bool Arguments::has(size_t i) const noexcept {
		return i < mArgs.size();
	}

	OutStream &operator<<(OutStream &os, const Arguments &arguments) {
		os << "Args: " << arguments.mArgs << '\n';
		os << "Kwargs: " << arguments.mKwargs << '\n';
		return os;
	}

	void Arguments::parse(const String &string) noexcept {
		std::smatch results;
		if (std::regex_search(string, results, std::regex("^([^= ]+)=([^= ]+)$"))) {
			mKwargs.emplace(results[1], results[2]);
		} else {
			mArgs.emplace_back(string);
		}
	}

	void Arguments::parseCommand(const String &string) noexcept {
		if (mNextIsValue) {
			mNextIsValue = false;
			if (string[0] != '-' or string[1] != '-') {
				mKwargs[mNextKey] = string;
			} else {
				mNextIsValue = true;
				mArgs.emplace_back(mNextKey);
				mNextKey = string.substr(2);
			}
		} else {
			if (string[0] == '-' and string[1] == '-') {
				mNextIsValue = true;
				mNextKey = string.substr(2);
			} else {
				mArgs.emplace_back(string);
			}
		}
	}

	const Arguments::Args &Arguments::getArgs() const noexcept {
		return mArgs;
	}

	const Arguments::Kwargs &Arguments::getKwargs() const noexcept {
		return mKwargs;
	}
}
