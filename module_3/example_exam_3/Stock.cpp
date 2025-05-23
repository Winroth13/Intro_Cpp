#include "Stock.h"
#include "Glasses.h"
#include "SunGlasses.h"
#include "ReadingGlasses.h"
#include <string>

Stock::Stock() {
	this->numGlasses = 0;
}

Stock::~Stock() {
	for (int i = 0; i < numGlasses; ++i) {
		if (dynamic_cast<SunGlasses*>(this->glassList[i])) {
			delete dynamic_cast<SunGlasses*>(this->glassList[i]);
		}
		else {
			delete dynamic_cast<ReadingGlasses*>(this->glassList[i]);
		}
	}
}

bool Stock::add(const std::string make, const int basePrice, const std::string colour) {
	if (numGlasses < 20) {
		this->glassList[numGlasses] = new SunGlasses(make, basePrice, colour);
		this->numGlasses += 1;
		return true;
	}

	return false;
}

bool Stock::add(const std::string make, const int basePrice, const float strength, const std::string typeOfGlass) {
	if (numGlasses < 20) {
		this->glassList[numGlasses] = new ReadingGlasses(make, basePrice, strength, typeOfGlass);
		this->numGlasses += 1;
		return true;
	}

	return false;
}

int Stock::nrOfGlasses() const {
	return numGlasses;
}

int Stock::nrOfSunGlasses(const std::string colour) const {
	int numHits = 0;

	for (int i = 0; i < numGlasses; ++i) {
		SunGlasses* sunGlasses = dynamic_cast<SunGlasses*>(glassList[i]);

		if (sunGlasses != nullptr && sunGlasses->getColour() == colour) {
			numHits += 1;
		}
	}
	return numHits;
}

int Stock::nrOfReadingGlassesWithStrengthAbove(const float strength) const {
	int numHits = 0;

	for (int i = 0; i < numGlasses; ++i) {
		ReadingGlasses* sunGlasses = dynamic_cast<ReadingGlasses*>(glassList[i]);

		if (sunGlasses != nullptr && sunGlasses->getStrength() > strength) {
			numHits += 1;
		}
	}
	return numHits;
}

int Stock::totalStockValue() const {
	int totPrice = 0;

	for (int i = 0; i < numGlasses; ++i) {
		totPrice += glassList[i]->calculateFinalPrice();
	}

	return totPrice;
}

Glasses* Stock::getAccessToGlassesAt(const int index) const {
	return glassList[index];
}

Stock::Stock(const Stock& other)
	: numGlasses(other.numGlasses) {
	for (int i = 0; i < other.numGlasses; ++i) {
		if (dynamic_cast<SunGlasses*>(other.glassList[i])) {
			this->glassList[i] = new SunGlasses(*dynamic_cast<SunGlasses*>(other.glassList[i]));
		}
		else {
			this->glassList[i] = new ReadingGlasses(*dynamic_cast<ReadingGlasses*>(other.glassList[i]));
		}
	}
}

Stock& Stock::operator=(const Stock& other) {
	if (this != &other) {
		for (int i = 0; i < numGlasses; ++i) {
			if (dynamic_cast<SunGlasses*>(this->glassList[i])) {
				delete dynamic_cast<SunGlasses*>(this->glassList[i]);
			}
			else {
				delete dynamic_cast<ReadingGlasses*>(this->glassList[i]);
			}
		}

		this->numGlasses = other.numGlasses;

		for (int i = 0; i < other.numGlasses; ++i) {
			if (dynamic_cast<SunGlasses*>(other.glassList[i])) {
				this->glassList[i] = new SunGlasses(*dynamic_cast<SunGlasses*>(other.glassList[i]));
			}
			else {
				this->glassList[i] = new ReadingGlasses(*dynamic_cast<ReadingGlasses*>(other.glassList[i]));
			}
		}
	}

	return *this;
}