#include "Participant.h"
#include <string>

Participant::Participant(const std::string name, const std::string gender)
	: name(name), gender(gender) {
}

void Participant::setName(const std::string name) {
	this->name = name;
}

void Participant::setGender(const std::string gender) {
	this->gender = gender;
}

std::string Participant::getName() const {
	return this->name;
}

std::string Participant::getGender() const {
	return this->gender;
}