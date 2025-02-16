#include "Vehicle.h"
#include <string>

Vehicle::Vehicle(const std::string regPlate, const std::string owner, const int loadWeight)
	: regPlate(regPlate), owner(owner), loadWeight(loadWeight) {
}

void Vehicle::setRegPlate(const std::string regPlate) {
	if (regPlate.length() == 6) {
		this->regPlate = regPlate;
	}
}

void Vehicle::setOwner(const std::string owner) {
	this->owner = owner;
}

void Vehicle::setLoadWeight(const int loadWeight) {
	this->loadWeight = loadWeight;
}

std::string Vehicle::getRegPlate() const {
	return this->regPlate;
}

std::string Vehicle::description() const {
	return "RegPlate: " + this->regPlate + " Owner: " + this->owner + " LoadWeight: " + std::to_string(this->loadWeight);
}

bool Vehicle::operator<(const Vehicle other) const {
	return this->loadWeight < other.loadWeight;
}

bool Vehicle::operator==(const Vehicle other) const {
	return this->regPlate == other.regPlate && this->owner == other.owner && this->loadWeight == other.loadWeight;
}