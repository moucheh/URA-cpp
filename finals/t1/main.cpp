#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

/*
	data je definicija strukture Element ispod

	dobije se std::list sa elementima tipa Element, sortiranim po kljucu u opadajucem redoslijedu

	napisati funkciju potpisa
	template<typename K, typename V>
	Element<K, V>* find(std::vector<Element<K,V>>&, const K&);
	koja vrati pointer na element koji ima isti kljuc, a nullptr u suprotnom

	obrazloziti algoritam u kratkim crtama i koja je slozenost moguca

*/

template<typename K, typename V>
struct Element {
	K key;
	V value;
};

template<typename K, typename V>
Element<K, V>* find(std::vector<Element<K, V>>& v, const K& k) {
	if (k > v.front().key) return nullptr;
	if (k < v.back().key) return nullptr;

	// bazni slucajevi, ako se element ne nalazi u vektoru slozenost je O(1)
	// ovo znamo sa sigornoscu, jer je vektor sortiran u opadajujcem redoslijedu

	for (auto it = v.begin(); it != v.end(); ++it)
		if (k == it->key)
			return &*it;

	return nullptr;
}

int main() {
	srand(420);

	std::vector<Element<int, double>> v;
	v.reserve(20);

	for (auto i = 0; i < 20; ++i) {
		auto t = rand() % 100 + 1;
		v.push_back(Element<int, double> {t, t * 0.69});
	}

	std::sort(v.begin(), v.end(),
	[](const auto & a, const auto & b) { return a.key > b.key; });

	for (const auto& [key, value] : v)
		std::cout << "{ key: " << key << ", value: " << value << "}\n";

	std::cout << std::endl;

	auto it = find(v, 30);

	if (it != nullptr)
		std::cout << "Element s kljucem 30 je pronadjen i njegova vrijednost je: "
				  << it->value << std::endl;
	else
		std::cout << "Element nije pronadjen!" << std::endl;


	return 0;
}