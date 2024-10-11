#include "Player.h"

int Player::playerCount_ = 0;

// コンストラクタ　( 実体を作った時に自動的に呼び出される関数 )
Player::Player(){

	playerCount_++;
	printf("プレイヤーが作成されました(現在%d体)\n", playerCount_);

	HP_ = 100;
	attack_ = 10.0f;
	difence_ = 12.3f;
	speed_ = 24.0f;
}

Player::Player(std::string name){
	playerCount_++;
	printf("プレイヤーが作成されました(現在%d体)\n", playerCount_);

	name_ = name;
	HP_ = 100;
	attack_ = 10.0f;
	difence_ = 12.3f;
	speed_ = 24.0f;
}

// デストラクタ　( 実体が破棄される時に自動的に呼び出される関数 )
Player::~Player(){
	playerCount_--;
	printf("プレイヤーが破棄されました(現在%d体)\n", playerCount_);
}


// ステータスを出力する関数
void Player::PrintStatus(){
	printf("player1 名前: %s\n", name_.c_str());
	printf("player1 HP: %d\n", HP_);
	printf("player1 攻撃力: %f\n", attack_);
	printf("player1 防御力: %f\n", difence_);
	printf("player1 素早さ: %f\n\n", speed_);
}
