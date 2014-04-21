/*
 * WindowAverager.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: CarlosJose
 */

#include "WindowAverager.h"

WindowAverager::WindowAverager() {
	average = 0;
}

WindowAverager::~WindowAverager() {
	// TODO Auto-generated destructor stub
}

void WindowAverager::push(double num)
{
	average = (average * buffer.size() + num) / (buffer.size() + 1);
	buffer.push(num);
}

double WindowAverager::pop()
{
	if(buffer.size() <= 60)return 0;
	double ret = average;
	average = (average * buffer.size() - buffer.front()) / (buffer.size() - 1);
	buffer.pop();
	return ret;
}

