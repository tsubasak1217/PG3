#pragma once
#include <list>

class BaseYamanoteLine{
public:
	BaseYamanoteLine();
	std::list<const char*> stations;
	const char* name;
	void Output();
};