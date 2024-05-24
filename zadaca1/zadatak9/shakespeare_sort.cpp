#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

/*
	Prvi pristup traje cca 420 milisekundi
	dok drugi pristup traje oko pola sata
	na mojoj masini
*/

int main() {
	std::ifstream file("shakespeare.txt");
	if (!file) {
		std::cout << "404. File nije pronadjen!" << std::endl;
		return 1;
	}

	std::vector<std::string> words;
	words.reserve(1000000);

	std::string input;
	auto start = std::chrono::system_clock::now();

	while (file >> input) {
		words.push_back(input); // O(n)
	}

	std::sort(words.begin(), words.end()); // O(nlogn)

	//ukupno O(nlogn)

	auto end = std::chrono::system_clock::now();

	auto interval = end - start;
	std::cout << "First approach, time elapsed: "
			  << interval.count() / 1000000 << "ms" << std::endl;

	words.clear();
	file.close();
	file.clear();

	std::ifstream file2("shakespeare.txt");

	std::vector<std::string> words2;
	words2.reserve(1000000);
	start = std::chrono::system_clock::now();
	while (file2 >> input) { //O(n)
		auto it = std::upper_bound( // O(logn)
					  words2.begin(),
					  words2.end(),
					  input
				  );
		words2.insert(it, input); //O(n)
	} //ukupno O(n^2logn)

	end = std::chrono::system_clock::now();
	interval = end - start;
	std::cout << "Second approach, time elapsed: "
			  << interval.count() / 1000000000 / 60 << "min" << std::endl;
	file2.close();
	return 0;
}