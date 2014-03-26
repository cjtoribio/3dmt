/*
 * Camera.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */


#ifndef File_Camera
#define File_Camera

#include <GL/gl.h>
#include <math.h>
#include "vec3.cpp"


class Camera
{
	float X , Y , Z;
	float PHI , THETA;
public: 
	Camera(){
		PHI = 180;
		THETA = 85;
		X = 200;
		Y = 80;
		Z = 10;
	}
	void fly(float dx)
	{
		Z += dx;
	}
	void walkLeft(float dx, float speed)
	{
		vec3 tV; 
		tV.x = -sin(PHI * M_PI / 180);
		tV.y = cos(PHI * M_PI / 180);
		tV = tV * (dx * speed / tV.mag());
		X += tV.x;
		Y += tV.y;
	}
	void walkFront(float dx, float speed)
	{
		vec3 tV; 
		tV.x = cos(PHI * M_PI / 180);
		tV.y = sin(PHI * M_PI / 180);
		tV = tV * (dx * speed / tV.mag());
		X += tV.x;
		Y += tV.y;
	}
	void rotateLeft(float dx, float speed)
	{
		PHI += dx * speed;
	}
	void rotateUp(float dx, float speed)
	{
		THETA += dx * speed;
	}
	float getPhi(){ return PHI;}
	float getTheta() {return THETA;}
	vec3 getPointingVector() const {
		double z = cos(M_PI / 180 * THETA); 
		double x = cos(M_PI / 180 * PHI) * sin(M_PI / 180 * THETA); 
		double y = sin(M_PI / 180 * PHI) * sin(M_PI / 180 * THETA); 
		return vec3(x,y,z);
	}
	vec3 getPointingVectorXY() const { 
		double x = cos(M_PI / 180 * PHI); 
		double y = sin(M_PI / 180 * PHI); 
		return vec3(x,y,0);
	}
	void position()
	{
		glRotatef(THETA + 180, 1.0, 0.0, 0.0);
		glRotatef(-PHI + 90, 0, 0, 1);
		glTranslatef(-X , -Y , -Z);
	}
};

#endif
