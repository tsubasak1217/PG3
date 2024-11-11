#pragma once
#include "IShape.h"
class Rectangle : public IShape{
public:
	Rectangle() = default;
	Rectangle(float width, float height);

	float Size()override;
	void Draw()override;

public:
	float width;
	float height;
};

