//
// Created by mard on 6/15/19.
//

#pragma once

#include <mardcpp/std/Pair.hpp>
#include <mardcpp/std/String.hpp>
#include <mardcpp/std/UnorderedMap.hpp>
#include <mardcpp/std/UnorderedSet.hpp>
#include <mardcpp/utils/util.hpp>

#include <mardcpp/stream/OutputStream.hpp>

namespace mardcpp {

	class Arguments {
	public:
		using Arg = String;
		using Args = UnorderedSet<Arg>;
		using Kwarg = Pair<Arg, String>;
		using Kwargs = UnorderedMap<Kwarg::first_type, Kwarg::second_type>;

	private:
		Args mArgs;
		Kwargs mKwargs;

		void parse(const String &string);

	public:
		Arguments(int argc, const char **argv) noexcept;

		Arguments(std::istream &input) noexcept;

		template <typename T>
		const T getOrDefault(const Arg& arg, const T& defaultValue) const noexcept {
			auto it = mKwargs.find(arg);
			if (it != mKwargs.end()) {
				return toType<T>(it->second);
			}
			return defaultValue;
		}

		template <typename T>
		const T get(const Arg& arg) const {
			auto it = mKwargs.find(arg);
			if (it != mKwargs.end()) {
				return toType<T>(it->second);
			}

			static char err[1024];
			snprintf(err, 1024, "Argument \'%s\' not found!", arg.c_str());
			throw std::invalid_argument(err);
		}

		bool has(const Arg& arg) const noexcept;

		inline const Args& getArgs() const noexcept;

		inline const Kwargs& getKwargs() const noexcept;

		friend OutputStream& operator<<(mardcpp::OutputStream &os, const mardcpp::Arguments &arguments);
	};

}