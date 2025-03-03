#include "Stock.h"
#include "Glasses.h"
#include "SunGlasses.h"
#include "ReadingGlasses.h"
#include <string>

Stock::~Stock() {
	delete[] glassList;
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

	for (Glasses* glasses : glassList) {
		SunGlasses* sunGlasses = dynamic_cast<SunGlasses*>(glasses);

		if (sunGlasses != nullptr && sunGlasses->getColour() == colour) {
			numHits += 1;
		}
	}
	return numHits;
}

int Stock::nrOfReadingGlassesWithStrengthAbove(const float strength) const {
	int numHits = 0;

	for (Glasses* glasses : glassList) {
		ReadingGlasses* sunGlasses = dynamic_cast<ReadingGlasses*>(glasses);

		if (sunGlasses != nullptr && sunGlasses->getStrength() > strength) {
			numHits += 1;
		}
	}
	return numHits;
}

int Stock::totalStockValue() const {
	int totPrice = 0;

	for (Glasses* glasses : glassList) {
		totPrice += glasses->calculateFinalPrice();
	}

	return totPrice;
}

Glasses* Stock::getAccessToGlassesAt(const int index) const {
	return glassList[index];
}