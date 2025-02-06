#include "WallPaper.h"
#include <iostream>

WallPaper::WallPaper(std::string pattern, int price) {
	this->pattern = pattern;
	this->price = price;
}

void WallPaper::setPattern(std::string pattern) {
	this->pattern = pattern;
}

void WallPaper::setPrice(int price) {
	this->price = price;
}

std::string WallPaper::getPattern() const {
	return this->pattern;
}

int WallPaper::getPrice() const {
	return this->price;
}

void WallPaper::show() const {
	std::cout << "Wallpaper with pattern " << this->pattern << " cost " << this->price << " SEK.\n";
}

bool WallPaper::operator==(const WallPaper& other) const {
	return this->pattern == other.pattern && this->price == other.price;
}