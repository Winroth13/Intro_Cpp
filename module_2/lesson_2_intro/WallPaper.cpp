#include "WallPaper.h"

WallPaper::WallPaper(const std::string pattern, const int price, const int nrOfRolls)
	: pattern(pattern), price(price), nrOfRolls(nrOfRolls) {
}

std::string WallPaper::GetPattern() const {
	return this->pattern;
}

int WallPaper::GetPrice() const {
	return this->price;
}

int WallPaper::GetNrOfRolls() const {
	return this->nrOfRolls;
}

void WallPaper::SetPattern(const std::string pattern) {
	this->pattern = pattern;
}

void WallPaper::SetPrice(const int price) {
	this->price = price;
}

void WallPaper::SetNrOfRolls(const int nrOfRolls) {
	this->nrOfRolls = nrOfRolls;
}

int WallPaper::TotalCost() const {
	return this->price * this->nrOfRolls;
}