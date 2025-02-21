#include "Product.h"
#include <string>

Product::Product(const std::string articleNum, const int price)
	: articleNum(articleNum), price(price) {
};

void Product::SetArticleNum(const std::string articleNum) {
	this->articleNum = articleNum;
}

void Product::SetPrice(const int price) {
	this->price = price;
}

std::string Product::GetArticleNum() const {
	return this->articleNum;
}

int Product::GetPrice() const {
	return this->price;
}

std::string Product::Description() const {
	return "ArticleNum: " + this->articleNum + " Price: " + std::to_string(this->price);
}