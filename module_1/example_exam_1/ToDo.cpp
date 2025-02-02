#include <fstream>
#include <iostream>
#include "ToDo.h"

using namespace std;

void doubleUp(int& number) {
	number += number;
}

void readStringsFromFile(string fileName, string strArr[], int numLines) {
	ifstream inFile(fileName);

	for (int i = 0; i < numLines; ++i) {
		getline(inFile, strArr[i]);
	}
}

int nrOfValuesBiggerThan(int arr[], int nrOf, int compareNum) {
	int result = 0;

	for (int i = 0; i < nrOf; ++i) {
		if (arr[i] > compareNum) {
			result += 1;
		}
	}

	return result;
}

void lowestAndHighest(int arr[], int nrOf, int& indexOfLowest, int& indexOfHighest) {
	int lowestValue, highestValue;
	lowestValue = highestValue = arr[0];
	indexOfLowest = indexOfHighest = 0;

	for (int i = 1; i < nrOf; ++i) {
		if (arr[i] < lowestValue) {
			lowestValue = arr[i];
			indexOfLowest = i;
		}
		else if (arr[i] > highestValue) {
			highestValue = arr[i];
			indexOfHighest = i;
		}
	}
}