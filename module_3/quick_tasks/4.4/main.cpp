#include "Array.h"
#include <iostream>
#include <string>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	const int SIZE = 10;

	Array<int> intArr(SIZE);

	for (int i = 0; i < SIZE; ++i) {
		intArr[i] = i;
	}

	Array<int> newArr(intArr);

	try {
		std::cout << std::to_string(newArr.GetElem(10));
	}
	catch (const std::out_of_range e) {
		std::cout << "Error: " << e.what() << "\n";
	}


	return 0;
}