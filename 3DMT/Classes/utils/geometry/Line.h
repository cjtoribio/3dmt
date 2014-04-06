//
//  Line.h
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef ___DMT__Line__
#define ___DMT__Line__

#include <iostream>
#include "../../utils/SpecialKeys.h"

class Line: public GLObject
{
    
    PROPERTY_PRIVATE(Point , a , A );
    PROPERTY_PRIVATE(Point, b, B);
    
public:
    
    PROPERTY(float, width, Width);
    Line(Point,Point,Color);
    
    ~Line();
    
    void draw();
    
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Line.cpp"
#endif

#endif /* defined(___DMT__Line__) */
