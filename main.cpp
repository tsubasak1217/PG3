#include <stdio.h>
#include <string>
#include <iostream>
#include "Player.h"

void CreatePlayer(){

	Player players[3] = { Player("ツバサ"),Player("マサキ"),Player("レン")};
	
	for(int i = 0; i < 3; i++){
		players[i].PrintStatus();
	}
}

int main(){ //開く

	CreatePlayer();

	return 0;
} //閉じる