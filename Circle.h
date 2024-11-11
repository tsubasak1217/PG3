#pragma once
#include "IShape.h"

class Circle : public IShape{
public:
	Circle() = default;
	Circle(float radius);

	float Size()override;
	void Draw()override;

public:
	float radius;
};
