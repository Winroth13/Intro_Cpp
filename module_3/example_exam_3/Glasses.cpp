#include "Glasses.h"
#include <string>

Glasses::Glasses(std::string make, int basePrice)
	: make(make), basePrice(basePrice) {
}

int Glasses::getBasePrice() const {
	return this->basePrice;
}

std::string Glasses::getMake() const {
	return this->make;
}