#pragma once
#include <stdio.h>

class IShape{
public:
	virtual float Size() = 0;
	virtual void Draw() = 0;
};

