//
//  Processor.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__IProcessor__
#define ___DMT__IProcessor__

#include <iostream>

class IProcessor
{
public:
    IProcessor();
    ~IProcessor();
    virtual void push(double);
    virtual double pop();
};


#if defined(__APPLE__) && defined(__MACH__)
#   include "IProcessor.cpp"
#endif


#endif /* defined(___DMT__Processor__) */
