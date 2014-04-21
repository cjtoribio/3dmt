//
//  vec3.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "vec3.h"

vec3::vec3(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

vec3::vec3()
{
    x = 0 , y = 0 , z = 0;
}

vec3::~vec3()
{
    
}

bool vec3::initialize(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
    
    return true;
}

void vec3::translate(vec3 vector)
{
    x += vector.x;
    y += vector.y;
    z += vector.z;
}

void vec3::rotate(float angle, vec3 &axis)
{
    glRotatef(angle, axis.x, axis.y, axis.z);
}

void vec3::scale(vec3 scale)
{
    x *= scale.x;
    y *= scale.y;
    z *= scale.z;
}

vec3 vec3::operator*(const float num)
{
    return vec3(x*num , y*num , z*num);
}

vec3 vec3::operator+(const float num)
{
    return vec3(x+num , y+num , z+num);
}

vec3 vec3::operator-(const float num)
{
    return vec3(x-num , y-num , z-num);
}

vec3 vec3::operator+(const vec3 &V)
{
    return vec3(x+V.x , y+V.y , z+V.z);
}

float vec3::mag()
{
    return sqrt(x*x + y*y + z*z);
}

vec3 vec3::operator^(const vec3 &V)
{
    return vec3(
				+(y * V.z - z * V.y) ,
				-(x * V.z - z * V.x) ,
				+(x * V.y - y * V.x)
                );
}

string vec3::toString()
{
	char str[40];
	sprintf(str,"vec3(%lf, %lf, %lf)",x,y,z);
	string a = str;
	return a;
}
