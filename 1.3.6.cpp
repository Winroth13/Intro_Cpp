#include <iostream>

int main() {
	int capacity = 5;
	int nrOfTitles = 0;
	std::string* bookTitles = new std::string[capacity];
	std::string book;

	std::cout << "Name a book:\n";
	std::cin >> book;

	while (book != "n") {
		if (capacity == nrOfTitles) {
			std::string* oldArray = bookTitles;
			bookTitles = new std::string[capacity + 1];

			for (int i = 0; i < capacity; ++i) {
				bookTitles[i] = oldArray[i];
			}

			capacity++;

			delete[] oldArray;
		}

		bookTitles[nrOfTitles] = book;
		nrOfTitles++;

		for (int i = 0; i < nrOfTitles; i++) {
			std::cout << bookTitles[i] << "\n";
		}

		std::cout << "\nName a book:\n";
		std::cin >> book;
		std::cout << "";
	}

	delete[] bookTitles;

	return 0;
}