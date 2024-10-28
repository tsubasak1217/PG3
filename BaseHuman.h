#pragma once
#include <stdio.h>

class BaseHuman{
public:
	BaseHuman() = default;
	virtual ~BaseHuman(){};

public:
	virtual void Introduce(){};
};

