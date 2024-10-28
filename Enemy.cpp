#include "Enemy.h"

Enemy::Enemy(){
	funcTable_[ENEMY_ACTION_APPROACH] = [this](){this->Approach();};
	funcTable_[ENEMY_ACTION_SHOOT] = [this](){this->Shoot();};
	funcTable_[ENEMY_ACTION_EXIT] = [this](){this->Exit();};
}

void Enemy::Action(){
	while(actionPhase_ != ENEMY_ACTION_END){
		funcTable_[(int)actionPhase_]();
		actionPhase_++;
	}
}

void Enemy::Approach(){ printf("“G‚ªÚ‹ßI\n"); }
void Enemy::Shoot(){ printf("“G‚ª’e‚ğŒ‚‚Á‚Ä‚«‚½I\n"); }
void Enemy::Exit(){ printf("“G‚ª—£’E‚µ‚½I\n"); }
