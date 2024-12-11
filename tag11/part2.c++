#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

void splitNumber(unsigned long long value, unsigned long long amount,
                 std::map<unsigned long long, unsigned long long> &map) {

  std::string numberString = std::to_string(value);
  size_t mid = numberString.length() / 2;
  std::string firstString = numberString.substr(0, mid);
  std::string secondString = numberString.substr(mid);
  unsigned long long firstPart = std::stoll(firstString);
  unsigned long long secondPart = std::stoll(secondString);
  map[firstPart] += amount;
  map[secondPart] += amount;
}

bool evenNumberOfDigits(unsigned long long number) {

  std::string string = std::to_string(number);
  if (string.size() % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char **argv) {
  std::ifstream file(argv[1]);

  std::map<unsigned long long, unsigned long long> stoned;
  std::map<unsigned long long, unsigned long long> newStoned;

  std::string line;
  long sum = 0;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    unsigned long long number;
    while (iss >> number)
      stoned[number]++;
  }
  for (int i = 0; i < 75; i++) {

    for (const auto &entry : stoned) {
      if (entry.first == 0) {
        newStoned[1] = entry.second;
      } else if (evenNumberOfDigits(entry.first)) {
        splitNumber(entry.first, entry.second, newStoned);

      } else {
        unsigned long long key = entry.first * 2024;
        newStoned[key] = entry.second;
      }
    }

    stoned = newStoned;
    newStoned.clear();
  }

  for (const auto &entry : stoned) {
    sum += entry.second;
  }

  std::cout << "\n\n\n" << sum << '\n';
  return 0;
}
