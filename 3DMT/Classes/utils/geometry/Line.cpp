//
//  Line.cpp
//  3DMT
//
//  Created by Victor Manuel Polanco on 4/6/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "Line.h"

Line::Line(Point A, Point B, Color C = BLACK)
{
    this->a = A;
    this->b = B;
    this->_color = C;
    this->width = 2.5;
}

Line::~Line()
{
    
}

void Line::draw()
{
    glLineWidth(width);
    this->_color.draw();
    glBegin(GL_LINES);
        glVertex3f(a.x , a.y , a.z);
        glVertex3f(b.x , b.y , b.z);
    glEnd();
}