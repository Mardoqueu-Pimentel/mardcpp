//
// Created by mard on 10/24/19.
//

#pragma once

#include <type_traits>

namespace mardCpp {
	
	template<typename tBase, typename tDerived>
	using IsBaseOf = std::is_base_of<tBase, tDerived>;
	
	using FalseType = std::false_type;
	
	template<typename tType, tType tValue>
	using IntegralConstant = std::integral_constant<tType, tValue>;
	
	template<typename tT1, typename tT2>
	using IsSame = std::is_same<tT1, tT2>;

	template<typename tType>
	using IsFundamental = std::is_fundamental<tType>;
	
	template<bool...>
	struct One;
	
	template<>
	struct One<> : public IntegralConstant<bool, false> {};
	
	template<bool B1>
	struct One<B1> : public IntegralConstant<bool, B1> {};
	
	template<bool B1, bool ... Bn>
	struct One<B1, Bn...> : public IntegralConstant<bool, B1 or One<Bn...>::value> {};
	
	template<bool...>
	struct All;
	
	template<>
	struct All<> : public IntegralConstant<bool, false> {};
	
	template<bool B1>
	struct All<B1> : public IntegralConstant<bool, B1> {};
	
	template<bool B1, bool ... Bn>
	struct All<B1, Bn...> : public IntegralConstant<bool, B1 and All<Bn...>::value> {};
	
	template<bool tBool>
	using EnableIf = typename std::enable_if<tBool, bool>::type;

	struct Streamable {};
	
	template<typename tType>
	using IsStreamable = IsBaseOf<Streamable, tType>;
	
	template<typename tTag>
	using IsInputTag = IsBaseOf<std::input_iterator_tag, tTag>;

	template<typename tIter>
	using IsInputIter = IsInputTag<typename tIter::iterator_category>;
	
	template<typename tCont>
	using IsCont = IsInputIter<typename tCont::iterator>;
}