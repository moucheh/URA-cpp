#include <iostream>

#include <string>

void print_combinations(std::string& combo, int n) {
	if (combo.size() == n) {
		auto ones = 0;
		auto zeros = 0;
		for (auto i = 0; i < n - 1; ++i) {
			if (combo[i] == '1') ++ones;
			if (combo[i] == '0') ++zeros;
		}
		if (ones >= zeros) {
			std::cout << combo << ' ';
		}
		return;
	}

	combo.push_back('1');
	print_combinations(combo, n);
	combo.pop_back();
	combo.push_back('0');
	print_combinations(combo, n);
	combo.pop_back();
}

int main() {
	std::string combo;
	int n = 8;
	combo.reserve(n);
	print_combinations(combo, n);
	return 0;
}