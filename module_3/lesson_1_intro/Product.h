#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product {
private:
	std::string articleNum;
	int price;
public:
	Product(const std::string articleNum = "", const int price = 0);
	void SetArticleNum(const std::string articleNum);
	void SetPrice(const int price);
	std::string GetArticleNum() const;
	int GetPrice() const;
	virtual std::string Description() const;
};

#endif