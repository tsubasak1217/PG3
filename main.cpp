#include <stdio.h>
#include <iostream>
#include "Compare.h"
#include <list>

int main(){ //開く

	std::list<VirtualCompare*>compareList_;
	compareList_.emplace_back(new Compare<int32_t, int32_t>(1,8));
	compareList_.emplace_back(new Compare<int32_t, float>(1,2.0f));
	compareList_.emplace_back(new Compare<int32_t, double>(1,1.9));
	compareList_.emplace_back(new Compare<float, int32_t>(0.7f,2));
	compareList_.emplace_back(new Compare<float, float>(1.5f,2.0f));
	compareList_.emplace_back(new Compare<float, double>(1.0f,2.6));
	compareList_.emplace_back(new Compare<double, int32_t>(1.2,2));
	compareList_.emplace_back(new Compare<double, float>(3.2,1.2f));
	compareList_.emplace_back(new Compare<double, double>(4.0,2.0));


	for(auto& compare : compareList_){
		compare->PrintMin();
		delete compare;
		compare = nullptr;
	}

	return 0;

} //閉じる