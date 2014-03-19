//
//  GLVec4.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLVec4.h"

GLVec4::GLVec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    _x = x;
    _y = y;
    _z = z;
    _w = w;
}

GLVec4::GLVec4()
{
    
}

GLVec4::~GLVec4()
{
    
}

GLfloat* GLVec4::getPosVec()
{
    GLfloat* pos = new GLfloat[4];
    
    pos[0] = _x;
    pos[1] = _y;
    pos[2] = _z;
    pos[3] = _w;
    
    return pos;
}

void GLVec4::traslate(GLVec4 vector)
{
    
}

void GLVec4::rotate(GLfloat angle, GLVec4 &axis)
{
    
}

void GLVec4::scale(GLVec4 scale)
{
    
}
