/*
 * Point.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: CarlosJose
 */

#ifndef File_Line
#define File_Line

#include "../../SpecialKeys.h"

#include "./Color.cpp"
#include "./Point.cpp"
struct Line
{
	Point A, B;
	Color C;
	double width;
	Line(Point A, Point B, Color C = Color(0,0,0)){
		this->A = A;
		this->B = B;
		this->C = C;
		this->width = 2.5;
	}
	void draw()
	{
		glPushMatrix();
		glLineWidth(width);
		glBegin(GL_LINES);
		glVertex3f(A.x , A.y , A.z);
		glVertex3f(B.x , B.y , B.z);
		glPopMatrix();
	}
};

#endif
