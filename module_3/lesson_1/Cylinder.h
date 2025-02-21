#ifndef CYLINDER_H
#define CYLINDER_H
#include "Shape3D.h"
#include <string>

enum Orientation { Vertical, Horizontal };

class Cylinder : Shape3D {
private:
	int radius;
	Orientation orientation;
public:
	Cylinder(const int height, const int radius, const Orientation orientation);
	void SetRadius(const int redius);
	void SetOrientation(const Orientation orientation);
	int GetRadius() const;
	Orientation GetOrientation() const;
	int Base() const override;
	int Volume() const override;
	std::string Description() const override;
};

#endif