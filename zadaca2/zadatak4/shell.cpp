#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include "../helpers.hpp"

/*
	slozenost: O(n^(3/2))
	iteratori: random access
	memoraija: inplace
	stabilnost: nije stabilan
*/

template <typename It, typename C>
void insertionsort_impl(It begin, It end, int increment, C comp) {
	for (int i = increment; i < (end - begin); i += increment) {
		for (int j = i; j >= increment; j -= increment) {
			if (comp(begin[j], begin[j - increment])) {
				std::swap(begin[j], begin[j - increment]);
			} else {
				break;
			}
		}
	}
}

template <typename It, typename C>
void shellsort(It begin, It end, C comp) {
	for (int increment = (end - begin) / 2; increment >= 1; increment /= 2) {
		for (int i = 0; i < increment; i++) {
			insertionsort_impl(begin + i, end - i, increment, comp);
		}
	}
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

	shellsort(v.begin(), v.end(), [](const int& a, const int& b) { return a > b; });

	auto elapsed = std::chrono::system_clock::now() - now;

	std::cout << "\nNakon sortiranja\n"
			  << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	std::cout << "\n\nZa shell sort je potrebno: " << elapsed.count() << "ns" << std::endl;
	return 0;
}