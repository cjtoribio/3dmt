/*
 * Color.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: CarlosJose
 */

#ifndef File_Color
#define File_Color

#include <GL/gl.h>
#include <GL/glut.h>
#include <algorithm>
using namespace std;

struct Color
{
	double R,G,B;
	Color(double R = 0,double G = 0,double B = 0){
		this->R = max(min(R , 255.0), 0.0);
		this->G = max(min(G , 255.0), 0.0);
		this->B = max(min(B , 255.0), 0.0);
	}
	Color& setRed(double R) { this->R = R; return *this; }
	Color& setGreen(double G) { this->G = G; return *this; }
	Color& setBlue(double B) { this->B = B; return *this; }
	Color operator+(const Color& C)const{
		return Color( R + C.R , G + C.G , B + C.B );
	}
	
	void draw()
	{
		glColor3f(R,G,B);
	}
};

#endif
