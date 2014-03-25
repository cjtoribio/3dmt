/*
 * Vector.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */

#include "math.h"
struct vec3
{
	double x,y,z;
	vec3(double x = 0,double y = 0,double z = 0){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	vec3 operator^(const vec3 &V){
		return vec3( 
				+(y * V.z - z * V.y) , 
				-(x * V.z - z * V.x) ,
				+(x * V.y - y * V.x)
		);
	}
	vec3 operator*(const float num){
		return vec3(x*num , y*num , z*num);
	}
	vec3 operator+(const vec3 &V){
		return vec3(x+V.x , y+V.y , z+V.z);
	}
	float mag(){
		return sqrt(x*x + y*y + z*z);
	}
};
