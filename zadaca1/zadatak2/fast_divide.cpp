#include <iostream>
#include <iomanip>

/*doesn't work*/

int fast_divide(int a, int b, int powers = 1, int result = 0) {
	if (a < b) return result;
	if (b * powers >= a) {
		b >>= 1;
		powers >>= 1;
		auto temp = powers;
		a -= b * powers;
		b /= powers;
		powers = 1;
		return fast_divide(a, b << 1, powers << 1, result + temp);
	}
	return fast_divide(a, b << 1, powers << 1);
}

int main() {
	std::cout << " 10 /  3 = " << std::setw(2) << fast_divide(10, 3) << std::endl;
	std::cout << " 69 /  4 = " << std::setw(2) << fast_divide(69, 4) << std::endl;
	std::cout << " 20 / 18 = " << std::setw(2) << fast_divide(20, 18) << std::endl;
	std::cout << " 99 / 45 = " << std::setw(2) << fast_divide(99, 45) << std::endl;
	std::cout << "100 / 50 = " << std::setw(2) << fast_divide(100, 50) << std::endl;
	std::cout << "  3 /  4 = " << std::setw(2) << fast_divide(3, 4) << std::endl;
	std::cout << "150 / 25 = " << std::setw(2) << fast_divide(150, 25) << std::endl;
	std::cout << "420 / 69 = " << std::setw(2) << fast_divide(150, 25) << std::endl;
	return 0;
}