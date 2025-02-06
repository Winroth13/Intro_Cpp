#ifndef RECTANGEL_H
#define RECTANGEL_H

class Rectangle
{
private:
	float width;
	float height;
public:
	Rectangle(float width = 0, float height = 0);
	void setWidth(float width);
	void setHeight(float height);
	float circumference() const;
	float area() const;
	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;
	bool operator<(const Rectangle& other) const;
	bool operator>(const Rectangle& other) const;
};

#endif