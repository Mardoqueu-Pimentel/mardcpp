//
// Created by mard on 10/19/19.
//

#pragma once

#include <sstream>
#include <mardcpp/def.hpp>
#include <mardcpp/String.hpp>

#include <streambuf>

namespace mardCpp::object {
	using string::String;
	using std::ostringstream;

	class Object {

	protected:
		Object &mSelf = *this;

	public:
		Object() = default;

		inline virtual bool operator==(const Object &other) const noexcept {
			return &mSelf == &other.mSelf;
		}

		inline virtual bool operator!=(const Object &other) const noexcept {
			return not(mSelf == other);
		}

		inline virtual Size operator()(Hash) const noexcept {
			const void *memory = static_cast<const void *>(this);
			return reinterpret_cast<Size>(memory);
		}

		[[nodiscard]] virtual String toString() const noexcept {
			ostringstream oss;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
			oss << typeid(typeof(*this)).hash_code();
#pragma clang diagnostic pop
			oss << ':';
			oss << static_cast<const void *>(this);
			return oss.str();
		}
	};

}