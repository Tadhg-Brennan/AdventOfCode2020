#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//made this validity checking function in part 2 to avoid repitition and simplify it
bool validCheck(string, string);

int main() {

	//input file into a string vector, split by empty lines
	fstream inputFile;
	vector<string> input;
	string inputLine, inputItem;
	inputFile.open("C:\\Users\\Tadhg\\OneDrive\\Documents\\AdventOfCode2020TextFiles\\Day4.txt", ios::in);
	while (true) {
		getline(inputFile, inputLine);
		if (inputLine == "") {
			inputItem.erase(inputItem.length() - 1, 1);
			input.push_back(inputItem);
			inputItem = "";
		}
		else {
			inputItem += inputLine + " ";
		}

		if (inputFile.eof()) {
			inputItem.erase(inputItem.length() - 1, 1);
			input.push_back(inputItem);
			inputItem = "";
			break;
		}
	}
	inputFile.close();

	//splitting the lines into their properties and remaking them into a 2D vector
	vector<vector<string>> input2D;
	vector<string> properties;
	string property = "";
	for (int i = 0; i < input.size(); i++) {
		properties = {};
		property = "";
		for (int j = 0; j < input[i].length(); j++) {
			if (input[i][j] == ' ') {
				properties.push_back(property);
				property = "";
			}
			else {
				property += input[i][j];
			}
		}
		properties.push_back(property);
		input2D.push_back(properties);
	}

	/*
	* Part 1:
	* Find the number of valid passports (those that have the 7 required fields)
	*/
	bool valid = true;
	int validCount1 = 0;
	for (int i = 0; i < input2D.size(); i++) {
		if (input2D[i].size() == 8) {
			validCount1 += 1;
			continue;
		}
		if (input2D[i].size() == 7) {
			valid = true;
			for (int j = 0; j < 7; j++) {
				if (input2D[i][j].substr(0, 3) == "cid") {
					valid = false;
					break;
				}
			}
			if (valid) {
				validCount1 += 1;
			}
		}
	}
	cout << validCount1 << endl;

	/*
	* Part 2:
	* Find the number of valid passports (those with the 7 required
	* fields filled with correctly formatted properties)
	*/
	int validCount2 = 0;
	for (int i = 0; i < input2D.size(); i++) {
		valid = true;
		if (input2D[i].size() == 8) {
			for (int j = 0; j < 8; j++) {
				valid = validCheck(input2D[i][j].substr(0, 3), input2D[i][j].substr(4));
				if (!valid) {
					break;
				}
			}
			if (valid) {
				validCount2 += 1;
			}
		}
		else if (input2D[i].size() == 7) {
			valid = true;
			for (int j = 0; j < 7; j++) {
				if (input2D[i][j].substr(0, 3) == "cid") {
					valid = false;
					break;
				}
				else {
					valid = validCheck(input2D[i][j].substr(0, 3), input2D[i][j].substr(4));
					if (!valid) {
						break;
					}
				}
			}
			if (valid) {
				validCount2 += 1;
			}
		}
	}
	cout << validCount2 << endl;
}

bool validCheck(string property, string value) {
	bool valid = true;
	if (property == "byr") {
		valid = stoi(value) >= 1920 && stoi(value) <= 2002;
	}
	else if (property == "iyr") {
		valid = stoi(value) >= 2010 && stoi(value) <= 2020;
	}
	else if (property == "eyr") {
		valid = stoi(value) >= 2020 && stoi(value) <= 2030;
	}
	else if (property == "hgt") {
		if (value.substr(value.length() - 2) == "in") {
			valid = stoi(value.substr(0, value.find('i'))) >= 59 && stoi(value.substr(0, value.find('i'))) <= 76;
		}
		else if (value.substr(value.length() - 2) == "cm") {
			valid = stoi(value.substr(0, value.find('c'))) >= 150 && stoi(value.substr(0, value.find('c'))) <= 193;
		}
		else {
			valid = false;
		}
	}
	else if (property == "hcl") {
		valid = value[0] == '#' && value.length() == 7;
		if (valid) {
			try {
				stoi(value.substr(1), nullptr, 16);
			}
			catch (...) {
				valid = false;
			}
		}
	}
	else if (property == "ecl") {
		vector<string> validEclValues = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
		valid = end(validEclValues) != find(validEclValues.begin(), validEclValues.end(), value);
	}
	else if (property == "pid") {
		valid = value.length() == 9;
		if (valid) {
			try {
				stoi(value);
			}
			catch (...) {
				valid = false;
			}
		}
	}
	return valid;
}
