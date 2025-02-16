#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

class Vehicle {
private:
	std::string regPlate;
	std::string owner;
	int loadWeight;
public:
	Vehicle(const std::string regPlate = "", const std::string owner = "", const int loadWeight = 0);
	void setRegPlate(const std::string regPlate);
	void setOwner(const std::string owner);
	void setLoadWeight(const int loadWeight);
	std::string getRegPlate() const;
	std::string description() const;
	bool operator<(const Vehicle other) const;
	bool operator==(const Vehicle other) const;
};

#endif