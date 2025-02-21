#include "Cylinder.h"
#include <string>
#include <cmath>

const float PI = 3.1415f;

Cylinder::Cylinder(const int height, const int radius, const Orientation orientation)
	: Shape3D(height), radius(radius), orientation(orientation) {
}

void Cylinder::SetRadius(const int redius) {
	this->radius = radius;
}

void Cylinder::SetOrientation(const Orientation orientation) {
	this->orientation = orientation;
}

int Cylinder::GetRadius() const {
	return this->radius;
}

Orientation Cylinder::GetOrientation() const {
	return this->orientation;
}

int Cylinder::Base() const {
	return (int)std::floor(this->radius * this->radius * PI);
}

int Cylinder::Volume() const {
	return (int)std::floor(this->radius * this->radius * PI * this->GetHeight());
}

std::string Cylinder::Description() const {
	return "Radius: " + std::to_string(this->radius) + " Height: " + std::to_string(this->GetHeight())
		+ " IsHorizontal: " + std::to_string(this->orientation);
}