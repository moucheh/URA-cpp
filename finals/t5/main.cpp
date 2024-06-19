#include <iostream>
#include <vector>

/*
	napisati funkciju koja racuna f(n)

			f(n) = {
		              n,  ako je n < 2
		f(n/3) + f(n-2),  ako je n djeljivo s 3
		   2*f(n/2) + 3,  ako je n parno
		f(n-4) + f(n-3),  za ostale n

	vise bodova za optimalnije rjesenje

	podrazumijeva se da korisnik nece unositi vrijednosti vece od 10 000 000
*/

int f(int n) {
	static std::vector<int> v;

	if (n < 2) return n;

	if (n > v.size())
		v.resize(n + 1);

	if (v[n] == 0) {
		if (n % 3 == 0) v[n] = f(n / 3) + f(n - 2);
		else if (n % 2 == 0) v[n] = 2 * f(n / 2) + 3;
		else v[n] = f(n - 4) + f(n - 3);
	}

	return v[n];
}

int main() {
	for (auto i = 0; i <= 1000; ++i) {
		std::cout << "f(" << i << ") = " << f(i) << '\n';
	}

	return 0;
}