#include <iostream>

int main() {
	std::string input;

	std::cout << "Text:\n";
	std::cin >> input;

	std::cout << "There were " << input.length() << " characters before the first whitespace.";

	return 0;
}