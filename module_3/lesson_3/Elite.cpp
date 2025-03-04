#include "Elite.h"
#include <string>

Elite::Elite(const std::string name, const std::string gender, const std::string club, const int yearsAsElite)
	: Participant(name, gender), club(club), yearsAsElite(yearsAsElite) {
}

void Elite::setClub(const std::string club) {
	this->club = club;
}

void Elite::setYearsAsElite(const int yearsAsElite) {
	this->yearsAsElite = yearsAsElite;
}

std::string Elite::getClub() const {
	return this->club;
}

int Elite::getYearsAsElite() const {
	return this->yearsAsElite;
}

bool Elite::contains(const std::string str) const {
	return this->getName() == str || this->getGender() == str || this->club == str || std::to_string(this->yearsAsElite) == str;
}

std::string Elite::toString() const {
	return "Elite, Name: " + this->getName() + " Gender: " + this->getGender() + " Club: " + this->club + " YearsAsElite: " + std::to_string(this->yearsAsElite);
}