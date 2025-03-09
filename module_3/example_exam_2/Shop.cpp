#include "Shop.h"
#include "Product.h"
#include "Egg.h"
#include "Juice.h"
#include <iostream>
#include <string>

Shop::Shop(const int startMax)
	: maxProducts(startMax) {
	this->productList = new Product * [startMax];
	this->numProducts = 0;

	for (int i = 0; i < maxProducts; ++i) {
		productList[i] = nullptr;
	}
}

Shop::~Shop() {
	for (int i = 0; i < this->numProducts; ++i) {
		Egg* eggCast = dynamic_cast<Egg*>(this->productList[i]);
		if (eggCast != nullptr) {
			delete eggCast;
		}
		else {
			Juice* juiceCast = dynamic_cast<Juice*>(this->productList[i]);
			if (juiceCast != nullptr) {
				delete juiceCast;
			}
		}
	}
	delete[] this->productList;
}

void Shop::expand() {
	Product** tempArr = productList;
	productList = new Product * [this->numProducts * 2];
	for (int i = 0; i < this->numProducts; ++i) {
		this->productList[i] = tempArr[i];
	}
	delete[] tempArr;
	this->maxProducts *= 2;
}

int Shop::getNrOfProducts() const {
	return this->numProducts;
}

void Shop::addEgg(const int price, const int cartonSize) {
	if (this->numProducts == this->maxProducts) {
		expand();
	}
	this->productList[this->numProducts] = new Egg(price, cartonSize);
	this->numProducts++;
}

void Shop::addJuice(const int price, const float volume, const std::string fruit) {
	if (this->numProducts == this->maxProducts) {
		expand();
	}
	this->productList[this->numProducts] = new Juice(price, volume, fruit);
	this->numProducts++;
}

int Shop::totalNrOfEggs() const {
	int total = 0;
	for (int i = 0; i < this->numProducts; ++i) {
		Egg* eggCast = dynamic_cast<Egg*>(this->productList[i]);
		if (eggCast != nullptr) {
			total += eggCast->getNrOfEggsInPackage();
		}
	}
	return total;
}

float Shop::totalLitresOfJuice() const {
	float total = 0;
	for (int i = 0; i < this->numProducts; ++i) {
		Juice* juiceCast = dynamic_cast<Juice*>(productList[i]);
		if (juiceCast != nullptr) {
			total += juiceCast->getLitres();
		}
	}
	return total;
}

void Shop::showAllProducts() const {
	for (int i = 0; i < this->numProducts; ++i) {
		std::cout << this->productList[i]->description() << "\n";
	}
}

Shop::Shop(const Shop& other) {
	this->numProducts = other.numProducts;
	this->maxProducts = other.maxProducts;

	this->productList = new Product * [this->maxProducts];
	for (int i = 0; i < this->numProducts; ++i) {
		Egg* eggCast = dynamic_cast<Egg*>(other.productList[i]);
		if (eggCast != nullptr) {
			this->productList[i] = new Egg(*eggCast);
		}
		else {
			Juice* juiceCast = dynamic_cast<Juice*>(other.productList[i]);
			if (juiceCast != nullptr) {
				this->productList[i] = new Juice(*juiceCast);
			}
		}
	}
}

Shop* Shop::operator=(const Shop& other) {
	if (this != &other) {
		for (int i = 0; i < this->numProducts; ++i) {
			Egg* eggCast = dynamic_cast<Egg*>(this->productList[i]);
			if (eggCast != nullptr) {
				delete eggCast;
			}
			else {
				Juice* juiceCast = dynamic_cast<Juice*>(this->productList[i]);
				if (juiceCast != nullptr) {
					delete juiceCast;
				}
			}
		}
		delete[] this->productList;

		this->numProducts = other.numProducts;
		this->maxProducts = other.maxProducts;
		this->productList = new Product * [this->maxProducts];

		for (int i = 0; i < numProducts; ++i) {
			Egg* eggCast = dynamic_cast<Egg*>(other.productList[i]);
			if (eggCast != nullptr) {
				this->productList[i] = new Egg(*eggCast);
			}
			else {
				Juice* juiceCast = dynamic_cast<Juice*>(other.productList[i]);
				if (juiceCast != nullptr) {
					this->productList[i] = new Juice(*juiceCast);
				}
			}
		}
	}

	return this;
}

Product** Shop::getAccessToArray() const {
	return this->productList;
}

Product* Shop::getAccessToProductAt(int index) const {
	return this->productList[index];
}