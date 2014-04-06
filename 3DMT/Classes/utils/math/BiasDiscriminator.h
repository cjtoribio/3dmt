//
//  Clamper.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__Clamper__
#define ___DMT__Clamper__

#include <iostream>
#include "../SpecialKeys.h"

class BiasDiscriminator : public IProcessor {
    
    PROPERTY_PRIVATE(float, minValue, MinValue);
    PROPERTY_PRIVATE(float, maxValue, MaxValue);
    PROPERTY_PRIVATE(queue<float>, buffer, Buffer);
    
public:
    
    BiasDiscriminator();
    BiasDiscriminator(double minMaxValue);
    BiasDiscriminator(double minValue , double maxValue);
    void push(double);
    double pop();
    
};


#if defined(__APPLE__) && defined(__MACH__)
#   include "BiasDiscriminator.cpp"
#endif

#endif /* defined(___DMT__Clamper__) */
