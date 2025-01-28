#include <iostream>

int main() {
	int num, remainder;
	std::cout << "Input number:\n";
	std::cin >> num;

	remainder = num % 7;

	std::cout << num;
	if (remainder == 0) {
		std::cout << " is ";
	}
	else {
		std::cout << " is not ";
	}
	std::cout << "divisable by 7";

	return 0;
}