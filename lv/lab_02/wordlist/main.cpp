#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std::chrono;

// std::binary_search
// std::sort
// std::unique
// std::vector::erase

int main() {
  std::vector<std::string> words;
  std::ifstream fin{"shakespeare.txt"};

  // benchmark file preparation
  std::string input;
  auto now = std::chrono::system_clock::now();
  words.reserve(1000000);
  while (fin >> input) {
    words.push_back(input);
  }
  auto elapsed = std::chrono::system_clock::now() - now;
  std::sort(words.begin(), words.end());
  // end benchmark
  std::cout << "Loading the file has finished." << std::endl;
  std::cout << "Duration: " << elapsed.count() / 1000 << "ms" << std::endl;

  std::cout << "Enter word:" << std::endl;
  while (std::cin >> input) {
    std::cout << "Searching word: " << input << std::endl;

    now = std::chrono::system_clock::now();
    // benchmark
    bool found = std::binary_search(words.begin(), words.end(), input);
    //
    elapsed = std::chrono::system_clock::now() - now;

    if (found) {
      std::cout << "Words exists in dictionary" << std::endl;
    } else {
      std::cout << "Words does not exists in dictionary" << std::endl;
    }
    std::cout << "Duration: " << elapsed.count() / 1000 << " ms" << std::endl;
  }
}
