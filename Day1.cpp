#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

	//input file into a string vector, each line being an item in the vector
	fstream inputFile;
	vector<string> input;
	string inputLine;
	inputFile.open("C:\\Users\\Tadhg\\OneDrive\\Documents\\AdventOfCode2020TextFiles\\Day1.txt", ios::in);
	while (true) {
		inputFile >> inputLine;
		input.push_back(inputLine);
		if (inputFile.eof()) {
			break;
		}
	}
	inputFile.close();

	//convert to integers for this case
	vector<int> intInput;
	for (int i = 0; i < input.size() - 2; i++) {
		intInput.push_back(stoi(input[i]));
	}

	//find 2 value combo that adds to 2020
	int value1 = 0, value2 = 0;
	bool valuesFound = false;
	for (int i = 0; i < intInput.size()-2; i++) {
		for (int j = i+1; j < intInput.size()-1; j++) {
			if (intInput[i] + intInput[j] == 2020) {
				value1 = intInput[i];
				value2 = intInput[j];
				valuesFound = true;
				break;
			}
		}
		if (valuesFound) { break; }
	}

	//find 3 value combo that adds to 2020
	int value3 = 0, value4 = 0, value5 = 0;
	valuesFound = false;
	for (int i = 0; i < intInput.size() - 3; i++) {
		for (int j = i + 1; j < intInput.size() - 2; j++) {
			for (int k = j + 1; k < intInput.size() - 3; k++) {
				if (intInput[i] + intInput[j] + intInput[k] == 2020) {
					value3 = intInput[i];
					value4 = intInput[j];
					value5 = intInput[k];
					valuesFound = true;
					break;
				}
			}
			if (valuesFound) { break; }
		}
		if (valuesFound) { break; }
	}

	cout << value1 * value2 << endl;
	cout << value3 * value4 * value5 << endl;
}
