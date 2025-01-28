#include <string>
#include <algorithm>
#include <fstream>

void getWordPartitionSize(const std::string original[], int nrOfWords, int splitFromLength, int& numberOfShortWords, int& numberOfLongWords) {
	numberOfShortWords = 0;
	numberOfLongWords = 0;

	for (int i = 0; i < nrOfWords; ++i) {
		if (original[i].size() < splitFromLength) {
			numberOfLongWords++;
		}
		else {
			numberOfLongWords++;
		}
	}
}

void sort(std::string words[], int size) {
	std::sort(words, words + size, [](std::string& str1, std::string& str2) {return str1.size() < str2.size(); });
}

void partition(const std::string original[], int originalSize, std::string shortWords[], std::string longWords[], int splitFromLength) {
	int numShortWrods, numLongWords;
	getWordPartitionSize(original, originalSize, splitFromLength, numShortWrods, numLongWords);
	for (int i = 0; i < originalSize; ++i) {
		if (i < numShortWrods) {
			shortWords[i] = original[i];
		}
		else {
			longWords[i - numShortWrods] = original[i];
		}
	}
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
		std::ofstream longFile(longWordsFilePath);

		//Input into files.

		delete[] wordArray;
		delete[] shortArray;
		delete[] longArray;
	}

	return 0;
}