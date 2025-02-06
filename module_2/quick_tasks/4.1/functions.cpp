#include <iostream>
#include "functions.h"

void showMetrics(const Rectangle rectArr[], const int nrOf) {
	for (int i = 0; i < nrOf; ++i) {
		std::cout << "Pos: " << i << " Circumference: " << rectArr[i].circumference() << " Area: " << rectArr[i].area() << "\n";
	}
}

void halveSides(Rectangle rectArr[], const int nrOf) {
	for (int i = 0; i < nrOf; ++i) {
		rectArr[i].setWidth(rectArr[i].getWidth() / 2);
		rectArr[i].setHeight(rectArr[i].getHeight() / 2);
	}
}

void doubleSides(Rectangle& rect) {
	rect.setWidth(rect.getWidth() * 2);
	rect.setHeight(rect.getHeight() * 2);
}