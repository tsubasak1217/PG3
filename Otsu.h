#pragma once
#include "BaseHuman.h"

class Otsu : public BaseHuman{
public:
	Otsu();
	~Otsu()override;

public:
	void Introduce()override;
};

