#pragma once

class Animal{
public:
	Animal();
	virtual ~Animal();

public:

	int GetHP(){ return HP_; }
	void SetHP(int HP){ HP_ = HP; }

	float GetAttack(){ return attack_; }
	float GetDifence(){ return difence_; }
	float GetSpeed(){ return speed_; }

protected:// ���̃N���X���p�������N���X�̂ݎQ�Ƃł���

	int HP_;
	float attack_;
	float difence_;
	float speed_;

};
