//
//  GLVec3.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/10/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLVec3.h"

GLVec3::GLVec3(GLfloat x, GLfloat y, GLfloat z)
{
    _x = x;
    _y = y;
    _z = z;
}

GLVec3::GLVec3()
{
    
}

GLVec3::~GLVec3()
{
    
}

bool GLVec3::initialize(GLfloat x, GLfloat y, GLfloat z)
{
    _x = x;
    _y = y;
    _z = z;
    
    return true;
}

void GLVec3::translate(GLVec3 vector)
{
    _x += vector.getX();
    _y += vector.getY();
    _z += vector.getZ();
}

void GLVec3::rotate(GLfloat angle, GLVec3 &axis)
{
    glRotatef(angle, axis.getX(), axis.getY(), axis.getY());
}

void GLVec3::scale(GLVec3 scale)
{
    _x *= scale.getX();
    _y *= scale.getY();
    _z *= scale.getZ();
}
