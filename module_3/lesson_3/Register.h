#ifndef REGISTER_H
#define REGISTER_H
#include "Participant.h"
#include <vector>
#include <memory>

class Register {
private:
	std::vector<std::shared_ptr<Participant>> partList;
public:
	Register();
	void addParticipant(const std::string name, const std::string gender, const int age);
	void addParticipant(const std::string name, const std::string gender, const std::string club, const int yearsAsEWlite);
	std::shared_ptr<Participant> getByName(const std::string name) const;
	int numParticipants() const;
	Register(const Register& other);
	Register& operator=(const Register& other);
};

#endif