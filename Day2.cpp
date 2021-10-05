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
	inputFile.open("C:\\Users\\Tadhg\\OneDrive\\Documents\\AdventOfCode2020TextFiles\\Day2.txt", ios::in);
	while (true) {
		inputFile >> inputLine;
		input.push_back(inputLine);
		if (inputFile.eof()) {
			break;
		}
	}
	inputFile.close();

	/*
	Part 1:
	find number of valid passwords : those within the bounds given
	ie a password with "2-4 w:" must have 2-4 w's
	*/
	int validCount1 = 0;
	for (int i = 0; i < input.size() - 1; i = i + 3) {
		int limitSplit = input[i].find("-");
		int lowerLimit = stoi(input[i].substr(0, limitSplit));
		int upperLimit = stoi(input[i].substr(limitSplit + 1));
		int characterOccurences = 0;
		for (int j = 0; j < input[i + 2].size(); j++) {
			if (input[i + 2][j] == input[i + 1][0]) {
				characterOccurences += 1;
			}
		}
		if (lowerLimit <= characterOccurences && characterOccurences <= upperLimit) {
			validCount1 += 1;
		}
	}
	cout << validCount1 << endl;

	/*
	Part 2:
	find number of valid passwords : those within the rules  given
	ie a password with "2-4 w:" must have their second or fourth character be "w", but not both
	*/
	int validCount2 = 0;
	for (int i = 0; i < input.size() - 1; i = i + 3) {
		int limitSplit = input[i].find("-");
		int lowerValue = stoi(input[i].substr(0, limitSplit));
		int upperValue = stoi(input[i].substr(limitSplit + 1));
		if (input[i + 2][lowerValue - 1] == input[i + 1][0] || input[i + 2][upperValue - 1] == input[i + 1][0]) {
			if (!(input[i + 2][lowerValue - 1] == input[i + 1][0] && input[i + 2][upperValue - 1] == input[i + 1][0])) {
				validCount2 += 1;
			}
		}
	}
	cout << validCount2 << endl;
}