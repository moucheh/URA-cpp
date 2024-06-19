#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

/*
	implementirati funkciju
	template<typename T>
	void shellsort(T* niz, size_t n);
*/

template<typename T>
void shellsort_impl(T* niz, size_t n, int increment) {
	for (auto i = increment; i <= n; i += increment) {
		for (auto j = i; j >= 0 && niz[j] < niz[j - increment]; j -= increment) {
			std::swap(niz[j], niz[j - increment]);
		}
	}
}

template<typename T>
void shellsort(T* niz, size_t n) {
	for (auto k = n / 2; k >= 1; k /= 2) {
		shellsort_impl(niz, n, k);
	}
}


int main() {
	srand(time(NULL));

	std::vector<int> v;
	v.reserve(20);

	for (auto i = 0; i < 20; ++i) {
		v.push_back(rand() % 100 + 1);
	}

	shellsort(v.data(), v.size());

	for (const auto& el : v) {
		std::cout << el << ' ';
	}

	std::cout << "\nsorted: "
			  << std::boolalpha
			  << std::is_sorted(v.begin(), v.end())
			  << std::endl;

	return 0;
}