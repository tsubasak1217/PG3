#include <stdio.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Vector3.h"

void CreatePlayer(){

	Player players[3] = { Player("ツバサ"),Player("マサキ"),Player("レン")};
	
	for(int i = 0; i < 3; i++){
		players[i].PrintStatus();
	}
}

int main(){ //開く

	Vector3 vector[2];
	Vector3 answer;

	vector[0] = { 0,1,2 };
	vector[1] = { 3,4,5 };

	vector[0] += vector[1];
	answer = vector[0] + vector[1];

	printf("x: %d y: %d z: %d", answer.x, answer.y, answer.z);

	return 0;

} //閉じる