#include "Circle.h"

Circle::Circle(float radius){
	this->radius = radius;
}

float Circle::Size(){
	return 3.14159f * radius * radius;
}

void Circle::Draw(){
	printf("Circle: radius = %f cm, size = %f cm2\n", radius, Size());
}
