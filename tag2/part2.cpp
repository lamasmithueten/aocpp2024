#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>


bool checkForSafety(std::vector <int>& vec){
	for (int i=0; i<vec.size()-1; i++){
		if (abs(
			vec[i] - vec[i+1]
		)>3 || 
		abs(
			vec[i]-vec[i+1]
		)==0){
			return false;
		}

	}
	return true;
}


int main (int argc , char* argv[]){
	
	std::ifstream file (argv[1]);

	int sum=0;
	std::string line;

	while(std::getline(file, line)){
		std::istringstream iss(line);
		std::vector<int> numbers;
		int number;
		while (iss >> number){
			numbers.push_back(number);
		}
		for(int i=0; i<numbers.size(); i++){
			std::vector <int> vector(numbers);
			vector.erase(vector.begin()+i);
			if(std::is_sorted(vector.begin(), vector.end()) &&checkForSafety(vector)){
					sum++;
					break;
			}
			else if(std::is_sorted(vector.begin(), vector.end(), std::greater<int>()) && checkForSafety(vector)){
					sum++;
					break;
			}
			
		}
	}
	std::cout << sum << "\n";

	return 0;
}
