#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool checkForSafety(std::vector<int> &vec) {
  for (int i = 0; i < vec.size() - 1; i++) {
    if (abs(vec[i] - vec[i + 1]) > 3 || abs(vec[i] - vec[i + 1]) == 0)
      return false;
  }
  for (int i : vec)
    std::cout << i << ' ';
  std::cout << "\n";
  return true;
}

int main(int argc, char *argv[]) {

  std::ifstream file(argv[1]);

  int sum = 0;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<int> numbers;
    int number;
    while (iss >> number) {
      numbers.push_back(number);
    }
    if (std::is_sorted(numbers.begin(), numbers.end())) {
      if (checkForSafety(numbers)) {
        sum++;
      }
    } else if (std::is_sorted(numbers.begin(), numbers.end(),
                              std::greater<int>())) {
      if (checkForSafety(numbers)) {
        sum++;
      }
    }
  }

  std::cout << sum << "\n";

  return 0;
}
