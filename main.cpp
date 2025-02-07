#include <iostream>
#include <string>
#include <chrono>

int main(){

    std::string str(100000,'a');
    std::string dest;
	printf("%d文字のコピーとムーブの速度比較\n", (int)str.size());

    // コピーの時間計測
	auto start = std::chrono::steady_clock::now();
	dest = str;
	auto end = std::chrono::steady_clock::now();
	auto copy_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	// ムーブの時間計測
	start = std::chrono::steady_clock::now();
	dest = std::move(str);
	end = std::chrono::steady_clock::now();
	auto move_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	// 結果の出力
	printf("コピー : %dμs\n", copy_time);
	printf("ムーブ : %dμs\n", move_time);

    return 0;
}
