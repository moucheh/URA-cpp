#include <iostream>
#include <iomanip>

int divide(int a, int b, int counter = 0) {
	if (a == 0) {
		return counter;
	} else if (a < 0) {
		return counter - 1;
	}
	return divide(a - b, b, counter + 1);
}

// T(n) = b => O(n)

int main() {
	std::cout << " 10 /  3 = " << std::setw(2) << divide(10, 3) << std::endl;
	std::cout << " 69 /  4 = " << std::setw(2) << divide(69, 4) << std::endl;
	std::cout << " 20 / 18 = " << std::setw(2) << divide(20, 18) << std::endl;
	std::cout << " 99 / 45 = " << std::setw(2) << divide(99, 45) << std::endl;
	std::cout << "100 / 50 = " << std::setw(2) << divide(100, 50) << std::endl;
	std::cout << "  3 /  4 = " << std::setw(2) << divide(3, 4) << std::endl;
	std::cout << "150 / 25 = " << std::setw(2) << divide(150, 25) << std::endl;
	std::cout << "420 / 69 = " << std::setw(2) << divide(150, 25) << std::endl;
	return 0;
}