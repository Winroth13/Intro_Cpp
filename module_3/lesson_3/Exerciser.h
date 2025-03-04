#ifndef EXERCISER_H
#define EXERCISER_H
#include "Participant.h"
#include <string>

class Exerciser : public Participant {
private:
	int age;
public:
	Exerciser(const std::string name, const std::string gender, const int age);
	void setAge(const int age);
	int getAge() const;
	bool contains(const std::string str) const override;
	std::string toString() const override;
};

#endif