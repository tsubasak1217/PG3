#include "Player.h"

int Player::playerCount_ = 0;

// �R���X�g���N�^�@( ���̂���������Ɏ����I�ɌĂяo�����֐� )
Player::Player(){

	playerCount_++;
	printf("�v���C���[���쐬����܂���(����%d��)\n", playerCount_);

	HP_ = 100;
	attack_ = 10.0f;
	difence_ = 12.3f;
	speed_ = 24.0f;
}

Player::Player(std::string name){
	playerCount_++;
	printf("�v���C���[���쐬����܂���(����%d��)\n", playerCount_);

	name_ = name;
	HP_ = 100;
	attack_ = 10.0f;
	difence_ = 12.3f;
	speed_ = 24.0f;
}

// �f�X�g���N�^�@( ���̂��j������鎞�Ɏ����I�ɌĂяo�����֐� )
Player::~Player(){
	playerCount_--;
	printf("�v���C���[���j������܂���(����%d��)\n", playerCount_);
}


// �X�e�[�^�X���o�͂���֐�
void Player::PrintStatus(){
	printf("player1 ���O: %s\n", name_.c_str());
	printf("player1 HP: %d\n", HP_);
	printf("player1 �U����: %f\n", attack_);
	printf("player1 �h���: %f\n", difence_);
	printf("player1 �f����: %f\n\n", speed_);
}
