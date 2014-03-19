//
//  GLVec3.h
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#ifndef __OpenGL__GLVec3__
#define __OpenGL__GLVec3__

#include "SpecialKeys.h"

class GLVec3
{
public:
    
    SYNTHESIZE(GLfloat, _x, X);
    SYNTHESIZE(GLfloat, _y, Y);
    SYNTHESIZE(GLfloat, _z, Z);
    
    GLVec3();
    GLVec3(GLfloat x, GLfloat y, GLfloat z);
    ~GLVec3();
    
    bool initialize(GLfloat x, GLfloat y, GLfloat z);
    
    void translate(GLVec3 vector);
    void rotate(GLfloat angle, GLVec3 &axis);
    void scale(GLVec3 scale);
    
    CREATE_METHOD(GLVec3, initialize, (GLfloat x, GLfloat y, GLfloat z), (), (x, y, z));
};

#if defined(__APPLE__) && defined(__MACH__)
#   include "GLVec3.cpp"
#endif

#endif /* defined(__OpenGL__GLVec3__) */
