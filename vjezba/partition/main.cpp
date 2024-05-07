#include <iostream>
#include <vector>

namespace my {
	template<typename forward_it, typename lambda>
	forward_it partition(forward_it begin, forward_it end, const lambda& predicate) {
		auto temp = begin;

		while (predicate(*temp)) ++temp;
		begin = temp;

		if (begin == end) return begin;

		auto it = begin; ++it;

		for (; it != end; ++it) {
			if (predicate(*it)) {
				std::swap(*it, *begin);
				++begin;
			}
		}
		return begin;
	}
}

int main() {
	std::vector<int> v{2, 2, 2, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto it = my::partition(v.begin(), v.end(), [](auto n) { return n & 1; });
	v.erase(it, v.end());
	for (const auto& el : v)
		std::cout << el << ' ';
	std::cout << std::endl;
	return 0;
}