#ifndef EGG_H
#define EGG_H
#include "Product.h"
#include <string>

class Egg : public Product {
private:
	int cartonSize;
public:
	Egg(const int price, const int cartonSize);
	void setCartonSize(const int cartonSize);
	int getNrOfEggsInPackage() const;
	std::string description() const;
};

#endif