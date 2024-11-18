#include <stdio.h>
#include <string>
#include <iostream>
#include <list>
#include "BaseYamanoteLine.h"
#include "YamanoteLine2022.h"

int main(){ //開く

	std::list<BaseYamanoteLine> stationLists;
	stationLists.emplace_back(YamanoteLine1970());
	stationLists.emplace_back(YamanoteLine2019());
	stationLists.emplace_back(YamanoteLine2022());

	for(auto& list : stationLists){
		list.Output();
	}

	return 0;

} //閉じる