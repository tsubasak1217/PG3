#include <stdio.h>
#include <cstdint>

// 最低賃金
const int32_t  minimunSalary = 1072;

// 給料形式の名前のenum
enum class SalalyType : int32_t{
	NORMAL = 0,
	RECURSIVE
};

// 再帰計算関数
int32_t CalcRecursiveSalary(int32_t loop, int32_t kMaxLoop, int32_t currentSalary){

	int32_t salary = currentSalary * 2 - 50;
	if(loop + 1 >= kMaxLoop){
		return salary;
	} else{
		return CalcRecursiveSalary(loop + 1, kMaxLoop, salary);
	}
};

// 給料計算関数
int32_t CalcSalary(SalalyType salaryType, int32_t hours){

	int32_t salary = 0;

	switch(salaryType){

	case SalalyType::NORMAL:
		salary = minimunSalary * hours;
		return salary;
		break;

	case SalalyType::RECURSIVE:
		return CalcRecursiveSalary(0, hours, 100);
		break;

	default:
		return 0;
		break;

	}
};



int main(){ //開く

	// 通常形式の計算12時間分
	for(int32_t i = 1; i <= 12; i++){
		printf("NORMAL: %d 時間 : %d 円\n", i, CalcSalary(SalalyType::NORMAL, i));
	}

	printf("\n");

	// 再帰形式の計算12時間分
	for(int32_t i = 1; i <= 12; i++){
		printf("RECURSIVE: %d 時間 : %d 円\n", i, CalcSalary(SalalyType::RECURSIVE, i));
	}

	return 0;
} //閉じる