#include "functions.hpp"
#include <string>
#include <iostream>

int main() {
	std::string inFile = "words.txt";
	std::string shortFile = "short.txt";
	std::string longFile = "long.txt";

	std::string arr[10]{ "mouse", "frog" , "fox", "snake", "cat", "dog", "cow", "fly", "hourse", "snail" };

	sort(arr, 10);

	//wordSorter(inFile, shortFile, longFile, 6);

	return 0;
}