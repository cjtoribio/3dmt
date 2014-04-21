/*
 * Drawing.cpp
 *
 *  Created on: Apr 20, 2014
 *      Author: CarlosJose
 */

#include "Drawing.h"

Drawing::Drawing() {
	referencePoints = vector<vec3>();
	mousePosition = vec3(0,0,0);
	lastPoint = vec3(0,0,0);
}

Drawing::~Drawing() {
}

void Drawing::draw()
{
	for(int i = 0; i + 1 < referencePoints.size(); ++i)
	{
		Line(referencePoints[i],referencePoints[i+1] , WHITE).draw();
	}
	Line(lastPoint , mousePosition, RED).draw();
}

void Drawing::savePoint()
{
	referencePoints.push_back(mousePosition);
	lastPoint = referencePoints.back();
}

void Drawing::undo()
{
	if(referencePoints.size())referencePoints.pop_back();
	lastPoint = referencePoints.size() ? referencePoints.back() : mousePosition;
}
