#include <iostream>

size_t product(size_t n) {
	if (n & 1) --n;
	if (n == 2)
		return 2;
	return n * product(n - 2);
}

int main() {
	std::cout << "Unesite neki prirodan broj n: ";
	size_t n;
	std::cin >> n;
	std::cout << "Proizvod svih parnih priodnih brojeva <= " << n
			  << " iznosi: " << product(n) << std::endl;;
	return 0;
}