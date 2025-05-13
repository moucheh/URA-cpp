#include <iostream>
#include <chrono>
#include <map>

int a_rec(int n) {
	if (n == 0)
		return 2;
	if (n == 1)
		return 4;
	if (n == 2)
		return 12;
	return 3 * a_rec(n - 3) + 2 * a_rec(n - 2) + a_rec(n - 1);
}

int a_mem(int n) {
	static std::map<int, int> m;
	if (n == 0)
		return 2;
	if (n == 1)
		return 4;
	if (n == 2)
		return 12;
	if (m[n] == 0)
		m[n] = 3 * a_rec(n - 3) + 2 * a_rec(n - 2) + a_rec(n - 1);

	return m[n];
}

int a_din(int n) {
	if (n == 0)
		return 2;
	if (n == 1)
		return 4;
	if (n == 2)
		return 12;
	int a_n_3 = 2;
	int a_n_2 = 4;
	int a_n_1 = 12;
	int a_n;
	for (auto i = 3; i <= n; ++i) {
		a_n = 3 * a_n_3 + 2 * a_n_2 + a_n_1;
		a_n_3 = a_n_2;
		a_n_2 = a_n_1;
		a_n_1 = a_n;
	}
	return a_n;
}

int main() {
	int (*a)(int) = a_rec;

	std::cout << "Rekurzija:" << std::endl;

	for (auto i = 0; i <= 10; ++i) {
		std::cout << "a(" << i << ") = " << a(i) << '\n';
	}

	a = a_mem;

	std::cout << "Memoizacija" << std::endl;

	for (auto i = 0; i <= 10; ++i) {
		std::cout << "a(" << i << ") = " << a(i) << '\n';
	}

	a = a_din;

	std::cout << "Dinamicko programiranje:" << std::endl;

	for (auto i = 0; i <= 10; ++i) {
		std::cout << "a(" << i << ") = " << a(i) << '\n';
	}

	auto now = std::chrono::system_clock::now();

	auto res = a_rec(20);

	auto elapsed = std::chrono::system_clock::now() - now;

	std::cout << "Rekurzivno: " << elapsed.count() / 1000 << "us" << std::endl;

	now = std::chrono::system_clock::now();

	res = a_mem(20);

	elapsed = std::chrono::system_clock::now() - now;

	std::cout << "Memoizacija: " << elapsed.count() / 1000 << "us" << std::endl;

	now = std::chrono::system_clock::now();

	res = a_din(20);

	elapsed = std::chrono::system_clock::now() - now;

	std::cout << "Dinamicki: " << elapsed.count() << "ns" << std::endl;

	std::cout << "a(20) = " << res << std::endl;

	return 0;
}