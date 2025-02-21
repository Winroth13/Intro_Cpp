#ifndef MILK_H
#define MILK_H
#include "Product.h"
#include <string>

class Milk : public Product {
private:
	int volume;
public:
	Milk(const std::string articleNum = "", const int price = 0, const int volume = 0);
	void SetVolume(const int volume);
	int GetVolume() const;
	std::string Description() const override;
};

#endif