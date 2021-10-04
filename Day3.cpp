#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

	//input file into a string vector, standardised for future use
	fstream inputFile;
	vector<string> input;
	string inputLine;
	inputFile.open("C:\\Users\\Tadhg\\OneDrive\\Documents\\AdventOfCode2020TextFiles\\Day3.txt", ios::in);
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
	Find how many trees (#s) you encounter travelling 3 across and 1 down to the bottom
	*/
	int treeCount1 = 0;
	int horizontalPos = 0;
	for (int i = 1; i < input.size() - 1; i++) {
		horizontalPos += 3;
		if (horizontalPos > input[i].length() - 1) {
			horizontalPos -= (input[i].length());
		}
		if (input[i][horizontalPos] == '#') {
			treeCount1 += 1;
		}
	}
	cout << treeCount1 << endl;

	/*
	Part 2:
	Find how many trees (#s) you encounter travelling 1,3,5,7 across and 1 down, and 1 across and 2 down, to the bottom
	Multiply the numbers together for the answer
	Worth noting we could skip over horizontalPos == 3 and take treeCount1 but choosing to do all of them new for completeness' sake
	*/
	int treeCounts[5] = {};
	for (int i = 1; i <= 7; i += 2) {
		int treeCount2 = 0;
		horizontalPos = 0;
		for (int j = 1; j < input.size() - 1; j++) {
			horizontalPos += i;
			if (horizontalPos > input[j].length() - 1) {
				horizontalPos -= (input[j].length());
			}
			if (input[j][horizontalPos] == '#') {
				treeCount2 += 1;
			}
		}
		treeCounts[i / 2] = treeCount2;
	}

	// have to handle the 1 across, down 2 slope separately
	horizontalPos = 0;
	int treeCount2 = 0;
	for (int i = 2; i < input.size() - 1; i+=2) {
		horizontalPos += 1;
		if (horizontalPos > input[i].length() - 1) {
			horizontalPos -= (input[i].length());
		}
		if (input[i][horizontalPos] == '#') {
			treeCount2 += 1;
		}
	}
	treeCounts[4] = treeCount2;
	
	long long int finalProduct = 1;
	for (int i = 0; i < 5; i++) {
		finalProduct *= treeCounts[i];
	}

	cout << finalProduct << endl;
}
