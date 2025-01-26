#include <iostream>
#include <string>

int main() {
	std::string lastName, firstName;

	std::cout << "Last name: ";
	std::getline(std::cin, lastName);

	std::cout << "\nFirst name: ";
	std::cin >> firstName;

	std::cout << "\nHello, " << lastName << " " << firstName << "! ";

	if (lastName.length() > firstName.length()) {
		std::cout << "Your last name contains more letters than your first name.";
	}
	else if (lastName.length() < firstName.length()) {
		std::cout << "Your first name contains more letters than your last name.";
	}
	else {
		std::cout << "Your last name contains the same amount of letters as your first name.";
	}

	return 0;
}