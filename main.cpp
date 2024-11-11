#include <stdio.h>
#include <string>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main(){ //開く

	IShape* shapes[] = {new Circle(1.0f),new Rectangle(5.0f,4.0f)};
	for(int i = 0; i < 2; i++){
		shapes[i]->Draw();
	}

	for(int i = 0; i < 2; i++){
		delete shapes[i];
		shapes[i] = nullptr;
	}

	return 0;

} //閉じる