#ifndef SHOP_H
#define SHOP_H
#include "Product.h"
#include <string>

class Shop {
private:
	Product** productList;
	int numProducts;
	int maxProducts;
	void expand();
public:
	Shop(const int startMax = 10);
	~Shop();
	int getNrOfProducts() const;
	void addEgg(const int price, const int cartonSize);
	void addJuice(const int price, const float volume, const std::string fruit);
	int totalNrOfEggs() const;
	float totalLitresOfJuice() const;
	void showAllProducts() const;
	Shop(const Shop& other);
	Shop* operator=(const Shop& other);
	Product** getAccessToArray() const;
	Product* getAccessToProductAt(int index) const;
};

#endif