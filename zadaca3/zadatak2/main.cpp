#include <iostream>

int collatz(unsigned long n) {
	static int counter = 0;
	if (n == 1) {
		std::cout << n << ' ';
		auto temp = counter;
		counter = 0;
		return temp;
	}
	++counter;
	std::cout << n << " -> ";
	return (n & 1) ? collatz(3 * n + 1) : collatz(n / 2);
}

int main() {
	int max = 0;
	int index;

	for (auto i = 2; i <= 100; ++i) {
		auto counter = collatz(i);
		std::cout << "\nBilo je potrebno: " << counter << " korak(a).\n\n";
		if (counter > max) {
			max = counter;
			index = i;
		}
	}
	std::cout << "Najvise koraka je potrebno za broj: " << index << ", a to je: " << max << std::endl;
	return 0;
}