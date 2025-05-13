#include <iostream>
#include <string>

bool palindrome(const char* s, int n) {
	if (n < 2) return true;
	return s[0] == s[n - 1] && palindrome(s + 1, n - 2);
}

int main() {
	std::string str = "anavolimilovana";
	std::string str2 = "kapak";
	std::string str3 = "algoritam";
	std::cout <<  str << (palindrome(str.c_str(), str.length())
						  ? " je" : " nije")
			  << " palindrom" << std::endl
			  << str2 << (palindrome(str2.c_str(), str2.length())
						  ? " je" : " nije")
			  << " palindrom" << std::endl
			  << str3 << (palindrome(str3.c_str(), str3.length())
						  ? " je" : " nije")
			  << " palindrom" << std::endl;
	return 0;
}