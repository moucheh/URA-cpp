#include <iostream>

unsigned int f(unsigned int a) {
	if (a == 0) {
		return a + 1;
	}
	return f(a - 1);
}

int main() {
	std::cout << "f(100) = " << f(100) << std::endl;
	return 0;
}