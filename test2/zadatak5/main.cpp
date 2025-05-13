#include <iostream>

long f(long n) {
	if (n == 1) return 2;
	if (n == 2) return 1;
	if (n == 3) return 3;
	long n_3 = 2;
	long n_2 = 1;
	long n_1 = 3;
	long f_n;
	for (auto i = 4; i <= n; ++i) {
		f_n = n_1 - n_3 * n_2;
		n_3 = n_2;
		n_2 = n_1;
		n_1 = f_n;
	}
	return f_n;
}
int main() {
	std::cout << "f(9) = " << f(9) << std::endl;
	return 0;
}