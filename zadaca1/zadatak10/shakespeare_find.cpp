#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

int main() {
	std::ifstream file("shakespeare.txt");
	if (!file) {
		std::cout << "404. File nije pronadjen!" << std::endl;
		return 1;
	}

	std::vector<std::string> words;
	words.reserve(1000000);

	std::string input;

	while (file >> input) {
		words.push_back(input);
	}

	std::sort(words.begin(), words.end());

	while (true) {
		std::cout << "Enter word: ";
		std::cin >> input;
		if (!std::cin) break;
		auto start = std::chrono::system_clock::now();

		auto found = std::binary_search(words.begin(), words.end(), input);

		auto end = std::chrono::system_clock::now();

		std::cout << "\nWord " << input << ((found) ? " was " : " wasn't ") << "found." << std::endl;

		auto interval = end - start;
		std::cout << "Binary search took: "
				  << interval.count() << "ns" << std::endl;
	}
	file.close();
	return 0;
}