#include "Rectangle.h"

Rectangle::Rectangle(float width, float height){
	this->width = width;
	this->height = height;
}

float Rectangle::Size(){
	return width * height;
}

void Rectangle::Draw(){
	printf("Rectangle: width = %f cm, height = %f cm,size = %f cm2\n", width, height,Size());
}
