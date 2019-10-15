//
// Created by mard on 6/15/19.
//

#pragma once

#include <mardcpp/utils/def.hpp>
#include <mardcpp/String.hpp>
#include <mardcpp/Vector.hpp>
#include <mardcpp/UnorderedSet.hpp>
#include <mardcpp/Pair.hpp>
#include <mardcpp/UnorderedMap.hpp>
#include <mardcpp/utils/util.hpp>

namespace mardCpp {

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
		T get(Size i) const {
			if (i < mArgs.size()) {
				return toType<T>(mArgs[i]);
			}
			throw std::invalid_argument(fmt("Argument %zu not found.", i));
		}

		bool has(const Arg& arg) const noexcept;

		bool has(Size i) const noexcept;

		inline const Args& getArgs() const noexcept;

		inline const Kwargs& getKwargs() const noexcept;

		friend OutputStream& operator<<(mardCpp::OutputStream &os, const mardCpp::Arguments &arguments);

		template<typename T>
		inline T operator[](Size i) const {
			return get<T>(i);
		}
	};

}
