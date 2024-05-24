#include <iostream>
#include <map>

int fib_rek(int n) {
	if (n < 2)
		return n;
	return fib_rek(n - 2) + fib_rek(n - 1);
}


int fib_mem(int n) {
	static std::map<int, int> memo;
	if (n < 2) {
		return n;
	}
	if (memo[n] == 0) {
		memo[n] = fib_mem(n - 2) + fib_mem(n - 1);
	}
	return memo[n];
}

int fib_din(int n) {
	int f_n_2 = 0;
	int f_n_1 = 1;
	int f_n;

	for (auto i = 2; i < n; ++i) {
		f_n = f_n_2 + f_n_1;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
	}
	return f_n;
}

int main(int argc, char** argv) {
	int (*fibo)(int) = fib_rek;

	if (argc == 2 && std::string("mem") == argv[1]) {
		fibo = fib_mem;
	} else if (argc == 2 && std::string("din") == argv[1]) {
		fibo = fib_din;
	}

	for (auto i = 0; i < 50; ++i) {
		std::cout << fibo(i) << '\t';
	}
	std::cout << std::endl;
	return 0;
}