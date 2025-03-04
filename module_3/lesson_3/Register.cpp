#include "Register.h"
#include "Participant.h"
#include "Exerciser.h"
#include "Elite.h"
#include <string>
#include <memory>
#include <stdexcept>

Register::Register() {}

void Register::addParticipant(const std::string name, const std::string gender, const int age) {
	std::shared_ptr<Exerciser> newParticipant = std::make_shared<Exerciser>(name, gender, age);

	this->partList.push_back(newParticipant);
}

void Register::addParticipant(const std::string name, const std::string gender, const std::string club, const int yearsAsEWlite) {
	std::shared_ptr<Elite> newParticipant = std::make_shared<Elite>(name, gender, club, yearsAsEWlite);

	this->partList.push_back(newParticipant);
}

std::shared_ptr<Participant> Register::getByName(const std::string name) const {
	for (std::shared_ptr<Participant> part : partList) {
		if (part->getName() == name) {
			return part;
		}
	}

	return nullptr;
}

int Register::numParticipants() const {
	return partList.size();
}

Register::Register(const Register& other) {
	for (std::shared_ptr<Participant> part : other.partList) {
		if (std::dynamic_pointer_cast<Exerciser>(part).use_count() != 0) {
			std::shared_ptr<Exerciser> partCopy = std::make_shared<Exerciser>(*std::dynamic_pointer_cast<Exerciser>(part));

			this->partList.push_back(partCopy);
		}
		else if (std::dynamic_pointer_cast<Elite>(part).use_count() != 0) {
			std::shared_ptr<Elite> partCopy = std::make_shared<Elite>(*std::dynamic_pointer_cast<Elite>(part));

			this->partList.push_back(partCopy);
		}
		else {
			throw std::invalid_argument("Members of partList must be Exerciser or Elite.");
		}
	}
}

Register& Register::operator=(const Register& other) {
	if (this != &other) {
		this->partList.clear();

		for (std::shared_ptr<Participant> part : other.partList) {
			if (std::dynamic_pointer_cast<Exerciser>(part).use_count() != 0) {
				std::shared_ptr<Exerciser> partCopy = std::make_shared<Exerciser>(*std::dynamic_pointer_cast<Exerciser>(part));

				this->partList.push_back(partCopy);
			}
			else if (std::dynamic_pointer_cast<Elite>(part).use_count() != 0) {
				std::shared_ptr<Elite> partCopy = std::make_shared<Elite>(*std::dynamic_pointer_cast<Elite>(part));

				this->partList.push_back(partCopy);
			}
			else {
				throw std::invalid_argument("Members of partList must be Exerciser or Elite.");
			}
		}
	}

	return *this;
}