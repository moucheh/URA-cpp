#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <vector>
#include <map>

template<typename It>
void quicksort(It begin, It end) {
	auto n = end - begin;
	if (n <= 1) return;

	auto& last = *(end - 1);

	auto it = std::partition(begin, end - 1,
	[&last](const auto & elem) { return elem <= last; });

	std::swap(*it, last);
	quicksort(begin, it);
	quicksort(it + 1, end);
}

int main() {
	srand(time(NULL));
	std::vector<int> v;
	v.reserve(1000000);
	for (auto i = 0; i < 1000000; ++i) {
		v.push_back(rand() % 100 + 1);
	}

	auto now = std::chrono::system_clock::now();

	quicksort(v.begin(), v.end());

	auto elapsed = std::chrono::system_clock::now() - now;

	for (const auto& element : v) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;
	std::cout << "Time elapsed: " << elapsed.count() / 1000 << "us" << std::endl;
	return 0;
}