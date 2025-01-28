#include <queue>
#include <string>
#include <fstream>

void Change(int& nrOne, int& nrTwo) {
	std::swap(nrOne, nrTwo);
}

int LongestStringIndex(std::string stringArray[], int arraySize) {
	int longestStringSize = 0;
	int longestStringIndex = 0;

	for (int i = 0; i < arraySize; ++i) {
		if (stringArray[i].size() > longestStringSize) {
			longestStringSize = stringArray[i].size();
			longestStringIndex = i;
		}
	}

	return longestStringIndex;
}

void WriteToFile(std::string stringArray[], int arraySize, std::string fileName) {
	std::ofstream outputFile(fileName);

	for (int i = 0; i < arraySize; ++i) {
		outputFile << stringArray[i] << "\n";
	}
}