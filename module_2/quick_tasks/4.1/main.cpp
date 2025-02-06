#include "rectangle.h"
#include "functions.h"
#include <iostream>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int nrOf = 3;

	Rectangle* rectArr = new Rectangle[nrOf];

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
	std::cout << "\n";

	nrOf = nrOf * 2;;

	Rectangle* oldArr = rectArr;

	rectArr = new Rectangle[nrOf];

	for (int i = 0; i < nrOf; ++i) {
		rectArr[i] = oldArr[i % 3];
	}

	delete[] oldArr;

	showMetrics(rectArr, nrOf);

	delete[] rectArr;

	return 0;
}