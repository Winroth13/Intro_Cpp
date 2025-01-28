#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

void getWordPartitionSize(const std::string original[], int nrOfWords, int splitFromLength, int& numberOfShortWords, int& numberOfLongWords) {
	numberOfShortWords = 0;
	numberOfLongWords = 0;

	for (int i = 0; i < nrOfWords; ++i) {
		if (original[i].size() < splitFromLength) {
			numberOfShortWords++;
		}
		else {
			numberOfLongWords++;
		}
	}
}

void sort(std::string words[], int size) {
	std::sort(words, words + size, [](std::string& str1, std::string& str2) {return str1 < str2; });
	//std::sort(words, words + size, [](std::string& str1, std::string& str2) {return str1.size() < str2.size(); });
}

void partition(const std::string original[], int originalSize, std::string shortWords[], std::string longWords[], int splitFromLength) {
	int shortIndex = 0;
	int longIndex = 0;
	//int numShortWords, numLongWords;

	//getWordPartitionSize(original, originalSize, splitFromLength, numShortWrods, numLongWords);

	for (int i = 0; i < originalSize; ++i) {
		if (original[i].size() < splitFromLength) {
			shortWords[shortIndex] = original[i];
			shortIndex++;
		}
		else {
			longWords[longIndex] = original[i];
			longIndex++;
		}
	}
	/*for (int i = 0; i < originalSize; ++i) {
		if (i < numShortWrods) {
			shortWords[i] = original[i];
		}
		else {
			longWords[i - numShortWrods] = original[i];
		}
	}*/
}

int wordSorter(std::string originalFilePath, std::string shortWordsFilePath, std::string longWordsFilePath, int splitFromLength) {
	bool success = false;
	int arraySize, numShort, numLong;

	std::ifstream inFile(originalFilePath);

	if (inFile) {
		inFile >> arraySize;

		std::string* wordArray = new std::string[arraySize];

		for (int i = 0; i < arraySize; ++i) {
			inFile >> wordArray[i];
		}

		sort(wordArray, arraySize);

		getWordPartitionSize(wordArray, arraySize, splitFromLength, numShort, numLong);

		std::string* shortArray = new std::string[numShort];
		std::string* longArray = new std::string[numLong];

		partition(wordArray, arraySize, shortArray, longArray, splitFromLength);

		std::ofstream shortFile(shortWordsFilePath);

		shortFile << numShort;

		for (int i = 0; i < numShort; ++i) {
			shortFile << "\n" << shortArray[i];
		}

		std::ofstream longFile(longWordsFilePath);

		longFile << numLong;

		for (int i = 0; i < numLong; ++i) {
			longFile << "\n" << longArray[i];
		}

		delete[] wordArray;
		delete[] shortArray;
		delete[] longArray;

		success = true;
	}

	return success;
}