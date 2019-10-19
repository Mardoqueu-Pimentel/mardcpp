//
// Created by mard on 10/19/19.
//

#include <mardcpp/hashing.hpp>
#include <mardcpp/utility.hpp>

namespace mardCpp::hashing {

	using mardCpp::utility::makeError;

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

