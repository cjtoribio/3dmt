//
//  vec3.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__vec3__
#define __OpenGL__vec3__

#include "../SpecialKeys.h"

class vec3
{
public:
    
    PROPERTY_PUBLIC(float, x, X);
    PROPERTY_PUBLIC(float, y, Y);
    PROPERTY_PUBLIC(float, z, Z);
    
    vec3();
    vec3(float x, float y, float z);
    ~vec3();
    
    bool initialize(float x, float y, float z);
    
    void translate(vec3 vector);
    void rotate(float angle, vec3 &axis);
    void scale(vec3 scale);
    
    float mag();
    
    vec3 operator^(const vec3 &V);
    vec3 operator*(const float num);
    vec3 operator+(const vec3 &V);
    
    CREATE_METHOD(vec3, initialize, (float x, float y, float z), (), (x, y, z));
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "vec3.cpp"
#endif

#endif /* defined(__OpenGL__vec3__) */
