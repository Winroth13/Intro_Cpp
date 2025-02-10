#ifndef CART_H
#define CART_H
#include "WallPaper.h"
#include <string>

class Cart {
private:
	int cartId;
	std::string name;
	WallPaper wallPaperArr[10];
	int nrOf;
public:
	Cart(int cartID, std::string name);
	void AddWallPaper(const std::string pattern, const int price, const int nrOfRolls);
	int TotalOrderCost() const;
	std::string ToString() const;
	bool RemoveWallPaper(const std::string pattern, const int price);
};

#endif