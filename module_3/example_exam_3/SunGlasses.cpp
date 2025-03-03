#include "SunGlasses.h"
#include <string>

SunGlasses::SunGlasses(const std::string make, const int basePrice, const std::string colour)
	: Glasses(make, basePrice), colour(colour) {
}

std::string SunGlasses::getColour() const {
	return this->colour;
}

int SunGlasses::calculateFinalPrice() const {
	int price = this->getBasePrice();

	if (this->colour != "brun") {
		price += 200;
	}

	return price;
}

std::string SunGlasses::description() const {
	return "SunGlasses, Make: " + this->getMake() + " Colour: " + this->colour + " Price: " + std::to_string(calculateFinalPrice());
}