#ifndef BOX_H
#define BOX_H
#include "Shape3D.h"
#include <string>

class Box : public Shape3D {
private:
	int length;
	int width;
public:
	Box(const int height, const int length, const int width);
	void SetLength(const int length);
	void SetWidth(const int width);
	int GetLength() const;
	int GetWidth() const;
	int Base() const override;
	int Volume() const override;
	std::string Description() const override;
};

#endif