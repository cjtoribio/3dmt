//
//  Integrator.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Integrator.h"

Integrator::Integrator()
{
    prevTime = 0;
    dt = 0;
}
Integrator::Integrator(float constant)
{
    prevTime = 0;
    dt = 0;
    this->constant = constant;
}

Integrator::~Integrator()
{
    
}

void Integrator::push(double p)
{
    buffer.push(p);
    
    dt = ((float)clock()/CLOCKS_PER_SEC - prevTime)/ buffer.size();
    
}

double Integrator::pop()
{
    if(buffer.size() == 0)return 0;
    double top = buffer.front();

    buffer.pop();
    
    prevTime += dt;
    
    sum += top * dt;
    
    return sum * constant;
}