//
//  color.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__color__
#define __OpenGL__color__

#include "../SpecialKeys.h"

class Color
{
public:
    
    PROPERTY_PUBLIC(float, r, R);
    PROPERTY_PUBLIC(float, g, G);
    PROPERTY_PUBLIC(float, b, B);
    
    Color();
    ~Color();
    
    Color(float R, float G, float B);
    
    Color& setRed(double R);
    Color& setGreen(double G);
    Color& setBlue(double B);
    
    Color operator+(const Color& C);
    
    void draw();
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "Color.cpp"
#endif

#endif /* defined(__OpenGL__color__) */
