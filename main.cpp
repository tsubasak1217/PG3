#include <stdio.h>
#include <iostream>
#include <list>

#include "TakeC.h"
#include "Tsubasa.h"
#include "Otsu.h"

int main(){ //開く

	std::list<BaseHuman*>humans;
	humans.emplace_back(new TakeC());
	humans.emplace_back(new Tsubasa());
	humans.emplace_back(new Otsu());

	for(auto& human : humans){
		human->Introduce();
		delete human;
		human = nullptr;
	}

	return 0;

} //閉じる