#ifndef STOCK_H
#define STOCK_H
#include "Glasses.h"
#include <string>
#include <memory>

class Stock {
private:
	Glasses* glassList[20];
	int numGlasses;
public:
	Stock();
	~Stock();
	bool add(const std::string make, const int basePrice, const std::string colour = "brun");
	bool add(const std::string make, const int basePrice, const float strength, const std::string typeOfGlass = "enkelslipade");
	int nrOfGlasses() const;
	int nrOfSunGlasses(const std::string colour) const;
	int nrOfReadingGlassesWithStrengthAbove(const float strength) const;
	int totalStockValue() const;
	Glasses* getAccessToGlassesAt(const int index) const;
	Stock(const Stock& other);
	Stock& operator=(const Stock& other);
};

#endif