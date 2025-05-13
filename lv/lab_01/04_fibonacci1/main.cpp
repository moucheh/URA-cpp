#include <chrono>
#include <iostream>

// implement a recursive function that computes the n-th fibonacci number
int fibonacci(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// Ova reukrzija se izvrsava u vidu stabla
//                      fib(4)
//                    /       \
//               fib(3)        fib(2)
//              /      \      /      \
//         fib(2)    fib(1)   1        1
//          /   \         \
//         1     1         1

// implement a iterative fibonacci and measure its performance
unsigned long fibonacci_iter(unsigned long n) {
  int n1 = 1, n2 = 1;
  for (int i = 3; i <= n; i++) {
    auto pom = n1;
    n1 = n1 + n2;
    n2 = pom;
  }
  return n1;
}

int main() {
  {
    auto now = std::chrono::steady_clock::now();
    auto r = fibonacci(40);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Fibonacci of 40 is: " << r << std::endl;
    std::cout << "Elapsed time for recursive method: "
              << elapsed.count() / 1000000 << "ms" << std::endl;
  }
  {
    auto now = std::chrono::steady_clock::now();
    auto r = fibonacci_iter(40);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Fibonacci of 40 is: " << r << std::endl;
    std::cout << "Elapsed time for iterative method: " << elapsed.count()
              << "ns" << std::endl;
  }
}
