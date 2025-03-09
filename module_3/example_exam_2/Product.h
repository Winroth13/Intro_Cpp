#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product {
private:
	int price;
public:
	Product(const int price);
	void setPrice(const int price);
	int getPrice() const;
	virtual std::string description() const = 0;
};

#endif