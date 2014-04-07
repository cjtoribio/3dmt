//
//  vec3.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__Point__
#define __OpenGL__Point__

#include "../primitives/GLObject.h"

class Point: public GLObject
{
public:
    
    PROPERTY_PUBLIC(float, x, X);
    PROPERTY_PUBLIC(float, y, Y);
    PROPERTY_PUBLIC(float, z, Z);
    PROPERTY_PUBLIC(float, radius, Radius);
    
    Point();
    Point(float x, float y, float z);
    ~Point();
    
    void draw();
    
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Point.cpp"
#endif

#endif /* defined(__OpenGL__Point__) */
