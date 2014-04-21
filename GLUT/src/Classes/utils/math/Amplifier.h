/*
 * WindowAverager.h
 *
 *  Created on: Apr 19, 2014
 *      Author: CarlosJose
 */

#ifndef AMPLIFIER_H_
#define AMPLIFIER_H_

#include "../SpecialKeys.h"
#include "IProcessor.h"

class Amplifier : public IProcessor{
	
	PROPERTY_PRIVATE(queue<double> , buffer, Buffer);
	PROPERTY_PRIVATE(double , constant, Constant);
	
public:
	Amplifier(double);
	virtual ~Amplifier();
	void push(double);
	double pop();
};

#endif /* AMPLIFIER_H_ */
