#include "ReadingGlasses.h"
#include <string>

ReadingGlasses::ReadingGlasses(const std::string make, const int basePrice, const float strength, const std::string typeOfGlass)
	: Glasses(make, basePrice), strength(strength), typeOfGlass(typeOfGlass) {
}

float ReadingGlasses::getStrength() {
	return this->strength;
}

int ReadingGlasses::calculateFinalPrice() const {
	int price = this->getBasePrice();

	if (this->typeOfGlass == "dubbelslipade") {
		price += 1500;
	}

	return price;
}

std::string ReadingGlasses::description() const {
	return "Reading glasses, Make: " + this->getMake() + " Strength: " + std::to_string(this->strength) + " GlassType: " + this->typeOfGlass + " Price: " + std::to_string(this->calculateFinalPrice());
}