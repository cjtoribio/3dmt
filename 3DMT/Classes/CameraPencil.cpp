/*
 * Pencil.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: CarlosJose
 */

#ifndef File_CameraPencil
#define File_CameraPencil

#include "Camera.cpp"
#include "vec3.cpp"

struct CameraPencil
{
	double x,y,z;
	double radius;
	double R,G,B;
	CameraPencil(){
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->radius = 3;
		R = G = B = 1;
	}
	void setColor(double R, double G, double B)
	{
		this->R = R;
		this->G = G;
		this->B = B;
	}
	void moveLeft(const Camera2 &camera, double dx)
	{
		vec3 direction = camera.getPointingVector();
		vec3 forward = camera.getPointingVectorXY();
		forward.z = 1;
		forward = forward * (1/forward.mag());
		vec3 left = forward ^ direction;
		x += left.x * dx;
		y += left.y * dx;
		z += left.z * dx;
	}
	void moveUp(const Camera2 &camera, double dx)
	{
		vec3 direction = camera.getPointingVector();
		vec3 forward = camera.getPointingVectorXY();
		forward.z = 1;
		forward = forward * (1/forward.mag());
		vec3 left = forward ^ direction;
		vec3 up = left ^ forward;
		x += up.x * dx;
		y += up.y * dx;
		z += up.z * dx;
	}
	void draw()
	{
		glPushMatrix();
		glColor3f(R,G,B);
		glTranslatef(x,y,z);
		glutSolidSphere(radius,10,10);
		glPopMatrix();
	}
};

#endif
