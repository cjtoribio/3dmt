//  OpenGL
//  GLObject.h
//
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLObject__
#define __OpenGL__GLObject__

#include <iostream>
#include "../SpecialKeys.h"
#include "vec3.h"
#include "vec4.h"
#include "Color.h"

using namespace std;

class GLObject
{
public:

    PROPERTY(string, _name, Name);
    PROPERTY(vec3, _position, Position);
    PROPERTY(Color, _color, Color);
    
    GLObject();
    ~GLObject();
    
    virtual void draw() = 0;
    
    void translate(vec3 vector);
    void rotate(float angle ,vec3 vector);
    void scale(vec3 vector);
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "GLObject.cpp"
#endif


#endif /* defined(__OpenGL__GLObject__) */
