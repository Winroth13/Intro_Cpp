#include "Milk.h"
#include <string>

Milk::Milk(const std::string articleNum, const int price, const int volume)
	: Product(articleNum, price), volume(volume) {
}

void Milk::SetVolume(const int volume) {
	this->volume = volume;
}

int Milk::GetVolume() const {
	return this->volume;
}

std::string Milk::Description() const {
	return "Milk, Volume : " + std::to_string(this->volume) + " ArticleNum: " + this->GetArticleNum() + " Price : " + std::to_string(this->GetPrice());
}