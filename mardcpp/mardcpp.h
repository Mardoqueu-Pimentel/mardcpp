//
// Created by mard on 4/27/19.
//

#ifndef CODEBENCH_MARDCPP_H
#define CODEBENCH_MARDCPP_H

#include <cinttypes>
#include <cmath>
#include <cstddef>

namespace mardcpp {



	u64 e(u64 a, u64 b, u64 c) {
		return a * ((u64) pow(b, c));
	}
}

#endif //CODEBENCH_MARDCPP_H
