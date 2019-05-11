//
// Created by mard on 5/11/19.
//

#ifndef MARDCPP_IOS_H
#define MARDCPP_IOS_H

#include <iostream>
#include <unordered_map>
#include <vector>

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T>& arr) {
	for (auto &e: arr) {
		os << e << ' ';
	}
	return os;
}

template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<T1, T2>& dict) {
	for (auto &[key, val]: dict) {
		os << key << ':' << val << ' ';
	}
	return os;
}

#endif //MARDCPP_IOS_H
