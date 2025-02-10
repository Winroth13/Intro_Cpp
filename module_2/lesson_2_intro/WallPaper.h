#ifndef WALLPAPER_H
#define WALLPAPER_H
#include <string>

class WallPaper {
private:
	std::string pattern;
	int price;
	int nrOfRolls;
public:
	WallPaper(const std::string pattern = "", const int price = 0, const int nrOfRolls = 0);
	std::string GetPattern() const;
	int GetPrice() const;
	int GetNrOfRolls() const;
	void SetPattern(const std::string pattern);
	void SetPrice(const int price);
	void SetNrOfRolls(const int nrOfRolls);
	int TotalCost() const;
};

#endif
