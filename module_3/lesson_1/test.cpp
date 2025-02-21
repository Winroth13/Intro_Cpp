#include "Cylinder.h"
#include "Box.h"
#include <iostream>

int main() {
	Cylinder cylinder1 = Cylinder(10, 5, Orientation(Vertical));

	std::cout << cylinder1.Description();

	return 0;
}