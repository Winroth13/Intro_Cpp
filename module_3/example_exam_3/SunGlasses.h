#ifndef SUNGLASSES_H
#define SUNGLASSES_H
#include "Glasses.h"
#include <string>

class SunGlasses : public Glasses {
private:
	std::string colour;
public:
	SunGlasses(const std::string make, const int basePrice, const std::string colour);
	std::string getColour() const;
	int calculateFinalPrice() const override;
	std::string description() const override;
};

#endif