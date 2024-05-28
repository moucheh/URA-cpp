#include <iostream>
#include <vector>

std::vector<int> parni(int n, int counter = 0) {
	static std::vector<int> res;
	if (counter > n)
		return res;
	res.push_back(counter);
	return parni(n, counter + 2);
}

int main() {
	std::vector<int> v = parni(9);

	for (const auto& el : v) {
		std::cout << el << ' ';
	}
	std::cout << std::endl;
	return 0;
}