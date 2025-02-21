#include "EggPackage.h"
#include "Milk.h"
#include <string>
#include <iostream>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Milk milk1 = Milk();
	milk1.SetArticleNum("ABC123");
	milk1.SetPrice(12);
	milk1.SetVolume(1);

	std::cout << milk1.Description() + "\n";

	Milk milk2 = Milk("123ABC", 2, 10);

	std::cout << milk2.Description() + "\n";

	EggPackage eggPack1 = EggPackage();
	eggPack1.SetArticleNum("E66");
	eggPack1.SetPrice(15);
	eggPack1.SetEggEize("M");
	eggPack1.SetNumEggs(8);

	std::cout << eggPack1.Description() + "\n";

	EggPackage eggPack2 = EggPackage("PAC2", 25, "S", 16);

	std::cout << eggPack2.Description() + "\n";

	Product* products[4];

	products[0] = &milk1;
	products[1] = &milk2;
	products[2] = &eggPack1;
	products[3] = &eggPack2;

	for (Product* product : products) {
		std::cout << product->Description() + "\n";
	}

	return 0;
}