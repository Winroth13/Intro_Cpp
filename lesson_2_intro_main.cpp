#include "lesson_2_intro_header.h"
#include <iostream>
#include <string>
#include <queue>

int main() {
	int numNames;

	std::cout << "How many names do you want to input? ";
	std::cin >> numNames;

	std::string* nameArray = new std::string[numNames];

	std::cout << "\nInput all names:\n";
	std::string name;

	std::cin.seekg(0, std::cin.beg);

	for (int i = 0; i < numNames; i++) {
		std::getline(std::cin, name);
		nameArray[i] = name;
	}

	int longestIndex = LongestStringIndex(nameArray, numNames);

	std::cout << "\n" << nameArray[longestIndex] << " is the longest word.";

	WriteToFile(nameArray, numNames, "lesson_2_intro_names.txt");

	delete[] nameArray;

	return 0;
}