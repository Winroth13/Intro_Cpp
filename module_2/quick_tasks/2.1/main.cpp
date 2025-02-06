#include <iostream>
#include <string>

int main() {
	std::string* aPtr = nullptr;

	std::string myString = "C++";

	aPtr = &myString;

	std::cout << *aPtr;
}