#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <vector>


int main(int argc, char ** argv){
	
	std::fstream file (argv[1]);
	std::regex regex (argv[2]);
	std::regex numberRegex (argv[3]);
	std::string string;
	std::smatch match;
	std::vector<int> numbers;
	int sum=0;
	
	while(std::getline(file, string)){
		for (std::sregex_iterator it(string.begin(), string.end(), regex), end_it; it != end_it; it++) {
			std::string fullMatch = it->str();
			for( std::sregex_iterator numIt(fullMatch.begin(), fullMatch.end(), numberRegex), numEnd; numIt != numEnd; ++numIt){
				int number = std::stoi(numIt->str());
				numbers.push_back(number);	
			}
		}	
	}
/*	    std::cout << "Extracted numbers:" << std::endl;
    for (int num : numbers) {
        std::cout << num << std::endl;
    }*/
	for (int i=0; i<numbers.size(); i++){
		int number1=numbers[i++];
		int number2=numbers[i];
		int mult=number1*number2;
		sum+=mult;
	}
	
	
	std::cout << sum << '\n';
	
	

	return 0;
}