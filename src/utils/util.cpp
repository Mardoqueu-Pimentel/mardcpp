//
// Created by mard on 5/11/19.
//

#include <mardcpp/utils/util.h>

namespace mardcpp {

	const pair <Args, Kwargs> parseArgv(int argc, const char *argv[]) {
		Args args; Kwargs kwargs;

		for (int i = 0; i < argc; ++i) {
			string arg(argv[i]);
			Index j = arg.find('=');
			if (j != std::string::npos) {
				kwargs[arg.substr(0, j)] = arg.substr(j + 1);
			} else {
				args.emplace_back(std::move(arg));
			}
		}

		return {args, kwargs};
	}

}
