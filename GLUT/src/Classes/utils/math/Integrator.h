//
//  Integrator.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__Integrator__
#define ___DMT__Integrator__

#include "../SpecialKeys.h"
#include "IProcessor.h"
#include "../Time/TimeUtils.h"
#include <queue>

class Integrator : public IProcessor
{
    
    PROPERTY_PRIVATE(float, dt, DT);
    PROPERTY_PRIVATE(float, constant, Constant);
    PROPERTY_PRIVATE(float, sum, Sum);
    PROPERTY_PRIVATE(float, prevTime, PrevTime);
    
public:
    
    PROPERTY(queue<double>, buffer, Buffer);
    
    Integrator();
    Integrator(float constant);
    ~Integrator();
    
    void integrate();
    void push(double p);
    double pop();
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Integrator.cpp"
#endif

#endif /* defined(___DMT__Integrator__) */
