#include <iostream>

int main() {
	int startHour, startMinute, startSecond, startTotal;
	int endHour, endMinute, endSecond, endTotal;
	int lengthHour, lengthMinute, lengthSecond, lengthTotal;

	std::cout << "Start\n";
	std::cout << "Hour: ";
	std::cin >> startHour;
	std::cout << "Minute: ";
	std::cin >> startMinute;
	std::cout << "Second: ";
	std::cin >> startSecond;

	std::cout << "\nGoal\n";
	std::cout << "Hour: ";
	std::cin >> endHour;
	std::cout << "Minute: ";
	std::cin >> endMinute;
	std::cout << "Second: ";
	std::cin >> endSecond;

	startTotal = startHour * 3600 + startMinute * 60 + startSecond;
	endTotal = endHour * 3600 + endMinute * 60 + endSecond;

	lengthTotal = endTotal - startTotal;

	lengthHour = lengthTotal / 3600;
	lengthMinute = (lengthTotal % 3600) / 60;
	lengthSecond = (lengthTotal % 3600) % 60;

	std::cout << "Your race took " << lengthHour << " hour(s), " << lengthMinute << " minute(s) and " << lengthSecond << "second(s).";

	return 0;
}