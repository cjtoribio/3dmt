/*
 * PittySignalCanceller.cpp
 *
 *  Created on: Apr 18, 2014
 *      Author: CarlosJose
 */

#include "PittySignalCanceller.h"

PittySignalCanceller::PittySignalCanceller(double window) {
	this->window = window;
}

PittySignalCanceller::~PittySignalCanceller() {
	
}

void PittySignalCanceller::push(double num)
{
	buffer.push(num);
}
double PittySignalCanceller::pop()
{
	if(buffer.empty())return 0;
	double ret = buffer.front();
	buffer.pop();
	if(ret <= window && ret >= -window)return 0;
	return ret;
}
