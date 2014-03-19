//
//  GLObject.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLObject.h"

GLObject::GLObject()
{
    
}

GLObject::~GLObject()
{
    
}

void GLObject::translate(GLVec3 vector)
{
    glTranslatef(vector.getX(), vector.getY(), vector.getZ());
}

void GLObject::rotate(GLfloat angle ,GLVec3 vector)
{
    glRotatef(angle, vector.getX(), vector.getY(), vector.getZ());
}

void GLObject::scale(GLVec3 vector)
{
    getPosition().scale(vector);
    glScalef(vector.getX(), vector.getY(), vector.getZ());
}