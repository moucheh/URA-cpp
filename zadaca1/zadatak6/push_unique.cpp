#include <iostream>
#include <vector>

bool push_unique(std::vector<int>& vect, int el) {
	bool element_exists = false;
	for (auto it = vect.begin(); it != vect.end(); ++it) {
		if (*it == el) {
			element_exists = true;
			break;
		}
	}
	if (!element_exists)
		vect.push_back(el);
	return !element_exists;
}

int main() {
	std::vector<int> vect{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << "Broj 9 " << (push_unique(vect, 9) ? "je uspjesno " : "vec postoji, te nije ")
			  << "dodan u vektor" << std::endl;
	std::cout << "Broj 25 " << (push_unique(vect, 25) ? "je uspjesno " : "vec postoji, te nije ")
			  << "dodan u vektor" << std::endl;
	std::cout << "Broj 6 " << (push_unique(vect, 6) ? "je uspjesno " : "vec postoji, te nije ")
			  << "dodan u vektor" << std::endl;
	return 0;
}