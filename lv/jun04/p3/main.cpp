#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Radnik {
	std::string ime;
	std::string prezime;
	double plata;
};

int main() {
	std::vector<Radnik> radnici;

	std::sort(radnici.begin(), radnici.end(), [](auto a, auto b) {
		return a.ime > b.ime;
	});

	std::stable_sort(radnici.begin(), radnici.end(), [](auto a, auto b) {
		return a.plata > b.plata;
	});

	std::stable_sort(radnici.begin(), radnici.end(), [](auto a, auto b) {
		return a.prezime > b.prezime;
	});

	return 0;
}