#include <iostream>
#include <vector>
#include <algorithm>

template <typename Iter, typename P>
Iter Partition(Iter begin, Iter end, const P& p) {
	auto temp = begin;
	while (p(*temp)) ++temp;
	begin = temp;

	if (begin == end)
		return begin;

	auto it = begin; ++it;

	for (; it != end; ++it) {
		if (p(*it)) {
			std::swap(*it, *begin);
			++begin;
		}
	}

	return begin;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vect) {
	for (const auto& el : vect)
		out << el << ' ';
	return out;
}


int main() {
	std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::partition(v.begin(), v.end(), [](int elem) { return elem % 2 == 0; });
	// v = {0, 2, 4, 6, 8, *1*, 3, 5, 7, 9};
	std::cout << v << std::endl;
	return 0;
}