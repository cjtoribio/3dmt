//
//  GLSphere.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLSphere.h"

GLSphere::GLSphere()
{
    setRadius(1.0);
    setSlices(20);
    setStacks(10);
    setColor(BLUE);
}

GLSphere::~GLSphere()
{
    
}

void GLSphere::draw()
{
    glPushMatrix();
    glColor3f(getColor().getR(), getColor().getG(), getColor().getB());
    
    glutSolidSphere(getRadius(), getSlices(), getStacks());
    glPopMatrix();
}