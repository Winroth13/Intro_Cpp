#ifndef BUDDY_H
#define BUDDY_H
#include <string>

class Buddy
{
private:
	std::string name;
	int age;
	int height;
public:
	Buddy(std::string name = "", int age = 0, int height = 0);
	std::string getName() const;
	int getAge() const;
	int getHeight()const;
	void setName(const std::string name);
	void setAge(const int age);
	void setHeight(const int height);
	std::string toString() const;
	bool operator==(const Buddy& other) const;
};

#endif