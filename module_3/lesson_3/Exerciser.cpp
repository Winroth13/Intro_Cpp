#include "Exerciser.h"

Exerciser::Exerciser(const std::string name, const std::string gender, const int age)
	: Participant(name, gender), age(age) {
}

void Exerciser::setAge(const int age) {
	this->age = age;
}

int Exerciser::getAge() const {
	return this->age;
}

bool Exerciser::contains(const std::string str) const {
	return this->getName() == str || this->getGender() == str || std::to_string(this->age) == str;
}

std::string Exerciser::toString() const {
	return "Exerciser, Name: " + this->getName() + " Gender: " + this->getGender() + " Age: " + std::to_string(this->age);
}