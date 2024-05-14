#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

template<typename forward_it>
bool is_array_sorted(forward_it begin, forward_it end) {
	for (; begin != end; ++begin) {
		auto it = begin;
		++it;
		if (it == end) break;
		if (*begin > *it) {
			return false;
		}
	}
	return true;
}

int main() {
	srand(time(NULL));
	std::vector<int> v;
	v.reserve(20);
	for (auto i = 0; i < 20; ++i) {
		v.push_back(rand() % 99 + 1);
	}

	for (const auto& el : v) {
		std::cout << el << ' ';
	}
	std::cout << std::endl;

	std::cout << "Prije sorta: " << std::boolalpha << is_array_sorted(v.begin(), v.end()) << std::endl;

	std::sort(v.begin(), v.end());

	std::cout << "Poslije sorta: " << std::boolalpha << is_array_sorted(v.begin(), v.end()) << std::endl;


	for (const auto& el : v) {
		std::cout << el << ' ';
	}
	std::cout << std::endl;

	return 0;
}