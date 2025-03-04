#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <string>

class Participant {
private:
	std::string name;
	std::string gender;
public:
	Participant(const std::string name = "", const std::string gender = "");
	void setName(const std::string name);
	void setGender(const std::string gender);
	std::string getName() const;
	std::string getGender() const;
	virtual bool contains(const std::string str) const = 0;
	virtual std::string toString() const = 0;
};

#endif