#include "find.hpp"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std::chrono;

int main() {
  std::vector<int> sut;
  sut.reserve(1000);
  for (int i = 0; i < 1000; i++) {
    sut.push_back(10 * i);
  }

  std::cout << "Loading the vector has finished." << std::endl;
  std::cout << "Enter number:" << std::endl;

  int input;
  while (std::cin >> input) {
    std::cout << "Searching : " << input << std::endl;

    // Search - linear
    auto now = std::chrono::system_clock::now();
    // benchmark
    auto it = ura::find(sut.begin(), sut.end(), input);
    auto found = it != sut.end();
    //
    auto elapsed = std::chrono::system_clock::now() - now;

    if (found) {
      std::cout << "Number exists" << std::endl;
    } else {
      std::cout << "Number does not exists" << std::endl;
    }
    std::cout << "Duration: " << elapsed.count() / 1000 << " ms" << std::endl
              << std::endl;

    // Search - binary
    now = std::chrono::system_clock::now();
    // benchmark
    it = ura::binary_search(sut.begin(), sut.end(), input);
    found = it != sut.end();

    elapsed = std::chrono::system_clock::now() - now;

    if (found) {
      std::cout << "Number exists" << std::endl;
    } else {
      std::cout << "Number does not exists" << std::endl;
    }
    std::cout << "Duration: " << elapsed.count() / 1000 << " ms" << std::endl;
  }
}
