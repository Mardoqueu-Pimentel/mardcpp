//
// Created by mard on 10/7/19.
//

#include <mardcpp/utils/hash.hpp>
#include <mardcpp/utils/util.hpp>

namespace mardCpp {

	Size nextPrimeOf(Size n) {
		for (Size i = n; i <= 0xFFFFFFFFFFFFFFFF; ++i) {
			if (isPrime(i)) {
				return i;
			}
		}
		throw makeError("couldn't find a representable prime greater than %zu", n);
	}

	bool isPrime(Size n) noexcept {
		for (Size i = 2; i <= std::sqrt(n) + 1; ++i) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

}

