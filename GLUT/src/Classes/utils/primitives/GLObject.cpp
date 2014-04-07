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

void GLObject::translate(vec3 vector)
{
    glTranslatef(vector.x, vector.y, vector.z);
}

void GLObject::rotate(float angle ,vec3 vector)
{
    glRotatef(angle, vector.x, vector.y, vector.z);
}

void GLObject::scale(vec3 vector)
{
    getPosition().scale(vector);
    glScalef(vector.x, vector.y, vector.z);
}