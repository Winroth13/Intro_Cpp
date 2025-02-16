#ifndef GARAGE_H
#define GARAGE_H
#include "Vehicle.h"
#include <string>

class Garage {
private:
	std::string name;
	int currentNrOfVehicles;
	int capacity;
	Vehicle** vehicleArr;
public:
	Garage(const std::string name = "");
	~Garage();
	std::string getName() const;
	int getCurrentNrOfVehicles() const;
	int findVehicle(const std::string regPlate) const;
	bool addVehicleAt(const std::string regPlate, const std::string owner, const int loadWeight, const int index);
	bool removeVehicleAt(const int index);
	Vehicle* vehicleAt(const int index) const;
};

#endif