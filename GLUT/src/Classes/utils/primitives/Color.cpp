//
//  color.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Color.h"

Color::Color()
{
//    color3f(0.0, 0.0, 0.0);
    r = 0.0;
    g = 0.0;
    b = 0.0;
}
Color::~Color()
{
    
}

Color::Color(float R, float G, float B)
{
    r = R;
    g = G;
    b = B;
}

Color& Color::setRed(double R)
{
    r = R;
    return *this;
}

Color& Color::setGreen(double G)
{
    g = G;
    return *this;
}

Color& Color::setBlue(double B)
{
    b = B;
    return *this;
}

Color Color::operator+(const Color& C)
{
    return Color(r + C.r, g + C.g, b + C.b);
}

void Color::draw()
{
    glColor3f(r, g, b);
}