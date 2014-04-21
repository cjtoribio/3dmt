//
//  Clamper.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "BiasDiscriminator.h"
#include <iostream>

BiasDiscriminator::BiasDiscriminator()
{
    avg = 0;
    sqAvg = 0;
    mode = 0;
}

BiasDiscriminator::~BiasDiscriminator()
{
	
}

void BiasDiscriminator::push(double value)
{
	avg = (avg * buffer.size() + value) / (buffer.size() + 1);
    buffer.push(value);
    value *= value;
	sqAvg = (sqAvg * sqBuffer.size() + value) / (sqBuffer.size() + 1);
    sqBuffer.push(value);
}

double BiasDiscriminator::pop()
{
	if(buffer.size() <= 100)return 0;
	double dev = sqAvg - avg * avg;
	avg = (avg * buffer.size() - buffer.front()) / (buffer.size() - 1);
	buffer.pop();
	sqAvg = (sqAvg * sqBuffer.size() - sqBuffer.front()) / (sqBuffer.size() - 1);
	sqBuffer.pop();
	if(dev <= 0.5e-5)
		mode = avg;
    return avg - mode;
}

