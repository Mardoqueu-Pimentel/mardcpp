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
#include <mardcpp/std/UnorderedSet.hpp>

namespace mc {

	class Arguments {

	public:
		using Arg = String;
		using Args = Vector<Arg>;
		using ExistingArgs = UnorderedSet<String>;
		using Kwarg = Pair<Arg, String>;
		using Kwargs = UnorderedMap<Kwarg::first_type, Kwarg::second_type>;

	private:
		Args mArgs;
		Kwargs mKwargs;
		ExistingArgs mExistingArgs;

		bool mNextIsValue;
		std::string mNextKey;

		void parseCommand(const String &string) noexcept;

		void parse(const String &string) noexcept;

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

		template <typename T = String>
		T get(const Arg& arg) const {
			auto it = mKwargs.find(arg);
			if (it != mKwargs.end()) {
				return toType<T>(it->second);
			}
			throw std::invalid_argument(fmt("Argument \'%s\' not found.", arg.c_str()));
		}

		template<typename T = String>
		T get(size_t i) const {
			if (i < mArgs.size()) {
				return toType<T>(mArgs[i]);
			}
			throw std::invalid_argument(fmt("Argument %zu not found.", i));
		}

		bool has(const Arg& arg) const noexcept;

		bool has(size_t i) const noexcept;

		inline const Args& getArgs() const noexcept;

		inline const Kwargs& getKwargs() const noexcept;

		friend OutputStream& operator<<(mc::OutputStream &os, const mc::Arguments &arguments);

		template<typename T>
		inline T operator[](size_t i) const {
			return get<T>(i);
		}
	};

}
