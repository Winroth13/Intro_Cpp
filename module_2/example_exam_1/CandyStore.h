#ifndef CANDYSTORE_H
#define CANDYSTORE_H
#include <string>
#include "Candy.h"

class CandyStore {
private:
	std::string storeName;
	int currentNrOfCandies;
	Candy* candyArr[10];
public:
	CandyStore(const std::string storeName = "");
	~CandyStore();
	std::string getStoreName() const;
	int getCurrentNrOfCandies() const;
	bool addCandy(const std::string name, const float price);
	bool removeCandy(const std::string name, const float price);
	Candy* candyAt(const int index) const;
};

#endif
