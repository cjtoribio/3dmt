//
//  vec4.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__vec4__
#define __OpenGL__vec4__

#include "../SpecialKeys.h"

class vec4
{
public:
    
    PROPERTY_PUBLIC(float, x, X);
    PROPERTY_PUBLIC(float, y, Y);
    PROPERTY_PUBLIC(float, z, Z);
    PROPERTY_PUBLIC(float, w, W);
    
    
    vec4();
    vec4(float x, float y, float z, float w);
    ~vec4();
    
    void traslate(vec4 vector);
    void rotate(float angle, vec4 &axis);
    void scale(vec4 scale);
    
    float* getPosVec();
    
};

#endif /* defined(__OpenGL__vec4__) */
