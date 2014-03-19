//
//  GLColor.cpp
//  OpenGL
//
//  Created by Victor Manuel Polanco on 3/11/14.
//  Copyright (c) 2014 Victor Manuel Polanco. All rights reserved.
//

#include "GLColor.h"

GLColor::GLColor()
{
//    glColor3f(0.0, 0.0, 0.0);
    _r = 0.0;
    _g = 0.0;
    _b = 0.0;
}
GLColor::~GLColor()
{
    
}

GLColor::GLColor(GLfloat R, GLfloat G, GLfloat B)
{
//    glColor3f(R, G, B);
    _r = R;
    _g = G;
    _b = B;
}