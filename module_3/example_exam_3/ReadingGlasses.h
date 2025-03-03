#ifndef READINGGLASSES_H
#define READINGGLASSES_H
#include "Glasses.h"
#include <string>

class ReadingGlasses : public Glasses {
private:
	float strength;
	std::string typeOfGlass;
public:
	ReadingGlasses(const std::string make, const int basePrice, const float strength, const std::string typeOfGlass = "enkelslipade");
	float getStrength();
	int calculateFinalPrice() const override;
	std::string description() const override;
};

#endif