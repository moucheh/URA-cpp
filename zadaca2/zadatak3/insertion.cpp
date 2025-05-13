#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <list>
#include "../helpers.hpp"

/*
	slozenost: O(n^2)
	iteratori: bidirectional
	memorija: inplace
	stabilnost: stabilan
*/

template <typename It, typename C>
void insertionsort(It begin, It end, C comp) {
	auto it = begin;
	++it;
	for (; it != end; ++it) {
		auto jt = it;
		auto prev = jt;
		--prev;
		for (; jt != begin && comp(*jt, *prev); --jt) {
			std::swap(*jt, *prev);
			--prev;
		}
	}
}


int main() {
	srand(time(NULL));
	std::vector<int> v;
	std::list<int> l;
	v.reserve(20);

	for (auto i = 0; i < 20; i++) {
		int random = rand() % 100 + 1;
		v.push_back(random);
		l.push_back(random);
	}

	std::cout << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	std::cout << std::endl;

	std::cout << "lista\n";
	print_container(l.begin(), l.end(), std::cout);
	std::cout << std::endl;

	auto now = std::chrono::system_clock::now();

	insertionsort(v.begin(), v.end(), [](const int& a, const int& b) { return a > b; });

	auto elapsed = std::chrono::system_clock::now() - now;

	insertionsort(l.begin(), l.end(), [](const int& a, const int& b) { return a > b; });

	std::cout << "\nNakon sortiranja\n"
			  << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	std::cout << std::endl;

	std::cout << "lista\n";
	print_container(l.begin(), l.end(), std::cout);
	std::cout << "\n\nZa insertion sort je bilo potrebno: " << elapsed.count() << "ns" << std::endl;

	return 0;
}