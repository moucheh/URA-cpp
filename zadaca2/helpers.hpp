#pragma once
#include <iostream>

template<typename it>
void print_container(it begin, it end, std::ostream& out) {
	for (; begin != end; ++begin) {
		out << *begin << ' ';
	}
}

template<typename It>
bool is_sorted(It begin, It end) {
	if (begin == end) return true;

	auto it = std::next(begin);

	if (it == end) return true;

	while (it != end) {
		if (*begin > *it) {
			return false;
		}
		++begin;
		++it;
	}
	return true;
}