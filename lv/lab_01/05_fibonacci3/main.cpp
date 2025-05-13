#include <chrono>
#include <cmath>
#include <iostream>

// implement a general function that computes the n-th fibonacci number
// using the general case formula
double fibonacci(int n) {
  const static auto sqrt5 = sqrt(5);
  return (1 / sqrt5) * (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n));
}

int main() {
  std::cout << "Fibonacci of 1 is: " << fibonacci(1) << std::endl;
  std::cout << "Fibonacci of 2 is: " << fibonacci(2) << std::endl;
  std::cout << "Fibonacci of 3 is: " << fibonacci(3) << std::endl;
  std::cout << "Fibonacci of 4 is: " << fibonacci(4) << std::endl;

  auto now = std::chrono::steady_clock::now();
  auto r = fibonacci(30);
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Fibonacci of 30 is: " << r << std::endl;
  std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
}
