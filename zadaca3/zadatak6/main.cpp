#include <iostream>
#include <vector>

void print_combinations(int n, int s, std::vector<int>& combination, int current) {
	if (combination.size() == n) {
		if (current < s) {
			for (const auto& el : combination) {
				std::cout << el << ' ';
			}
			std::cout << std::endl;
		}
		return;
	}

	for (auto i = 1; i < 7; ++i) {
		combination.push_back(i);
		print_combinations(n, s, combination, current + i);
		combination.pop_back();
	}
}


int main() {
	std::vector<int> combination;
	int n = 7;
	int s = 15;
	print_combinations(n, s, combination, 0);
	return 0;
}