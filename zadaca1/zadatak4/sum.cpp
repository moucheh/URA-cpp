#include <iostream>

int sum(const int* array, int n) {
	if (n == 0) return 0;
	return *array + sum(array + 1, n - 1);
}

int main() {
	int array[] = {0, 0, 1, 1, 2, 3, 5, 8, 13, 21};
	std::cout << "Suma brojeva iznosi: " << sum(array, 10) << std::endl;
	return 0;
}