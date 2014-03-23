//  GLObject.h
//  OpenGL
//
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLObject__
#define __OpenGL__GLObject__

#include <iostream>
#include "SpecialKeys.h"
#include "GLVec3.h"
#include "GLVec4.h"
#include "GLColor.h"

using namespace std;

class GLObject
{
public:

    SYNTHESIZE(string, _name, Name);
    SYNTHESIZE(GLVec3, _position, Position);
    SYNTHESIZE(GLColor, _color, Color);
    
    GLObject();
    ~GLObject();
    
    virtual void draw() = 0;
    
    void translate(GLVec3 vector);
    void rotate(GLfloat angle ,GLVec3 vector);
    void scale(GLVec3 vector);
};

#endif /* defined(__OpenGL__GLObject__) */
