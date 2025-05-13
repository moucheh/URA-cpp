#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

template<typename It>
void merge(It begin1, It end1, It begin2, It end2, It dest) {
	while (begin1 != end1 || begin2 != end2) {
		if (begin1 == end1) {
			*dest++ = *begin2++;
		} else if (begin2 == end2) {
			*dest++ = *begin1++;
		}  else if (*begin1 <= *begin2) {
			*dest++ = *begin1++;
		} else if (*begin2 < *begin1) {
			*dest++ = *begin2++;
		}
	}
}

template<typename It>
void mergesort(It begin, It end) {
	int n = end - begin;
	if (n <= 1) return;
	It middle = begin + n / 2;

	mergesort(begin, middle);
	mergesort(middle, end);


	std::vector<typename It::value_type> v;
	v.resize(n);

	merge(begin, middle, middle, end, v.begin());

	std::move(v.begin(), v.end(), begin);
}

int main() {
	srand(time(NULL));
	std::vector<int> v;
	v.reserve(1000);
	for (auto i = 0; i < 1000; ++i) {
		v.push_back(rand() % 100 + 1);
	}
	auto now = std::chrono::system_clock::now();
	mergesort(v.begin(), v.end());
	auto elapsed = std::chrono::system_clock::now() - now;
	for (const auto& element : v) {
		std::cout << element << ' ';
	}
	std::cout << std::endl;
	std::cout << "Time elapsed: " << elapsed.count() / 1000 << "us\n";
	return 0;
}