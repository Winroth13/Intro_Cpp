#include "Egg.h"
#include <string>

Egg::Egg(const int price, const int cartonSize)
	: Product(price), cartonSize(cartonSize) {
}

void Egg::setCartonSize(const int cartonSize) {
	this->cartonSize = cartonSize;
}

int Egg::getNrOfEggsInPackage() const {
	return cartonSize;
}

std::string Egg::description() const {
	return "Egg, price: " + std::to_string(getPrice()) + ", cartonSize: " + std::to_string(cartonSize);
}