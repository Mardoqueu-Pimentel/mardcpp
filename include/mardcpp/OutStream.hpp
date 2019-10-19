//
// Created by mard on 10/17/19.
//

#pragma once

#include <ostream>
#include <mardcpp/def.hpp>
#include <mardcpp/iosfwd.hpp>
#include <mardcpp/Pair.hpp>
#include <mardcpp/String.hpp>

namespace mardCpp::outStream {

	using OStream = std::ostream;
	using pair::Pair;
	using string::String;

	class OutStream {

		OutStream &mSelf = *this;
		OStream &mStream;

		template<typename tType>
		inline OutStream &sendToStream(const tType &value) {
			mStream << value;
			return mSelf;
		}

	public:
		OutStream(OStream &stream) noexcept
			: mStream(stream) {}

		template<typename tType, typename std::enable_if<std::is_fundamental<tType>::value, bool>::type _ = true>
		inline OutStream &operator<<(const tType &value) {
			return mSelf.sendToStream(value);
		}

		inline OutStream &operator<<(const StringView &stringView) {
			return mSelf.sendToStream(stringView);
		}

		template<typename tFirst, typename tSecond>
		inline OutStream &operator<<(const Pair<tFirst, tSecond> &pair) {
			mSelf << pair.first << ':' << pair.second;
			return mSelf;
		}

		template <typename tIterator>
		inline void range(tIterator it, tIterator end, Char separator = ' ') {
			if (it != end) {
				tIterator nextIt = it;
				while (++nextIt != end) {
					mSelf << *it;
					mStream << separator;
					it = nextIt;
				}
				mSelf << *it;
			}
		}

		template<
			typename tContainer,
			typename std::enable_if<
				std::is_same<typename std::iterator_traits<typename tContainer::iterator>::value_type, typename tContainer::value_type>::value
				and not std::is_same<tContainer, String>::value,
				bool
			>::type = true
		>
		inline OutStream &operator<<(const tContainer &container) {
			mSelf.range(container.begin(), container.end());
			return mSelf;
		}
	};
}
