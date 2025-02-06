#include "rectangle.h"
#include "functions.h"
#include <iostream>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Rectangle rectArr[3];

	rectArr[0].setWidth(12);
	rectArr[0].setHeight(15);

	rectArr[1].setWidth(10);
	rectArr[1].setHeight(5);

	rectArr[2].setWidth(2);
	rectArr[2].setHeight(25);


	showMetrics(rectArr, 3);
	std::cout << "\n";

	halveSides(rectArr, 3);
	showMetrics(rectArr, 3);
	std::cout << "\n";

	doubleSides(rectArr[0]);
	showMetrics(rectArr, 3);

	return 0;
}