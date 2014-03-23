/*
 * Camera.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: CarlosJose
 */

#include "./vec3.cpp"
#include "math.h"

struct Camera
{
	float X , Y , Z;
	float PHI , THETA;
	Camera(){
		PHI = M_PI / 2;
		THETA = 0;
		X = 0;
		Y = 0;
		Z = 100;
	}
	void panLeft(float dx, float speed)
	{
		vec3 pV; 
		pV.x = cos(PHI);
		pV.y = sin(PHI);

		vec3 tV; 
		tV.x = cos(PHI) * sin(THETA);
		tV.y = sin(PHI) * sin(THETA);
		tV.z = cos(THETA);
		
		vec3 result = THETA >= 90 ? (tV ^ pV) : (pV ^ tV);
		result = result * (dx * speed / result.mag());
		X += result.x;
		Y += result.y;
		Z += result.z;
	}
	void panUp(float dx, float speed)
	{
		vec3 pV; 
		pV.x = cos(PHI);
		pV.y = sin(PHI);

		vec3 tV; 
		tV.x = cos(PHI) * sin(THETA);
		tV.y = sin(PHI) * sin(THETA);
		tV.z = cos(THETA);
		
		vec3 result = THETA >= 90 ? (tV ^ pV) : (pV ^ tV);
		
		vec3 result2 = result ^ tV;
		result2 = result2 * (dx * speed / result2.mag());
		X += result2.x;
		Y += result2.y;
		Z += result2.z;
	}
	void zoomIn(float dx, float speed)
	{
		vec3 tV; 
		tV.x = cos(PHI) * sin(THETA);
		tV.y = sin(PHI) * sin(THETA);
		tV.z = cos(THETA);
		tV = tV * (dx * speed / tV.mag());
		X -= tV.x;
		Y -= tV.y;
		Z -= tV.z;
	}
	void rotateLeft(float dx, float speed)
	{
		PHI += dx * speed;
	}
	void rotateUp(float dx, float speed)
	{
		THETA += dx * speed;
	}
};
