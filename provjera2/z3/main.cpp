#include <iostream>
#include <vector>

template<typename forward_it>
bool is_array_sorted(forward_it begin, forward_it end) {
	for (; begin != end; ++begin) {
		auto it = begin;
		++it;
		if (it == end) break;
		if (*begin > *it) {
			return false;
		}
	}
	return true;
}


void print_vector(const std::vector<int>& v) {
	for (const auto& el : v) {
		std::cout << el << ' ';
	}
	std::cout << std::endl;
}

template<typename It, typename lambda>
void selectionsort(It begin, It end, lambda p) {
	for (; begin != end; ++begin) {
		auto select_min = begin;
		auto select_max = begin;
		auto it = begin;
		++it;
		for (; it != end; ++it) {
			if (p(*it, *select_min)) {
				select_min = it;
			}

			if (!p(*it, *select_max)) {
				select_max = it;
			}
		}
		--end;
		if (begin != select_min)
			std::swap(*begin, *select_min);
		if (end != select_max)
			std::swap(*end, *select_max);
	}
}

int main() {
	srand(time(NULL));
	for (auto j = 0; j < 5; ++j) {
		std::vector<int> v;
		v.reserve(20);
		for (auto i = 0; i < 20; ++i) {
			v.push_back(rand() % 99 + 1);
		}
		std::cout << "Before sort:\n";
		print_vector(v);
		std::cout << std::endl;

		selectionsort(v.begin(), v.end(), [](auto a, auto b) { return a < b; });

		std::cout << "After sort:\n";
		print_vector(v);
		std::cout << std::endl;

		std::cout << "Sorted = " << std::boolalpha << is_array_sorted(v.begin(), v.end()) << '\n';
		std::cout << std::string(50, '=') << std::endl;
	}
	return 0;
}