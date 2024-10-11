#pragma once
#include <string>
#include <stdio.h>
#include "Animal.h"

// åpè≥
class Player : public Animal{

public:
	Player();
	Player(std::string name);
	~Player()override;

	Player& operator=(const Player&) = default;

public:
	std::string GetName(){ return name_; }
	void SetName(std::string name){ name_ = name; }

public:
	void PrintStatus();

private:
	std::string name_;
	static int playerCount_;
};