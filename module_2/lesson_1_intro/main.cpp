#include "WallPaper.h"
#include <iostream>

int main() {
	WallPaper wallPaper1;
	WallPaper wallPaper2("stripes", 750);

	wallPaper1.show();
	wallPaper2.show();

	wallPaper1.setPattern("flowers");
	wallPaper1.setPrice(800);
	wallPaper1.show();

	std::cout << wallPaper1.getPrice() + wallPaper2.getPrice() << "\n";

	std::cout << (wallPaper1 == wallPaper2);

	return 0;
}