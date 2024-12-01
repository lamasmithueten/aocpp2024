#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]){

	//Lesen der Dateien
	std::ifstream file (argv[1]);

	//Vektoren für den Vergleich
	std::vector<int> column1;
	std::vector<int> column2;

	//temporäre Variablen 
	int number1, number2;
	int sum=0;

	while (file >> number1 >> number2){
		column1.push_back(number1);
		column2.push_back(number2);
	}

	file.close();

	std::sort(column1.begin(), column1.end());
	std::sort(column2.begin(), column2.end());

	
	for(int i=0; i<column1.size(); i++){
		if(column1[i]>column2[i]) sum += column1[i]-column2[i];
		else sum += column2[i]-column1[i];
	}
	
	std::cout << sum << "\n";


	return 0;
}