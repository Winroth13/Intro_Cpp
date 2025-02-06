#include "rectangle.h"

Rectangle::Rectangle() {
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(float width, float height) {
	this->width = width;
	this->height = height;
}

void Rectangle::setWidth(float width) {
	this->width = width;
}

void Rectangle::setHeight(float height) {
	this->height = height;
}

float Rectangle::circumference() {
	float widthHeight = this->width + this->height;
	return 2 * widthHeight;
}

float Rectangle::area() {
	return this->width * this->height;
}