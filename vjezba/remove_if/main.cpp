#include <iostream>
#include <vector>

namespace my {
	template<typename forward_it, typename lambda>
	forward_it remove_if(forward_it begin, forward_it end, const lambda& predicate) {
		auto temp = begin;

		while (!predicate(*temp)) ++temp;
		begin = temp;

		if (begin != end) {
			auto it = begin; ++it;
			for (; it != end; ++it) {
				if (!predicate(*it)) {
					std::swap(*it, *begin);
					++begin;
				}
			}
		}

		return begin;
	}
}

int main() {
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	auto it = my::remove_if(v.begin(), v.end(), [](auto a) { return a & 1; });
	v.erase(it, v.end());

	for (const auto& el : v)
		std::cout << el << ' ';
	std::cout << std::endl;
	return 0;
}