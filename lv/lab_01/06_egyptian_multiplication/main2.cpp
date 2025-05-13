#include <chrono>
#include <cmath>
#include <iostream>

// implement a recursive function that computes the product of two
// numbers using the "Egyptian multiplication" method

// fast_multiply, O(log(n))
bool odd(int n) {
  return n & 1;
}

int half(int n) {
  return n >> 1;
}

/// n na a
int pow(int n, int a) {
  if (a == 1)
    return n;
  auto rez = pow(n * n, half(a));
  if (odd(a))
    rez *= n;
  return rez;
}

int main() {
  std::cout << "multiply 5 * 3  is: " << pow(5, 3) << std::endl;
  std::cout << "multiply 5 * 4 is: " << pow(5, 4) << std::endl;

  {
    auto now = std::chrono::steady_clock::now();
    auto r = pow(2, 11);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Computed multiply(2, 11) = " << r << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
  }
  {
    auto now = std::chrono::steady_clock::now();
    auto r = std::pow(2, 11);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Computed multiply(2, 11) = " << r << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
  }
}
