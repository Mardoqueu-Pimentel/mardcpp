//
// Created by mard on 10/17/19.
//

#pragma once

#include <memory>
#include <ostream>
#include <tuple>
#include <mardcpp/def.hpp>
#include <mardcpp/iosfwd.hpp>
#include <mardcpp/pair.hpp>
#include <mardcpp/typeTraits.hpp>

namespace mardCpp::outStream {
	using pair::Pair;
	
	class OutStream {
		const static inline bool initialized = ([]() noexcept {
			OStream::sync_with_stdio(false);
			return true;
		})();
		
		OutStream &mSelf = *this;
		OStream   &mStream;
		
		template<typename tType>
		inline OutStream &sendToStream(const tType &value) {
			mStream << value;
			return mSelf;
		}
		
		template<typename ... tTypes, Size ... tIndexes>
		inline OutStream &tupleToStream(
			const std::tuple<tTypes...> &tuple,
			std::index_sequence<tIndexes...>
		) {
			mStream << "(";
			((mSelf << std::get<tIndexes>(tuple), mStream << ", "), ...);
			mStream << std::get<sizeof ... (tIndexes)>(tuple);
			mStream << ')';
			return mSelf;
		}
	
	public:
		OutStream(OStream &stream) noexcept
			: mStream(stream) {
			mStream.tie(nullptr);
		}
		
		inline void flush() {
			mStream.flush();
		}
		
		template<
			typename tType,
			EnableIf<IsFundamental<tType>::value or IsStreamable<tType>::value> = true
		>
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
		
		template<typename tType, EnableIf<std::is_pointer<tType>::value> = true>
		inline OutStream &operator<<(const tType &ptr) {
			mSelf.sendToStream(static_cast<const void *>(ptr));
			mSelf << '#' << *ptr;
			return mSelf;
		}
		
		inline OutStream &operator<<(char *cString) {
			mSelf.sendToStream(cString);
			return mSelf;
		}
		
		template<typename ... tTypes>
		inline OutStream &operator<<(const std::tuple<tTypes...> &tuple) {
			return mSelf.tupleToStream<tTypes...>(
				tuple, std::make_index_sequence<
					sizeof...(tTypes) - 1
				>());
		}
		
		template<
			template<typename> class tSmartPtr,
			typename tType, EnableIf<
				IsSame<tSmartPtr<tType>, std::unique_ptr<tType>>::value or
				IsSame<tSmartPtr<tType>, std::shared_ptr<tType>>::value
			> = true
		>
		inline OutStream &operator<<(const tSmartPtr<tType> &ptr) {
			mSelf << *ptr;
			return mSelf;
		}
		
		template<typename tType>
		inline OutStream &operator<<(const std::weak_ptr<tType> &ptr) {
			if (auto p = ptr.lock()) {
				mSelf << *p;
			}
			else {
				mSelf << "nullPtr";
			}
			return mSelf;
		}
		
		template<typename tIter, EnableIf<IsInputIter<tIter>::value> = true>
		inline void range(tIter it, tIter end, Char separator = ' ') {
			if (it != end) {
				tIter nextIt = it;
				while (++nextIt != end) {
					mSelf << *it;
					mStream << separator;
					it = nextIt;
				}
				mSelf << *it;
			}
		}
		
		inline OutStream &operator<<(const char *cStr) {
			mSelf.sendToStream(cStr);
			return mSelf;
		}
		
		template<typename tType, Size tSize>
		inline OutStream &operator<<(const tType (&value)[tSize]) {
			mSelf.range(value, value + tSize);
			return mSelf;
		}
		
		template<
			typename tCont, EnableIf<
				IsCont<tCont>::value and not IsSame<tCont, String>::value
			> = true
		>
		inline OutStream &operator<<(const tCont &cont) {
			mSelf.range(cont.begin(), cont.end());
			return mSelf;
		}
		
		template<typename tIterator, EnableIf<IsInputIter<tIterator>::value> = true>
		inline OutStream &operator<<(const tIterator &iterator) {
			mSelf << *iterator;
			return mSelf;
		}
	};
}
