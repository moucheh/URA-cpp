#include <iostream>
#include <vector>

template<typename It, typename T>
It upper_bound(It begin, It end, const T& element) {
	It old_end = end;
	if (element < *begin) return begin;
	if (element > *(end - 1)) return end;
	auto n = end - begin;
	auto middle = begin + n / 2;
	if (element == *middle) {
		return middle;
	} else if (element < *middle) {
		return upper_bound(begin, middle, element);
	} else if (element > *middle) {
		return upper_bound(middle + 1, end, element);
	}
	return old_end;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vect) {
	for (const auto& el : vect)
		out << el << ' ';
	return out;
}

int main() {
	std::vector<int> v{2, 4, 6, 8, 10};
	auto it = upper_bound(v.begin(), v.end(), 8);
	it = upper_bound(v.begin(), v.end(), 7);
	std::cout << "Original array:\n" << v << std::endl;
	v.insert(it, 7);
	std::cout << "Inserting 7\n" << v << std::endl;
	it = upper_bound(v.begin(), v.end(), 20);
	v.insert(it, 20);
	std::cout << "Inserting 20\n" << v << std::endl;
	it = upper_bound(v.begin(), v.end(), 7);
	v.insert(it, 7);
	std::cout << "Inserting 7\n" << v << std::endl;
	return 0;
}