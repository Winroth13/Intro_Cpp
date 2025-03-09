#ifndef JUICE_H
#define JUICE_H
#include "Product.h"
#include <string>

class Juice : public Product {
private:
	std::string fruit;
	float volume;
public:
	Juice(const int price, const float volume, const std::string fruit);
	void setFrouit(const std::string fruit);
	void setVolume(const float volume);
	std::string getFrouit() const;
	float getLitres() const;
	std::string description() const;
};

#endif