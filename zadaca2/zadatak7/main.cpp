#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

namespace my {
	//preuzeto s geeksforgeeks
	int nextGap(int gap) {
		if (gap <= 1)
			return 0;

		return (int)ceil(gap / 2.0);
	}

	template<typename It, typename lambda>
	void merge(It begin, It end, lambda predicate) {
		int gap = end - begin + 1;

		for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
			for (auto it = begin; it + gap != end; ++it) {
				It jt = it + gap;
				if (predicate(*jt, *it))
					std::swap(*it, *jt);
			}
		}
	}

	template<typename It, typename lambda>
	void mergesort(It begin, It end, lambda predicate) {
		auto n = end - begin;

		if (n <= 1) return;

		auto middle = begin + n / 2;

		mergesort(begin, middle, predicate);
		mergesort(middle, end, predicate);

		merge(begin, end, predicate);
	}
}

struct Tim {
	std::string naziv;
	int bodovi;
	int primljeniGolovi;
	int postignutiGolovi;
};

int main() {
	std::vector<Tim> timovi;
	timovi.reserve(20);

	timovi.push_back({"Manchester United", 60, 58, 57});
	timovi.push_back({"Fulham", 47, 61, 55});
	timovi.push_back({"Manchester City", 91, 34, 96});
	timovi.push_back({"Chelsea", 63, 63, 77});
	timovi.push_back({"AFC Bournemouth", 63, 56, 88});
	timovi.push_back({"Everton", 40, 51, 40});
	timovi.push_back({"West Ham United", 52, 74, 60});
	timovi.push_back({"Arsenal", 89, 29, 91});
	timovi.push_back({"Aston Villa", 89, 25, 89});
	timovi.push_back({"Brighton & Hove Albion", 48, 62, 55});
	timovi.push_back({"Liverpool", 82, 41, 86});
	timovi.push_back({"Crystal Palace", 49, 58, 57});
	timovi.push_back({"Tottenham Hostpur", 66, 61, 74});
	timovi.push_back({"Brentford", 40, 51, 42});

	// Vektor se sortira po kriterijima u obrnutom redoslijedu od onog u kojem su navedeni,
	// i potrebno je da sortiranje bude stabilno
	// u ovom primjeru koristen je inplace merge sort koji je slozenosti O(nlog^2(n))

	my::mergesort(timovi.begin(), timovi.end(), [](const Tim & a, const Tim & b) {
		return a.naziv < b.naziv;
	});

	my::mergesort(timovi.begin(), timovi.end(), [](const Tim & a, const Tim & b) {
		return a.postignutiGolovi - a.primljeniGolovi > b.postignutiGolovi - b.primljeniGolovi;
	});

	my::mergesort(timovi.begin(), timovi.end(), [](const Tim & a, const Tim & b) {
		return a.postignutiGolovi > b.postignutiGolovi;
	});

	my::mergesort(timovi.begin(), timovi.end(), [](const Tim & a, const Tim & b) {
		return a.bodovi < b.bodovi;
	});

	std::cout << "Naziv" << std::string(20, ' ')
			  << '|' << std::string(4, ' ') << "Bodovi" << std::string(4, ' ')
			  << "| Posignuti Golovi "
			  << "| Primljeni Golovi "
			  << "| Gol Razlika\n"
			  << std::string(92, '-') << std::endl;

	for (const auto& tim : timovi) {
		std::cout << tim.naziv << std::string(25 - tim.naziv.length(), ' ') << '|'
				  << std::setw(8) << tim.bodovi << std::string(6, ' ') << '|'
				  << std::setw(10) << tim.postignutiGolovi <<  std::string(8, ' ') << '|'
				  << std::setw(10) << tim.primljeniGolovi <<  std::string(8, ' ') << '|'
				  << std::setw(8) << tim.postignutiGolovi - tim.primljeniGolovi << '\n';
	}

	return 0;
}