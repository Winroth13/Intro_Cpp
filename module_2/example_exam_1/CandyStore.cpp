#include "CandyStore.h"
#include <string>

CandyStore::CandyStore(const std::string storeName)
	: storeName(storeName), currentNrOfCandies(0) {
	for (int i = 0; i < 10; ++i) {
		candyArr[i] = nullptr;
	}
};

CandyStore::~CandyStore() {
	for (int i = 0; i < this->currentNrOfCandies; ++i) {
		delete candyArr[i];
	}
}

std::string CandyStore::getStoreName() const {
	return this->storeName;
}

int CandyStore::getCurrentNrOfCandies() const {
	return this->currentNrOfCandies;
}

bool CandyStore::addCandy(const std::string name, const float price) {
	if (this->currentNrOfCandies == 10) {
		return false;
	}

	this->candyArr[currentNrOfCandies] = new Candy(name, price);

	this->currentNrOfCandies++;

	return true;
}

bool CandyStore::removeCandy(const std::string name, const float price) {
	Candy comapreCandy = Candy(name, price);

	for (int i = 0; i < this->currentNrOfCandies; ++i) {
		if (*candyArr[i] == comapreCandy) {
			delete candyArr[i];

			candyArr[i] = candyArr[this->currentNrOfCandies - 1];

			candyArr[this->currentNrOfCandies - 1] = nullptr;

			currentNrOfCandies--;

			return true;
		}
	}

	return false;
}

Candy* CandyStore::candyAt(const int index) const {
	return candyArr[index];
}