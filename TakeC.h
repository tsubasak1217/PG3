#pragma once
#include "BaseHuman.h"

class TakeC : public BaseHuman{
public:
	TakeC();
	~TakeC()override;

public:
	void Introduce()override;
};

