#include <iostream>
#include <vector>

int foo1(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;

	return 1 + foo1(n - 1) + foo1(foo1(n - 2));
}

int foo2(int n) {
	static std::vector<int> mem;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n > mem.size())
		mem.resize(n + 1);
	if (mem[n] == 0)
		mem[n] = 1 + foo2(n - 1) + foo2(foo2(n - 2));

	return mem[n];
}

int foo3(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	int n_2 = 1;
	int n_1 = 2;
	int f_n;
	for (auto i = 3; i <= n; ++i) {
		f_n = 1 + n_1 + foo3(n_2);
		n_2 = n_1;
		n_1 = f_n;
	}
	return f_n;
}

int main() {
	std::cout << foo1(5) << std::endl;
	std::cout << foo2(5) << std::endl;
	std::cout << foo3(5) << std::endl;
	return 0;
}