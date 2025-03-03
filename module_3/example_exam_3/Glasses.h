#ifndef GLASSES_H
#define GLASSES_H
#include <string>

class Glasses {
private:
	std::string make;
	int basePrice;
public:
	Glasses(const std::string make, const int basePrice);
	int getBasePrice() const;
	std::string getMake() const;
	virtual int calculateFinalPrice() const = 0;
	virtual std::string description() const = 0;
};

#endif