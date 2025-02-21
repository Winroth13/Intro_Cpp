#include "Box.h"

Box::Box(const int height, const int length, const int width)
	: Shape3D(height), length(length), width(width) {
}

void Box::SetLength(const int length) {
	this->length = length;
}

void Box::SetWidth(const int width) {
	this->width = width;
}

int Box::GetLength() const {
	return this->length;
}

int Box::GetWidth() const {
	return this->width;
}

int Box::Base() const {
	return this->length * this->width;
}

int Box::Volume() const {
	return this->length * this->width * this->GetHeight();
}

std::string Box::Description() const {
	return "Length: " + std::to_string(this->length) + " Width: " + std::to_string(this->width)
		+ " Height: " + std::to_string(this->GetHeight());
}