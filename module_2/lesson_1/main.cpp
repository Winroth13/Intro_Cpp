#include "buddy.h"
#include <iostream>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Buddy buddy1;
	buddy1.setName("Hans");
	buddy1.setAge(21);
	buddy1.setHeight(172);

	std::cout << buddy1.toString();

	Buddy buddyArr[3];

	return 0;
}