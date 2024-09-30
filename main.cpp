#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdint>
#include <random>
#include <chrono>


/////////////////////////////////////////////////
// 乱数生成
/////////////////////////////////////////////////

int32_t Random(int min, int max){
	// 乱数生成器を作成
	std::random_device rd;
	std::mt19937 gen(rd());

	// minからmaxまでの一様分布を設定
	std::uniform_int_distribution<> distrib(min, max);

	// 乱数を生成して返す
	return distrib(gen);
}


/////////////////////////////////////////////////
// 結果の回答関数
/////////////////////////////////////////////////

void Correct(){
	printf("正解！\n\n");
}

void Icorrect(){
	printf("不正解...\n\n");
}

typedef void(*pFunc)();


/////////////////////////////////////////////////
// 時限発動
/////////////////////////////////////////////////

void TimedFunc(float sec, pFunc func){

	// エントリー時の時間
	std::chrono::steady_clock::time_point enterTime_ = std::chrono::high_resolution_clock::now();

	while(true){
		// 現在の時間との差分を取る
		std::chrono::steady_clock::time_point currentTime_ = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> totalTime = currentTime_ - enterTime_;

		// 指定時間が経過したら
		if(totalTime.count() >= sec){
			(*func)();//発動
			break;
		}
	}
}


/////////////////////////////////////////////////
// main
/////////////////////////////////////////////////
int main(){ //開く

	// 関数ポインタ
	pFunc func;
	float waitTime = 3.0f;

	//
	while(true){

		// 出題
		printf("乱数当てゲーム！\n\n");
		printf("これから抽選される乱数は偶数？奇数？\n");
		printf("0.偶数   1.奇数\n\n");

		// 乱数取得
		uint32_t result = Random(1, 100);

		// 入力受付
		uint32_t input;

		while(true){

			// 入力受付
			printf("answer: ");
			std::cin >> input;

			if(input > 1){// 範囲外の場合続行
				printf("\n範囲外です！(0 or 1)\n\n");

			} else{// 回答

				printf("結果は...");

				if(result % 2 == input){
					func = &Correct;
					TimedFunc(waitTime, func);

				} else{
					func = &Icorrect;
					TimedFunc(waitTime, func);
				}

				break;
			}
		}
	}

	return 0;
} //閉じる