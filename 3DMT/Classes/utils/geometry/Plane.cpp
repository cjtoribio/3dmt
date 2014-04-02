//
//  Plane.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/2/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Plane.h"

Plane::Plane()
{
    limit = PLANE_MAX;
}

Plane::Plane(string _axis)
{
    axis = _axis;
    limit = PLANE_MAX;
}

Plane::~Plane()
{
    
}

void Plane::draw()
{
    
}

void Plane::draw(float dx)
{
    if(axis == PLANEXY)
        drawXYPlane(dx);
    else if(axis == PLANEXZ)
        drawXZPlane(dx);
    else if(axis == PLANEYZ)
        drawYZPlane(dx);
    
    draw();
}

void Plane::drawXYPlane(float dx)
{
    if (dx==0)
        glColor3f(.3,.6,.3);
    else
        glColor3f(.0,0.50,.0);
    
    glVertex3f(0,dx,0);
    glVertex3f(limit,dx,0);
    
    
    if (dx==0)
        glColor3f(.3,.3,.6);
    else
        glColor3f(0.25,0.25,0.25);
    
    glVertex3f(dx,0,0);
    glVertex3f(dx,limit,0);
}

void Plane::drawXZPlane(float dx)
{
    if (dx==0)
        glColor3f(.6,.3,.3);
    else
        glColor3f(0.50,0,0);
    
    glVertex3f(dx,0,0);
    glVertex3f(dx,0,limit);
    
    if (dx==0)
        glColor3f(.3,.3,.6);
    else
        glColor3f(0.25,0.25,0.25);
    
    glVertex3f(0,0,dx);
    glVertex3f(limit,0,dx);
}

void Plane::drawYZPlane(float dx)
{
    if (dx==0)
        glColor3f(.3,.3,.6);
    else
        glColor3f(0, 0,0.50);
    
    glVertex3f(0,0,dx);
    glVertex3f(0,limit,dx);
    
    
    if (dx==0)
        glColor3f(.6,.3,.3);
    else
        glColor3f(0.25,0.25,0.25);
    
    glVertex3f(0,dx,0);
    glVertex3f(0,dx,limit);
}