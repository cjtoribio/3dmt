/*
 * Point.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: CarlosJose
 */

#ifndef File_Point
#define File_Point

#include <GL/glut.h>

struct Point
{
	double x,y,z;
	double radius;
	double R,G,B;
	Point(double x = 0,double y = 0,double z = 0){
		this->x = x;
		this->y = y;
		this->z = z;
		this->radius = 0.3;
		R = G = B = 1;
	}
	void setColor(double R, double G, double B)
	{
		this->R = R;
		this->G = G;
		this->B = B;
	}
	void draw()
	{
		glPushMatrix();
		glColor3f(R,G,B);
		glTranslatef(x,y,z);
		glutSolidSphere(radius,3,3);
		glPopMatrix();
	}
};

#endif
