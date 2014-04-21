/*
 * WindowAverager.h
 *
 *  Created on: Apr 19, 2014
 *      Author: CarlosJose
 */

#ifndef WINDOWAVERAGER_H_
#define WINDOWAVERAGER_H_

#include "../SpecialKeys.h"
#include "IProcessor.h"

class WindowAverager : public IProcessor{
	
	PROPERTY_PRIVATE(queue<double> , buffer, Buffer);
	double average;
	
public:
	WindowAverager();
	virtual ~WindowAverager();
	void push(double);
	double pop();
};

#endif /* WINDOWAVERAGER_H_ */
