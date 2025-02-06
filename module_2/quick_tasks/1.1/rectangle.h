#ifndef RECTANGEL_H
#define RECTANGEL_H

class Rectangle
{
private:
	float width;
	float height;
public:
	Rectangle();
	Rectangle(float width, float height);
	void setWidth(float width);
	void setHeight(float height);
	float circumference();
	float area();
};

#endif