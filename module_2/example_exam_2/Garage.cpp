#include "Garage.h"
#include <string>

Garage::Garage(const std::string name)
	: name(name) {
	this->currentNrOfVehicles = 0;
	this->capacity = 1;

	this->vehicleArr = new Vehicle * [capacity];

	for (int i = 0; i < this->capacity; ++i) {
		this->vehicleArr[i] = nullptr;
	}
}

Garage::~Garage() {
	for (int i = 0; i < this->capacity; ++i) {
		delete this->vehicleArr[i];
	}

	delete[] vehicleArr;
}

std::string Garage::getName() const {
	return this->name;
}

int Garage::getCurrentNrOfVehicles() const {
	return this->currentNrOfVehicles;
}

int Garage::findVehicle(const std::string regPlate) const {
	for (int i = 0; i < this->capacity; ++i) {
		if (this->vehicleArr[i] != nullptr && this->vehicleArr[i]->getRegPlate() == regPlate) {
			return i;
		}
	}

	return -1;
}

bool Garage::addVehicleAt(const std::string regPlate, const std::string owner, const int loadWeight, const int index) {
	while (this->capacity <= index) {
		// THe specifications of the assignment specifies no additional functions, otherwise this would have been a private expand-function.
		capacity += 10;

		Vehicle** oldArr = vehicleArr;

		vehicleArr = new Vehicle * [capacity];

		for (int i = 0; i < capacity; ++i) {
			if (i < capacity - 10) {
				this->vehicleArr[i] = oldArr[i];
			}
			else {
				this->vehicleArr[i] = nullptr;
			}
		}

		delete[] oldArr;
	}

	if (this->vehicleArr[index] == nullptr) {
		this->vehicleArr[index] = new Vehicle(regPlate, owner, loadWeight);

		this->currentNrOfVehicles += 1;

		return true;
	}

	return false;
}

bool Garage::removeVehicleAt(const int index) {
	if (this->vehicleArr[index] != nullptr) {
		delete this->vehicleArr[index];

		this->vehicleArr[index] = nullptr;

		this->currentNrOfVehicles -= 1;

		return true;
	}

	return false;
}

Vehicle* Garage::vehicleAt(const int index) const {
	return this->vehicleArr[index];
}