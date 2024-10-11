#pragma once

struct Vector3 final{

public:
	int x;
	int y;
	int z;

public:

	Vector3 operator+(const Vector3& other){

		Vector3 result;

		result.x = this->x + other.x;
		result.y = this->y + other.y;
		result.z = this->z + other.z;

		return result;
	}

	void operator+=(const Vector3& other){
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

};