#include "rectangle.h"

Rectangle::Rectangle(float width, float height) {
	this->width = width;
	this->height = height;
}

float Rectangle::getWidth() const {
	return this->width;
}

float Rectangle::getHeight() const {
	return this->height;
}

void Rectangle::setWidth(float width) {
	this->width = width;
}

void Rectangle::setHeight(float height) {
	this->height = height;
}

float Rectangle::circumference() const {
	float widthHeight = this->width + this->height;
	return 2 * widthHeight;
}

float Rectangle::area() const {
	return this->width * this->height;
}

bool Rectangle::operator==(const Rectangle& other) const {
	return this->circumference() == other.circumference();
}

bool Rectangle::operator!=(const Rectangle& other) const {
	return this->circumference() != other.circumference();
}

bool Rectangle::operator<(const Rectangle& other) const {
	return this->circumference() < other.circumference();
}

bool Rectangle::operator>(const Rectangle& other) const {
	return this->circumference() > other.circumference();
}