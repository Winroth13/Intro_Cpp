#include "Candy.h"
#include <string>

Candy::Candy(const std::string name, const float price)
	: name(name), price(price) {
}

void Candy::setName(const std::string name) {
	this->name = name;
}

void Candy::setPrice(const float price) {
	this->price = price;
}

std::string Candy::getName() const {
	return this->name;
}

std::string Candy::toString() const {
	return "Name: " + this->name + " Price: " + std::to_string(this->price);
}

bool Candy::operator<(const Candy& other) const {
	return this->price < other.price;
}

bool Candy::operator==(const Candy& other) const {
	return this->name == other.name && this->price == other.price;
}