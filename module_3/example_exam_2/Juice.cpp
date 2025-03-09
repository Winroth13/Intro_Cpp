#include "Juice.h"

Juice::Juice(const int price, const float volume, const std::string fruit)
	: Product(price), volume(volume), fruit(fruit) {
}

void Juice::setFrouit(const std::string fruit) {
	this->fruit = fruit;
}

void Juice::setVolume(const float volume) {
	this->volume = volume;
}

std::string Juice::getFrouit() const {
	return fruit;
}

float Juice::getLitres() const {
	return volume;
}

std::string Juice::description() const {
	return "Juice, price: " + std::to_string(getPrice()) + ", fruit: " + fruit + ", volume: " + std::to_string(volume);
}