#ifndef CANDY_H
#define CANDY_H
#include <string>


class Candy {
private:
	std::string name;
	float price;
public:
	Candy(const std::string name = "", const float price = 0);
	void setName(const std::string);
	void setPrice(const float price);
	std::string getName() const;
	std::string toString() const;
	bool operator<(const Candy& other) const;
	bool operator==(const Candy& other) const;
};

#endif