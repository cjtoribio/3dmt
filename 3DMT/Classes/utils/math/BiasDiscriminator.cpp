//
//  Clamper.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "BiasDiscriminator.h"

BiasDiscriminator::BiasDiscriminator()
{
    
}

BiasDiscriminator::BiasDiscriminator(double minMaxValue)
{
    this->minValue = -minMaxValue;
    this->maxValue = minMaxValue;
}

BiasDiscriminator::BiasDiscriminator(double minValue , double maxValue)
{
    this->minValue = minValue;
    this->maxValue = maxValue;
}


void BiasDiscriminator::push(double value)
{
    if(value >= minValue && value <= maxValue) value = 0;
    buffer.push( value );
}

double BiasDiscriminator::pop()
{
    if(buffer.size() == 0)return 0;
    double ret = buffer.front();
    buffer.pop();
    return ret;
}