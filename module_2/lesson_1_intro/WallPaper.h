#ifndef WALLPAPER_H
#define WALLPAPER_H
#include <string>

class WallPaper {
private:
	std::string pattern;
	int price;
public:
	WallPaper(std::string pattern = "", int price = 0);
	void setPattern(std::string pattern);
	void setPrice(int price);
	std::string getPattern() const;
	int getPrice() const;
	void show() const;
	bool operator==(const WallPaper& other) const;
};

#endif
