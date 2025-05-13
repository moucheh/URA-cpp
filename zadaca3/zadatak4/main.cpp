#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>

std::vector<int> max_sum_subarray(const std::vector<int>& v) {
	std::vector<int> result;
	result.reserve(v.size());
	auto max = 0;
	auto index = 0;
	for (auto i = 0; i < v.size(); ++i) {
		auto sum = 0;
		for (auto j = i; j < v.size(); ++j) {
			sum += v[j];
			if (sum > max) {
				index = i;
				max = sum;
			}
		}
	}
	auto sum = 0;
	for (auto i = index; i < v.size(); ++i) {
		sum += v[i];
		result.push_back(v[i]);
		if (sum == max)
			break;
	}
	return result;
}

int main() {
	std::vector<int> v;
	int x;
	while (std::cin >> x)
		v.push_back(x);

	auto result = max_sum_subarray(v);

	auto sum = 0;

	for (const auto& el : result) {
		sum += el;
		std::cout << el << ' ';
	}

	std::cout << std::endl << sum << std::endl;

	return 0;
}