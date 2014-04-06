//
//  Plane.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/2/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__Plane__
#define ___DMT__Plane__

#include "../primitives/GLObject.h"

class Plane: public GLObject
{
public:
    
    PROPERTY(int, limit, Limit);
    PROPERTY(string, axis, Axis);
    
    Plane();
    Plane(string axis);
    ~Plane();
    
    virtual void draw();
    
    void draw(float dx);
    void drawXYPlane(float dx);
    void drawXZPlane(float dx);
    void drawYZPlane(float dx);
    
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Plane.cpp"
#endif

#endif /* defined(___DMT__Plane__) */
