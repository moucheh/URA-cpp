#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../helpers.hpp"

/*
	slozenost: O(nlogn)
	iteratori: random_access
	memorija: inplace
	stabilnost: nije stabilan
*/


template <typename It>
void insertionsort(It begin, It end) {
	auto it = begin;
	++it;
	for (; it != end; ++it) {
		auto jt = it;
		auto prev = it;
		--prev;
		for (; jt != begin && *jt < *prev; --jt) {
			std::swap(*jt, *prev);
			--prev;
		}
	}
}

template<typename It>
void quicksort(It begin, It end) {
	auto n = end - begin;

	if (n <= 1) return;

	if (n <= 16) {
		insertionsort(begin, end);
		return;
	}

	auto& last = *(end - 1);

	auto it = std::partition(begin, end - 1,
	[&last](const typename It::value_type & value) {
		return value < last;
	});

	std::swap(*it, last);


	quicksort(begin, it);
	quicksort(it + 1, end);
}

int main() {
	srand(time(NULL));
	std::vector<int> v;
	v.reserve(100);
	for (auto i = 0; i < 100; i++) {
		v.push_back(rand() % 100 + 1);
	}

	std::cout << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	std::cout << std::endl;

	auto now = std::chrono::system_clock::now();

	quicksort(v.begin(), v.end());


	auto elapsed = std::chrono::system_clock::now() - now;

	std::cout << "\nNakon sortiranja\n"
			  << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	if (::is_sorted(v.begin(), v.end())) {
		std::cout << "\nPassed" << std::endl;
	} else {
		std::cout << "\nFailed" << std::endl;
	}
	std::cout << "\n\nZa quick sort je potrebno: " << elapsed.count() << "ns" << std::endl;
	return 0;
}