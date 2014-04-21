/*
 * WindowAverager.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: CarlosJose
 */

#include "Amplifier.h"

Amplifier::Amplifier(double constant) {
	this->constant = constant;
}

Amplifier::~Amplifier() {
	// TODO Auto-generated destructor stub
}

void Amplifier::push(double num)
{
	buffer.push(num);
}

double Amplifier::pop()
{
	if(buffer.size() == 0)return 0;
	double ret = buffer.front();
	buffer.pop();
	return ret * this->constant;
}

