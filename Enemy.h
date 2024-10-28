#pragma once
#include <stdio.h>
#include <functional>

enum EnemyActionPhase{
	ENEMY_ACTION_APPROACH = 0,
	ENEMY_ACTION_SHOOT,
	ENEMY_ACTION_EXIT,
	ENEMY_ACTION_END
};

class Enemy{

public:
	Enemy();
	void Action();

private:
	void Approach();
	void Shoot();
	void Exit();

private:
	int32_t actionPhase_ = ENEMY_ACTION_APPROACH;
	std::function<void()> funcTable_[3];
};

