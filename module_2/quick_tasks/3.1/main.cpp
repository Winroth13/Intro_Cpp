#include "rectangle.h"
#include <iostream>

int main() {
	Rectangle rect1;

	std::cout << rect1.circumference() << "\n";
	std::cout << rect1.area() << "\n";

	rect1.setHeight(3);
	rect1.setWidth(4);

	std::cout << "\n" << rect1.circumference() << "\n";
	std::cout << rect1.area() << "\n";

	Rectangle rect2(5, 6);

	std::cout << "\n" << rect2.circumference() << "\n";
	std::cout << rect2.area() << "\n";

	std::cout << (rect1 == rect2) << "\n";
	std::cout << (rect1 != rect2) << "\n";
	std::cout << (rect1 < rect2) << "\n";
	std::cout << (rect1 > rect2) << "\n";

	return 0;
}