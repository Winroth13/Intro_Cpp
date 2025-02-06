#include "buddy.h"

Buddy::Buddy(std::string name, int age, int height) {
	this->name = name;
	this->age = age;
	this->height = height;
}

std::string Buddy::getName() const {
	return this->name;
}

int Buddy::getAge() const {
	return this->age;
}

int Buddy::getHeight() const {
	return this->height;
}

void Buddy::setName(const std::string name) {
	this->name = name;
}

void Buddy::setAge(const int age) {
	this->age = age;
}

void Buddy::setHeight(const int height) {
	this->height = height;
}

std::string Buddy::toString() const {
	return this->name + " is " + std::to_string(this->age) + " years old and " + std::to_string(this->height) + "cm long.";
}

bool Buddy::operator==(const Buddy& other) const {
	return this->name == other.name && this->age == other.age && this->height == other.height;
}