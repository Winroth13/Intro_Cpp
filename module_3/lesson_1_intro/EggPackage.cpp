#include "EggPackage.h"
#include <string>

EggPackage::EggPackage(const std::string articleNum, const int price, const std::string eggSize, const int numEggs)
	: Product(articleNum, price), eggSize(eggSize), numEggs(numEggs) {
}

void EggPackage::SetEggEize(const std::string eggSize) {
	this->eggSize = eggSize;
}

void EggPackage::SetNumEggs(const int numEggs) {
	this->numEggs = numEggs;
}

std::string EggPackage::GetEggSize() const {
	return this->eggSize;
}

int EggPackage::GetNumEggs() const {
	return this->numEggs;
}

std::string EggPackage::Description() const {
	return "Egg package, EggSize: " + this->eggSize + " NumEggs: " + std::to_string(this->numEggs)
		+ " ArticleNum: " + this->GetArticleNum() + " Price: " + std::to_string(this->GetPrice());
}