#include "Shape3D.h"
#include <string>

Shape3D::Shape3D(const int height)
	: height(height) {
}

void Shape3D::SetHeight(const int height) {
	this->height = height;
}

int Shape3D::GetHeight() const {
	return this->height;
}