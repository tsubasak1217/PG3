#include <stdio.h>

// テンプレ
template <typename T>
T Min(T value1, T value2){ return value1 < value2 ? value1 : value2; }

// charはテンプレ解除
template<>
char Min<char>(char value1, char value2){ 
	printf("数字以外は代入できません\n"); 
	return 0;
}

int main(){ //開く

	// 出力
	printf("Min<int>(114,514) = %d\n", Min<int>(114, 514));
	printf("Min<float>(11.4f,51.4f) = %f\n", Min<float>(11.4f, 51.4f));
	printf("Min<double>(1919.0,810.0) = %lf\n", Min<double>(1919.0, 810.0));
	printf("Min<char>(a,b) = %c\n", Min<char>('a', 'b'));

	return 0;
} //閉じる