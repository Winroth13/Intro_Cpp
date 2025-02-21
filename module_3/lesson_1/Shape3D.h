#ifndef SHAPE3D_H
#define SHAPE3D_H
#include <string>

class Shape3D {
private:
	int height;
public:
	Shape3D(const int height = 1);
	void SetHeight(const int height);
	int GetHeight() const;
	virtual int Base() const = 0;
	virtual int Volume() const = 0;
	virtual std::string Description() const = 0;
};

#endif