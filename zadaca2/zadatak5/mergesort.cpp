#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <utility>
#include "../helpers.hpp"

/*
	slozenost: O(nlog^2(n))
	iteratori: random_access
	memorija: inplace
	stabilnost: stabilan
*/

//preuzeto s geeksfogeeks

int nextGap(int gap) {
	if (gap <= 1)
		return 0;

	return (int)ceil(gap / 2.0);
}


template<typename It>
void merge(It begin, It end) {
	int gap = end - begin + 1;

	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
		for (It it = begin; it + gap <= end; ++it) {
			It jt = it + gap;
			if (*it > *jt)
				std::swap(*it, *jt);
		}
	}
}

template<typename It>
void mergesort(It begin, It end) {
	auto n = end - begin;

	if (n <= 1) return;

	auto middle = begin + n / 2;

	mergesort(begin, middle);
	mergesort(middle, end);

	merge(begin, end);
}

int main() {
	srand(time(NULL));
	std::vector<int> v;
	v.reserve(20);
	for (auto i = 0; i < 20; i++) {
		v.push_back(rand() % 100 + 1);
	}

	std::cout << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	std::cout << std::endl;

	auto now = std::chrono::system_clock::now();

	mergesort(v.begin(), v.end());

	auto sorted = is_sorted(v.begin(), v.end());

	auto elapsed = std::chrono::system_clock::now() - now;

	std::cout << "\nNakon sortiranja\n"
			  << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	if (sorted) {
		std::cout << "\nPassed\n";
	} else {
		std::cout << "\nFailed\n";
	}
	std::cout << "\n\nZa merge sort je potrebno: " << elapsed.count() << "ns" << std::endl;
	return 0;
}