#include "product.h"
#include <string>

Product::Product(const int price) : price(price) {}

void Product::setPrice(const int price) {
	this->price = price;
}

int Product::getPrice() const {
	return price;
}