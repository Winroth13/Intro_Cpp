#include "functions.hpp"
#include <string>
#include <iostream>

int main() {
	std::string inFile = "words.txt";
	std::string shortFile = "short.txt";
	std::string longFile = "long.txt";

	wordSorter(inFile, shortFile, longFile, 5);

	return 0;
}