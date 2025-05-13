#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <forward_list>
#include "../helpers.hpp"

/*
	slozenost: O(n^2)
	iteratori: forward
	memorija: inplace
	stabilnost: stabilan
*/

template <typename It, typename C>
void bubblesort(It begin, It end, C comp) {
	for (; begin != end; ++begin) {
		auto it = begin;
		++it;
		if (it == end) break;
		for (; it != end; ++it) {
			if (comp(*it, *begin))
				std::swap(*it, *begin);
		}
	}
}

int main() {
	std::vector<int> v;
	std::list<int> l;
	std::forward_list<int> fl;
	v.reserve(20);

	for (auto i = 0; i < 20; i++) {
		int random = rand() % 100 + 1;
		v.push_back(random);
		l.push_back(random);
		fl.push_front(random);
	}

	std::cout << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	std::cout << std::endl;

	std::cout << "lista\n";
	print_container(l.begin(), l.end(), std::cout);
	std::cout << std::endl;

	std::cout << "forward lista\n";
	print_container(fl.begin(), fl.end(), std::cout);
	std::cout << std::endl;

	auto now = std::chrono::system_clock::now();

	bubblesort(v.begin(), v.end(), [](const int& a, const int& b) { return a > b; });

	auto elapsed = std::chrono::system_clock::now() - now;

	bubblesort(l.begin(), l.end(), [](const int& a, const int& b) { return a > b; });
	bubblesort(fl.begin(), fl.end(), [](const int& a, const int& b) { return a > b; });


	std::cout << "\nNakon sortiranja\n"
			  << "vektor\n";
	print_container(v.begin(), v.end(), std::cout);
	std::cout << std::endl;

	std::cout << "lista\n";
	print_container(l.begin(), l.end(), std::cout);
	std::cout << std::endl;

	std::cout << "forward lista\n";
	print_container(fl.begin(), fl.end(), std::cout);
	std::cout << "\n\nZa bubble sort je bilo potrebno: " << elapsed.count() << "ns" << std::endl;

	return 0;
}