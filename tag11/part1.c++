#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

void splitNumber(long long value, long long index,
                 std::vector<long long> &vec) {
  std::string numberString = std::to_string(value);
  long long firstPart =
      std::stoi(numberString.substr(0, numberString.length() / 2));
  long long secondPart = std::stoi(
      numberString.substr(numberString.length() / 2, numberString.length()));

  vec.push_back(firstPart);
  vec.push_back(secondPart);
}

bool evenNumberOfDigets(long long number) {

  std::string string = std::to_string(number);
  if (string.size() % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char **argv) {
  std::ifstream file(argv[1]);

  std::vector<long long> stoned;
  std::vector<long long> newStoned;

  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    long long number;
    while (iss >> number)
      stoned.push_back(number);
  }


  for (int j = 0; j < 25; j++) {


    for (long long i = 0; i < stoned.size(); i++) {
      if (stoned[i] == 0) {
        newStoned.push_back(1);
      } else if (evenNumberOfDigets(stoned[i])) {
        splitNumber(stoned[i], i, newStoned);
      } else {
        newStoned.push_back(stoned[i] * 2024);
      }
    }
    stoned = newStoned;
    newStoned.clear();
  }


  std::cout << "\n\n\n" << stoned.size() << '\n';
  return 0;
}
