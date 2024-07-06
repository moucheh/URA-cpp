#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

//ukoliko se indeksi krecu od 0 do n-1
//racunanje djece cvora je malo drukcije,

//lijevo dijete cvora je indeks_cvora * 2 + 1
//desno dijete cvora je indeks_cvora * 2 + 2

//roditelj cvora se racuna na nacin,
//ako je indeks neparan, samo se podijeli s 2
//ukoliko je paran, potrebno je i oduzeti 1
//ovo je najbolje da se skicira

template<typename T>
void rearrange_downwards(T* arr, int root, int last_child) {
	while (2 * root + 1 <= last_child) {
		auto child = 2 * root + 1;
		if (child < last_child && arr[child] < arr[child + 1]) ++child;

		if (arr[root] > arr[child]) break;

		std::swap(arr[root], arr[child]);

		root = child;
	}
}

template<typename T>
void heapsort(T* arr, int size) {

	/*
		i = size / 2 + ~(size & 1)

		ukoliko je size paran, size & 1 ce biti 0,
		kada se uradi prvi komplement, dobije se -1

		ukoliko je size neparan, size & ce biti 1,
		kada se uradi prvi komplement, dobije se 0
	*/

	// uspostavlja se gomila krenuvsi od prvog cvora koji nije list

	for (auto i = size / 2 + ~(size & 1); i >= 0; --i)
		rearrange_downwards(arr, i, size);

	auto i = size - 1;

	// mijenja se prvi i posljednji, te se uspostavlja gomila za elemente od 0 do n-1

	while (i > 0) {
		std::swap(arr[0], arr[i]);

		rearrange_downwards(arr, 0, --i);
	}
}

int main() {
	srand(time(NULL));
	auto counter = 0;
	for (auto i = 0; i < 1000; ++i) {
		std::vector<int> v;
		v.reserve(1000);
		for (auto i = 0; i < 1000; ++i) {
			v.push_back(rand() % 1000 + 1);
		}

		// for (const auto& el : v) {
		// 	std::cout << el << ' ';
		// }
		// std::cout << std::endl;

		heapsort(v.data(), v.size());

		// for (const auto& el : v) {
		// 	std::cout << el << ' ';
		// }
		// std::cout << std::endl;
		if (std::is_sorted(v.begin(), v.end())) ++counter;
	}

	std::cout << "passed " << counter << " / 1000 times" << std::endl;

	return 0;
}