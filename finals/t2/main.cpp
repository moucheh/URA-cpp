#include <iostream>
#include <vector>
#include <cstdlib>

/*
	implementirati funkciju void neg_pos(std::vector<long>&);

	koja dijeli vektor na dva dijela, na pocetku trebaju biti negativni brojevi,
	pa nakon njih svi nenegativni brojevi

	potrebno je ukratko objasniti algoritam i napisati koje je slozenosti

	algoritam je slozenosti O(n), jer je potrebno samo jednom proci kroz sve elemente
*/

void neg_pos(std::vector<long>& v) {
	auto it = v.begin();
	while (*it < 0) ++it;

	if (it == v.end()) return;

	for (auto jt = it; jt != v.end(); ++jt) {
		if (*jt < 0) {
			std::iter_swap(it, jt);
			++it;
		}
	}
}

int main() {
	srand(time(NULL));

	std::vector<long> v;
	v.reserve(20);

	for (auto i = 0; i < 20; ++i) {
		v.push_back((rand() % 100 + 1) * ((i & 1) ? -1 : 1));
	}

	neg_pos(v);

	for (const auto& el : v) {
		std::cout << el << ' ';
	}

	std::cout << std::endl;

	return 0;
}