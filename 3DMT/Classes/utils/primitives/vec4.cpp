//
//  vec4.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "vec4.h"

vec4::vec4(float _x, float _y, float _z, float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

vec4::vec4()
{
    
}

vec4::~vec4()
{
    
}

float* vec4::getPosVec()
{
    float* pos = new float[4];
    
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;
    pos[3] = w;
    
    return pos;
}

void vec4::traslate(vec4 vector)
{
    
}

void vec4::rotate(float angle, vec4 &axis)
{
    
}

void vec4::scale(vec4 scale)
{
    
}
