/*
 * PittySignalCanceller.h
 *
 *  Created on: Apr 18, 2014
 *      Author: CarlosJose
 */

#ifndef PITTYSIGNALCANCELLER_H_
#define PITTYSIGNALCANCELLER_H_

#include "IProcessor.h"
#include "../SpecialKeys.h"

class PittySignalCanceller: public IProcessor {
	
	PROPERTY_PRIVATE(double , window , Window);
	PROPERTY_PRIVATE(queue<double> , buffer , Buffer);
	
public:
	PittySignalCanceller(double);
	virtual ~PittySignalCanceller();
	
	void push(double);
	double pop();
};

#endif /* PITTYSIGNALCANCELLER_H_ */
