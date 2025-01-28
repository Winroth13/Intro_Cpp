#include <iostream>
#include <string>

int main() {
	std::string input;

	std::cout << "Input a sentence: ";
	std::getline(std::cin, input);

	int nrWords = 0;

	if (!input.empty()) {
		nrWords++;

		for (char i : input) {
			if (i == ' ') {
				nrWords++;
			}
		}
	}

	if (input.back() != '.') {
		std::cout << "You forgot to end the sentence with . ";
	}

	std::cout << "The sentence contained " << nrWords << " words.";

	return 0;
}