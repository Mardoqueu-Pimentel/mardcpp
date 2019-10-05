//
// Created by mard on 6/15/19.
//

#pragma once

#include <mardcpp/std/Pair.hpp>
#include <mardcpp/std/String.hpp>
#include <mardcpp/std/UnorderedMap.hpp>
#include <mardcpp/utils/util.hpp>

#include <mardcpp/stream/OutputStream.hpp>
#include <mardcpp/std/Vector.hpp>

namespace mardcpp {

	class Arguments {

	public:
		using Arg = String;
		using Args = Vector<Arg>;
		using Kwarg = Pair<Arg, String>;
		using Kwargs = UnorderedMap<Kwarg::first_type, Kwarg::second_type>;

	private:
		Args mArgs;
		Kwargs mKwargs;

		bool mNextIsValue;
		std::string mNextKey;

		void parseCommands(size_t i, const String &string);

		void parse(const String &string);

	public:
		Arguments(int argc, const char **argv) noexcept;

		explicit Arguments(std::istream &input) noexcept;

		template <typename T>
		T getOrDefault(const Arg& arg, const T& defaultValue) const noexcept {
			auto it = mKwargs.find(arg);
			if (it != mKwargs.end()) {
				return toType<T>(it->second);
			}
			return defaultValue;
		}

		template <typename T>
		T get(const Arg& arg) const {
			auto it = mKwargs.find(arg);
			if (it != mKwargs.end()) {
				return toType<T>(it->second);
			}
			throw std::invalid_argument(format<>("Argument \'%s\' not found.", arg.c_str()));
		}

		template<typename T>
		T get(size_t i) {
			if (i < mArgs.size()) {
				return toType<T>(mArgs[i]);
			}
			throw std::invalid_argument(format<>("Argument %d not found.", i));
		}

		bool has(const Arg& arg) const noexcept;

		bool has(size_t i) const noexcept;

		inline const Args& getArgs() const noexcept;

		inline const Kwargs& getKwargs() const noexcept;

		friend OutputStream& operator<<(mardcpp::OutputStream &os, const mardcpp::Arguments &arguments);
	};

}
