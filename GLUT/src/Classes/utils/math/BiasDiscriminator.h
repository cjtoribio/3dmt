//
//  Clamper.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__Clamper__
#define ___DMT__Clamper__

#include "../SpecialKeys.h"
#include "IProcessor.h"

class BiasDiscriminator : public IProcessor 
{
    PROPERTY_PRIVATE(float , avg , Avg);
    PROPERTY_PRIVATE(float , mode, Mode);
    PROPERTY_PRIVATE(float , sqAvg , SqAvg);
    PROPERTY_PRIVATE(queue<float>, buffer, Buffer);
    PROPERTY_PRIVATE(queue<float>, sqBuffer, SqBuffer);
    
public:
    
    BiasDiscriminator();
    ~BiasDiscriminator();
    void push(double);
    double pop();
    
};


#if defined(__APPLE__) && defined(__MACH__)
#   include "BiasDiscriminator.cpp"
#endif

#endif /* defined(___DMT__Clamper__) */
