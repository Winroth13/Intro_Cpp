#include "Cart.h"
#include <iostream>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Cart cart1(1, "Person");

	cart1.AddWallPaper("Flowers", 750, 2);
	cart1.AddWallPaper("Stripes", 800, 3);

	std::cout << cart1.TotalOrderCost() << "\n";
	std::cout << cart1.ToString();

	std::cout << cart1.RemoveWallPaper("Flowers", 750);
	std::cout << cart1.ToString();

	return 0;
}