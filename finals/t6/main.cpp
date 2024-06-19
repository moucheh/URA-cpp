#include <iostream>
#include <vector>
#include <algorithm>

/*
	napisati funkciju int min_br_flasa(int, std::vector<int>&);

	koja vraca koliki je minimalan broj koje se mogu napuniti da se kanister
	u potpunosti iscrpi ili da ostane kolicina vode koja je manja od
	kapaciteta najmanje flase

	koja se metodologija koristi za rijesavanje i implementirati

	potrebno je koristiti greedy (pohlepni) algoritam
	kriterij je sipati vodu u boce s najvecim kapacitetom
	dok se ne iscrpi kapacitet kanistera
*/

int min_br_flasa(int capacity, std::vector<int>& bottles) {
	auto res = 0;

	std::sort(bottles.begin(), bottles.end(), [](const auto & a, const auto & b) { return a > b; });

	for (const auto& bottle : bottles) {
		if (capacity - bottle >= 0) {
			capacity -= bottle;
			++res;
		}

		if (capacity == 0)
			return res;
	}

	return res;
}

int main() {
	int capacity = 25;

	std::vector<int> bottles{4, 3, 20, 7, 4, 1, 2, 1, 10, 15};

	std::cout << min_br_flasa(capacity, bottles) << std::endl;

	return 0;
}